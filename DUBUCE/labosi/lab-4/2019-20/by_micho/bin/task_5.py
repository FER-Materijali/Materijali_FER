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

from copy import deepcopy
from sys import stdout
from time import sleep
from typing import Callable, List, Tuple

from matplotlib import pyplot as plt
import numpy as np
import torch
import torch.utils.data
from tqdm import tqdm

from util.losses import get_gan_loss


class Discriminator(torch.nn.Module):
    def __init__(self,
                 in_channels: int = 1,
                 channels: List[int] or Tuple[int] = (64, 128, 256, 512, 1),
                 kernels: List[int] or Tuple[int] = (4, 4, 4, 4, 4),
                 strides: List[int] or Tuple[int] = (2, 2, 2, 2, 1),
                 padding: List[int] or Tuple[int] = (1, 1, 1, 1, 0),
                 leaky_relu_slope: float = 0.2,
                 use_batch_norm: bool = True):
        """
        The Discriminator constructor.

        :param in_channels:
            (Optional) An int representing the number of input channels.
            Default: 1.

        :param channels:
            (Optional) A List[int] or Tuple[int] representing the channels of
            every convolutional layer. Default: (64, 128, 256, 512, 1).

        :param kernels:
            (Optional) A List[int] or Tuple[int] representing the kernels of
            every convolutional layer. Default: (4, 4, 4, 4, 4).

        :param strides:
            (Optional) A List[int] or Tuple[int] representing the strides of
            every convolutional layer. Default: (2, 2, 2, 2, 1).

        :param padding:
            (Optional) A List[int] or Tuple[int] representing the padding of
            every convolutional layer. Default: (1, 1, 1, 1, 0).

        :param leaky_relu_slope:
            (Optional) A float representing the slope of the leaky ReLu
            activation functions. Default: 0.2.

        :param use_batch_norm:
            (Optional) A bool: True if you wish to use batch normalization,
            False otherwise. Batch normalization is applied after every layer
            that isn't the input or an output. Default: True.
        """
        super().__init__()

        self._conv = torch.nn.ModuleList()
        self._batch_norm = torch.nn.ModuleList() if use_batch_norm else None
        self._leaky_relu = torch.nn.LeakyReLU(leaky_relu_slope)

        last_out = in_channels

        for i, (chan, kern, stri, padd) in enumerate(zip(channels,
                                                         kernels,
                                                         strides,
                                                         padding)):
            self.conv.append(torch.nn.Conv2d(in_channels=last_out,
                                             out_channels=chan,
                                             kernel_size=kern,
                                             stride=stri,
                                             padding=padd))

            if use_batch_norm and i != 0 and i != (len(channels) - 1):
                self.batch_norm.append(torch.nn.BatchNorm2d(num_features=chan))

            last_out = chan

        self.reset_parameters()

    # region Properties
    @property
    def conv(self) -> List[torch.nn.Conv2d]:
        return self._conv

    @property
    def batch_norm(self) -> List[torch.nn.BatchNorm2d]:
        return self._batch_norm

    @property
    def leaky_relu(self) -> Callable:
        return self._leaky_relu

    # endregion

    def reset_parameters(self):
        """
        Resets this instance's parameters.


        :return:
            Nothing.
        """
        for conv in self.conv[:-1]:
            torch.nn.init.kaiming_normal_(conv.weight,
                                          nonlinearity="leaky_relu")
            torch.nn.init.normal_(conv.bias, 0, 1e-6 / 3)

        torch.nn.init.xavier_normal_(self.conv[-1].weight)
        torch.nn.init.constant_(self.conv[-1].bias, 0.)

    def forward(self, x):
        """
        The forward method of a Discriminator instance.

        :param x:
            A torch.Tensor representing the network input.


        :return:
            A torch.Tensor of shape (B, 1) representing the network's
            confidence that the input is a real image.
        """
        y = self.conv[0](x)
        y = self.leaky_relu(y)

        for i, conv in enumerate(self.conv[1:-1]):
            y = conv(y)
            y = self.leaky_relu(y)

            if self.batch_norm is not None:
                y = self.batch_norm[i](y)

        y = self.conv[-1](y)
        y = y.view(-1)

        return torch.sigmoid(y)


