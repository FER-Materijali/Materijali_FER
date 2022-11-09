#   Copyright 2020 Miljenko Šuflaj
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#
#    NOTE: Applies only to forward, backward_inputs and backward_params
#    method implementations of FC, ReLU, SoftmaxCrossEntropyWithLogits
#    and L2Regularizer.

from abc import ABCMeta, abstractmethod
import numpy as np
import scipy
import scipy.stats as stats

from im2col_cython import col2im_cython, im2col_cython

zero_init = np.zeros


def variance_scaling_initializer(shape, fan_in, factor=2.0, seed=None):
    sigma = np.sqrt(factor / fan_in)
    return stats.truncnorm(-2, 2, loc=0, scale=sigma).rvs(shape)


class Layer(metaclass=ABCMeta):
    @abstractmethod
    def forward(self, inputs):
        pass

    @abstractmethod
    def backward_inputs(self, grads):
        pass

    def backward_params(self, grads):
        pass


# -- CONVOLUTION LAYER --
class Convolution(Layer):
    def __init__(self, input_layer, num_filters, kernel_size, name, padding='SAME',
                 weights_initializer_fn=variance_scaling_initializer,
                 bias_initializer_fn=zero_init):
        self.input_shape = input_layer.shape
        N, C, H, W = input_layer.shape
        self.C = C
        self.N = N
        self.num_filters = num_filters
        self.kernel_size = kernel_size

        assert kernel_size % 2 == 1

        self.padding = padding
        if padding == 'SAME':
            # with zero padding
            self.shape = (N, num_filters, H, W)
            self.pad = (kernel_size - 1) // 2
        else:
            # without padding
            self.shape = (N, num_filters, H - kernel_size + 1, W - kernel_size + 1)
            self.pad = 0

        fan_in = C * kernel_size ** 2
        self.weights = weights_initializer_fn([num_filters, kernel_size ** 2 * C], fan_in)
        self.bias = bias_initializer_fn([num_filters])
        # this implementation doesn't support strided convolutions
        self.stride = 1
        self.name = name
        self.has_params = True

    def forward(self, x):
        k = self.kernel_size
        self.x_cols = im2col_cython(x, k, k, self.pad, self.stride)
        res = self.weights.dot(self.x_cols) + self.bias.reshape(-1, 1)
        N, C, H, W = x.shape
        out = res.reshape(self.num_filters, self.shape[2], self.shape[3], N)
        return out.transpose(3, 0, 1, 2)

    def backward_inputs(self, grad_out):
        # nice trick from CS231n, backward pass can be done with just matrix mul and col2im
        grad_out = grad_out.transpose(1, 2, 3, 0).reshape(self.num_filters, -1)
        grad_x_cols = self.weights.T.dot(grad_out)
        N, C, H, W = self.input_shape
        k = self.kernel_size
        grad_x = col2im_cython(grad_x_cols, N, C, H, W, k, k, self.pad, self.stride)
        return grad_x

    def backward_params(self, grad_out):
        grad_bias = np.sum(grad_out, axis=(0, 2, 3))
        grad_out = grad_out.transpose(1, 2, 3, 0).reshape(self.num_filters, -1)
        grad_weights = grad_out.dot(self.x_cols.T).reshape(self.weights.shape)
        return [[self.weights, grad_weights], [self.bias, grad_bias], self.name]


