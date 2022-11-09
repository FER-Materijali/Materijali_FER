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

from typing import Callable

import torch


def get_vae_loss() -> Callable:
    """
    Gets the VAE loss method.


    :return:
        A function representing the VAE loss.
    """
    bcewll = torch.nn.BCEWithLogitsLoss(reduction="none")

    def _loss(y_real, y_pred, mu, logvar, kl_beta: int = 1.):
        ce = torch.sum(bcewll(y_pred, y_real), dim=1)
        kl_div = torch.sum(torch.square(mu) + torch.exp(logvar) - logvar - 1,
                           dim=1) / 2

        return torch.mean(ce + kl_div * kl_beta)

    return _loss


def get_gan_loss() -> Callable:
    """
    Gets the GAN loss method.

    :return:
        A function representing the GAN loss.
    """
    bcel = torch.nn.BCELoss()

    def _loss(y_pred, y_real):
        return bcel(y_pred, y_real)

    return _loss
