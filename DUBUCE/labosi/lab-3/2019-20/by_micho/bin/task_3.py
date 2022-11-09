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

import json
import os
from sys import stdout
from typing import Any, Callable, Dict, List, Tuple

import numpy as np
import torch
import torch.utils.data
from tqdm import tqdm

from util.embeddings import embedding_matrix_to_torch, pad_collate
from util.metrics import evaluate, convert_timeline_to_diary
from util.paths import DEFAULT_SAVE_TASK3


class LSTM(torch.nn.Module):
    def __init__(self,
                 embedding_matrix: str or np.ndarray,
                 rnn_units: List[int] = (150, 150),
                 fc_units: List[int] or Tuple[int] = (150, 1),
                 loss: Callable = torch.nn.BCEWithLogitsLoss(),
                 freeze_embedding: bool = True):
        """
        LSTM constructor.

        :param embedding_matrix:
            A string representing the path to the numpy-serialized embedding
            matrix, or a np.ndarray object containing the embedding matrix.

        :param rnn_units:
            (Optional) A List or Tuple of ints representing the neurons of the
            LSTM layers. Defaults to (150, 150).
        :param fc_units:
            (Optional) A List or Tuple of ints representing the neurons of the
            dense layers. Defaults to (150, 1).

        :param loss:
            (Optional) A Callable representing the loss function. Defaults to
            torch.nn.BCEWithLogitsLoss().

        :param freeze_embedding:
            (Optional) A bool: True if you don't want to train embeddings,
            False otherwise. Defaults to True.
        """
        super().__init__()

        if isinstance(embedding_matrix, str):
            embedding_matrix = np.load(embedding_matrix).astype(np.float32)

        self._embedding = embedding_matrix_to_torch(embedding_matrix,
                                                    freeze=freeze_embedding)
        self._rnn = list()
        self._fc = list()
        self._loss = loss

        rnn_units = (300, *rnn_units)
        fc_units = (rnn_units[-1], *fc_units)

        for i in range(1, len(rnn_units)):
            self._rnn.append(torch.nn.LSTM(rnn_units[i - 1], rnn_units[i],
                                           num_layers=2, batch_first=False))

        for i in range(1, len(fc_units)):
            self._fc.append(torch.nn.Linear(fc_units[i - 1], fc_units[i]))

        self.reset_parameters()

    # region Properties
    @property
    def embedding(self) -> torch.nn.Embedding:
        """
        Embedding property.


        :return:
            A torch.nn.Embedding object representing this model's embedding.
        """
        return self._embedding

    @property
    def fc(self) -> List[torch.nn.Linear]:
        """
        Fully connected layers list property.


        :return:
            A List[torch.nn.Linear] object representing the fully connected
            layers of this model.
        """
        return self._fc

    @property
    def rnn(self) -> List[torch.nn.LSTM]:
        """
        Recurrent layers list property.


        :return:
            A List[torch.nn.LSTM] object representing the recurrent layers of
            this model.
        """
        return self._rnn

    @property
    def loss(self) -> Callable:
        """
        Loss property.


        :return:
            A Callable representing this model's loss function.
        """
        return self._loss

    # endregion

    def reset_parameters(self):
        """
        Resets this model's parameters.

        Does:
            Xavier normal on recurrent layers' weights
            N(0, 1e-6 / 3) on recurrent layers' biases
            Kaiming normal on fully connected layers' weights
            N(0, 1e-6 / 3) on fully connected layers' biases
            Xavier normal on the last fully connected layers' weights
            Constant(0) on the last fully connected layers' biases


        :return:
            Nothing.
        """
        for rnn in self.rnn:
            weights = [x[1] for x in rnn.named_parameters()
                       if x[0].startswith("weight")]
            biases = [x[1] for x in rnn.named_parameters()
                      if x[0].startswith("bias")]

            for weight, bias in zip(weights, biases):
                torch.nn.init.xavier_normal_(weight)
                torch.nn.init.normal_(bias, 0., 1e-6 / 3)

        for fc in self.fc[:-1]:
            torch.nn.init.kaiming_normal_(fc.weight, nonlinearity="relu")
            torch.nn.init.normal_(fc.bias, 0., 1e-6 / 3)

        torch.nn.init.xavier_normal_(self.fc[-1].weight)
        torch.nn.init.constant_(self.fc[-1].bias, 0.)

    def get_trainable_parameters(self) -> List[torch.Tensor]:
        """
        Gets this model's trainable parameters.


        :return:
            A List[torch.Tensor] representing all tensors which can be
            trained.
        """
        parameters = list()

        for rnn in self.rnn:
            parameters.extend(rnn.parameters())

        for fc in self.fc:
            parameters.extend(fc.parameters())

        parameters.extend(self.embedding.parameters())

        return parameters

    def forward(self, x) -> torch.Tensor:
        """
        Forward pass - BxSx300 in, Bx1 out.

        :param x:
            The input to the model.


        :return:
            A torch.Tensor object representing the output of the model.
        """
        assert len(x.shape) == 2, "Make sure you're passing batched data!"

        # Input shape is (batch_size, sequence_length)
        y = self.embedding(x)

        # Now it's (batch_size, sequence_length, embedding_length)

        y = torch.transpose(y, 0, 1)

        # The shape is finally (sequence_length, batch_size, embedding_length)

        hidden = None

        for rnn in self.rnn:
            y, hidden = rnn(y, hidden)

        # Take the last RNN output
        # NOTE: You shouldn't use the last RNN output, you should either pack
        # the sequence or you should take the y[length]
        y = y[-1]

        for fc in self.fc[:-1]:
            y = fc(y)
            y = torch.relu(y)

        return self.fc[-1](y)

    def infer(self, x) -> int:
        """
        Model's inference method. Doesn't affect gradients.

        :param x:
            The input to the model.


        :return:
            A int representing the classification answer.
        """
        with torch.no_grad():
            y = torch.sigmoid(self.forward(x))
            y = y.round().int().squeeze(-1)

        return int(y)

    def fit(self,
            dataset: torch.utils.data.Dataset,
            validation_dataset: torch.utils.data.Dataset or None = None,
            n_epochs: int = 1,
            learning_rate: float = 3e-4,
            batch_size: int = 1,
            gradient_clipping: float = None,
            save_folder: str = DEFAULT_SAVE_TASK3,
            verbose: int = 1):
        """
        This model's fit method. Used to train the model.

        :param dataset:
            A torch.utils.data.Dataset object representing the training dataset.

        :param validation_dataset:
            (Optional) A torch.utils.data.Dataset object representing the
            training dataset. Defaults to None, skipping validation.

        :param n_epochs:
            (Optional) An int representing the number of epochs you wish to
            train the model for. Defaults to 1.

        :param learning_rate:
            (Optional) A float representing the starting learning rate of the
            model. Defaults to 3e-4.

        :param batch_size:
            (Optional) An int representing the batch size. Defaults to 1.

        :param gradient_clipping
            (Optional) A float representing the gradient clipping value.
            Defaults to None (same as 0).

        :param save_folder:
            (Optional) A str representing the folder path where results should
            be saved. Defaults to DEFAULT_SAVE_TASK3.

        :param verbose:
            (Optional) An int representing the level of verbosity during
            training. Defaults to 1 (just above no input).


        :return:
            Nothing.
        """
        self.train()

        val_metrics = list()
        losses = list()

        trainable_params = self.get_trainable_parameters()
        optimizer = torch.optim.Adam(trainable_params, lr=learning_rate)

        # Train
        for i_epoch in range(n_epochs):
            loss_memory = list()
            dataloader = torch.utils.data.DataLoader(dataset=dataset,
                                                     batch_size=batch_size,
                                                     shuffle=True,
                                                     collate_fn=pad_collate)

            if verbose > 0:
                dataloader = tqdm(dataloader,
                                  total=len(dataloader),
                                  file=stdout)

            self.train()

            for i, batch in enumerate(dataloader):
                loss = self.loss(self.forward(batch[0]).squeeze(-1),
                                 batch[1].float())
                loss.backward()

                if gradient_clipping is not None:
                    torch.nn.utils.clip_grad_norm_(trainable_params,
                                                   gradient_clipping)

                loss_memory.append(float(loss))

                optimizer.step()

                if verbose > 0:
                    dataloader.set_description(
                        f"Loss: {np.mean(loss_memory):.04f}")

                optimizer.zero_grad()

            with torch.no_grad():
                losses.append(np.mean(loss_memory))

                val_dict = self.evaluate(validation_dataset)

                val_loss = val_dict["loss"]

                print(f"[Validation]\t"
                      f"Val Loss: {val_loss:.04f}\t\t"
                      f"Accuracy: {val_dict['acc'] * 100:.02f}%\t\t"
                      f"F1 Score: {val_dict['f1'] * 100:.02f}%\n")

                val_metrics.append(val_dict)

        # Process results
        train_metrics = convert_timeline_to_diary([self.evaluate(dataset)])
        val_metrics = convert_timeline_to_diary(val_metrics)

        # Create folder structure
        os.makedirs(save_folder, exist_ok=True)
        tr_res_path = os.path.join(save_folder, "results_tr.json")
        val_res_path = os.path.join(save_folder, "results_val.json")

        # Save results
        with open(tr_res_path, mode="w+") as file:
            json.dump(train_metrics, file,
                      sort_keys=False, ensure_ascii=False, indent=2)

        with open(val_res_path, mode="w+") as file:
            json.dump(val_metrics, file,
                      sort_keys=False, ensure_ascii=False, indent=2)

    def evaluate(self,
                 dataset: torch.utils.data.Dataset) -> Dict[str, Any]:
        """
        This model's evaluation function.

        :param dataset:
            A torch.utils.data.Dataset object representing the dataset you wish
            to evaluate this model's performance on.


        :return:
            A Dict[str, Any] object mapping metric keys with values measured
            by evaluating the model.
        """
        dl = list(torch.utils.data.DataLoader(dataset=dataset,
                                              batch_size=1,
                                              shuffle=False,
                                              collate_fn=pad_collate))
        x, y = zip(*[(entry[0], entry[1].view(entry[0].shape[0], -1))
                     for entry in dl])

        return evaluate(self, x, y, loss=self.loss)
