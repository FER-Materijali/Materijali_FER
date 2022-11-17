import re
import sys

podatci=[]
for line in sys.stdin.readlines():
    line.strip()
    if (len(line)>0):
        podatci.append(line)

def srediulaz(ulaz):
    rezultat=[]
    ulaz=ulaz.split("|")
    for niz in ulaz:
        niz=niz.strip()
        niz=niz.split(",")
        niz1=[]
        for znak in niz:
            niz1.append(znak)
        rezultat.append(niz1)
    return rezultat

def sredi(svastanja):
    svastanja=svastanja.strip()
    svastanja=svastanja.split(",")
    return svastanja

def generiraj(prijelazi):
    rezultat={}
    for prijelaz in prijelazi:
        prijelaz=prijelaz.strip()
        r=re.match("^(.+?),(.+?),(.+?)->(.+)$",prijelaz)
        trenutno=r.group(1)
        ulazzn=r.group(2)
        stog=r.group(3)
        iduce=r.group(4)
        rezultat[(trenutno,ulazzn,stog)]=iduce
    return rezultat

def simulacija(niz,tabprij,pocetno,pocznstog,prihvatljiva):
    rezultat=[]
    dodaj=[]
    stog=[]
    stog.append(pocznstog[0])
    pocetno=str(pocetno[0])
    
    dodaj=[pocetno,"#",stog[0]]
    
    trenutno=pocetno
    rezultat.append(dodaj)
    brojac=0
#ovdje je za znakove koji su u nizu
    while brojac<(len(niz)):
        znak=niz[brojac]
        dodaj=[]
        if (len(stog)):
            znstog=stog.pop()
        else:
            znstog="$"
        sljedeci=tabprij.get((trenutno,znak,znstog[0]),[])
        if (sljedeci==[]):
            sljedeci=tabprij.get((trenutno,"$",znstog[0]),[])
            brojac-=1
        if (sljedeci !=[]):
            sljedeci=sljedeci.strip()
            sljedeci=sljedeci.split(",")
            sljedecestanje=sljedeci[0]
            iducistog=sljedeci[1]
            ajmo=""
            ajmo1=""
            for zn in iducistog:
                ajmo=zn+ajmo
            for zn in stog:
                ajmo1+=zn
            ajmo1=ajmo1+ajmo
            stog=[]
            for zn in ajmo1:
                if zn != "$":
                    stog.append(zn)
            novo=""
            for zn in ajmo1:
                if zn !="$":
                    novo=zn + novo
            if (len(novo)==0):
                novo="$"
                stog=["$"]
            dodaj=[sljedecestanje,"#",novo]
            rezultat.append(dodaj)
            trenutno=sljedecestanje
        else:
            fail=[]
            fail.append("fail")
            rezultat.append(fail)
            negativ=["0"]
            rezultat.append(negativ)
            return rezultat
        brojac=brojac+1
    #ovdje su sad prazni prijelazi, ako vec nije u prihvatljivom
    if (trenutno in prihvatljiva):
            rezultat.append(["1"])
            return rezultat
    uvjet=1
    while (uvjet==1):
        dodaj=[]
        if (len(stog)):
            znstog=stog.pop()
        else:
            znstog="$"
        znak="$"
        sljedeci=tabprij.get((trenutno,znak,znstog[0]),[])
        if (sljedeci !=[]):
            sljedeci=sljedeci.strip()
            sljedeci=sljedeci.split(",")
            sljedecestanje=sljedeci[0]
            iducistog=sljedeci[1]
            ajmo=""
            ajmo1=""
            for zn in iducistog:
                ajmo=zn+ajmo
            for zn in stog:
                ajmo1+=zn
            ajmo1=ajmo1+ajmo
            stog=[]
            for zn in ajmo1:
                    stog.append(zn)
            novo=""
            for zn in ajmo1:
                    novo=zn + novo
            dodaj=[sljedecestanje,"#",novo]
            rezultat.append(dodaj)
            trenutno=sljedecestanje
        else:
            uvjet=0
    if (trenutno in prihvatljiva):
            rezultat.append(["1"])
    else:
        negativ=["0"]
        rezultat.append(negativ)
    return rezultat

def ispisuj(ispis):
    hjoj=""
    ajoj=""
    for niz in ispis:
        for skupic in niz:
            hjoj+=skupic
        hjoj+="|"
    for i in range(0,len(hjoj)-1):
        ajoj+=hjoj[i]
    print ajoj
    return
                   
#iznad f-je sve rade :D

ulaz=podatci[0]
ulaz=srediulaz(ulaz)
    
for niz in ulaz:
    svastanja=podatci[1]
    svastanja=sredi(svastanja)
    ulazniznakovi=podatci[2]
    ulazniznakovi=sredi(ulazniznakovi)
    znakstoga=podatci[3]
    znakstoga=sredi(znakstoga)
    prihvatljiva=podatci[4]
    prihvatljiva=sredi(prihvatljiva)
    pocetno=podatci[5]
    pocetnost=sredi(pocetno)
    tabprij=generiraj(podatci[7:])
    pocznstog=podatci[6]
    pocznstog=sredi(pocznstog)

    ispis=simulacija(niz,tabprij,pocetnost,pocznstog,prihvatljiva)
    ispisuj(ispis)
