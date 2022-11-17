#!/usr/bin/env python

from math import log

d = list(map(lambda l: l.split(), [
    'Istra da privatni 5 obitelj auto 4000 da',
    'Kvarner ne hotel 14 par auto 5000 ne',
    'Dalmacija da hotel 3 par avion 8000 da',
    'Dalmacija ne privatni 7 par avion 5000 ne',
    'Istra ne privatni 5 obitelj auto 6000 da',
    'Kvarner ne vlastiti 14 ekipa autobus 3000 ne',
    'Kvarner da kamp 7 ekipa autobus 2500 možda',
    'Dalmacija da hotel 7 ekipa auto 2000 da',
    'Istra ne privatni 5 obitelj auto 4500 da',
    'Kvarner ne hotel 14 ekipa auto 2500 ne',
    'Dalmacija ne kamp 21 par autobus 9000 možda',
    'Istra ne privatni 3 obitelj avion 9000 da',
    'Kvarner da hotel 14 par auto 4000 da',
    'Dalmacija ne vlastiti 14 par auto 3500 ne',
    'Istra ne vlastiti 5 par autobus 2000 možda'
]))

def y_is(y, l):
    return l[-1] == y

def take_by_y(y, d):
    return list(filter(lambda l: y_is(y, l), d))

def subset(i, v, d):
    return list(filter(lambda l: l[i] == v, d))

def how_many_y(y, d):
    return l(take_by_y(y, d))

def sum_for_each_y(d, f):
    s = 0
    for y in ['da', 'ne', 'možda']:
        dv = take_by_y(y, d)
        s += f(dv)
    return s

def vals_for(d, i):
    return list(set([l[i] for l in d]))

def log2(x):
    if x == 0: return 0
    else: return log(x) / log(2)

def e(d):
    return sum_for_each_y(d, lambda dv: -l(dv)/l(d)*log2(l(dv)/l(d)))

def l(d):
    return float(len(d))

def without_col(i, d):
    return [l[:i] + l[i+1:] for l in d]

def id(d, i):
    s = 0
    for v in vals_for(d, i):
        dv = subset(i, v, d)
        s += l(dv)/l(d)*e(dv)
    return e(d) - s

print('Za korijen:')
print('E(D)   =', e(d))
for i in range(7):
    print('I(D,%d) =' % i, id(d, i))

for cijena in '2500 2000 9000'.split():
    print('Za Cijena==%s:' % cijena)
    dv = without_col(6, subset(6, cijena, d))
    for i in range(6):
        print('I(D%s,%d) = %f' % (cijena, i, id(dv, i)))
