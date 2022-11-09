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


import torch
import torch.optim as optim


def square_loss(y_real, y_pred):
    return torch.sum((y_real - y_pred) ** 2)


def mean_square_loss(y_real, y_pred):
    return torch.mean((y_real - y_pred) ** 2)


def do_linear_regression(x_and_y=None, n_epochs: int = 100, learning_rate: float = 0.1, verbose: int = 0):
    # Initialize parameters for y = ax + b
    a = torch.randn(1, requires_grad=True)
    b = torch.randn(1, requires_grad=True)

    # Initialize dataset
    if x_and_y is None:
        x = torch.tensor([1, 2])
        y_real = torch.tensor([3, 5])
    else:
        x, y_real = x_and_y

    optimizer = optim.SGD([a, b], lr=learning_rate)

    for epoch in range(1, n_epochs + 1):
        y_pred = a * x + b

        # Make training identical for different dataset sizes.
        loss = mean_square_loss(y_real, y_pred)
        loss.backward()
        optimizer.step()

        if verbose > 0:
            print(f"Epoha {epoch}:\t"
                  f"gubitak = {loss:.06f}, "
                  f"{a.detach().numpy()[0]:.02f} * {x.detach().numpy()} + {b.data.detach().numpy()[0]:.02f} = "
                  f"{y_pred.detach().numpy()}")

            if verbose > 1:
                neg_diffs = y_pred - y_real

                our_grad_a = 2 * torch.mean(neg_diffs * x)
                our_grad_b = 2 * torch.mean(neg_diffs)

                print(f"∇(a) = {a.grad.detach().numpy()[0]:.03f},  ∇(b) = {b.grad.detach().numpy()[0]:.03f}")
                print(f"∇*(a) = {our_grad_a.detach().numpy():.03f},  ∇*(b) = {our_grad_b.detach().numpy():.03f}")

        optimizer.zero_grad()
        print()
