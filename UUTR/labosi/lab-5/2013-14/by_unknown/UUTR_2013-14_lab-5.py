
import fileinput
import re

ulaz = fileinput.input()

skupstanja = ulaz.readline().split(',') # skup stanja odvojenih zarezom
ulazniznakovi = ulaz.readline().split(',') # ulazni znakovi
znaktraka = ulaz.readline().split(',') # znakovi trake
prazna = ulaz.readline().rstrip() # oznaka prazne celije
zapistrake = ulaz.readline().rstrip() # zapis trake stroja
prihvatljiva = ulaz.readline().split(',') # prihvatljiva
pocetno = ulaz.readline().rstrip() # pocetno stanje
glava = ulaz.readline().rstrip() # pocetno stanje glave

prihvatljiva[-1]=prihvatljiva[-1].strip()

listatraka = []
for svaki in zapistrake:
    listatraka.append(svaki)




prijelazi = {} # matematicki skup za prijelaze
for prijelaz in ulaz: #ucitaj u prijelaz novi prijelaz
    linija = re.match(r'(.*),(.*)->(.*),(.*),(.*)', prijelaz)
    if linija is None:
        continue

    trenutnos=linija.group(1) # trenutno
    trakaz=linija.group(2) # trenutno na traci
    novos=linija.group(3) # novo stanje
    zapisz=linija.group(4) # zapis na traku
    pomak=linija.group(5) # pomak glave

    prijelazi[(trenutnos,trakaz)] = [novos,zapisz,pomak]

pozicija = int(glava)
novo = []


while (1):

    novo = prijelazi.get((pocetno,listatraka[pozicija]))
    #print pocetno, listatraka[pozicija]
    #print novo
    #raw_input("SVAKI KRUG")


    if novo is None:

        if pocetno in prihvatljiva:
            lista = [pocetno,str(pozicija),''.join(listatraka),str(1)]
            print '|'.join(lista)
        else:
            lista = [pocetno,str(pozicija),''.join(listatraka),str(0)]
            print '|'.join(lista)


        break


    elif pozicija == 0 and novo[2] == 'L':

        if pocetno in prihvatljiva:
            lista = [pocetno,str(pozicija),''.join(listatraka),str(1)]
            print '|'.join(lista)
        else:
            lista = [pocetno,str(pozicija),''.join(listatraka),str(0)]
            print '|'.join(lista)

        break

    elif pozicija == 69 and novo[2] == 'R':
        if pocetno in prihvatljiva:
            lista = [pocetno,str(pozicija),''.join(listatraka),str(1)]
            print '|'.join(lista)
        else:
            lista = [pocetno,str(pozicija),''.join(listatraka),str(0)]
            print '|'.join(lista)

        break


    else:
        pocetno = novo[0]
        listatraka[pozicija]= novo[1]
        if novo[2]== 'R':
            pozicija = (pozicija+1)
        else:
            pozicija = (pozicija-1)












