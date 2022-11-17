import re
import sys
from collections import defaultdict

podatci=[]
for line in sys.stdin.readlines():
    line=line.strip()
    if (len(line)>0):
        podatci.append(line)
odnosi = defaultdict(list)
polje = defaultdict(lambda: False)

def tablicaprijelaza(prijelazi):
    rezultat={}
    for prijelaz in prijelazi:
        r=re.match("^(.+?),(.+?)->(.+)$",prijelaz)
        sadasnje=r.group(1)
        znak=r.group(2)
        iduce=r.group(3)
        rezultat[(sadasnje,znak)]=iduce
      
    return rezultat

def nadjidohvatljiva(transitionDict, symbols, initial):
    dohvatljiva = []
    zaprobat = [pocetno]

    while (len(zaprobat)):
        trenutno = zaprobat.pop()

        if (trenutno not in dohvatljiva):
            dohvatljiva.append(trenutno)

            for znak in znakovi:
                zaprobat.append(tabprij[(trenutno, znak)])
    dohvatljiva.sort()
    return dohvatljiva

def nadjidohvprij(tabprij, dohvatljiva):
    dohvatljiviprij = {}
    stanje=[]
    for stanje in tabprij:
        if stanje[0] in dohvatljiva:
            dohvatljiviprij[stanje] = tabprij[stanje]

    return dohvatljiviprij

def rekurzivnooznaci(par):
    polje[par] = True

    for relation in odnosi[par]:
        if not polje[relation]:
            rekurzivnooznaci(relation)

    odnosi[par] = []
    return

def minimiziraj(tabprij, stanja, zavrsna):
    for p in stanja:
        for q in stanja:
            if p != q and (not p in zavrsna and q in zavrsna or p in zavrsna and not q in zavrsna):
                polje[(p, q)] = True

    for p in stanja:
        for q in stanja:
            if (p in zavrsna and q in zavrsna or not (p in zavrsna) and not (q in zavrsna)):
        
                oznacen = False
  
                for a in znakovi:
                    if polje[(tabprij[(p, a)], tabprij[(q, a)])]:
                        oznacen = True

                if oznacen:
                    rekurzivnooznaci((p, q))
                else:
                    for a in znakovi:
                        if tabprij[(p, a)] != tabprij[(q, a)]:
                            odnosi[(tabprij[(p, a)], tabprij[(q, a)])].append((p, q))

    istovjetna = []
    for p in stanja:
        for q in stanja:
            if p != q and not polje[(p, q)]:
                nadjen = False

                for item in istovjetna:
                    if p in item or q in item:
                        item.append(p)
                        item.append(q)
                        nadjen = True

                if not nadjen:
                    istovjetna.append([p, q])
    
    rezultat = {}
    for istovjetna in [sorted(list(set(item))) for item in istovjetna]:
        for item in istovjetna:
            rezultat[item] = istovjetna[0]

    return rezultat

def zamijenielemente(istovjetna, stanja):
    nova = []

    for element in stanja:
        if element in istovjetna:
            nova.append(istovjetna[element])
        else:
            nova.append(element)
    
    nova=list(set(nova))
    nova.sort()
    return nova

def izbacidupla (stanja):
    ovo=[]
    for i in stanja:
        if i not in ovo:
            ovo.append(i)
    return ovo

def zamijenitabprij(istovjetna, dohvtabprij):
    novo = {}

    for stanje in dohvtabprij:
        kljuc = stanje
        st = dohvtabprij[stanje]

        if dohvtabprij[stanje] in istovjetna:
            st = istovjetna[dohvtabprij[stanje]] 

        if stanje[0] in istovjetna:
            kljuc = (istovjetna[stanje[0]], stanje[1])

        novo[kljuc] = st

    return novo


stanja = podatci[0].split(",")
znakovi = podatci[1].split(",")
znakovi.sort()
zavrsna = podatci[2].split(",")
pocetno = podatci[3]
tabprij = tablicaprijelaza(podatci[4:])

dohvatljiva = nadjidohvatljiva(tabprij, znakovi, pocetno)
dohvatljivafinalna = []
for stanje in zavrsna:
    if stanje in dohvatljiva:
        dohvatljivafinalna.append(stanje)
dohvatljivafinalna.sort()

dohvtabprij = nadjidohvprij(tabprij, dohvatljiva)

istovjetna = minimiziraj(dohvtabprij, dohvatljiva, zavrsna)
novastanja = zamijenielemente(istovjetna, dohvatljiva)
novafinalna = zamijenielemente(istovjetna, dohvatljivafinalna)
novopocetno = zamijenielemente(istovjetna, [pocetno])[0]
novatabprij = zamijenitabprij(istovjetna, dohvtabprij)  
  
print (",".join(novastanja))
print (",".join(znakovi))
print (",".join(novafinalna))
print (novopocetno)
for stanje in novastanja:
    for znak in znakovi:
        print ("{},{}->{}".format(stanje, znak, novatabprij[(stanje, znak)]))


  
