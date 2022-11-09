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
#
#    NOTE: Applies only to the CNNT3 class and its components.

import json
from sys import stdout
from pathlib import Path

import numpy as np
import os
from sklearn.metrics import confusion_matrix
import torch
from torch import nn
from torchvision.datasets import MNIST
from tqdm import tqdm

from util import torch_draw_filters

DATA_DIR = Path(__file__).parent / "datasets" / "MNIST"
SAVE_DIR = Path(__file__).parent / "out_task3"


def dense_to_one_hot(y, class_count):
    return np.eye(class_count)[y]


def prepare_MNIST():
    ds_train, ds_test = MNIST(DATA_DIR, train=True, download=True), MNIST(DATA_DIR, train=False)

    train_x = ds_train.data.reshape([-1, 1, 28, 28]).numpy().astype(np.float) / 255
    train_y = ds_train.targets.numpy()

    train_x, valid_x = train_x[:55000], train_x[55000:]
    train_y, valid_y = train_y[:55000], train_y[55000:]

    test_x = ds_test.data.reshape([-1, 1, 28, 28]).numpy().astype(np.float) / 255
    test_y = ds_test.targets.numpy()

    train_mean = train_x.mean()

    x_tr, x_val, x_te = (x - train_mean for x in (train_x, valid_x, test_x))
    y_tr, y_val, y_te = (dense_to_one_hot(y, 10) for y in (train_y, valid_y, test_y))

    return {"x": (x_tr, x_val, x_te),
            "y": (y_tr, y_val, y_te),
            "mean": train_mean}


class CNNT3(nn.Module):
    def __init__(self, class_count: int = 10):
        super().__init__()

        # 28x28
        self.conv_1 = nn.Conv2d(in_channels=1, out_channels=16, kernel_size=5, padding=2)
        # 28x28
        self.maxpool_1 = nn.MaxPool2d(kernel_size=2, stride=2)
        # 14x14
        self.conv_2 = nn.Conv2d(in_channels=16, out_channels=32, kernel_size=5, padding=2)
        # 14x14
        self.maxpool_2 = nn.MaxPool2d(kernel_size=2, stride=2)
        # 7x7

        self.fc_1 = nn.Linear(in_features=32 * 7 * 7, out_features=512)
        self.fc_2 = nn.Linear(in_features=512, out_features=class_count)

        self.reset_parameters()

    def reset_parameters(self):
        nn.init.kaiming_normal_(self.conv_1.weight, nonlinearity="relu")
        nn.init.normal_(self.conv_1.bias, 0., 1e-6 / 3)

        nn.init.kaiming_normal_(self.conv_2.weight, nonlinearity="relu")
        nn.init.normal_(self.conv_2.bias, 0., 1e-6 / 3)

        nn.init.kaiming_normal_(self.fc_1.weight, nonlinearity="relu")
        nn.init.normal_(self.fc_1.bias, 0., 1e-6 / 3)

        nn.init.xavier_uniform_(self.fc_2.weight)
        nn.init.constant_(self.fc_2.bias, 0.)

    def forward(self, x):
        if not isinstance(x, torch.Tensor):
            x = torch.tensor(x)

        x = x.float()

        conv_1 = self.conv_1(x)
        conv_1 = self.maxpool_1(conv_1)
        conv_1 = torch.relu(conv_1)

        conv_2 = self.conv_2(conv_1)
        conv_2 = self.maxpool_2(conv_2)
        conv_2 = torch.relu(conv_2)

        flatten = conv_2.view((conv_2.shape[0], -1))

        fc_1 = self.fc_1(flatten)
        fc_1 = torch.relu(fc_1)

        fc_2 = self.fc_2(fc_1)

        return fc_2

    def predict(self, x):
        return torch.argmax(self.forward(x))

    @staticmethod
    def loss(x, y):
        sumlog = torch.log(torch.sum(torch.exp(x), dim=1))
        mulsum = torch.sum(x * y, dim=1)

        return torch.mean(sumlog - mulsum)

    def tr(self, x, y, val_x, val_y, weight_decay: float = 1e-3, verbose: int = 1):
        n_epochs = 8
        batch_size = 50
        t3_save_dir = SAVE_DIR / f"lambda{weight_decay:.03f}"

        os.makedirs(t3_save_dir, exist_ok=True)

        optimizer = torch.optim.SGD([
            {"params": [*self.conv_1.parameters(),
                        *self.conv_2.parameters(),
                        *self.fc_1.parameters()], "weight_decay": weight_decay},
            {"params": self.fc_2.parameters(), "weight_decay": 0.}
        ], lr=1e-1)
        scheduler = torch.optim.lr_scheduler.StepLR(optimizer=optimizer, step_size=2, gamma=0.1)

        iterator = range(n_epochs)
        losses = list()
        val_losses = list()

        if verbose > 0:
            iterator = tqdm(iterator, total=len(iterator), file=stdout)

        torch_draw_filters(layer=self.conv_1, file_path=t3_save_dir / f"beginning_conv1.png")

        for epoch in iterator:
            perm = torch.randperm(len(x))
            xs = torch.tensor(x).detach()[perm]
            ys = torch.tensor(y).detach()[perm]

            x_batches = torch.split(xs, batch_size)
            y_batches = torch.split(ys, batch_size)

            loss_memory = list()

            for i, (_x, _y) in enumerate(zip(x_batches, y_batches)):
                loss = self.loss(self.forward(_x), _y)
                loss_memory.append(float(loss))
                loss.backward()

                optimizer.step()
                scheduler.step(epoch=epoch)

                if verbose > 0:
                    iterator.set_description(f"Step {i}\tloss: {np.mean(loss_memory):.04f}")

                optimizer.zero_grad()

            losses.append(np.mean(loss_memory))
            val_losses.append(float(self.loss(self.forward(val_x).clone().detach(), val_y)))

            eval_dict = self.eval_after_epoch(val_x, val_y)
            torch_draw_filters(layer=self.conv_1, file_path=t3_save_dir / f"E{epoch:03d}_conv1.png")

            print(f"\n[Validation]\t"
                  f"Accuracy: {eval_dict['acc'] * 100:.02f}%\t\t"
                  f"F1 Score: {eval_dict['f1'] * 100:.02f}%\n")

        with open(t3_save_dir / "results.json", mode="w+") as file:
            json.dump({"loss": losses, "val_loss": val_losses}, file, ensure_ascii=False, indent=2)

        print("\n\n")

    def ev(self, inputs):
        return self.forward(inputs).detach().cpu().numpy()

    def eval_after_epoch(self, x_val, y_val):
        y_pred = self.ev(x_val)

        y_true = np.argmax(y_val, axis=1)
        y_pred = np.argmax(y_pred, axis=1)

        cm = confusion_matrix(y_true, y_pred)
        cm_diag = np.diag(cm)

        sums = [np.sum(cm, axis=y) for y in [None, 0, 1]]

        sums[0] = np.maximum(1, sums[0])
        for i in range(1, len(sums)):
            sums[i][sums[i] == 0] = 1

        accuracy = np.sum(cm_diag) / sums[0]
        precision, recall = [np.mean(cm_diag / x) for x in sums[1:]]
        f1 = (2 * precision * recall) / (precision + recall)

        return {"acc": accuracy, "pr": precision, "re": recall, "f1": f1}
