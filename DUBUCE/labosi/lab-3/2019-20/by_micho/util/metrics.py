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

from sys import stdout
from typing import Any, Callable, Dict, List

import numpy as np
from sklearn.metrics import confusion_matrix
import torch
import torch.utils.data
from tqdm import tqdm


def evaluate(model: torch.nn.Module, x, y,
             loss: Callable = None, verbose: int = 1) -> Dict[str, Any]:
    """
    Evaluates a given model given a set of inputs, outputs and a loss function.

    :param model:
        A torch.nn.Module representing the model you wish to evaluate.

    :param x:
        A set of inputs you wish to evaluate the model on.

    :param y:
        A set of labels you wish to evaluate the model on.

    :param loss:
        (Optional) A Callable representing the loss function you wish to
        evaluate the model with. Defaults to None (which will ignore loss
        calculations).

    :param verbose:
        (Optional) An int representing the verbosity of evaluation. Defaults to
        1 (just above no input).


    :return:
        A Dict[str, any] mapping metric keys to the measure values.
    """
    model.eval()

    y_pred = list()
    losses = list()

    iterator = tqdm(x, total=len(x), file=stdout) if verbose > 0 else x

    for _x, _y in zip(iterator, y):
        y_pred.append(model.infer(_x))
        y_pred_tensor = torch.tensor(y_pred[-1]).float().view(_y.shape)

        if loss is not None:
            losses.append(float(loss(_y.float(), y_pred_tensor)))

    cm = confusion_matrix(np.array(y, dtype=np.int32),
                          np.array(y_pred, dtype=np.int32))
    cm_diag = np.diag(cm)

    sums = [np.sum(cm, axis=y) for y in [None, 0, 1]]

    sums[0] = np.maximum(1, sums[0])
    for i in range(1, len(sums)):
        sums[i][sums[i] == 0] = 1

    accuracy = np.sum(cm_diag) / sums[0]
    precision, recall = [np.mean(cm_diag / x) for x in sums[1:]]
    f1 = (2 * precision * recall) / (precision + recall)

    return {"loss": None if loss is None else float(np.mean(losses)),
            "acc": accuracy,
            "pr": precision,
            "re": recall,
            "f1": f1,
            "cm": np.ndarray.tolist(cm)}


def convert_timeline_to_diary(timeline: List[Dict[str, Any]]) -> Dict[str, Any]:
    """
    Converts a list of logged data into a Dict[str, Any] containing lists of
    data instead of singular values, or in other words a diary.

    :param timeline:
        A List[Dict[str, Any]] containing the logged metrics you wish to
        flatten into a diary dictionary.


    :return:
        A Dict[str, Any] representing the diary dictionary.
    """
    to_return = dict()

    for time_stamp in timeline:
        for metric, value in time_stamp.items():
            if metric not in to_return:
                to_return[metric] = list()

            to_return[metric].append(value)

    return to_return
