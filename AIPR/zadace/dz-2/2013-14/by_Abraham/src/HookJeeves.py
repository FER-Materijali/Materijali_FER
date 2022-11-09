'''
Created on 28. 11. 2013.

@author: Abraham
'''
import Funkcije as F
# import math

#  poziv funkcije koja se racuna
def f(x):
    if (funkcija==1):
        return F.f1(x)
    if (funkcija==2):
        return F.f2(x)
    if (funkcija==3):
        return F.f3(x,p)
    if (funkcija==4):
        return F.f4(x)
    
# ----- unos podataka
file = open( "Hook.txt", 'r')
X0 = []
for line in file:
    el = line.split()
    try:
        if el[0] == 'f':
            funkcija = int(el[1])
        if el[0] == 'dx':
            dx = float(el[1])
        if el[0] == 'e':
            e = float(el[1])
        if el[0] == 'X0':
            for i in range(1, len(el)):
                X0.append(float(el[i]))
    except:
        print ("unos gotov")
pfile = open( "P.txt", 'r')
p = pfile.readline()
p=p.split()
for i in range(len(p)):
    p[i] = float(p[i])
# ------- gotov unos podataka



def istrazi(x):
    F = f(x)
    xs=x.copy()
    for i in range(len(x)):
        xs[i] += dx
        N = f(xs)
        if (N>F):
            xs[i] -= 2*dx
            N = f(xs)
            if (N>F):
                xs[i] += dx
    return xs


# ---------------   ALGORITAM     ----------------
# dx, e
xB = X0.copy()
xP = X0.copy()
while ( dx > e):
    print(xB)
    xN = istrazi(xP)
    if ( f(xN) < f(xB)):
        for i in range(len(xP)):
            xP[i] = 2*xN[i] - xB[i]
        xB = xN.copy()
    else:
        dx /= 2.
        xP = xB.copy()

print ( "Rj: "+ str(xB).strip("[").strip("]"))