class MaxPooling(Layer):
    def __init__(self, input_layer, name, pool_size=2, stride=2):
        self.name = name
        self.input_shape = input_layer.shape
        N, C, H, W = self.input_shape
        self.stride = stride
        self.shape = (N, C, H // stride, W // stride)
        self.pool_size = pool_size
        assert pool_size == stride, 'Invalid pooling params'
        assert H % pool_size == 0
        assert W % pool_size == 0
        self.has_params = False

    def forward(self, x):
        N, C, H, W = x.shape
        self.input_shape = x.shape
        # with this clever reshaping we can implement pooling where pool_size == stride
        self.x = x.reshape(N, C, H // self.pool_size, self.pool_size,
                           W // self.pool_size, self.pool_size)
        self.out = self.x.max(axis=3).max(axis=4)
        # if you are returning class member be sure to return a copy
        return self.out.copy()

    def backward_inputs(self, grad_out):
        grad_x = np.zeros_like(self.x)
        out_newaxis = self.out[:, :, :, np.newaxis, :, np.newaxis]
        mask = (self.x == out_newaxis)
        dout_newaxis = grad_out[:, :, :, np.newaxis, :, np.newaxis]
        dout_broadcast, _ = np.broadcast_arrays(dout_newaxis, grad_x)
        # this is almost the same as the real backward pass
        grad_x[mask] = dout_broadcast[mask]
        # in the very rare case that more then one input have the same max value
        # we can aprox the real gradient routing by evenly distributing across multiple inputs
        # but in almost all cases this sum will be 1
        grad_x /= np.sum(mask, axis=(3, 5), keepdims=True)
        grad_x = grad_x.reshape(self.input_shape)
        return grad_x


class Flatten(Layer):
    def __init__(self, input_layer, name):
        self.input_shape = input_layer.shape
        self.N = self.input_shape[0]
        self.num_outputs = 1
        for i in range(1, len(self.input_shape)):
            self.num_outputs *= self.input_shape[i]
        self.shape = (self.N, self.num_outputs)
        self.has_params = False
        self.name = name

    def forward(self, inputs):
        self.input_shape = inputs.shape
        inputs_flat = inputs.reshape(self.input_shape[0], -1)
        self.shape = inputs_flat.shape
        return inputs_flat

    def backward_inputs(self, grads):
        return grads.reshape(self.input_shape)


class FC(Layer):
    def __init__(self, input_layer, num_outputs, name,
                 weights_initializer_fn=variance_scaling_initializer,
                 bias_initializer_fn=zero_init):
        self.input_shape = input_layer.shape
        self.N = self.input_shape[0]
        self.shape = (self.N, num_outputs)
        self.num_outputs = num_outputs

        self.num_inputs = 1
        for i in range(1, len(self.input_shape)):
            self.num_inputs *= self.input_shape[i]

        self.weights = weights_initializer_fn([num_outputs, self.num_inputs], fan_in=self.num_inputs)
        self.bias = bias_initializer_fn([num_outputs])
        self.name = name
        self.has_params = True

        # Ne znam kako bi bez ovoga radio backward_params
        self._last_inputs = None

    def forward(self, inputs):
        self._last_inputs = inputs

        return inputs @ self.weights.T + self.bias

    def backward_inputs(self, grads):
        return grads @ self.weights

    def backward_params(self, grads):
        grad_weights = grads.T @ self._last_inputs
        grad_bias = np.sum(grads, axis=0)

        return [[self.weights, grad_weights], [self.bias, grad_bias], self.name]


class ReLU(Layer):
    def __init__(self, input_layer, name):
        self.shape = input_layer.shape
        self.name = name
        self.has_params = False

        # Isto kao i za FC
        self._last_inputs = None

    def forward(self, inputs):
        self._last_inputs = inputs

        return np.maximum(0, inputs)

    def backward_inputs(self, grads):
        grads[self._last_inputs <= 0.] = 0.

        return grads


class SoftmaxCrossEntropyWithLogits:
    def __init__(self):
        self.has_params = False

    def forward(self, x, y):
        sumlog = np.log(np.sum(np.exp(x), axis=1))
        mulsum = np.sum(x * y, axis=1)

        return np.mean(sumlog - mulsum)

    def backward_inputs(self, x, y):
        x_exp = np.exp(x)
        expsum = np.sum(x_exp, axis=1)

        x_softmax = x_exp.T / expsum

        return (x_softmax.T - y) / x.shape[0]


class L2Regularizer:
    def __init__(self, weights, weight_decay, name):
        self.weights = weights
        self.weight_decay = weight_decay
        self.name = name

    def forward(self):
        l2_norm = np.power(np.linalg.norm(self.weights), 2)

        return 0.5 * self.weight_decay * l2_norm

    def backward_params(self):
        grad_weights = self.weight_decay * self.weights

        return [[self.weights, grad_weights], self.name]


class RegularizedLoss:
    def __init__(self, data_loss, regularizer_losses):
        self.data_loss = data_loss
        self.regularizer_losses = regularizer_losses
        self.has_params = True
        self.name = 'RegularizedLoss'

    def forward(self, x, y):
        loss_val = self.data_loss.forward(x, y)
        for loss in self.regularizer_losses:
            loss_val += loss.forward()
        return loss_val

    def backward_inputs(self, x, y):
        return self.data_loss.backward_inputs(x, y)

    def backward_params(self):
        grads = []
        for loss in self.regularizer_losses:
            grads += [loss.backward_params()]
        return grads
