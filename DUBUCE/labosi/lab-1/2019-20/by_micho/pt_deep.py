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


from typing import Callable, List

import numpy as np
from sklearn.metrics import confusion_matrix
import torch
from torch import nn


class Deep(nn.Module):
    def __init__(self, configuration_list: List[int], activation=None, is_cuda: bool = False):
        super().__init__()

        if activation is None:
            activation = lambda x: x

        _weights_list = []
        _bias_list = []

        for i in range(len(configuration_list) - 1):
            weights_prototype = torch.tensor(np.zeros((configuration_list[i], configuration_list[i + 1])),
                                             dtype=torch.float,
                                             device="cuda" if is_cuda else None)

            _weights_list.append(nn.Parameter(nn.init.xavier_normal_(weights_prototype), requires_grad=True))
            _bias_list.append(nn.Parameter(torch.zeros(configuration_list[i + 1],
                                                       device="cuda" if is_cuda else None), requires_grad=True))

        self._weights = nn.ParameterList(_weights_list)
        self._biases = nn.ParameterList(_bias_list)
        self._activation = activation

    @property
    def weights(self) -> nn.ParameterList:
        return self._weights

    @weights.setter
    def weights(self, value):
        self._weights = value

    @property
    def biases(self) -> nn.ParameterList:
        return self._biases

    @biases.setter
    def biases(self, value):
        self._biases = value

    @property
    def activation(self) -> Callable:
        return self._activation

    def forward(self, inputs) -> torch.Tensor:
        for weights, bias in zip(self.weights, self.biases):
            inputs = inputs.mm(weights) + bias
            inputs = self.activation(inputs)

        _probs = torch.softmax(inputs, dim=1)

        return _probs

    def get_loss(self, inputs, y_true) -> torch.Tensor:
        # Shape: (inputs.length, output_units)
        _outputs = self.forward(inputs)

        # Add 1e-13 to prevent NaN
        _logmul_outputs = torch.log(_outputs + 1e-13) * y_true
        _logsum = torch.sum(_logmul_outputs, dim=1)
        _logsum_mean = torch.mean(_logsum)

        # Convert to positive number
        return -_logsum_mean

    def count_params(self):
        name_and_dim_tuples = list()

        for parameter in self.named_parameters():
            name_and_dim_tuples.append((parameter[0], tuple(parameter[1].shape)))

        total_parameters = np.sum(p.numel() for p in self.parameters())

        return {"layers": name_and_dim_tuples, "element_count": total_parameters}


def train(model: nn.Module, x, y, n_epochs: int, learning_rate: float, verbose: int = 0):
    optimizer = torch.optim.SGD(params=model.parameters(), lr=learning_rate, momentum=0.99)

    for epoch in range(1, n_epochs + 1):
        loss = model.get_loss(x, y)
        loss.backward()
        optimizer.step()

        if verbose > 0:
            print(f"Epoha {epoch}:\tgubitak = {loss:.06f}")

        optimizer.zero_grad()


def eval(model, inputs):
    return model.forward(inputs).detach().cpu().numpy()


def eval_metrics(model, inputs, y_real, prefix: str or None = None):
    if prefix is None:
        prefix = ""

    y_pred = eval(model, inputs).argmax(axis=1)
    y_real = y_real.detach().cpu().numpy()

    cm = confusion_matrix(y_real, y_pred)
    cm_diag = np.diag(cm)

    sums = [np.sum(cm, axis=y) for y in [None, 0, 1]]

    sums[0] = np.maximum(1, sums[0])
    for i in range(1, len(sums)):
        sums[i][sums[i] == 0] = 1

    accuracy = np.sum(cm_diag) / sums[0]
    precision, recall = [np.mean(cm_diag / x) for x in sums[1:]]
    f1 = (2 * precision * recall) / (precision + recall)

    return {f"{prefix}acc": accuracy, f"{prefix}pr": precision, f"{prefix}re": recall, f"{prefix}f1": f1}
