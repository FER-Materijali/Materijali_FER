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

from typing import Any, Dict, List, Tuple

import numpy as np


def get_random_params(range_dict: Dict[str, Tuple[Any, Any]],
                      force_dict: Dict[str, Tuple] = None,
                      amount: int = 1) -> List[Dict[str, Any]]:
    """
    Generates random parameters.

    :param range_dict:
        A Dict[str, Tuple[Any, Any]] mapping parameter names to their numerical
        ranges.

    :param force_dict:
        (Optional) A Dict[str, Tuple] mapping parameter names to all their
        possible values. For every value a copy of the range_dict-generated
        parameter dict is created (or in other words, every possibility in a
        force dict branches into a version which has the range_dict-generated
        parameters as base. Defaults to None.

    :param amount:
        (Optional) A int representing the number of random samples drawn when
        generating range_dict based parameters. Defaults to 1.


    :return:
        A List[Dict[str, Any]] containing the list of different parameter
        configurations randomly generated given the ranges passed as arguments.
    """
    params_list = list()

    if range_dict is not None:
        for _ in range(amount):
            params = dict()

            for key, value in range_dict.items():
                if isinstance(value[0], int):
                    params[key] = np.random.randint(*value)
                elif isinstance(value[0], float):
                    params[key] = np.random.uniform(*value)

            params_list.append(params)

    if force_dict is not None:
        for key, value in force_dict.items():
            t_params_list = list()

            for subvalue in value:
                for params in params_list:
                    params[key] = subvalue
                    t_params_list.append(dict(params))

            params_list = list(t_params_list)

    return params_list
