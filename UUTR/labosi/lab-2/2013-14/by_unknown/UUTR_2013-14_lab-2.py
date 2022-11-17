import sys,os

def spoji(nespojeniParovi):
    i=0
    j=0

    while(i < len(nespojeniParovi)):
        if (i+1 < len(nespojeniParovi)):
            j = i+1

            while(j < len(nespojeniParovi)):

                    presjek = []
                    for stanje in nespojeniParovi[i]:
                        if (stanje in nespojeniParovi[j]):
                            presjek.append(stanje)
                    presjek = sorted(presjek)
                    if (presjek != []):
                       
                        nespojeniParovi[i]+=nespojeniParovi[j]
                        nespojeniParovi[i]=sorted(list(set(nespojeniParovi[i])))
                        nespojeniParovi.remove(nespojeniParovi[j])
                    else:
                        j+=1
        i+=1
    return nespojeniParovi

def vratiNeistovjetne(nepodudarniParovi):
    for parStanja in podudarniParovi:
        stanje1 = parStanja[0]
        stanje2 = parStanja[1]
        nalaziSe = 0
        for simbol in skupSimbola:
            if ((stanje1,simbol) in rjecnikPrijelaza) and ((stanje2,simbol) in rjecnikPrijelaza):
                parStanja2 = sorted([rjecnikPrijelaza[(stanje1,simbol)],rjecnikPrijelaza[(stanje2,simbol)]])
                if parStanja2 in nepodudarniParovi:
                    nalaziSe = 1
        if (nalaziSe):
            nalaziSe= 0
            
            nepodudarniParovi.append(parStanja)
            if(listaStanja != []):
                for parovi in listaStanja:
                    if (parStanja in parovi):
                        for parPom in parovi:
                            if (parPom not in nepodudarniParovi):
                                nepodudarniParovi.append(parPom[0])
                        break
        else:
            for simbol in skupSimbola:
                if (((stanje1,simbol) in rjecnikPrijelaza)and((stanje2,simbol) in rjecnikPrijelaza)):
                    
                    if (rjecnikPrijelaza[stanje1,simbol] != rjecnikPrijelaza[(stanje2,simbol)]):
                        razlicito = 1
                        for i in range(len(listaStanja)):
                            if (sorted([rjecnikPrijelaza[stanje1,simbol],rjecnikPrijelaza[stanje2,simbol]]) in listaStanja[i]):
                                if (parStanja not in listaStanja[i]):
                                    listaStanja[i]+=[parStanja]
                                razlicito = 0
                    if(razlicito):
                        listaStanja.append([[rjecnikPrijelaza[stanje1,simbol],rjecnikPrijelaza[stanje2,simbol]],parStanja])
    return nepodudarniParovi

ulaz = [linija.rstrip() for linija in sys.stdin.readlines()]
liste = [linija.split(',') for linija in ulaz[:4]]
skupStanja = liste[0]
skupSimbola = liste[1]
prihvatljivaStanja = liste[2]
pocetnoStanje = liste[3][0]
dohvatljivaStanja = liste[3]
rjecnikPrijelaza = {}
for prijelaz in ulaz[4:]:
    kljuc = prijelaz.split('->')[0].split(',')
    stanje = prijelaz.split('->')[1]
    rjecnikPrijelaza[tuple(kljuc)] = stanje

for stanje in dohvatljivaStanja:
    for simbol in skupSimbola:
        kljuc = stanje,simbol
        if (kljuc in rjecnikPrijelaza) and (rjecnikPrijelaza[kljuc] not in dohvatljivaStanja):
            dohvatljivaStanja += [rjecnikPrijelaza[kljuc]]
skupStanja = sorted(dohvatljivaStanja)
prihvatljivaStanja = [stanje for stanje in prihvatljivaStanja if stanje in dohvatljivaStanja]
for kljuc in sorted(rjecnikPrijelaza):
    if kljuc[0] not in dohvatljivaStanja:
        del(rjecnikPrijelaza[kljuc])
neprihvatljivaStanja = [stanje for stanje in dohvatljivaStanja if stanje not in prihvatljivaStanja]

nepriStanja = [neprihvatljivaStanja,prihvatljivaStanja]

podudarniParovi = []
for stanja in nepriStanja:
    for i in range(len(stanja)):
        if(i+1<len(stanja)):
            for j in range(i+1,len(stanja)):
                podudarniParovi.append(sorted([stanja[i],stanja[j]]))

nepodudarniParovi = []
for i in range(len(prihvatljivaStanja)):
    for j in range(len(neprihvatljivaStanja)):
        nepodudarniParovi.append(sorted([prihvatljivaStanja[i],neprihvatljivaStanja[j]]))

listaStanja = []

nepodudarniParovi = vratiNeistovjetne(nepodudarniParovi)
while(nepodudarniParovi != vratiNeistovjetne(nepodudarniParovi)):
    nepodudarniParovi = vratiNeistovjetne(nepodudarniParovi)

nespojeniParovi = [parStanja for parStanja in podudarniParovi if parStanja not in nepodudarniParovi]

nespojeniParovi = spoji(nespojeniParovi)
while(nespojeniParovi!=spoji(nespojeniParovi)):
    nespojeniParovi = spoji(nespojeniParovi)



for stanja in skupStanja:
    nalaziSe = 0

    for parStanja in nespojeniParovi:
        if (stanja in parStanja):
            nalaziSe = 1

    if(nalaziSe == 0):
        nespojeniParovi.append([stanja])

nespojeniParovi = [sorted(stanja) for stanja in sorted(nespojeniParovi)]
listaMicanje=[]  

for stanja in nespojeniParovi:
    if (len(stanja) > 1):
        listaMicanje += stanja[1:]
for stanje in listaMicanje:
    skupStanja.remove(stanje)
    if (stanje in prihvatljivaStanja):
        prihvatljivaStanja.remove(stanje)

    for kljuc in sorted(rjecnikPrijelaza):
        if(kljuc[0] == stanje):
            del(rjecnikPrijelaza[kljuc])
for kljuc in rjecnikPrijelaza:
    if(rjecnikPrijelaza[kljuc] in listaMicanje):
        for stanja in nespojeniParovi:
            if(rjecnikPrijelaza[kljuc]in stanja):
                rjecnikPrijelaza[kljuc] = stanja[0]
if (pocetnoStanje in listaMicanje):
    for stanja in nespojeniParovi:
        if(pocetnoStanje in stanja):
            pocetnoStanje=stanja[0]
            
izlazLista = [','.join(sorted(skupStanja)),','.join(sorted(skupSimbola)),','.join(sorted(prihvatljivaStanja)),pocetnoStanje]
for prijelaz in sorted(rjecnikPrijelaza):
    izlazLista+= [prijelaz[0]+','+prijelaz[1]+'->'+rjecnikPrijelaza[prijelaz]]
sys.stdout.write('\n'.join(izlazLista)+'\n')
