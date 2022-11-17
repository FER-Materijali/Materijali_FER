import fileinput
import re

ulaz = fileinput.input()

ulazninizovi = [x.strip().split(',') for x in ulaz.readline().split('|')] # ulazni niz
skupstanja = ulaz.readline().split(',') # skup stanja odvojenih zarezom
simboli = ulaz.readline().split(',') # ulazni znakovi
znakovistog = ulaz.readline().split(',') # skup znakova stoga
prihvatljivo = ulaz.readline().split(',') # skup prihvatljivih stanja
pocetno1 = ulaz.readline().strip() # pocetno stanje
pstog = ulaz.readline().strip() # pocetni znak stoga


pocetno = pocetno1
prihvatljivo = prihvatljivo[0].rstrip()

prijelaz = {} # ovdje dodajem funkcije prijelaza
for red in ulaz:
    lin = re.match(r'(.*),(.*),(.*)->(.*),(.*)',red) # u lin sam stavio jedan prijelaz
    if lin is None:
        continue



    trenutno = lin.group(1) # trenutno stanje
    ulazniznak = lin.group(2) # ulazni simbol
    znakstog = lin.group(3) # znak stoga
    novostanje = lin.group(4) # novo stanje
    nizstog = lin.group(5) # niz stoga


    prijelaz[(trenutno,ulazniznak,znakstog)] = [novostanje,nizstog]
eokolina = []
listastog = []
listastog.append(pstog)
i = 0
#log = []
#log.append(('{0}#{1}'.format(pocetno,''.join(listastog))))
for niz in ulazninizovi: # ucitavam prvi niz
    log = []
    log.append(('{0}#{1}'.format(pocetno,''.join(listastog))))

    for znak in niz: # ucitavam prvi znak
        i=0
        #print ('{0}#{1}'.format(pocetno,''.join(listastog)))
        #log.append(('{0}#{1}'.format(pocetno,''.join(listastog))))
        sljedece = prijelaz.get((pocetno, znak, listastog[0]))
        #print sljedece
        #raw_input("SLJEDECE ZA Znak")

        if sljedece is None:
                eokolina = prijelaz.get((pocetno, "$", listastog[0]))
                while (eokolina):
                    i=+1
                    pocetno = eokolina[0]
                    eokolina = '#'.join(eokolina)
                    log.append(eokolina)
                    eokolina = prijelaz.get((pocetno, "$", listastog[0]))
                    sljedece = prijelaz.get((pocetno, znak, listastog[0]))
                    #print sljedece
                    #print log
                    if (log[-1]==log[-2]):
                        log.pop()
                        break
                        #print log
                        #print sljedece
                        #raw_input("IF LOG")
                    #raw_input("WHILE ITERACIJA")


                if i == 0:
                    log.append(str('fail'))
                    break

        if sljedece is None:
            log.append(str('fail'))
            break

        if sljedece[1] == "$":

                listastog.pop(0)


                pocetno = sljedece[0]

                novo3 = []
                novo3.append(pocetno)
                novo3.append(''.join(listastog))
                novo3 = '#'.join(novo3)

                log.append(novo3)
                #print log
                #raw_input("LOG3")

        elif len(sljedece[1]) == 1: # samo jedan znak
                pocetno = sljedece[0] # spremio sam u pocetno
                novo2 = []
                novo2.append(pocetno)
                novo2.append(''.join(listastog))
                novo2 = '#'.join(novo2)

                log.append(novo2)
                #print log
                #raw_input("LOG2")


        elif len(sljedece[1]) == 2: # imamo 2 znaka
                slovo = sljedece[1]

                listastog.insert(0,slovo[0:1])

                pocetno = sljedece[0]

                novo1 = []
                novo1.append(pocetno)
                novo1.append(''.join(listastog))
                novo1 = '#'.join(novo1)

                log.append(novo1)
                #print log
                #raw_input("LOG1")






    provjera = []
    provjera = log[-1].split('#')



    if provjera[0] == str(prihvatljivo):
        log.append('1')
        print '|'.join(log)
        break

    elif provjera[0] == 'fail':
        log.append('0')
        print '|'.join(log)
        break


    e = []
    e = prijelaz.get((pocetno, "$", listastog[0]))

    if e:
        p = '#'.join(e)
        log.append(p)
        #print e
        #raw_input("IF E")
        if e[0] == str(prihvatljivo):
            log.append('1')
        else:
            log.append('0')
        print '|'.join(log)
    else:
        log.append('0')
        print '|'.join(log)

    log = []

    pocetno = pocetno1
    listastog = []
    listastog.append(pstog)

















