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


import numpy as np
import torch
from torch import nn


class LogisticRegression(nn.Module):
    def __init__(self, input_units: int, output_units: int):
        super().__init__()

        self._weights = nn.Parameter(torch.randn((input_units, output_units)), requires_grad=True)
        self._bias = nn.Parameter(torch.zeros(output_units), requires_grad=True)

    @property
    def weights(self) -> nn.Parameter:
        return self._weights

    @property
    def bias(self) -> nn.Parameter:
        return self._bias

    def forward(self, inputs) -> torch.Tensor:
        _logits = inputs.mm(self.weights) + self.bias
        _probs = torch.softmax(_logits, dim=1)

        return _probs

    def get_loss(self, inputs, y_true):
        # Shape: (inputs.length, output_units)
        _outputs = self.forward(inputs)

        # Add 1e-13 to prevent NaN
        _logmul_outputs = torch.log(_outputs + 1e-13) * y_true
        _logsum = torch.sum(_logmul_outputs, dim=1)
        _logsum_mean = torch.mean(_logsum)

        # Convert to positive number
        return -_logsum_mean


def train(model: nn.Module, x, y, n_epochs, learning_rate, verbose: int = 0, regularize: float or None = None):
    optimizer = torch.optim.SGD(params=model.parameters(), lr=learning_rate)
    regularize = 0. if regularize is None else regularize

    for epoch in range(1, n_epochs + 1):
        loss = model.get_loss(x, y) + (regularize * torch.norm(model.weights))
        loss.backward()
        optimizer.step()

        if verbose > 0:
            print(f"Epoha {epoch}:\tgubitak = {loss:.06f}")

        optimizer.zero_grad()


def eval(model, inputs):
    return np.argmax(model.forward(inputs).detach().cpu().numpy(), axis=1)
