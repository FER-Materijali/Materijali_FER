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
from time import sleep

from matplotlib import image as mpimage
import numpy as np
from sklearn import svm
from sklearn.metrics import confusion_matrix
import torch
import torchvision
from tqdm import tqdm

import pt_deep


# region Helper Methods
def get_mnist():
    _root_folder = "data/"
    _root_dataset_folder = os.path.join(_root_folder, "MNIST", "processed")
    _run_train_download = not os.path.exists(os.path.join(_root_dataset_folder, "training.pt"))
    _run_test_download = not os.path.exists(os.path.join(_root_dataset_folder, "test.pt"))

    _train = torchvision.datasets.MNIST(_root_folder, train=True, download=_run_train_download)
    _test = torchvision.datasets.MNIST(_root_folder, train=False, download=_run_train_download)

    return _train.data.float().div_(255.), \
           _train.targets, \
           _test.data.float().div_(255.), \
           _test.targets


def convert_labels_to_one_hot(labels):
    _new_labels = list()

    for tensor in labels:
        _zeros = np.zeros(10)
        _zeros[tensor.data] = 1.

        _new_labels.append(_zeros)

    return torch.tensor(_new_labels)


def get_normalized_data_points(x_tr, y_tr, x_te, y_te):
    return x_tr.view(-1, 784), \
           convert_labels_to_one_hot(y_tr), \
           x_te.view(-1, 784), \
           convert_labels_to_one_hot(y_te)


def cudify_data_points(x_tr, y_tr, x_te, y_te):
    return x_tr.cuda(), y_tr.cuda(), x_te.cuda(), y_te.cuda()


def eval_metrics(y_real, y_pred, prefix: str or None = None):
    if prefix is None:
        prefix = ""

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
# endregion


def task_1_prep(x_tr, y_tr, x_te, y_te, weight_decays=(0., 1e-4, 1e-2, 1.)):
    n_epochs = 3000
    learning_rate = 0.1
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    for weight_decay in weight_decays:
        folder_path = f"data/problem_7/task_1/l_{weight_decay}"

        if not os.path.exists(folder_path):
            os.mkdir(folder_path)

        _model = pt_deep.Deep([784, 10], activation=torch.relu, is_cuda=is_cuda)
        _sgd = torch.optim.SGD(params=_model.parameters(), lr=learning_rate, weight_decay=weight_decay)

        iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

        for _ in iterator:
            _loss = _model.get_loss(*normalized_data[:2])
            _loss.backward()
            _sgd.step()

            iterator.set_description(f"Loss: {float(_loss):.04f}")

            _sgd.zero_grad()

        _digit_weights = _model.weights[0].detach().cpu().numpy().T.reshape((-1, 28, 28))

        for i, digit_matrix in enumerate(_digit_weights):
            mpimage.imsave(os.path.join(folder_path, f"{i}.png"), digit_matrix)


def task_2_prep(x_tr, y_tr, x_te, y_te, model_configurations, n_repeats: int = 3):
    n_epochs = 3000
    learning_rate = 0.1
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    _results = dict()

    for name, model_configuration in zip(["1", "2", "3", "4"], model_configurations):
        _t_results = list()

        for i in range(n_repeats):
            _losses = list()

            _model = pt_deep.Deep(model_configuration, activation=torch.relu, is_cuda=is_cuda)
            _sgd = torch.optim.SGD(params=_model.parameters(), lr=learning_rate)

            _iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

            for _ in _iterator:
                _loss = _model.get_loss(*normalized_data[:2])
                _loss.backward()
                _sgd.step()

                _losses.append(float(_loss.detach().cpu().numpy()))
                _iterator.set_description(f"[Configuration {model_configuration}, repeat {i + 1}]\tloss: {_loss:.04f}")

                _sgd.zero_grad()

            _t_result = {"losses": _losses}
            _t_result.update(pt_deep.eval_metrics(_model, normalized_data[0], y_tr, "tr_"))
            _t_result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

            _t_results.append(_t_result)

        print()
        _f1s = [x["te_f1"] for x in _t_results]
        _chosen_index = int(np.argmax(_f1s))

        _results[name] = _t_results[_chosen_index]

    with open("data/problem_7/task_2.json", mode="w+") as file:
        json.dump(_results, file, indent=2)