class Generator(torch.nn.Module):
    def __init__(self,
                 input_size: int = 100,
                 channels: List[int] or Tuple[int] = (512, 256, 128, 64, 1),
                 kernels: List[int] or Tuple[int] = (4, 4, 4, 4, 4),
                 strides: List[int] or Tuple[int] = (1, 2, 2, 2, 2),
                 padding: List[int] or Tuple[int] = (0, 1, 1, 1, 1),
                 leaky_relu_slope: float = 0.2,
                 use_batch_norm: bool = True):
        """
        The Generator constructor.

        :param input_size:
            (Optional) An int representing the dimensionality of the samples
            generated. Default: 100.

        :param channels:
            (Optional) A List[int] or Tuple[int] representing the channels of
            every convolutional layer. Default: (512, 256, 128, 64, 1).

        :param kernels:
            (Optional) A List[int] or Tuple[int] representing the kernels of
            every convolutional layer. Default: (4, 4, 4, 4, 4).

        :param strides:
            (Optional) A List[int] or Tuple[int] representing the strides of
            every convolutional layer. Default: (1, 2, 2, 2, 2).

        :param padding:
            (Optional) A List[int] or Tuple[int] representing the padding of
            every convolutional layer. Default: (0, 1, 1, 1, 1).

        :param leaky_relu_slope:
            (Optional) A float representing the slope of the leaky ReLu
            activation functions. Default: 0.2.

        :param use_batch_norm:
            (Optional) A bool: True if you wish to use batch normalization,
            False otherwise. Batch normalization is applied after every layer
            except the output. Default: True.
        """
        super().__init__()

        self._input_size = input_size
        self._conv = torch.nn.ModuleList()
        self._batch_norm = torch.nn.ModuleList() if use_batch_norm else None
        self._leaky_relu = torch.nn.LeakyReLU(leaky_relu_slope)

        last_out = input_size

        for i, (chan, kern, stri, padd) in enumerate(zip(channels,
                                                         kernels,
                                                         strides,
                                                         padding)):
            self.conv.append(torch.nn.ConvTranspose2d(in_channels=last_out,
                                                      out_channels=chan,
                                                      kernel_size=kern,
                                                      stride=stri,
                                                      padding=padd))

            if use_batch_norm and i != (len(channels) - 1):
                self.batch_norm.append(torch.nn.BatchNorm2d(num_features=chan))

            last_out = chan

        self.reset_parameters()

    # region Properties
    @property
    def input_size(self):
        return self._input_size

    @property
    def conv(self) -> List[torch.nn.ConvTranspose2d]:
        return self._conv

    @property
    def batch_norm(self) -> List[torch.nn.BatchNorm2d]:
        return self._batch_norm

    @property
    def leaky_relu(self) -> Callable:
        return self._leaky_relu

    # endregion

    def reset_parameters(self):
        """
        Resets this instance's parameters.


        :return:
            Nothing.
        """
        for conv in self.conv[:-1]:
            torch.nn.init.kaiming_normal_(conv.weight,
                                          nonlinearity="leaky_relu")
            torch.nn.init.normal_(conv.bias, 0, 1e-6 / 3)

        torch.nn.init.xavier_normal_(self.conv[-1].weight)
        torch.nn.init.constant_(self.conv[-1].bias, 0.)

    def forward(self, x):
        """
        The forward method of a Generator instance.

        :param x:
            A torch.Tensor representing the network input.


        :return:
            A torch.Tensor of shape (B, 64, 64) representing the generator's
            output.
        """
        for i in range(len(self.conv) - 1):
            x = self.conv[i](x)
            x = self.leaky_relu(x)

            if self.batch_norm is not None:
                x = self.batch_norm[i](x)

        x = self.conv[-1](x)

        return torch.tanh(x)


