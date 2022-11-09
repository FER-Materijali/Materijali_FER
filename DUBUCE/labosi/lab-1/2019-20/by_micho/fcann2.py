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


from sys import stdout

import numpy as np
from tqdm import tqdm


class ANN:
    def __init__(self, input_units: int, hidden_units: int, n_classes: int = 2):
        self._weights = [np.random.normal(loc=0,
                                          scale=np.reciprocal(np.mean([input_units, hidden_units])),
                                          size=(input_units, hidden_units)),
                         np.random.normal(loc=0,
                                          scale=np.reciprocal(np.mean([hidden_units, n_classes])),
                                          size=(hidden_units, n_classes))]

        self._bias = [np.zeros([1, hidden_units]), np.zeros([1, n_classes])]

    @property
    def weights(self):
        return self._weights

    @property
    def bias(self):
        return self._bias

    def forward(self, inputs):
        inputs = np.array(inputs)

        dense_1 = inputs @ self.weights[0] + self.bias[0]
        relu_1 = np.maximum(0., dense_1)

        dense_2 = relu_1 @ self.weights[1] + self.bias[1]
        exp_2 = np.exp(dense_2)
        exp_sum_2 = np.sum(exp_2, axis=1)
        softmax_2 = exp_2 / exp_sum_2[:, np.newaxis]

        return softmax_2

    def loss(self, y_true, y_pred, weight_decay: float = 0.):
        isolated_y_pred = y_pred[np.arange(len(y_pred)), y_true.argmax(axis=-1)]
        net_loss = -np.mean(np.log(isolated_y_pred))

        regularization_loss = weight_decay * np.sum([np.sum(np.square(x)) for x in self.weights])

        return net_loss + regularization_loss

    def train(self, x, y, n_epochs: int, learning_rate: float = 0.1, weight_decay: float = 0.):
        iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

        for i in iterator:
            dense_1 = x @ self.weights[0] + self.bias[0]
            relu_1 = np.maximum(0., dense_1)

            dense_2 = relu_1 @ self.weights[1] + self.bias[1]
            exp_2 = np.exp(dense_2)
            exp_sum_2 = np.sum(exp_2, axis=1)
            outputs = exp_2 / exp_sum_2[:, np.newaxis]

            loss = self.loss(y, outputs, weight_decay)

            iterator.set_description(f"[Epoch {i}]\tLoss: {loss:.04f}")

            grad_loss_wrt_y = outputs
            grad_loss_wrt_y[np.arange(len(outputs)), y.argmax(axis=-1)] -= 1
            grad_loss_wrt_y = grad_loss_wrt_y / len(x)

            grad_loss_wrt_weights_2 = relu_1.T @ grad_loss_wrt_y
            grad_loss_wrt_bias_2 = np.sum(grad_loss_wrt_y, axis=0)

            grad_loss_wrt_hidden = grad_loss_wrt_y @ self.weights[1].T
            grad_loss_wrt_hidden[relu_1 <= 0.] = 0.

            grad_loss_wrt_weights_1 = np.mean(x.T @ grad_loss_wrt_hidden, axis=0)
            grad_loss_wrt_bias_1 = np.sum(grad_loss_wrt_hidden, axis=0)

            self._weights[0] -= learning_rate * grad_loss_wrt_weights_1
            self._bias[0] -= learning_rate * grad_loss_wrt_bias_1
            self._weights[1] -= learning_rate * grad_loss_wrt_weights_2
            self._bias[1] -= learning_rate * grad_loss_wrt_bias_2

    def classify(self, x):
        return np.argmax(self.forward(x), axis=1)