def task_3_prep(x_tr, y_tr, x_te, y_te, weight_decays=(1e-3, 1e-2, 0.1, 1)):
    n_epochs = 1000
    learning_rate = 0.1
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    _results = {k: None for k in weight_decays}

    for weight_decay in weight_decays:
        _losses = list()

        _model = pt_deep.Deep([784, 100, 10], activation=torch.relu, is_cuda=is_cuda)
        _sgd = torch.optim.SGD(params=_model.parameters(), lr=learning_rate, weight_decay=weight_decay)

        _iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

        for _ in _iterator:
            _loss = _model.get_loss(*normalized_data[:2])
            _loss.backward()
            _sgd.step()

            _losses.append(float(_loss.detach().cpu().numpy()))
            _iterator.set_description(f"[Weight Decay {weight_decay:.06f}]\tloss: {_loss:.04f}")

            _sgd.zero_grad()

        _result = {"losses": _losses}
        _result.update(pt_deep.eval_metrics(_model, normalized_data[0], y_tr, "tr_"))
        _result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

        _results[weight_decay] = _result

    with open("data/problem_7/task_3.json", mode="w+") as file:
        json.dump(_results, file, indent=2)


def task_4_prep(x_tr, y_tr, x_te, y_te, patience: int = 5):
    n_epochs = 100000
    learning_rate = 0.1
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    val_indices = np.random.choice(range(len(x_tr)), int(0.2 * x_tr.shape[0]), replace=False)
    tr_indices = list(set(range(len(x_tr))) - set(val_indices))

    y_tr_ = y_tr
    x_tr = normalized_data[0][tr_indices].cuda()
    y_tr = normalized_data[1][tr_indices].cuda()
    x_val = normalized_data[0][val_indices].cuda()
    y_val = normalized_data[1][val_indices].cuda()

    _model = pt_deep.Deep([784, 100, 10], activation=torch.relu, is_cuda=is_cuda)
    _sgd = torch.optim.SGD(params=_model.parameters(), lr=learning_rate)

    _min_loss = None
    _last_weights = None
    _last_biases = None
    _best_epoch = 0
    _counter = 0

    _last_weights = _model.weights
    _last_biases = _model.biases

    _iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

    for i in _iterator:
        # Need this so my PC doesn't overheat lmao
        if i % 5000 == 0: sleep(90)

        _loss = _model.get_loss(x_tr, y_tr)
        _loss.backward()
        _sgd.step()

        _val_loss = float(_model.get_loss(x_val, y_val).detach().cpu().numpy())
        _iterator.set_description(f"[Validation Loss]\tval_loss: {_val_loss:.04f}")

        _sgd.zero_grad()

        if _min_loss is None or _min_loss > _val_loss:
            _min_loss = _val_loss

            _last_weights = _model.weights
            _last_biases = _model.biases

            _best_epoch = i
            _counter = 0
        else:
            _counter += 1

            if _counter >= patience:
                _model.weights = _last_weights
                _model.biases = _last_biases
                break

    _result = {"best_epoch": _best_epoch, "val_loss": _min_loss}
    _result.update(pt_deep.eval_metrics(_model, x_val, y_tr_[val_indices], "val_"))
    _result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

    with open("data/problem_7/task_4.json", mode="w+") as file:
        json.dump(_result, file, indent=2)


def task_5_prep(x_tr, y_tr, x_te, y_te, batch_sizes=(16, 64, 256, -1)):
    batch_sizes = [len(x_tr) if x < 1 else x for x in batch_sizes]
    n_epochs = 100
    learning_rate = 0.01
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    _losses = list()
    _results = {k: None for k in batch_sizes}

    for batch_size in batch_sizes:
        _model = pt_deep.Deep([784, 100, 100, 10], activation=torch.relu, is_cuda=is_cuda)
        _sgd = torch.optim.SGD(params=_model.parameters(), lr=learning_rate)

        _losses = list()

        _iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

        for _ in _iterator:
            _perm = torch.randperm(len(x_tr))
            _xs = normalized_data[0].clone().detach()[_perm]
            _ys = normalized_data[1].clone().detach()[_perm]

            x_batches = [x.cuda() for x in torch.split(_xs, batch_size)]
            y_batches = [x.cuda() for x in torch.split(_ys, batch_size)]

            _loss = 0.
            _loss_memory = list()

            for i, (_x, _y) in enumerate(zip(x_batches, y_batches)):
                _loss = _model.get_loss(_x, _y)
                _loss_memory.append(float(_loss))
                _loss.backward()
                _sgd.step()

                _iterator.set_description(f"[Batch Size {batch_size}]\tStep {i}\tloss: {np.mean(_loss_memory):.04f}")

                _sgd.zero_grad()

            _losses.append(np.mean(_loss_memory))

        _result = {"losses": _losses}
        _result.update(pt_deep.eval_metrics(_model, normalized_data[0], y_tr, "tr_"))
        _result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

        _results[batch_size] = _result

    with open("data/problem_7/task_5.json", mode="w+") as file:
        json.dump(_results, file, indent=2)


