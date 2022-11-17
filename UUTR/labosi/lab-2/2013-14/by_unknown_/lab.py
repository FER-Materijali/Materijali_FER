import sys
import re


podatci=[]
for line in sys.stdin.readlines():
    line=line.strip()
    if (len(line)>0):
        podatci.append(line)

def tablicaprijelaza(prijelazi):
    rezultat={}
    for prijelaz in prijelazi:
        r=re.match("^(.+?),(.+?)->(.+)$",prijelaz)
        sadasnje=r.group(1)
        znak=r.group(2)
        iduce=r.group(3)
        rezultat[(sadasnje,znak)]=iduce
      
    return rezultat

def izbaciduple (rezultat):
    ovo=[]
    for i in rezultat:
        if i not in ovo:
            ovo.append(i)
    return ovo

def izbacinedohvatljiva(prijelazi,svastanja,tabprij):
    rezultat=[]
    iduca=[]
    trenutna=[]
    for prijelaz in prijelazi:
        r=re.match("^(.+?),(.+?)->(.+)$",prijelaz)
        sadasnje=r.group(1)
        znak=r.group(2)
        iduce=r.group(3)
        iduca.append(iduce)
        trenutna.append(sadasnje)
    trenutna.sort()
    trenutna=izbaciduple(trenutna)

    iduca.sort()
    iduca=izbaciduple(iduca)

    print "ovo su trenutna",trenutna
    print "ovo su iduca", iduca
    for stanje in trenutna:
        if stanje in iduca:
            rezultat.append(stanje)
            
   # for stanje in rezultat:
    #    c='c'
     #   d='d'
      #  rez1=tabprij[(stanje,c)]
       # rez2=tabprij[(stanje,d)]
        
    #fali da ako iz nedohvatljivog ide u nedohvatljiva i to makne
    rezultat.sort()
    rezultat=izbaciduple(rezultat)
    
    return rezultat

dohvatljiva=[]

svastanja=podatci[0]
svastanja=svastanja.split(",")

tabprij=tablicaprijelaza(podatci[4:])

dohvatljiva=izbacinedohvatljiva(podatci[4:],svastanja,tabprij)
dohvatljiva.append(podatci[3])
dohvatljiva=izbaciduple(dohvatljiva)
dohvatljiva.sort()


print svastanja
print
print dohvatljiva

