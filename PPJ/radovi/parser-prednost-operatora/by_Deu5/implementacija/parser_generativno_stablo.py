'''
    Parser koji parsira tehnikom prednosti operatora + gradnja generativnog stabla
'''
#################### citanje ulaznih znakova

def procitaj_ulazni(path):
    temp = open(path, 'r')
    tmp = temp.read().split()
    lista = []
    for x in tmp:
        for y in x:
            lista.append(y)
    return lista

#################### citanje tablice prednosti operatora

def procitaj_tablicu(path):
    rjecnik = {}
    datoteka = open(path,'r')
    linije = datoteka.read().split('\n')
    for i in range(1, len(linije[1:]) + 1):
        for brojac in range(1, len(linije[2])):
            if ( (linije[i][brojac] != ' ') and (linije[i][0] != ' ')  ):
                rjecnik[linije[i][0], linije[1][brojac]] = linije[i][brojac]
    return rjecnik

#################### citanje prijelaza gramatike

def citaj_prijelaze(path):
    lista = []
    temp = open(path, 'r')
    tmp = temp.read().split('\n')
    for i in range(3, len(tmp[1:]) + 1):
        lista.append(tmp[i][2:])        
    return lista

#################### citanje zavrsnih znakova gramatike

def citaj_zavrsne(path):
    lista = []
    temp = open(path, 'r')
    tmp = temp.read().split('\n')
    for i in range(0,len(tmp[1])):
        if(tmp[1][i] != ' ' ):
            lista.append(tmp[1][i])
            
    return lista

#################### stvaranje reduciranZnakom rjecnika

def citaj_reduciranZnakom(path):
    temp = open(path, 'r')
    tmp = temp.read().split('\n')
    return tmp[2].split(',')

#################### simulator

