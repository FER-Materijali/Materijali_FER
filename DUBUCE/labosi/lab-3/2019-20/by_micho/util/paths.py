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

import os

#   PATHS ARE RELATIVE TO THE PROJECT ROOT
#
#       This doesn't bother us since we'll change our directory to the project
#       root anyways.

EMBEDDINGS_PATH = "data/embeddings_300-d.txt"
EMBEDDINGS_MATRIX_PATH = "data/embedding-matrix.npy"

TRAIN_CSV_PATH = "data/train.csv"
VAL_CSV_PATH = "data/val.csv"
TEST_CSV_PATH = "data/test.csv"

DEFAULT_SAVE_TASK2 = "results/task_2"
DEFAULT_SAVE_TASK3 = "results/task_3"
DEFAULT_SAVE_TASK4 = "results/task_4"
DEFAULT_SAVE_TASK4_1 = os.path.join(DEFAULT_SAVE_TASK4, "part-1")
DEFAULT_SAVE_TASK4_2 = os.path.join(DEFAULT_SAVE_TASK4, "part-2")
