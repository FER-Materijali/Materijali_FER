#!/usr/bin/env python

from numpy import *
from dataload import load_dataset
from logreg import *

lambdas = '0 0.01 0.02 0.05 0.1 0.2 0.5 1 2 5 10 20'.split()
lambdas = map(longdouble, lambdas)

if __name__ == '__main__':
  from sys import argv
  if len(argv) < 3:
    exit("usage: python bestlambda.py /train/set /validation/set")

  Xt, Yt = load_dataset(argv[1])
  Yt = guess(Yt)
  Xv, Yv = load_dataset(argv[2])
  Yv = guess(Yv)

  for l in lambdas:
    print("Lambda", l, ":\t E =", end=' ')
    W, iters = descent(Xt, Yt, l)
    print(E(W, Xv, Yv, l), "u", iters, "koraka.")

    misses, percent = diff(guess(h(Xv, W)), Yv)
    print("Misclassified:\t", int(misses), "primjera ili", "%.3f%%" % percent)
