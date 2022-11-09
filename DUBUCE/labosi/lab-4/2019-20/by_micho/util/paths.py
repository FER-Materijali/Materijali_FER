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
# Keep in mind this is relative to the project root.

DEFAULT_MNIST_FOLDER = "data"
DEFAULT_MNIST_PATH = f"{DEFAULT_MNIST_FOLDER}/MNIST"

DEFAULT_SAVE_TASK4 = "data/task-4"
DEFAULT_SAVE_TASK5 = "data/task-5"

DEFAULT_WEIGHTS_FOLDER_TASK4 = "models/task-4"
VAE20_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK4}/vae20.pt"
VAE02_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK4}/vae02.pt"
VAE20_WEIGHTS_UNMODDED_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK4}/vae20unmod.pt"
VAE02_WEIGHTS_UNMODDED_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK4}/vae02unmod.pt"

DEFAULT_WEIGHTS_FOLDER_TASK5 = "models/task-5"
GAN21_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK5}/gan21.pt"
GAN12_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK5}/gan12.pt"
GAN11BN_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK5}/gan11bn.pt"
GAN21BN_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK5}/gan21bn.pt"
GAN12BN_WEIGHTS_PATH = f"{DEFAULT_WEIGHTS_FOLDER_TASK5}/gan12bn.pt"
