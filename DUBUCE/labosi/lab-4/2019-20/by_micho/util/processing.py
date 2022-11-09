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

from typing import List, Tuple

import torch.utils.data
import torchvision


def get_dataset(root_path: str, is_train: bool = True)\
        -> torch.utils.data.Dataset:
    """
    Gets the MNIST dataset cast to Torch tensors.

    :param root_path:
        A string representing the path where the dataset will be saved.

    :param is_train:
        (Optional) A bool: True if you want the training dataset, False if you
        want the validation dataset. Default: True.


    :return:
        A torch.utils.data.Dataset object containing the MNIST dataset.
    """
    return torchvision.datasets.MNIST(root=root_path,
                                      train=is_train,
                                      download=True,
                                      transform=torchvision.transforms.Compose([
                                          torchvision.transforms.ToTensor()
                                      ]))


def get_datasets(root_path: str) -> List[torch.utils.data.Dataset]:
    """
    Gets the training and validation MNIST datasets.

    :param root_path:
        A string representing the path where the datasets will be saved.


    :return:
        A pair of torch.utils.data.Dataset objects containing the training
         and validation MNIST datasets.
    """
    return [get_dataset(root_path=root_path, is_train=x)
            for x in (True, False)]


def get_gan_dataset(root_path: str,
                    scale: Tuple[int, int] = (64, 64),
                    is_train: bool = True)\
        -> torch.utils.data.Dataset:
    """
    Gets the MNIST dataset cast to Torch tensors and resized to scale.

    :param root_path:
        A string representing the path where the dataset will be saved.

    :param scale:
        (Optional) A Tuple[int, int] containing the size you want to resize the
        images to. Default: (64, 64).

    :param is_train:
        (Official) A bool: True if you want the training dataset, False if you
        want the validation dataset. Default: True.


    :return:
        A torch.utils.data.Dataset object containing the MNIST dataset.
    """
    return torchvision.datasets.MNIST(root=root_path,
                                      train=is_train,
                                      download=True,
                                      transform=torchvision.transforms.Compose([
                                          torchvision.transforms.Resize(scale),
                                          torchvision.transforms.ToTensor(),
                                      ]))


def get_gan_datasets(root_path: str, scale: Tuple[int, int] = (64, 64))\
        -> List[torch.utils.data.Dataset]:
    """
    Gets the training and validation MNIST datasets resized to scale.

    :param root_path:
        A string representing the path where the datasets will be saved.

    :param scale:
        (Optional) A Tuple[int, int] containing the size you want to resize the
        images to. Default: (64, 64).


    :return:
        A pair of torch.utils.data.Dataset objects containing the training
         and validation MNIST datasets.
    """
    return [get_gan_dataset(root_path=root_path, scale=scale, is_train=x)
            for x in (True, False)]
