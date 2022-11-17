# -*- coding: cp1250 -*-
ulaz = open('./ulazni_niz.txt','r')
stanje=[[]]
d=0
dulj=0
duljina=0
definicija=[] #uodnosno ponudjene i trazene cijevi

#ucitavanje ulazne datoteke
for line in ulaz.readlines():
    stringLine=line.split()
    if d==0:
        dulj=len(stringLine) #do kuda su ponuđene cijevi
        d=1
    for i in range(len(stringLine)):
        definicija.append(int(stringLine[i]))

duljina=len(definicija) #ukupno koliko ima ponudjenih i trazenih cijevi
stanje[0]=definicija
stanje[0].append(0) #dubina prvog cvora = 0
n=0
novostnj=[]

# pretrazivanje stabla
while True:
    try:
        #print "Gledam cvor" ,stanje[n]
        m=n+1 #index novog cvora u listi/stablu
        for i in range(dulj):
            for j in range(dulj,duljina):                
                razlika=stanje[n][i]-stanje[n][j]                                
                if (razlika>=0) & ((stanje[n][j])!=0):   #ako se odreze dio cijevi               
                    novostnj=[]
                    for k in range(len(stanje[n])):
                                   novostnj.append(stanje[n][k])                 
                    novostnj[j]=0           #cijev koja je nadjena           
                    novostnj[i]=razlika     #koliko je ostalo od ponudjene cijevi
                    novostnj[duljina]=stanje[n][duljina]+1     #dubina cvora
                    stanje.append(novostnj)
                    #print "   dodajem cvor ",novostnj
                    m=m+1                    
        n=n+1
    except IndexError:
        print "sagradjeno je stablo"
        #print ". OOOps, ne gledam, gotovo gradjenje :D"
        break

print "\nZato sada trazim rjesenje..."
max=0    #max dubina
trazena=[]
trazCij=[]


#trazenje cvorova s najvecom dubinom(max), odnosno listova, spremaju se u trazena
for i in range(len(stanje)):
    if stanje[i][duljina]>max:
        trazena=[]
        trazena.append(i)
        max=max+1
    else:
        if stanje[i][duljina]==max:
            trazena.append(i)

opcija=[] #moguci nacin s kojim se mogu dobiti te cijevi
ista=0 
trazenaCij=[]   #cijevi koje se mogu dobiti na neki nacin

for i in range(len(trazena)):    
    for j in range(dulj,duljina):       #za svaki list radi listu s cijevima koje se moze dobiti
        if stanje[trazena[i]][j]==0:    #a posto u tim cvorovima dobivene cijevi imaju 0, moramo 
            opcija.append(stanje[0][j]) #vrijednost uzeti iz pocetnog cvora(ili definicije)
    opcija.sort()
    for j in range(len(trazCij)): #pazi da se ne dodaje ista kombinacija cijevi
        if trazCij[j]==opcija:
            ista=1
    if ista==0 :
        trazCij.append(opcija)
    ista=0
    opcija=[]
print "moze se dobiti ove cijevi na neki nacin: "
for i in trazCij:
    print i

