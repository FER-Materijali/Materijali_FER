#!/usr/bin/env python

from numpy import *
from dataload import *

# Ne prijavljuj grešku dijeljenja s nulom.
seterr(divide='ignore')

# Sigmoidalna funkcija.
def sigmoid(a):
  return 1.0 / (1.0 + e**(-1.0*a))

# Računa vektor hipoteza.
def h(X, W):
  return sigmoid(X.dot(W))

# U slučaju NaN ili +-inf, zaokruži na prvi bliži stvarni broj.
def ln(v):
  return nan_to_num(log(v))

# Zaokruži: < 0.5 = 0, >= 0.5 = 1
def guess(H):
  return array(list(map(round, H)))

# Koliki je udio različitih elemenata dvaju vektora?
def diff(A, B):
  how_many = sum(list(map(abs, A-B)))
  percentage = float(how_many) / A.size
  return how_many, percentage * 100.0

# Regularizirana funkcija pogreške.
def E(W, X, Y, l=0):
  H = h(X, W)
  error = -Y.dot(ln(H)) -(1.0-Y).dot(ln(1.0-H))
  reg_term = l/2.0 * W[1:].dot(W[1:])
  return error + reg_term

# Nađi najbolju stopu učenja za dani korak
def best_lrate(W_0, grads, X, Y, l=0):
  lrate, dl = 0, 1e-3
  E_last = E(W_0, X, Y, l)
  W_i = W_0.copy()
  while True:
    lrate += dl
    W_i[1:] = W_0[1:] - lrate*grads[1:]
    E_i = E(W_i, X, Y, l)

    # Ako je greška dovoljno mala ili krenula rasti, imamo lrate.
    if abs(E_i - E_last) < 1e-6 or E_i > E_last:
      return lrate
    else:
      E_last = E_i

# Gradijentim spustom pronalazimo dobar vektor težina.
def descent(X, Y, l=0):
  W = starting_weights(X)
  W_old = W.copy()
  iters = 0

  for i in range(20):
    iters += 1
    grads = starting_weights(X)

    dist = h(X, W) - Y
    grads[0] += dist.sum()
    grads[1:] += dist.dot(X[:,1:])

    lrate = best_lrate(W, grads, X, Y)

    W[0] = W[0] - lrate*grads[0]
    W[1:] = W[1:]*(1-lrate*l) - lrate*grads[1:]

    # Ako je razlika u grešci dovoljno malena, prekidamo postupak.
    E_i, E_old = E(W, X, Y, l), E(W_old, X, Y, l)
    if abs(E_i - E_old) < 1e-5:
      W_old = W.copy()
      break

    W_old = W.copy()

  return W_old, iters

if __name__ == '__main__':
  from sys import argv
  if len(argv) < 3:
    exit("usage: python logreg.py /path/to/dataset /output/file")

  X, Y = load_dataset(argv[1])
  W, _ = descent(X, Y)
  print("E(w|D) =", E(W, X, Y, l=0))

  misses, percent = diff(guess(h(X, W)), guess(Y))
  print("Loše klasificirano", int(misses), "primjera ili", "%.2f%%." % percent)

  out = open(argv[2], 'w')
  for w_i in list(W): out.write('%f\n' % w_i)
  out.close()
