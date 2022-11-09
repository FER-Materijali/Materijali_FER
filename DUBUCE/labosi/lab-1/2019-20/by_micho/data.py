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
#    NOTE: This notice only applies to the methods sample_gmm_2d and
#    convert_to_one_hot. Methods graph_data and graph_surface aren't my
#    intellectual property, and belong to their respective owners, even
#    though I slightly modified them. You can find both of them at:
#    http://www.zemris.fer.hr/~ssegvic/du/lab0.shtml


from matplotlib import pyplot as plt
import numpy as np
import torch


def sample_gmm_2d(k, c, n):
    x = list()
    y = list()

    for _ in range(k):
        x.append(np.random.normal(loc=np.random.uniform(-10, 10),
                                  scale=np.random.uniform(1, np.sqrt(10)),
                                  size=(n, 2)))
        y.append(np.random.randint(low=0, high=c, size=n))

    return np.vstack(x), np.hstack(y)


def graph_data(x, y_true, y_pred, special=None):
    if special is None:
        special = []

    special = np.array(special)

    palette = ([0.4, 0.4, 0.4], [0., 0., 0.], [1., 0., 0.])
    colors = np.tile([0., 0., 0.], (y_true.shape[0], 1))

    for i in range(len(palette)):
        colors[y_true == i] = palette[i]

    sizes = np.repeat(20, len(y_true))

    if len(special) != 0:
        sizes[special] = 80

    good = (y_true == y_pred)
    plt.scatter(x[good, 0], x[good, 1], c=colors[good], s=sizes[good], marker='o')

    bad = (y_true != y_pred)
    plt.scatter(x[bad, 0], x[bad, 1], c=colors[bad], s=sizes[bad], marker='s')


def graph_surface(function, rect, offset=0.5, width=256, height=256):
    lsw = np.linspace(rect[0][1], rect[1][1], width)
    lsh = np.linspace(rect[0][0], rect[1][0], height)
    xx0, xx1 = np.meshgrid(lsh, lsw)
    grid = np.stack((xx0.flatten(), xx1.flatten()), axis=1)

    values = function(torch.tensor(grid, dtype=torch.float)).reshape((width, height))

    delta = offset if offset else 0
    max_val = max(np.max(values) - delta, - (np.min(values) - delta))

    plt.pcolormesh(xx0, xx1, values, vmin=delta - max_val, vmax=delta + max_val)

    if offset is not None:
        plt.contour(xx0, xx1, values, colors="black", levels=[offset])


def convert_to_one_hot(datapoints, n_classes: int or None = None):
    if n_classes is None:
        n_classes = np.max(datapoints) + 1

    _datapoints = list()

    for datapoint in datapoints:
        _t = np.zeros(n_classes)
        _t[datapoint] = 1

        _datapoints.append(_t)

    return np.array(_datapoints)