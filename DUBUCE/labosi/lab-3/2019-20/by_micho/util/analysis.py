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
from typing import Any, Dict, List

from matplotlib.axes import Axes


# region Fetching Data
def get_entry_dict_from_json(save_file: str) -> Dict[str, Any]:
    """
    Gets an dictionary from a JSON file, using the latest values if met with a
    list. Useful for analyzing latest log data.

    :param save_file:
        A str representing the file path towards a JSON file you wish to read.


    :return:
        A Dict[str, Any] mapping variable names to their latest values.
    """
    entries = dict()

    with open(save_file) as file:
        for key, value in json.load(file).items():
            entries[key] = value[-1] if isinstance(value, list) else value

    return entries


def get_final_dicts(folder_path: str,
                    without: List[str] = ("learn-embeddings",)) \
        -> List[Dict[str, Any]]:
    """
    Get all results_val.json final dictionaries for a given folder.

    :param folder_path:
        A str representing the folder path containing folders with JSON files
        you wish to read.

    :param without:
        (Optional) A List[str] representing a list of folders you wish to
        ignore when looking at candidates. Useful when ignoring specific logs.
        Defaults to ("learn-embeddings", ).


    :return:
        A List[Dict[str, Any]] containing the final logs of runs found in the
        folder path given.
    """
    run_folder_paths = [os.path.abspath(os.path.join(folder_path, x))
                        for x in sorted(os.listdir(folder_path))
                        if x not in without]

    return [get_entry_dict_from_json(os.path.join(path, "results_val.json"))
            for path in run_folder_paths]


def get_all_final_dicts(folder_path: str) -> List[List[Dict[str, Any]]]:
    """
    Gets all final dictionary lists for a given folder. The same thing as
    get_all_dicts, but one step higher.

    :param folder_path:
        A str representing the folder path containing folders containing JSON
        files you wish to read.


    :return:
        A List[List[Dict[str, Any]] containing the list of final logs of runs
        found in the folders found in the folder path given.
    """
    all_final_tuples = list()

    for folder_path in [os.path.abspath(os.path.join(folder_path, x))
                        for x in sorted(os.listdir(folder_path))]:
        all_final_tuples.append(get_final_dicts(folder_path))

    return all_final_tuples


# endregion


