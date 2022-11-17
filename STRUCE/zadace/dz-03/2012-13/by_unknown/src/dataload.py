from numpy import *

try:
  rjecnik = open('rjecnik.txt', 'r').read().splitlines()
except:
  exit("Couldn't find rjecnik.txt, exiting")

# Učitava skup podataka, odvaja X od Y, dodaje značajku x_0 = 1.
def load_dataset(path):
  num_feats = len(rjecnik)
  file_lines = open(path, 'r').read().splitlines()

  # Inicijaliziramo matrice.
  X = zeros((len(file_lines), 1 + num_feats))
  Y = zeros(len(file_lines))

  for j, line in zip(range(len(file_lines)), file_lines):
    words = line.split()

    # Prvi stupac uvijek je oznaka klase.
    Y[j] = longdouble(words[0])

    # Prva značajka uvijek je 1.
    X[j, 0] = 1.0

    for word in words[1:]:
      i, val = word.split(':')
      X[j, int(i)+1] = longdouble(val)

  return X, Y

# Početan ~W, sve nule.
def starting_weights(X):
  _, num_feats = X.shape
  return zeros(num_feats)

if __name__ == '__main__':
  from sys import argv
  X, Y = load_dataset(argv[1])
  print("Loaded X", X.shape, "and Y", Y.shape)
