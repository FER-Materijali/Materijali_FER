import fileinput
import re

ulaz = fileinput.input()

ulazninizovi = [x.strip().split(',') for x in ulaz.readline().split('|')]
skupstanja = ulaz.readline().split(',')
simboli = ulaz.readline().split(',')
pstanje = ulaz.readline().split(',')
pocetno = ulaz.readline().strip()

prijelaz = {}
for red in ulaz:
    lin = re.match(r'(.*),(.*)->(.*)',red) # u lin sam stavio jedan prijelaz
    if lin.group(3) == '#':
        continue

    trenutno = lin.group(1) # trenutno stanje
    ulazsimbol = lin.group(2) # ulazni simbol
    sljstanje = lin.group(3).split(',') # sljedece stanje
    prijelaz[(trenutno,ulazsimbol)] = sljstanje


def okolina(x, posjeceni = None): # okolina za epsilon stanja
    if(posjeceni == None):
        posjeceni = []
    rezultat = []
    eprijelaz = prijelaz.get((x,'$'),[])
    posjeceni.append(x)
    if not eprijelaz:
        return []
    for y in eprijelaz :
        rezultat.append(y)
        if y in posjeceni:
            continue

        for o in okolina(y,posjeceni):
            rezultat.append(o)
    return rezultat



for listaznakova in ulazninizovi: # ucitali listu znakova
    stanje = okolina(pocetno)
    stanje.append(pocetno)



    log = [stanje]
    for znak in listaznakova: # ucitavamo znak
        iducastanja = set()
        for stanjeporedu in stanje: # ucitavam stanje po stanje, idem redom po pocetnim stanjima
            listaepsilona = []
            sljstanje = prijelaz.get((stanjeporedu,znak), []) # provjere

            for nstanje in sljstanje: #ovdje trazim epsilone
                eeokolina = okolina(nstanje)
                for element in eeokolina:
                    listaepsilona.append(element)
            iducastanja1 = set(sljstanje).union(set(listaepsilona))
            iducastanja = iducastanja.union(iducastanja1)
        log.append(iducastanja)
        stanje = iducastanja



    print '|'.join(','.join(sorted(set(x))) if x else '#' for x in log)













