'''
    Parser koji parsira tehnikom prednosti operatora
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
    zavrsni = citaj_zavrsne('gramatika2.txt')
    reduciranZnakom = citaj_reduciranZnakom('gramatika2.txt')
    prijelazi = citaj_prijelaze('gramatika2.txt') # lista prijelaza
    ulazni = procitaj_ulazni(path)
    ulazni.append('$')
    print("Ulazni niz : " + str(''.join(str(n) for n in ulazni[:-1])))
    zastavica = 1
    uzorakZaZamjenu = ''

    while(zastavica):
        if( (stog[-1] == '@') and (ulazni[kazaljka] == '$') ):
            print("Akcija prihvati() ")
            #prihvati
            print( "Ulazni niz " + str(ulazni) + " se prihvaca" )
            zastavica = 0
                        
            break
        else:
            if( (rjecnik_prednosti[(stog[-1], ulazni[kazaljka])] == '<') or (rjecnik_prednosti[(stog[-1], ulazni[kazaljka])] == '=')):
                print("Ulazni znak: " + str(ulazni[kazaljka]))
                print("Akcija pomakni()")
                print("Stog = " + str(stog))
                stog.append(ulazni[kazaljka])
                
                kazaljka += 1
                
            elif( rjecnik_prednosti[(stog[-1], ulazni[kazaljka])] == '>' ):
                print("Ulazni znak: " + str(ulazni[kazaljka]))
                print("Akcija reduciraj()")
                print("Stog = " + str(stog))
                                
                znakSaVrhaStoga = stog.pop()
                print("Znak sa vrha stoga = " + str(znakSaVrhaStoga))
                duljina_uzorka = len(uzorakZaZamjenu)
                
                while( rjecnik_prednosti[stog[-1], znakSaVrhaStoga] != '<' ):
                    znakSaVrhaStoga = stog.pop()
                    print("Izbacujem: " + str(znakSaVrhaStoga))
            else:
                #odbaci
                print("Ulazni niz " + str(ulazni) + " se odbacuje.")
                zastavica = 0
                break

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
print(" ")
print("Ulazni niz 4")
print(" ")
simulator('UlazniNiz4.txt')
print(" ")
print("Ulazni niz 5")
print(" ")
simulator('UlazniNiz5.txt')
print("Ulazni niz 6")
print(" ")
simulator('UlazniNiz6.txt')
