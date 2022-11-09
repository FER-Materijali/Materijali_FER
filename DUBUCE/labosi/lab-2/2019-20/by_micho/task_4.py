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
#    NOTE: Doesn't apply to dense_to_one_hot, shuffle_data, unpickle,
#    prepare_CIFAR and tensor_to_image.

import json
import os
from pathlib import Path
from sys import stdout

import numpy as np
from skimage import io as skio
from sklearn.metrics import confusion_matrix
import pickle
import torch
from torch import nn
from tqdm import tqdm

from util import torch_draw_filters

SAVE_DIR = Path(__file__).parent / "out_task4"

cifar_labels = ["Zrakoplov", "Automobil",
                "Ptica", "Mačka",
                "Jelen", "Pas",
                "Žaba", "Konj",
                "Brod", "Kamion"]


def dense_to_one_hot(y, class_count):
    return np.eye(class_count)[y]


def shuffle_data(x, y):
    indices = np.arange(x.shape[0])
    np.random.shuffle(indices)

    return [np.ascontiguousarray(z[indices]) for z in (x, y)]


def unpickle(file_path: str):
    with open(file_path, mode="rb") as file:
        return pickle.load(file, encoding="latin1")


def prepare_CIFAR():
    data_dir = "datasets/CIFAR"

    img_height = 32
    img_width = 32
    num_channels = 3

    x_tr = np.ndarray((0, img_height * img_width * num_channels), dtype=np.float32)
    y_tr = []

    for i in range(1, 6):
        subset = unpickle(os.path.join(data_dir, f"data_batch_{i}"))
        x_tr = np.vstack((x_tr, subset["data"]))
        y_tr += subset["labels"]

    x_tr = x_tr.reshape((-1, num_channels, img_height, img_width)).transpose(0, 2, 3, 1)
    y_tr = np.array(y_tr, dtype=np.int32)

    subset = unpickle(os.path.join(data_dir, "test_batch"))
    x_te = subset["data"].reshape((-1, num_channels, img_height, img_width)).transpose(0, 2, 3, 1).astype(np.float32)
    y_te = np.array(subset["labels"], dtype=np.int32)

    val_size = 5000
    x_tr, y_tr = shuffle_data(x_tr, y_tr)
    x_val = x_tr[:val_size, ...]
    y_val = y_tr[:val_size, ...]
    x_tr = x_tr[val_size:, ...]
    y_tr = y_tr[val_size:, ...]

    data_mean = x_tr.mean((0, 1, 2))
    data_std = x_tr.std((0, 1, 2))

    x_tr, x_val, x_te = [((x - data_mean) / data_std).transpose(0, 3, 1, 2)
                         for x in (x_tr, x_val, x_te)]
    y_tr, y_val, y_te = (dense_to_one_hot(y, 10) for y in (y_tr, y_val, y_te))

    return {"x": (x_tr, x_val, x_te),
            "y": (y_tr, y_val, y_te),
            "mean": data_mean,
            "std": data_std}


def convert_timeline_to_diary(timeline):
    to_return = dict()

    for time_stamp in timeline:
        for metric, value in time_stamp.items():
            if metric not in to_return:
                to_return[metric] = list()

            to_return[metric].append(value)

    return to_return