# region MatPlotLib
def insert_multicategory_histogram(plt_axis: Axes,
                                   stat_dicts: List[Dict[str, Any]],
                                   key_order: List[str] = None,
                                   bar_titles: List[str] = None,
                                   title: str = None) -> Axes:
    """
    Given a final log dictionaries creates a histogram on the given Axes object.

    :param plt_axis:
        A matplotlib.axes.Axes object representing the matplotlib axes you wish
        to draw on.

    :param stat_dicts:
        A List[Dict[str, Any]] containing all the final log dictionaries you
        wish to draw a histogram for.

    :param key_order:
        (Optional) A List[str] containing the keys of the final log dictionary
        you wish to draw form. Defaults to None (draws nothing).

    :param bar_titles:
        (Optional) A List[str] containing the histogram x-axis labels. Defaults
        to None (takes key_order as reference).

    :param title:
        (Optional) A str representing the title of the subplot. Defaults to
        None (no title).

    :return:
        A matplotlib.axes.Axes object (same as the one passed). Useful for
        chaining calls.
    """
    if key_order is None:
        key_order = list(stat_dicts[0].keys())

    if bar_titles is None:
        bar_titles = list(key_order)

    width = (1 - 0.2) / len(stat_dicts)
    offsets = [-(width * (len(stat_dicts) // 2)) + (x * width)
               for x in range(len(stat_dicts))]

    for i, key in enumerate(key_order):
        plt_axis.bar(x=[i + x for x in offsets],
                     height=[stat_dict[key] for stat_dict in stat_dicts],
                     width=width - 0.01,
                     align="center")

    plt_axis.set_xticks(range(len(bar_titles)))
    plt_axis.set_xticklabels(bar_titles, fontsize=16)

    if title is not None:
        plt_axis.set_title(title, fontsize=16)

    plt_axis.autoscale(tight=True)

    return plt_axis


# endregion


# region Markdown
def hyperparameters_to_particles(hyperparameter_dict: Dict[str, Any],
                                 key_to_label: Dict[str, str] = None) \
        -> List[str]:
    """
    Converts a dictionary of hyperparameters to particles of text.

    :param hyperparameter_dict:
        A Dict[str, Any] representing the hyperparameters.

    :param key_to_label:
        (Optional) A Dict[str, str] mapping hyperparameter keys to titles.


    :return:
        A List[str] containing particles of text.
    """
    particles = list()

    for key, value in hyperparameter_dict.items():
        if isinstance(value, float):
            value = f"{value:.04f}"

        particles.append(f"{key_to_label.get(key, key)}: **{value}**")

    return particles


def markdown_particles_to_line(markdown_particles: List[str],
                               delimiter: str = None) -> str:
    """
    Converts text particles to lines of text.

    :param markdown_particles:
        A List[str] containing text particles.

    :param delimiter:
        (Optional) A str representing the delimiter between text particles.
        Defaults to None (which is essentially 10 "&nbsp;"'s one after another).


    :return:
        A str representing the text line.
    """
    if delimiter is None:
        delimiter = "".join(["&nbsp;"] * 10)

    return delimiter.join(markdown_particles)


def hyperparameters_to_markdown(hyperparameters: List[Dict[str, Any]],
                                key_to_label: Dict[str, str],
                                prefix: str = None,
                                delimiter: str = None) -> str:
    """
    Converts a hyperparameter dictionary to a Markdown string.

    :param hyperparameters:
        A Dict[str, Any] representing the hyperparameters.

    :param key_to_label:
        (Optional) A Dict[str, str] mapping hyperparameter keys to titles.

    :param prefix:
        (Optional) A str representing the prefix of the lines. Defaults to None.

    :param delimiter:
        (Optional) A str representing the delimiter between text particles.
        Defaults to None.


    :return:
        A str representing the Markdown text generated from the hyperparameters.
    """
    if prefix is None:
        prefix = ""

    if delimiter is None:
        delimiter = ""

    particle_list = [hyperparameters_to_particles(hyperparameter, key_to_label)
                     for hyperparameter in hyperparameters]

    lines = [markdown_particles_to_line(particles)
             for particles in particle_list]

    return prefix + delimiter.join(lines)


# endregion


# region Best Search
def find_best(folder_path: str,
              metric: str = "f1",
              mode: str = "high") -> Dict[str, Any]:
    """
    Finds the best hyperparameters in all runs in a folder.

    :param folder_path:
        A str representing the folder path in which to look for runs.

    :param metric:
        (Optional) A str representing the key which to look at when determining
        what the best setup is. Defaults to "f1".

    :param mode:
        (Optional) A str representing the mode of how to look at a certain
        metric. Valid values are "high" and "low". Defaults to "high".


    :return:
        A Dict[str, Any] representing the best hyperparameters.
    """
    run_paths = [os.path.join(folder_path, x)
                 for x in sorted(os.listdir(folder_path))]

    metrics = list()

    for json_path in [os.path.join(path, "results_val.json")
                      for path in run_paths]:
        if os.path.exists(json_path):
            with open(json_path) as file:
                t_dict = json.load(file)

                t_metric = t_dict[metric]

                while isinstance(t_metric, list):
                    t_metric = t_metric[-1]

                metrics.append((t_metric,
                                t_dict["additional_hyperparameters"]))

    metrics = sorted(metrics,
                     key=lambda x: x[0],
                     reverse=True
                             if mode == "high"
                             else False
                                  if mode == "low"
                                  else None)

    return metrics[0][1]


def find_all_best(folder_path: str,
                  metric: str = "f1",
                  mode: str = "high") -> Dict[str, Dict[str, Any]]:
    """
    Finds the best hyperparameters in all runs in a folder.

    :param folder_path:
        A str representing the folder path in which to look for runs.

    :param metric:
        (Optional) A str representing the key which to look at when determining
        what the best setup is. Defaults to "f1".

    :param mode:
        (Optional) A str representing the mode of how to look at a certain
        metric. Valid values are "high" and "low". Defaults to "high".


    :return:
        A Dict[str, Any] mapping rnn types to their best hyperparameters.
    """
    best_ones = dict()

    for folder_name in sorted(os.listdir(folder_path)):
        best_ones[folder_name] = find_best(os.path.join(folder_path,
                                                        folder_name),
                                           metric,
                                           mode)

    return best_ones

# endregion
