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


import csv
from typing import Dict, Iterable, List

import torch
import torch.utils.data

from util.embeddings import tokenize


class Vocabulary:
    def __init__(self,
                 frequencies: Dict[str, int],
                 max_size: int = None,
                 min_freq: int = None,
                 additional_tokens: List[str] = None):
        """
        Vocabulary constructor.

        :param frequencies:
            A Dict[str, int] mapping a word to its frequency in a dataset.

        :param max_size:
            (Optional) An integer representing the maximum size of the
            vocabulary. By default a vocabulary has an unlimited size.

        :param min_freq:
            (Optional) An integer representing the lower bound frequency needed
            by a word to enter the vocabulary. By default there is no lower
            bound.

        :param additional_tokens:
            (Optional) A List[str] representing the list of special tokens to
            prepend to the vocabulary. Useful for special tokens: passing
            ["<PAD>", "<UNK>"] will create a vocabulary that maps at least
            {0: "<PAD>", 1: "<UNK>"}.
        """
        if max_size is None or max_size < 1:
            max_size = -1
        if min_freq is None or min_freq < 1:
            min_freq = 1

        frequencies = {k: v for k, v in frequencies.items() if v >= min_freq}
        sorted_frequencies = sorted([tuple(x) for x in frequencies.items()],
                                    key=lambda x: x[1],
                                    reverse=True)

        if max_size != -1:
            sorted_frequencies = sorted_frequencies[:max_size]

        self._itos = dict()
        self._stoi = dict()

        if additional_tokens is not None:
            for i, additional_token in enumerate(additional_tokens):
                self._itos[i] = additional_token
                self._stoi[additional_token] = i

        for i, (token, _) in enumerate(sorted_frequencies, len(self._itos)):
            self._itos[i] = token
            self._stoi[token] = i

        self._max_size = max_size
        self._min_freq = min_freq

    # region Properties
    @property
    def itos(self) -> Dict[str, int]:
        """
        Index to string property.


        :return:
            A Dict[int, str] representing the index to string dictionary.
        """
        return self._itos

    @property
    def stoi(self) -> Dict[str, int]:
        """
        String to index property.


        :return:
            A Dict[str, int] representing the string to index dictionary.
        """
        return self._stoi

    @property
    def max_size(self) -> int:
        """
        The vocabulary max size property.


        :return:
            An int representing the maximum size of the vocabulary.
        """
        return self._max_size

    @property
    def min_freq(self) -> int:
        """
        The minimum word frequency property.


        :return:
            An int representing the lower bound frequency for a word to be
            added to the vocabulary.
        """
        return self._min_freq

    # endregion

    def encode(self, token: str or Iterable,
               default_string: str = "<UNK>") -> int:
        """
        Converts a token into a vocabulary index (or an iterable into
        a list iterable of vocabulary indices reqursively).

        :param token:
            A string or Iterable representing/containg word tokens.

        :param default_string:
            (Optional) A string representing the word that will be encoded if
            the original word is not found in the vocabulary. Defaults to
            "<UNK">.


        :return:
            An integer or a list iterable of integers representing the
            vocabulary index/indices of the given token argument.
        """
        if isinstance(token, list):
            return [self.encode(x) for x in token]

        return self.stoi.get(token, self.stoi.get(default_string, 0))

    def decode(self, identifier: str or Iterable,
               default_string: str = "<UNK>") -> str:
        """
        Converts an identifier into the original string (or an iterable into
        a list iterable of original strings reqursively).

        :param identifier:
            An integer or Iterable representing/containg vocabulary indices.

        :param default_string:
            (Optional) A string representing the word that will be returned if
            the vocabulary index doesn't exist in the vocabulary. Defaults to
            "<UNK">.


        :return:
            A string or a list iterable of strings representing the original
            word(s) of the given identifier argument.
        """
        if isinstance(identifier, list):
            return [self.decode(x) for x in identifier]

        return self.itos.get(identifier, default_string)


class Dataset(torch.utils.data.Dataset):
    def __init__(self,
                 csv_file_path: str,
                 data_vocab: Vocabulary,
                 label_vocab: Vocabulary):
        """
        Dataset constructor.

        :param csv_file_path:
            A string representing the file path to the csv file where the
            dataset is located.

        :param data_vocab:
            A Vocabulary object for the data.

        :param label_vocab:
            A Vocabulary object for the labels.
        """
        with open(csv_file_path) as file:
            self._instances = [(tokenize(x[0]), x[1].strip())
                               for x in list(csv.reader(file))]

        self._data_vocab = data_vocab
        self._label_vocab = label_vocab

    # region Properties
    @property
    def instances(self) -> List[str]:
        """
        Instances property.


        :return:
            A List[str, str] representing the copy of dataset pairs.
        """
        return list(self._instances)

    @property
    def data_vocab(self) -> Vocabulary:
        """
        Data vocabulary property.


        :return:
            A Vocabulary representing the data vocabulary.
        """
        return self._data_vocab

    @property
    def label_vocab(self) -> Vocabulary:
        """
        Label vocabulary property.


        :return:
            A Vocabulary representing the label vocabulary.
        """
        return self._label_vocab

    @property
    def vocabs(self):
        """
        A vocabulary collection property.


        :return:
            A pair of vocabularies: data, label.
        """
        return self.data_vocab, self.label_vocab

    # endregion

    def __len__(self):
        return len(self._instances)

    def __getitem__(self, idx):
        return [torch.tensor(vocab.encode(element))
                for vocab, element
                in zip(self.vocabs, self.instances[idx])]