class DCGAN(torch.nn.Module):
    def __init__(self,
                 discriminator: Discriminator,
                 generator: Generator):
        """
        The DCGAN constructor.

        :param discriminator:
            A Discriminator object representing the model's discriminator
            module.

        :param generator:
            A Generator object representing the model's generator module.
        """
        super().__init__()

        self._discriminator = deepcopy(discriminator)
        self._generator = deepcopy(generator)

        self._component_names = ("discriminator", "generator")

    # region Properties
    @property
    def discriminator(self) -> Discriminator:
        return self._discriminator

    @property
    def generator(self) -> Generator:
        return self._generator

    @property
    def component_names(self) -> Tuple[str, str]:
        return self._component_names

    # endregion

    def fit(self,
            dataset: torch.utils.data.Dataset,
            n_epochs: int = 1,
            batch_size: int = 1,
            learning_rate: float or Tuple[float, float] or List[float] = 3e-4,
            lr_gamma: float or Tuple[float, float] or List[float] = None,
            loss: Callable = None,
            device: str = "cpu",
            discriminator_batches_till_step: int = 1,
            generator_batches_till_step: int = 1,
            verbose: int = 1):
        """

        :param dataset:
            A torch.utils.data.Dataset representing the dataset your wish to
            fit the model on.

        :param n_epochs:
            (Optional) An int representing the number of epochs you wish to
            train the model for. Default: 1.

        :param batch_size:
            (Optional) An int representing the batch size. Default: 1.

        :param learning_rate:
            (Optional) A float representing the starting learning rate during
            training. Default: 3e-4.

        :param lr_gamma:
            (Optional) A float representing the learning rate decay multiplier
            per fit epoch. Default: None.

        :param loss:
            (Optional) A Callable representing the loss function for the VAE.
            Default: None (takes it from losses.get_gan_loss())

        :param device:
            (Optional) A string representing the device you wish to fit on.
            Default: "cpu".

        :param discriminator_batches_till_step:
            An int representing the number of batches to wait before updating
            the discriminator parameters.

        :param generator_batches_till_step:
            An int representing the number of batches to wait before updating
            the generator parameters.

        :param verbose:
            (Optional) An int representing the level of verbosity you wish to
            have which fitting the model. Default: 1 (progress bar).


        :return:
            Nothing.
        """
        self.train()
        self.to(device)

        if loss is None:
            loss = get_gan_loss()

        if isinstance(learning_rate, int) or isinstance(learning_rate, float):
            learning_rate = tuple([learning_rate] * 2)

        if lr_gamma is None:
            lr_gamma = 1.

        if isinstance(lr_gamma, int) or isinstance(lr_gamma, float):
            lr_gamma = tuple([lr_gamma] * 2)

        loss = {k: loss for k in self.component_names}
        losses = {k: list() for k in self.component_names}

        optimizer = dict()
        scheduler = dict()

        for key, component, lr, gamma in zip(self.component_names,
                                             [self.discriminator,
                                              self.generator],
                                             learning_rate,
                                             lr_gamma):
            optimizer[key] = torch.optim.Adam(component.parameters(),
                                              lr=lr)
            scheduler[key] = torch.optim \
                                  .lr_scheduler \
                                  .ExponentialLR(optimizer[key], gamma=gamma)

        tr_loader = torch.utils.data.DataLoader(dataset,
                                                batch_size=batch_size,
                                                shuffle=True)

        for epoch in range(n_epochs):
            iterator = tqdm(tr_loader, file=stdout)\
                       if verbose > 0\
                       else tr_loader

            for i, (x, _) in enumerate(iterator):
                curr_batch_size = x.shape[0]

                noise = torch.randn((curr_batch_size, self.generator.input_size,
                                    1, 1),
                                    device=device)

                x_real = x.to(device)
                x_fake = self.generator.forward(noise)

                y_real = torch.ones(curr_batch_size, device=device).float()
                y_fake = torch.zeros(curr_batch_size, device=device).float()
                y_dis_real = self.discriminator.forward(x_real)
                y_dis_fake = self.discriminator.forward(x_fake.detach())

                loss_dis = loss[self.component_names[0]](y_dis_real, y_real) +\
                           loss[self.component_names[0]](y_dis_fake, y_fake)
                loss_dis.backward()
                losses[self.component_names[0]].append(float(loss_dis))

                if (i + 1) % discriminator_batches_till_step == 0:
                    optimizer[self.component_names[0]].step()

                # --------------------------------------------------------------

                y_dis_fake = self.discriminator.forward(x_fake)

                loss_gen = loss[self.component_names[1]](y_dis_fake, y_real)
                loss_gen.backward()
                losses[self.component_names[1]].append(float(loss_gen))

                if (i + 1) % generator_batches_till_step == 0:
                    optimizer[self.component_names[1]].step()

                if verbose > 0:
                    iterator.set_description(
                        f"Epoch {epoch + 1}    "
                        f"DisLoss: "
                        f"{np.mean(losses[self.component_names[0]]):.04f}  "
                        f"GenLoss: "
                        f"{np.mean(losses[self.component_names[1]]):.04f}")

                for component_name in self.component_names:
                    optimizer[component_name].zero_grad()

            for component_name in self.component_names:
                scheduler[component_name].step()
                losses[component_name].clear()

    def plot_generations(self,
                         n_samples: int = 4,
                         shape: Tuple[int, int] = None,
                         base_size: Tuple[int, int] = (1.6, 1.6),
                         device: str = "cpu"):
        """
        Plots generated images given a number of samples from the dataset.

        :param n_samples:
            (Optional) An int representing the number of samples you wish to
            plot. Default: 4.

        :param shape:
            (Optional) The shape of the subplots. Default: None (calculates
            the shape dynamically, focusing on a square shape with a width of
            at most 10).

        :param base_size:
            (Optional) A Tuple[float, float] containing the base sizes of a
            subplot. Default: (1.6, 1.6).

        :param device:
            (Optional) A string representing the device you wish to fit on.
            Default: "cpu".


        :return:
            A Tuple[matplotlib.pyplot.Figure, matplotlib.pyplot.Axes]
            containing the plot information.
        """
        self.eval()
        self.to(device)

        if n_samples is None or n_samples < 3:
            n_samples = 4

        if shape is None or shape[0] * shape[1] < n_samples:
            width = min(int((n_samples ** 0.5) + 1e-6), 10)
            height = (n_samples + width - 1) // width

            shape = (height, width)

        fig, ax = plt.subplots(*shape, figsize=(base_size[0] * shape[0],
                                                base_size[1] * shape[1]))

        with torch.no_grad():
            samples = self.generator.forward(
                torch.randn(n_samples, 100, 1, 1, device=device))\
                     .view(n_samples, 64, 64)\
                     .data\
                     .cpu()\
                     .numpy()

            for i in range(n_samples):
                curr_axis = ax[i // shape[0]][i % shape[0]]

                curr_axis.axis("off")
                curr_axis.imshow(samples[i], vmin=0, vmax=1)

        return fig, ax
