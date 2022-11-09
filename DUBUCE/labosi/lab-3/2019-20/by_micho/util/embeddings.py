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

from collections import Counter
import csv
import re
from typing import Iterable, List, Tuple

import numpy as np
import torch
from torch.nn.utils.rnn import pad_sequence


whitespace_regex = re.compile(r"\s+")


def get_embedding_matrix(vocabulary,
                         file_path: str = None,
                         vector_length: int = None,
                         separate_unk: bool = True) -> np.ndarray:
    """
    Returns an embedding matrix for a given iterable of words. If no path
    to glove embeddings is provided, or a word in vocabulary is not found
    in the glove embedding dictionary, a word embedding will be generated
    by sampling from N(0, 1).

    :param vocabulary:
        An iterable of strings representing the vocabulary.

    :param file_path:
        (Optional) A string representing the path to a glove embedding file.

    :param vector_length:
        (Optional) An int representing the length of a word embedding. Defaults
        to the length of given glove embeddings, or 300 if nothing is specified.

    :param separate_unk:
        (Optional) A bool: True if you want to assing <UNK> a vector with all
        values set to 1, False if you want it to take a value from the glove
        embeddings or have the default value in case it's missing from it.


    :return:
        A numpy array of dimensions (len(vocabulary), vector_length) mapping
        word indices to embeddings.
    """
    embedding_dict = dict()

    if file_path is not None:
        with open(file_path) as file:
            for line in file.readlines():
                line_tokens = whitespace_regex.split(line)
                word = line_tokens[0]
                vector = np.array([float(x)
                                   for x in line_tokens[1:]
                                   if x is not None and len(x) > 0])

                embedding_dict[word] = vector

    if len(embedding_dict) == 0:
        if vector_length is None or vector_length < 1:
            vector_length = 300
    else:
        vector_length = len(list(embedding_dict.values())[0])

    words = [x[0] for x in sorted(vocabulary.stoi.items(), key=lambda x: x[1])]
    embedding_matrix = np.random.normal(loc=0,
                                        scale=1,
                                        size=(len(words), vector_length))

    for i, word in enumerate(words):
        if word == "<PAD>":
            embedding_matrix[i] = np.zeros(vector_length)
        elif separate_unk and word == "<UNK>":
            embedding_matrix[i] = np.array([1.] * vector_length)
        elif word in embedding_dict:
            embedding_matrix[i] = embedding_dict[word]

    return embedding_matrix.astype(np.float32)


def get_frequencies(dataset: Iterable[Tuple[str, str]] or str) -> Counter:
    """
    Counts the frequency of words in a dataset.

    :param dataset:
        A Iterable of pairs of values (sentence, label) or a string
        representing the path to the csv file containing the dataset. The
        sentences must be seperated by at least 1 whitespace character.


    :return:
        A Counter with word counts.
    """
    if isinstance(dataset, str):
        with open(dataset) as file:
            dataset = tuple(csv.reader(file))

    word_frequencies = Counter()

    for sentence, label in dataset:
        for word in whitespace_regex.split(sentence):
            if word is not None and len(word) != 0:
                word_frequencies[word] += 1

    return word_frequencies


def embedding_matrix_to_torch(embedding_matrix: np.ndarray,
                              freeze: bool = True,
                              padding_idx: int = 0) -> torch.nn.Embedding:
    """
    Converts a non-torch embedding matrix to a Torch Embedding instance.

    :param embedding_matrix:
        A 2D numpy.ndarray object (but can be anything Torch can convert into a
        Tensor object) containing word embeddings.

    :param freeze:
        (Optional) A bool: True if you don't want the Tensor to be updated in
        the learning process, False otherwise. Defaults to True.

    :param padding_idx:
        (Optional) The index of the padding symbol embedding.


    :return:
        A Torch Embedding created from the numpy embedding matrix.
    """
    return torch.nn.Embedding.from_pretrained(torch.tensor(embedding_matrix),
                                              freeze=freeze,
                                              padding_idx=padding_idx)


def pad_collate(batch: List, padding_value: int = 0):
    """
    A PyTorch collate function that pads the data.

    :param batch:
        A List of PyTorch dataset entries.

    :param padding_value:
        (Optional) An int representing the index with which the data will be
        padded. Defaults to 0.


    :return:
        A triple: padded data, labels, original sequence lengths.
    """
    data, labels = zip(*batch)

    return (pad_sequence(data, batch_first=True, padding_value=padding_value),
            torch.tensor(labels),
            torch.tensor([len(element) for element in data]))


def tokenize(sentence: str) -> Tuple[str]:
    """
    Tokenize a sentence delimited with whitespace into a Tuple of strings
    representing words.

    :param sentence:
        A string representing the sentence.


    :return:
        A Tuple of strings; the sentence delimited by whitespace.
    """
    return [x for x in whitespace_regex.split(sentence)
            if (x is not None and len(x) != 0)]