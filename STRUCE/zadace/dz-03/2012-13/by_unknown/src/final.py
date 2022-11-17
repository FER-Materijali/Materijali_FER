#!/usr/bin/env python

from numpy import *
from logreg import *

if __name__ == '__main__':
  from sys import argv

  Xt, Yt = load_dataset('train-set.txt')
  Xv, Yv = load_dataset('validation-set.txt')
  X = append(Xt, Xv, axis=0)
  Y = append(Yt, Yv, axis=0)
  W, _ = descent(X, Y)
  print("E(w|D) =", E(W, X, Y, l=0))

  out = open('tezine2.txt', 'w')
  for w_i in list(W): out.write('%f\n' % w_i)
  out.close()

  Xtest, Ytest = load_dataset('test-set.txt')
  misses, percent = diff(guess(h(Xtest, W)), guess(Ytest))
  print("Loše klasificirano", int(misses), "primjera ili", "%.2f%%." % percent)

  rjecnik = open('rjecnik.txt', 'r').read().splitlines()
  bigst_w = list(reversed(sorted(zip(W[1:], range(W[1:].size)))))

  for w, i in bigst_w[:20]:
    print(rjecnik[i].split()[0])