def task_6_prep(x_tr, y_tr, x_te, y_te):
    n_epochs = 3000
    learning_rate = 1e-4
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    _losses = list()

    _model = pt_deep.Deep([784, 100, 100, 10], activation=torch.relu, is_cuda=is_cuda)
    _adam = torch.optim.Adam(params=_model.parameters(), lr=learning_rate)

    _iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

    for _ in _iterator:
        _loss = _model.get_loss(*normalized_data[:2])
        _loss.backward()
        _adam.step()

        _losses.append(float(_loss.detach().cpu().numpy()))

        _iterator.set_description(f"[ADAM]\tloss: {_losses[-1]:.04f}")

        _adam.zero_grad()

    _result = {"losses": _losses}
    _result.update(pt_deep.eval_metrics(_model, normalized_data[0], y_tr, "tr_"))
    _result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

    with open("data/problem_7/task_6.json", mode="w+") as file:
        json.dump(_result, file, indent=2)


def task_7_prep(x_tr, y_tr, x_te, y_te):
    n_epochs = 3000
    learning_rate = 1e-4
    is_cuda = True

    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    if is_cuda:
        normalized_data = cudify_data_points(*normalized_data)

    _losses = list()

    _model = pt_deep.Deep([784, 100, 100, 10], activation=torch.relu, is_cuda=is_cuda)
    _adam = torch.optim.Adam(params=_model.parameters(), lr=learning_rate)
    _scheduler = torch.optim.lr_scheduler.ExponentialLR(_adam, gamma=0.9999)

    _iterator = tqdm(range(1, n_epochs + 1), total=n_epochs, file=stdout)

    for i in _iterator:
        _loss = _model.get_loss(*normalized_data[:2])
        _loss.backward()
        _adam.step()
        _scheduler.step()

        _losses.append(float(_loss.detach().cpu().numpy()))

        _iterator.set_description(f"[ADAM Decay]\tEpoch {i}\tloss: {_losses[-1]:.04f}")

        _adam.zero_grad()

    _result = {"losses": _losses}
    _result.update(pt_deep.eval_metrics(_model, normalized_data[0], y_tr, "tr_"))
    _result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

    with open("data/problem_7/task_7.json", mode="w+") as file:
        json.dump(_result, file, indent=2)


def task_8_prep(x_tr, y_tr, x_te, y_te):
    normalized_data = get_normalized_data_points(x_tr, y_tr, x_te, y_te)

    _model = pt_deep.Deep([784, 100, 100, 10], activation=torch.relu)

    _result = {"tr_loss": float(_model.get_loss(*normalized_data[:2])),
               "te_loss": float(_model.get_loss(*normalized_data[2:]))}
    _result.update(pt_deep.eval_metrics(_model, normalized_data[0], y_tr, "tr_"))
    _result.update(pt_deep.eval_metrics(_model, normalized_data[2], y_te, "te_"))

    with open("data/problem_7/task_8.json", mode="w+") as file:
        json.dump(_result, file, indent=2)


def task_9_prep(x_tr, y_tr, x_te, y_te):
    x_tr, y_tr, x_te, y_te = [x.detach().cpu().numpy() for x in [x_tr, y_tr, x_te, y_te]]
    x_tr = x_tr.reshape((len(x_tr), -1))
    x_te = x_te.reshape((len(x_te), -1))

    _result = dict()

    # Linear
    _classifier = svm.SVC(kernel="linear", decision_function_shape="ovo")
    _classifier.fit(x_tr, y_tr)
    _result.update(eval_metrics(y_te, _classifier.predict(x_te), prefix="lsvm_"))

    print("Done with Linear!")

    # Kernel
    _classifier = svm.SVC(decision_function_shape="ovo")
    _classifier.fit(x_tr, y_tr)
    _result.update(eval_metrics(y_te, _classifier.predict(x_te), prefix="ksvm_"))

    print("Done with Kernel!")

    with open("data/problem_7/task_9.json", mode="w+") as file:
        json.dump(_result, file, indent=2)