def simulator(path):
    rjecnik_prednosti = procitaj_tablicu('tablicaPrednosti2.txt') 
    stog = []   #koristim za rad parsera
    rjecnik_stabla = {} #sprema generativno stablo
    stog.append('@')     #@ je znak dna stoga
    kazaljka = 0         #za pomicanje po ulaznom nizu
    operatori = citaj_zavrsne('gramatika2.txt')
    reduciranZnakom = citaj_reduciranZnakom('gramatika2.txt')    
    
    prijelazi = citaj_prijelaze('gramatika2.txt') # lista prijelaza
    ulazni = procitaj_ulazni(path)
    ulazni.append('$')
    print("Ulazni niz : " + str(''.join(str(n) for n in ulazni[:-1])))
    zastavica = 1
    stogStablo = []
    rjecnik_stablo = {}
    nivo = []
    i = 0
    uzorak = []


    while(zastavica):
        if( (stog[-1] == '@') and (ulazni[kazaljka] == '$') ):
            #prihvati
            print( "Ulazni niz " + str(ulazni) + " se prihvaca" )
            zastavica = 0
                 
            break
            
        else:
            if( (rjecnik_prednosti[(stog[-1], ulazni[kazaljka])] == '<') or
                (rjecnik_prednosti[(stog[-1], ulazni[kazaljka])] == '=')):
                print("Ulazni znak: " + str(ulazni[kazaljka]))
                print("Akcija pomakni()")
                print("Stog = " + str(stog))
                if(ulazni[kazaljka] != '$'):
                    stog.append(ulazni[kazaljka])
                print("Stog = " + str(stog))
                kazaljka += 1
                
            elif( rjecnik_prednosti[(stog[-1], ulazni[kazaljka])] == '>' ):
                print("Ulazni znak: " + str(ulazni[kazaljka]))
                print("Akcija reduciraj!")
                print("Stog = " + str(stog))
                
                znakSaVrhaStoga = stog.pop()
                while( rjecnik_prednosti[stog[-1], znakSaVrhaStoga] != '<' ):
                    znakSaVrhaStoga = stog.pop()
                    uzorak.append(znakSaVrhaStoga)
                    print("izbacujem: " + str(znakSaVrhaStoga))
                print("Znak sa vrha stoga = " + str(znakSaVrhaStoga))
                uzorak.append(ulazni[kazaljka-1])
                stogStablo.append(uzorak[-1])
                if(len(uzorak) > 2):
                    b = ''.join(str(n) for n in uzorak)

                while(((str(uzorak[-1]) + str(ulazni[kazaljka])) in reduciranZnakom) and
                      (ulazni[kazaljka] != '$')):
                    for i in prijelazi:
                        if(ulazni[kazaljka] in i):
                            for s in prijelazi:
                                if(uzorak[-1] == s[3]):
                                    uzorak[-1] = s[0]
                                    stogStablo.append(s[0])
                                    
                if(ulazni[kazaljka] == '$'):
                    for s in prijelazi:
                        duljina = len(s[3:])
                        tmp = ''.join(str(n) for n in uzorak[-duljina:])
                        if(uzorak[-2] in s):
                            while(tmp not in s):
                                for x in prijelazi:
                                    if(uzorak[-1] == x[3]):
                                        uzorak[-1] = x[0]
                                        stogStablo.append(x[0])
                                        tmp = ''.join(str(n) for n in uzorak[-duljina:])
                                    elif(uzorak[-1] == x[-1]):
                                        tmp2 = ''.join(str(n) for n in uzorak[-duljina:])
                                        if(tmp2 == x[-duljina:]):
                                            for i in duljina:
                                                uzorak.pop()
                                            uzorak.append(x[0])
                    for i in range(len(stog)-1):
                        stog.pop()
                    
                uzorak.append(ulazni[kazaljka]) 
                duljina = len(stogStablo)
                
                if(ulazni[kazaljka] != '$'):
                    for i in range(len(stogStablo)):
                        znak = stogStablo.pop()
                        rjecnik_stablo[(kazaljka-1, duljina-i)] = znak
                        nivo.append(duljina-i)
                        for s in prijelazi:
                            if((str(znak) + str(ulazni[kazaljka])) == s[3:5]):
                                rjecnik_stablo[(kazaljka, duljina-i)] = ulazni[kazaljka]
                                maks = duljina - i
                else:
                    for i in range(len(stogStablo)):
                        znak = stogStablo.pop()
                        rjecnik_stablo[(kazaljka-1, maks-i)] = znak
                        nivo.append(maks-i)
                        for s in prijelazi:
                            if((str(znak) + str(ulazni[kazaljka])) == s[3:5]):
                                rjecnik_stablo[(kazaljka, maks-i)] = ulazni[kazaljka]
            else:
                #odbaci
                print("Ulazni niz " + str(ulazni) + " se odbacuje.")
                zastavica = 0
                stog_stablo = []

                break

    uzorak.pop()

    maks = max(nivo)
    if(len(uzorak) == 3):
        maks +=1
    duljina_uzorka = len(uzorak)
    while((len(uzorak) > 1) and (uzorak[-1] != 'E')):
        for s in prijelazi:
            duljina = len(s[3:])
            tmp = ''.join(str(n) for n in uzorak[-duljina:])
            if(tmp == s[3:]):
                for j in range(duljina):
                    uzorak.pop()
                uzorak.append(s[0])
                rjecnik_stablo[(duljina_uzorka - duljina, maks)] = s[0]
                stogStablo.append(s[0])
                maks += 1
                if (len(uzorak) >= duljina):
                    tmp = ''.join(str(n) for n in uzorak[-duljina:])
                elif((len(uzorak) == 1) and (str(uzorak[-1]) != 'E')):
                    for x in prijelazi:
                        if(str(uzorak[-1]) == x[3]):
                            uzorak[-1] = x[0]
                            rjecnik_stablo[(duljina_uzorka - duljina, maks)] = x[0]
    print("Rjecnik koji sadrzi generativno stablo = " + str(rjecnik_stablo))

print(" ")
print("Ulazni niz 1")
print(" ")
simulator('UlazniNiz.txt')
print(" ")
print("Ulazni niz 2")
print(" ")
simulator('UlazniNiz2.txt')
print(" ")
print("Ulazni niz 3")
print(" ")
simulator('UlazniNiz3.txt')
