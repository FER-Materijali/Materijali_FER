import re
import sys

podatci=[]
for line in sys.stdin.readlines():
    line.strip()
    if (len(line)>0):
        podatci.append(line)

def sredi(svastanja):
    svastanja=svastanja.strip()
    svastanja=svastanja.split(",")
    return svastanja

def generiraj(prijelazi):
    rezultat={}
    for prijelaz in prijelazi:
        prijelaz=prijelaz.strip()
        r=re.match("^(.+?),(.+?)->(.+?)$",prijelaz)
        trenutno=r.group(1)
        znaktrake=r.group(2)
        iduce=r.group(3)
        rezultat[(trenutno,znaktrake)]=iduce
    return rezultat

#iznad f-je

svastanja=sredi(podatci[0])
ulaz=sredi(podatci[1])
znaktrake=sredi(podatci[2])
prazna=sredi(podatci[3])
trakas=sredi(podatci[4])
prihvatljiva=sredi(podatci[5])
pocst=sredi(podatci[6])
pocpol=sredi(podatci[7])
tabprij=generiraj(podatci[8:])
traka=""
for i in trakas:
    traka+=i

i=int (pocpol[0])
trenutno=pocst[0]
b=0

while (1):
    sljedeci=tabprij.get((trenutno,traka[i]),[])
    if sljedeci==[]:
        break
    else:
        sljedeci=sljedeci.strip()
        sljedeci=sljedeci.split(",")
        iduce=sljedeci[0]
        if sljedeci[2]=='L' and i==0:
            break
        elif sljedeci[2]=='R' and i==69:
            break
        elif sljedeci[2]=='L':
            b=i-1
        else:
            b=i+1
    trenutno=iduce
    straka=""
    for j in range(0,len(traka)):
        if j==i:
            straka+=str (sljedeci[1])
        else:
            straka+=traka[j]
    i=b
    traka=straka

if trenutno in prihvatljiva:
    rez=1
else:
    rez=0
rezultat=""
rezultat=str (trenutno)+"|"+str(i)+"|"+traka+"|"+str (rez)

print rezultat