class CNNT4(nn.Module):
    def __init__(self, class_count: int = 10):
        super().__init__()

        _chan = [[64], [64], [64, 128]]
        _kern = [[7],  [5],  [3, 3]]

        _fc = [512, 256]

        self.conv = list()
        self.maxpool = list()
        self.prelu = list()
        self.batch_norm = list()

        self.fc = list()

        _last_size = 3

        for channels, kernels in zip(_chan, _kern):
            t_conv = list()
            t_prelu = list()
            t_batch_norm = list()

            for channel, kernel in zip(channels, kernels):
                t_conv.append(nn.Conv2d(_last_size, channel, kernel, padding=(kernel - 1) // 2))
                t_prelu.append(nn.PReLU(channel))
                t_batch_norm.append(nn.BatchNorm2d(channel))

                _last_size = channel

            self.conv.append(t_conv)
            self.prelu.append(t_prelu)
            self.batch_norm.append(t_batch_norm)
            self.maxpool.append(nn.MaxPool2d(2, 2))

        _pic_side = 32 // int(2 ** len(_chan) + 0.1)
        _last_size *= (_pic_side * _pic_side)

        for units in _fc:
            self.fc.append(nn.Linear(_last_size, units))
            self.prelu.append(nn.PReLU())
            self.batch_norm.append(nn.BatchNorm1d(units))

            _last_size = units

        self.fc.append(nn.Linear(_last_size, out_features=class_count))

        self.reset_parameters()

    def get_static_params(self):
        to_return = list()
        modules = list()
        n_blocks = len(self.conv)

        blocks = [*self.conv, *self.prelu[:n_blocks], *self.batch_norm[:n_blocks]]

        for block in blocks:
            modules += block

        for x in [*modules, *self.fc[:-1], *self.prelu[n_blocks:], *self.batch_norm[n_blocks:]]:
            to_return.extend(x.parameters())

        return to_return

    def reset_parameters(self):
        for convolutions in self.conv:
            for conv in convolutions:
                nn.init.kaiming_normal_(conv.weight, nonlinearity="leaky_relu")
                nn.init.normal_(conv.bias, 0., 1e-6 / 3)

        for fc in self.fc[:-1]:
            nn.init.kaiming_normal_(fc.weight, nonlinearity="leaky_relu")
            nn.init.normal_(fc.bias, 0., 1e-6 / 3)

        nn.init.xavier_normal_(self.fc[-1].weight)
        nn.init.constant_(self.fc[-1].bias, 0.)

    def forward(self, x):
        if not isinstance(x, torch.Tensor):
            x = torch.tensor(x)

        last = x.float()

        n_blocks = len(self.conv)

        for conv, maxpool, prelu, batch_norm in zip(self.conv,
                                                    self.maxpool,
                                                    self.prelu[:n_blocks],
                                                    self.batch_norm[:n_blocks]):
            for c, p, b in zip(conv[:-1], prelu[:-1], batch_norm[:-1]):
                last = c(last)
                last = p(last)
                last = b(last)

            last = conv[-1](last)
            last = maxpool(last)
            last = prelu[-1](last)
            last = batch_norm[-1](last)

        last = last.view((last.shape[0], -1))

        for fc, prelu, batch_norm in zip(self.fc[:-1],
                                         self.prelu[n_blocks:],
                                         self.batch_norm[n_blocks:]):
            last = fc(last)
            last = prelu(last)
            last = batch_norm(last)

        last = self.fc[-1](last)

        return last

    def predict(self, x):
        return torch.argmax(self.forward(x))

    @staticmethod
    def loss(y_true, y_pred):
        if not isinstance(y_true, torch.Tensor):
            y_true = torch.tensor(y_true)

        if not isinstance(y_pred, torch.Tensor):
            y_pred = torch.tensor(y_pred)

        sumlog = torch.log(torch.sum(torch.exp(y_pred), dim=-1))
        mulsum = torch.sum(y_true * y_pred, dim=-1)

        return torch.mean(sumlog - mulsum)

    def tr(self, x, y, val_x, val_y,
           n_epochs: int = 1,
           batch_size: int = 16,
           weight_decay: float = 0.,
           verbose: int = 1):
        self.train()

        train_metrics = list()
        val_metrics = list()
        learning_rates = list()

        optimizer = torch.optim.Adam([
            {"params": self.fc[-1].parameters(), "weight_decay": weight_decay},
            {"params": self.get_static_params()}], lr=3e-4)
        scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(optimizer=optimizer,
                                                               factor=0.1,
                                                               patience=1,
                                                               verbose=True,
                                                               cooldown=0,
                                                               min_lr=1e-9)

        iterator = range(n_epochs)
        losses = list()

        torch_draw_filters(self.conv[0][0], SAVE_DIR / f"beginning_conv1.png")

        for epoch in iterator:
            print(f"\nEpoch {epoch}")

            if epoch == 4:
                optimizer = torch.optim.SGD([
                    {"params": self.fc[-1].parameters(), "weight_decay": weight_decay},
                    {"params": self.get_static_params()}], lr=3e-5, momentum=0.9)
                scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(optimizer=optimizer,
                                                                       factor=0.1,
                                                                       patience=1,
                                                                       verbose=True,
                                                                       cooldown=0,
                                                                       min_lr=1e-9)

            perm = torch.randperm(len(x))
            xs = torch.tensor(x).detach()[perm]
            ys = torch.tensor(y).detach()[perm]

            x_batches = torch.split(xs, batch_size)
            y_batches = torch.split(ys, batch_size)

            loss_memory = list()

            batches = list(zip(x_batches, y_batches))

            if verbose > 0:
                batches = tqdm(batches, total=len(batches), file=stdout)

            for i, (_x, _y) in enumerate(batches):
                loss = self.loss(_y, self.forward(_x))
                loss_memory.append(float(loss))
                loss.backward()

                optimizer.step()

                if verbose > 0:
                    batches.set_description(f"loss: {np.mean(loss_memory):.04f}")

                optimizer.zero_grad()

            self.eval()

            with torch.no_grad():
                losses.append(np.mean(loss_memory))

                torch_draw_filters(self.conv[0][0], SAVE_DIR / f"E{epoch:03d}_conv1.png")

                train_dict = self.evaluate(x, y)
                val_dict = self.evaluate(val_x, val_y)

                val_loss = val_dict['loss']
                learning_rates.append(optimizer.param_groups[0]["lr"])

                print(f"[Validation]\t"
                      f"Val Loss: {val_loss:.04f}\t\t"
                      f"Accuracy: {val_dict['acc'] * 100:.02f}%\t\t"
                      f"F1 Score: {val_dict['f1'] * 100:.02f}%")

                scheduler.step(epoch=epoch, metrics=val_loss)

                train_metrics.append(train_dict)
                val_metrics.append(val_dict)

            self.train()

        train_metrics = convert_timeline_to_diary(train_metrics)
        val_metrics = convert_timeline_to_diary(val_metrics)

        with open(SAVE_DIR / "results_tr.json", mode="w+") as file:
            json.dump(train_metrics, file, sort_keys=False, ensure_ascii=False, indent=2)

        with open(SAVE_DIR / "results_val.json", mode="w+") as file:
            json.dump(val_metrics, file, sort_keys=False, ensure_ascii=False, indent=2)

        with open(SAVE_DIR / "learning_rates.json", mode="w+") as file:
            json.dump(learning_rates, file, sort_keys=False, ensure_ascii=False, indent=2)

    def ev(self, inputs):
        with torch.no_grad():
            return self.forward(inputs).detach().cpu().numpy()

    def evaluate(self, x, y):
        y_true, y_pred = [np.argmax(z, axis=1) for z in (y, self.ev(x))]

        cm = confusion_matrix(y_true, y_pred)
        cm_diag = np.diag(cm)

        sums = [np.sum(cm, axis=y) for y in [None, 0, 1]]

        sums[0] = np.maximum(1, sums[0])
        for i in range(1, len(sums)):
            sums[i][sums[i] == 0] = 1

        with torch.no_grad():
            loss = float(self.loss(y, self.forward(x).clone().detach()))

        accuracy = float(np.sum(cm_diag) / sums[0])
        precision, recall = [float(np.mean(cm_diag / x)) for x in sums[1:]]
        f1 = (2 * precision * recall) / (precision + recall)

        return {"loss": loss, "acc": accuracy, "pr": precision, "re": recall, "f1": f1}


def tensor_to_image(tensor, mean, std):
    to_return = np.array(tensor).transpose(1, 2, 0)
    to_return *= std
    to_return += mean

    return np.array(to_return, dtype=np.uint8)


def analyze_evaluation(model: CNNT4, x, y, mean, std,
                       n_worst_images: int = 20, n_best_classes: int = 3,
                       folder_path=SAVE_DIR / "t4_s5"):
    model.eval()

    os.makedirs(folder_path, exist_ok=True)

    class_count = dict()
    class_dict = dict()

    loss_tuples = list()

    with torch.no_grad():
        y_pred = model.forward(x)

        if not isinstance(y, torch.Tensor):
            y = torch.tensor(y)

        c_trues = torch.argmax(y, dim=1)
        c_preds = torch.argmax(y_pred, dim=1)

        pairs = list(zip(c_trues, c_preds))

        for i, (c_true, c_pred) in enumerate(tqdm(pairs, total=len(pairs), file=stdout)):
            c_true, c_pred = [int(a) for a in [c_true, c_pred]]

            if c_true not in class_count:
                class_count[c_true] = 0

            class_count[c_true] += 1

            if c_true != c_pred:
                loss_tuples.append((float(model.loss(y[i], y_pred[i])), x[i], c_true, c_pred))
            else:
                if c_pred not in class_dict:
                    class_dict[c_pred] = 0

                class_dict[c_pred] += 1

    loss_tuples.sort(key=lambda a: a[0], reverse=True)
    class_frequency = dict()

    for count in class_count:
        class_frequency[count] = class_dict.get(count, 0) / class_count[count]

    classes = sorted(class_frequency.items(), key=lambda a: a[1], reverse=True)

    worst_images = [a[1] for a in loss_tuples[:n_worst_images]]
    worst_image_classes = [a[2:] for a in loss_tuples[:n_worst_images]]
    best_classes = classes[:n_best_classes]

    with open(folder_path / "best_classes.json", mode="w+") as file:
        json.dump(best_classes, file)

    with open(folder_path / "worst_classes.json", mode="w+") as file:
        json.dump(worst_image_classes, file)

    for i, bad_image in enumerate(worst_images):
        image_array = tensor_to_image(bad_image, mean, std)

        skio.imsave(folder_path / f"worst_{i:02d}.png", image_array)
