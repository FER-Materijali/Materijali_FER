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


import numpy as np
from sklearn import svm
from sklearn.metrics import confusion_matrix


class KSVMWrap:
    def __init__(self, x, y, c: float = 1., kernel="linear", gamma="auto"):
        self._classifier = svm.SVC(C=c, kernel=kernel, gamma=gamma)
        self.classifier.fit(x, y)

    @property
    def classifier(self):
        return self._classifier

    def predict(self, x):
        return self.classifier.predict(x)

    def get_scores(self, x):
        return self.classifier.decision_function(x)

    def support(self):
        return self.classifier.support_

    def eval_metrics(self, x, y_real, prefix: str or None = None):
        if prefix is None:
            prefix = ""

        y_pred = self.predict(x)
        y_real = np.array(y_real)

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
