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
from typing import Callable, Dict, List, Tuple

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import torch
import torch.utils.data
from tqdm import tqdm

import seaborn as sns

from util.losses import get_vae_loss


class VAE(torch.nn.Module):
    def __init__(self,
                 encoder_units: List[int] or Tuple[int] = (200, 200),
                 bottleneck_size: int = 20,
                 decoder_units: List[int] or Tuple[int] = (200, 200),
                 data_units: int = 784,
                 loss: Callable = None):
        """
        A VAE constructor.

        :param encoder_units:
            (Optional) A List[int] or Tuple[int] containing the units of the
            encoder. Default: (200, 200).

        :param bottleneck_size:
            (Optional) A int representing the dimensionality of the latent
            variable. Default: 20.

        :param decoder_units:
            (Optional) A List[int] or Tuple[int] containing the units of the
            decoder. Default: (200, 200).

        :param data_units:
            (Optional) A int representing the dimensionality of the input and
            output. Default: 784.

        :param loss:
            (Optional) A Callable representing the loss function for the VAE.
            Default: None (takes it from losses.get_vae_loss())
        """
        super(VAE, self).__init__()

        self._bottleneck_size = bottleneck_size
        self._data_units = data_units
        self._loss = get_vae_loss() if loss is None else loss

        self._encoder = torch.nn.ModuleList()
        self._bottleneck = torch.nn.ModuleDict()
        self._decoder = torch.nn.ModuleList()

        encoder_units = (self.data_units, *encoder_units)
        decoder_units = (bottleneck_size, *decoder_units)

        for i in range(1, len(encoder_units)):
            self.encoder.append(torch.nn.Linear(encoder_units[i - 1],
                                                encoder_units[i]))

        for key in ["mu", "logvar"]:
            self.bottleneck[key] = torch.nn.Linear(encoder_units[-1],
                                                   bottleneck_size)

        for i in range(1, len(decoder_units)):
            self.decoder.append(torch.nn.Linear(decoder_units[i - 1],
                                                decoder_units[i]))

        self._reconstructor = torch.nn.Linear(decoder_units[-1],
                                              self.data_units)

        self._softplus = torch.nn.Softplus()

        self.reset_parameters()

    # region Properties
    @property
    def bottleneck_size(self) -> int:
        return self._bottleneck_size

    @property
    def data_units(self) -> int:
        return self._data_units

    @property
    def encoder(self) -> List[torch.nn.Linear]:
        return self._encoder

    @property
    def bottleneck(self) -> Dict[str, torch.nn.Linear]:
        return self._bottleneck

    @property
    def decoder(self) -> List[torch.nn.Linear]:
        return self._decoder

    @property
    def reconstructor(self) -> torch.nn.Linear:
        return self._reconstructor

    @property
    def softplus(self) -> torch.nn.Softplus:
        return self._softplus

    # endregion

    def reset_parameters(self):
        """
        Resets this instance's parameters.


        :return:
            Nothing.
        """
        for fc in self.encoder:
            torch.nn.init.kaiming_normal_(fc.weight, nonlinearity="relu")
            torch.nn.init.normal_(fc.bias, 0., 1e-6 / 3)

        for fc in self.bottleneck.values():
            torch.nn.init.xavier_normal_(fc.weight)
            torch.nn.init.normal_(fc.bias, 0., 1e-6 / 3)

        for fc in self.decoder:
            torch.nn.init.kaiming_normal_(fc.weight, nonlinearity="relu")
            torch.nn.init.normal_(fc.bias, 0., 1e-6 / 3)

        torch.nn.init.xavier_normal_(self.reconstructor.weight)
        torch.nn.init.constant_(self.reconstructor.bias, 0.)

    @staticmethod
    def get_z(mu: torch.Tensor,
              logvar: torch.Tensor,
              noise: torch.Tensor = None) -> torch.Tensor:
        """
        Gets the z for a set of means, variance logarithms and noise.

        :param mu:
            A torch.Tensor representing the mean of the latent variable.

        :param logvar:
            A torch.Tensor representing the variance logarithm of the latent
            variable.

        :param noise:
            (Optional) A torch.Tensor representing. Default: None.


        :return:
            A torch.Tensor representing a sample from the latent variable.
        """
        if noise is None:
            noise = 1.

        return mu + torch.sqrt(torch.exp(logvar)) * noise

    def decode(self, x: torch.Tensor) -> torch.Tensor:
        """
        Decodes the latent variable output.

        :param x:
            A torch.Tensor representing the decoder input.


        :return:
            A torch.Tensor representing the output for a given latent variable
            sample.
        """
        for fc in self.decoder:
            x = fc(x)
            x = self.softplus(x)

        return self.reconstructor(x)

    def forward(self, x: torch.Tensor)\
            -> Tuple[torch.Tensor, torch.Tensor, torch.Tensor]:
        """
        The forward method of a VAE instance.

        :param x:
            A torch.Tensor representing the network input.


        :return:
            A triple of torch.Tensor objects representing the reconstructed
            input, the mean of the latent variable and the variance logarithm
            of the latent variable.
        """
        # Flatten
        y = x.view(-1, self.data_units)

        # Encode
        for fc in self.encoder:
            y = fc(y)
            y = self.softplus(y)

        # Reparametrize
        mu = self.bottleneck["mu"](y)
        logvar = self.bottleneck["logvar"](y)
        noise = torch.normal(0., 1., size=logvar.shape, device=logvar.device)

        y = self.get_z(mu, logvar, noise)

        # Decode
        y = self.decode(y)

        return y, mu, logvar

    def fit(self,
            dataset: torch.utils.data.Dataset,
            n_epochs: int = 1,
            batch_size: int = 1,
            learning_rate: float = 3e-4,
            lr_gamma: float = None,
            loss: Callable = None,
            kl_beta_sine_multiplier: float = None,
            device: str = "cpu",
            verbose: int = 1):
        """
        A fit method of a VAE instance.

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
            Default: None (takes it from losses.get_vae_loss())

        :param kl_beta_sine_multiplier:
            (Optional) A float representing the frequency multiplier of a sine
            function regulating the magnitude of the KL divergence used in
            loss. Default: None (the multiplier is a constant 1).

        :param device:
            (Optional) A string representing the device you wish to fit on.
            Default: "cpu".

        :param verbose:
            (Optional) An int representing the level of verbosity you wish to
            have which fitting the model. Default: 1 (progress bar).


        :return:
            Nothing.
        """
        self.train()
        self.to(device)

        if loss is None:
            loss = get_vae_loss()

        tr_loss = list()
        optimizer = torch.optim.Adam(self.parameters(), lr=learning_rate)

        if lr_gamma is None:
            lr_gamma = 1.

        scheduler = torch.optim.lr_scheduler.ExponentialLR(optimizer,
                                                           gamma=lr_gamma)

        tr_loader = torch.utils.data.DataLoader(dataset,
                                                batch_size=batch_size,
                                                shuffle=True)

        for epoch in range(n_epochs):
            iterator = tqdm(tr_loader, file=stdout) \
                       if verbose > 0 \
                       else tr_loader
            kl_beta = 1. \
                      if kl_beta_sine_multiplier is None \
                      else abs(np.sin(epoch * kl_beta_sine_multiplier))

            for i, (x, _) in enumerate(iterator):
                x = x.to(device)

                optimizer.zero_grad()

                y, mu, logvar = self.forward(x)
                loss = loss(y_real=x.view(y.shape), y_pred=y,
                            mu=mu, logvar=logvar, kl_beta=kl_beta)
                tr_loss.append(float(loss))

                if verbose > 0:
                    iterator.set_description(f"Epoch {epoch + 1}   "
                                             f"Loss: {np.mean(tr_loss):.04f}")

                loss.backward()
                optimizer.step()

            scheduler.step()

            tr_loss.clear()

    def generate_mu_and_stddev_dataframes(self,
                                          dataset: torch.utils.data.Dataset,
                                          device: str = "cpu",
                                          verbose: int = 1)\
            -> Tuple[pd.DataFrame, pd.DataFrame]:
        """
        Generates the pandas.DataFrame objects for the mean and standard
        deviations of the latent variables.

        :param dataset:
            A torch.utils.data.Dataset representing the dataset on which you
            wish to create the dataframes on.

        :param device:
            (Optional) A string representing the device you wish to fit on.
            Default: "cpu".

        :param verbose:
            (Optional) An int representing the level of verbosity you wish to
            have which fitting the model. Default: 1 (progress bar).


        :return:
            A Tuple[pandas.DataFrame, pandas.DataFrame] representing the mean
            and standard deviation dataframes creates from the given dataset.
        """
        self.to(device)
        self.eval()

        loader = torch.utils.data.DataLoader(dataset)

        mus = list()
        logvars = list()
        labels = list()

        with torch.no_grad():
            iterator = tqdm(loader, file=stdout) if verbose > 0 else loader

            for x, y in iterator:
                _, mu, logvar = self.forward(x.view(-1, self.data_units)
                                              .to(device))

                mus.extend(mu.data.cpu().numpy())
                logvars.extend(logvar.data.cpu().numpy())
                labels.extend(y.data.cpu().numpy())

            mus = np.array(mus)
            logvars = np.array(logvars)

            to_return = list()

            for c_list, c_name in zip((mus, logvars), ("μ", "σ")):
                t_dict = {"label": labels}

                for i in range(c_list.shape[1]):
                    t_dict[f"{c_name} {i:02d}"] = c_list[..., i]

                to_return.append(pd.DataFrame(t_dict))
                to_return[-1]["label"] = \
                    to_return[-1]["label"].astype("category")

            return to_return

    def plot_io(self,
                dataset: torch.utils.data.Dataset,
                n_samples: int,
                device: str = "cpu") -> Tuple[plt.Figure, plt.Axes]:
        """
        Plots the input and output of the model for a number of samples.

        :param dataset:
            A torch.utils.data.Dataset representing the dataset you wish to
            take the samples from.

        :param n_samples:
            An int representing the number of samples you wish to plot.

        :param device:
            (Optional) A string representing the device you wish to fit on.
            Default: "cpu".


        :return:
            A Tuple[matplotlib.pyplot.Figure, matplotlib.pyplot.Axes]
            containing the plot information.
        """
        self.to(device)
        self.eval()

        n_samples = min(n_samples, len(dataset))

        loader = torch.utils.data.DataLoader(dataset, batch_size=n_samples)
        batch, _ = next(iter(loader))

        fig, ax = plt.subplots(n_samples, 2,
                               figsize=(4, n_samples * 2))

        with torch.no_grad():
            output, mu, logvar = self.forward(batch.to(device))

            for i in range(n_samples):
                x = batch[i, ...].view(28, 28).data.cpu()
                y = torch.sigmoid(output)[i, ...].view(28, 28).cpu()

                for j, plot_subject in enumerate((x, y)):
                    ax[i][j].axis("off")
                    ax[i][j].imshow(plot_subject)

        fig.tight_layout()

        return fig, ax

    @staticmethod
    def plot_distribution(mu_dataframe: pd.DataFrame,
                          stddev_dataframe: pd.DataFrame)\
            -> Tuple[plt.Figure, plt.Axes]:
        """
        Plots the distribution in 3 axes - 2 box plots: one for the latent
        variable means, other for the latent variable standard deviations, as
        well as plotting the scatter of the mean values from the 0th dimension
        against the 1st.

        :param mu_dataframe:
            A pandas.DataFrame object representing the latent variable means.

        :param stddev_dataframe:
            A pandas.DataFrame object representing the latent variable standard
            deviations.


        :return:
            A Tuple[matplotlib.pyplot.Figure, matplotlib.pyplot.Axes]
            containing the plot information.
        """
        fig, ax = plt.subplots(3, 1, figsize=(16, 30))

        sns.scatterplot(x="μ 00", y="μ 01", hue="label", s=50,
                        data=mu_dataframe, ax=ax[-1])

        mu_dataframe = mu_dataframe.melt(["label"])
        stddev_dataframe = stddev_dataframe.melt(["label"])

        for i, (df, name) in enumerate(zip((mu_dataframe, stddev_dataframe),
                                           ("μ", "σ"))):
            df.boxplot(ax=ax[i], column="value", by="variable")

            ax[i].title.set_text(f"Distribucija {name}")
            ax[i].set_xlabel("Varijabla")
            ax[i].set_ylabel("Vrijednost")

        return fig, ax

    def plot_latent_space(self,
                          n_samples: int = 20,
                          latent_space_limit: float = 3,
                          device: str = "cpu") -> Tuple[plt.Figure, plt.Axes]:
        """
        Plots the latent space of the model.

        :param n_samples:
            (Optional) An int representing the number of samples you wish to
            plot. Default: 20.

        :param latent_space_limit:
            (Optional) A float representing the absolute bounds for the
            samples of the latent variable space you wish to plot. Default: 3.

        :param device:
            (Optional) A string representing the device you wish to fit on.
            Default: "cpu".


        :return:
            A Tuple[matplotlib.pyplot.Figure, matplotlib.pyplot.Axes]
            containing the plot information.
        """
        canvas = np.zeros((n_samples * 28, n_samples * 28))

        d1 = np.linspace(-latent_space_limit, latent_space_limit,
                         num=n_samples)
        d2 = np.linspace(-latent_space_limit, latent_space_limit,
                         num=n_samples)

        _d1, _d2 = np.meshgrid(d1, d2)
        synth_reps = np.array([_d1.flatten(), _d2.flatten()]).T
        synth_reps_pt = torch.from_numpy(synth_reps).float().to(device)

        recons = self.decode(synth_reps_pt)

        for idx in range(0, n_samples * n_samples):
            x, y = np.unravel_index(idx, (n_samples, n_samples))

            sample_offset = n_samples - x - 1

            first_from = 28 * sample_offset
            first_to = 28 * (sample_offset + 1)

            second_from = 28 * y
            second_to = 28 * (y + 1)

            canvas[first_from: first_to, second_from:second_to] = \
                recons[idx, ...].view(28, 28).data.cpu().numpy()

        fig, ax = plt.subplots(1, 1, figsize=(16, 16))
        ax.imshow(canvas)

        return fig, ax

    def plot_generations(self,
                         dataset: torch.utils.data.Dataset,
                         n_samples: int = 4,
                         shape: Tuple[int, int] = None,
                         base_size: Tuple[int, int] = (1.6, 1.6),
                         device: str = "cpu") -> Tuple[plt.Figure, plt.Axes]:
        """
        Plots generated images given a number of samples from the dataset.

        :param dataset:
            A torch.utils.data.Dataset representing the dataset you wish to
            take the samples from.

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

        loader = torch.utils.data.DataLoader(dataset, batch_size=n_samples)
        batch, _ = next(iter(loader))

        fig, ax = plt.subplots(*shape, figsize=(base_size[0] * shape[0],
                                                base_size[1] * shape[1]))

        with torch.no_grad():
            output, _, _ = self.forward(batch.to(device))

            for i in range(n_samples):
                curr_axis = ax[i // shape[0]][i % shape[0]]
                y = torch.sigmoid(output)[i, ...].view(28, 28).cpu()

                curr_axis.axis("off")
                curr_axis.imshow(y, vmin=0, vmax=1)

        fig.tight_layout()

        return fig, ax
