'''
Created on 30. 11. 2013.

@author: Abraham
'''
import Funkcije as F
import  sys
import random
import time


print("Algoritam po Boxu pokrenut!")
# --------  unos e, a, poc. X0, te r.br. f-je "funkcija" // 
file = open( "Box.txt", 'r')
X0 = []
n, funkcija, a, e = 0, 0., 0., 0.
for line in file:
    el = line.split()
    try:
        if el[0] == 'f':
            funkcija = int(el[1])
        if el[0] == 'a':
            a = float(el[1])
        if el[0] == 'e':
            e = float(el[1])
        if el[0] == 'X0':
            for i in range(1, len(el)):
                X0.append(float(el[i]))
            n = int(len(X0))
    except:
        print ("unos gotov")
pfile = open( "P.txt", 'r')
p = pfile.readline()
p=p.split()
for i in range(len(p)):
    p[i] = float(p[i])
    


#  poziv funkcije koja se racuna
def f(x):
    if (funkcija==2):
        return F.f2(x)
    if (funkcija==3):
        return F.f3(x,p)
    if (funkcija==4):
        return F.f4(x)
    

# expl [-100,100]
def zadovoljavaEksplicitna(x):
    OK = True
    for i in range(n):
        if (x[i] > 100.) or (x[i] < -100.):
            OK = False
    return OK

# implicitna ogranicenja: (x1-x2 <= 0), (x1-2 <= 0)
def zadovoljavaImplicitna(x):
    OK = True
    if (x[0]-x[1])>0 :
        OK = False
    if (x[0]-2. > 0):
        OK = False
    return OK

def zadovoljavaSvaOgranicenja(x):
    return zadovoljavaEksplicitna(x) and zadovoljavaImplicitna(x)

def pomakniPremaCentroiduPrihvacenih(x, el):
    Xc = [0.]*n 
    Nc = 0.
    for k in range(len(x)): #za sve X
        if zadovoljavaSvaOgranicenja( x[k] ):
            for i in range(n):
                Xc[i] += x[k][i]
            Nc+=1.
    for i in range(n):
        Xc[i] /=Nc
    while (not(zadovoljavaImplicitna(el))):
        for i in range(n):
            el[i] = 0.5* (Xc[i]+el[i])
    return el
def pomakniPremaCentroidu(x, xc):
    for i in range(n):
        x[i] = 0.5 * ( x[i] + xc[i])
    return x


def vratiNajlosiju(x):
    F= sys.float_info.min
    index = 0.
    for k in range(len(x)):
        if ( f(x[k]) > F):
            F = f(x[k])
            index = k
    return index
def refleksija(xh, xc):
    xr = xc.copy()
    for i in range(n):
        xr[i] = (1 + a) * xc[i] - a * xh[i]
    return xr
def centroidBezH(x, h):
    xc = [0.]*n 
    Nc = 0.
    for k in range(len(x)): #za sve X
        if ( k != h ):
            for i in range(n):
                xc[i] += x[k][i]
            Nc+=1.
    for i in range(n):
        xc[i] /= Nc
    return xc
def provjeriUvjet(x, xc, h):
    u = False
    for i in range(n):
        if (abs(x[h][i]-xc[i]) > e):
                    u = True
    return u


    

print("a:" + str(a))
    
# --------------- ALGORITAM BOX ---------------

X = [] # generiranje simplexa
if (not zadovoljavaSvaOgranicenja(X0)):
    print ("Pocetna tocka pretrazivanja ne zadovoljava sva ogranicenja!!!")    
X.append(X0)
Xc = X0.copy()
for k in range (1, 2*n):
    el=[]
    for i in range(n):
        el.append(-100. + random.random() * 200.)

#provjera implicitnih ogranicenja za simplex X
    while (not zadovoljavaSvaOgranicenja(el)):
        el = pomakniPremaCentroiduPrihvacenih(X, el)
    X.append(el)
    
for i in range(len(X)):
    print(zadovoljavaSvaOgranicenja(X[i]))
    print(X[i])
#dalje = input("jel ok?")

# algoritam
startTime = time.time()
uvjet = True
while(uvjet):
    h = vratiNajlosiju(X)
    Xc = centroidBezH(X, h)
    Xr = refleksija(X[h], Xc)
    print(Xc)
    #===========================================================================
    # print(X)
    # print (Xc)
    # print(X[h])
    # print(Xr)
    # input()
    #===========================================================================
    
    if (not zadovoljavaEksplicitna(Xr)):
        for i in range(n):
            if ( Xr[i]<-100.):
                Xr[i] = -100.
            if ( Xr[i]>100.):
                Xr[i] = 100.
    while ( not zadovoljavaSvaOgranicenja(Xr)):
        Xr = pomakniPremaCentroidu(Xr, Xc)
    if (f(Xr) > f(X[h])):
        Xr = pomakniPremaCentroidu(Xr, Xc)
    for i in range(n):
        X[h][i] = Xr[i]
    uvjet = provjeriUvjet(X, Xc, h)

print("Algoritam je zavrsio u: " + str(-startTime+time.time()) + " sekundi.")
print("Nadjeni minimum je tocka: " + str(Xc))






