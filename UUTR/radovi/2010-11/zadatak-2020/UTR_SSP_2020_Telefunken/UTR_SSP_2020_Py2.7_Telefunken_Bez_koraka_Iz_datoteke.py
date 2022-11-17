print "\tPARSER TEHNIKOM REKURZIVNOG SPUSTA ZA ARITMETICKE IZRAZE\n"
print "\t\t\t\t\t\tAutor: Telefunken\n\n\n"

import time

f = open('Izrazi.txt','r')

def B(Izraz,Ulaz):
    Ulaz = C(Izraz,Ulaz)
    if ((Ulaz == "+") or (Ulaz == "-") or (Ulaz == "/") or (Ulaz == "*")):
        Ulaz = Izraz.pop(0)
        Ulaz = B(Izraz,Ulaz)
    return Ulaz
  

def D(Izraz,Ulaz):
    if (Ulaz == "("):
        Ulaz = Izraz.pop(0)
        Ulaz = B(Izraz,Ulaz)
        if (Ulaz != ")"):
            return 0
        else:
            Ulaz = Izraz.pop(0)
            return Ulaz
    if (Ulaz == "v"):
        Ulaz = Izraz.pop(0)
        return Ulaz        

def C(Izraz,Ulaz):
    Ulaz = D(Izraz,Ulaz)
    if ((Ulaz == "=") or (Ulaz == "!=") or (Ulaz == "<=") or (Ulaz == ">=") or (Ulaz == "<") or (Ulaz == ">")):
        Ulaz = Izraz.pop(0)
        Ulaz = B(Izraz,Ulaz)
    return Ulaz



def A(Izraz,Ulaz):
    Ulaz = B(Izraz,Ulaz)
    if (Ulaz != "$"):
        return 0
    return Ulaz

def GlavniProgram(Izraz):
    Ulaz = Izraz.pop(0)
    Ulaz = A(Izraz,Ulaz)
    if (Ulaz != "$"):
        return 0
    else:
        return 1

def Provjera_varijable(Varijabla):
    nedopusteno = 1
    for i in range(0,65):
        if (ord(Varijabla[0]) == i):
            nedopusteno = 0
            break
    for i in range(91,97):
        if (ord(Varijabla[0]) == i):
            nedopusteno = 0
            break
    for i in range(123,128):
        if (ord(Varijabla[0]) == i):
            nedopusteno = 0
            break
    if (nedopusteno == 1):
        return 1
    else:
        print "Izraz",Upisano,"nije ispravno napisan!"
        print "Varijabla",Varijabla,"nije ispravno napisana!"
        return 0

for linija in f:
    Provjera = 1
    Izraz = []
    Varijabla = ""
    Pom = ""
    Upisano = linija
    t0 = time.time()
    for Znak in  Upisano:
        for i in range(48,58):
            if (ord(Znak) == i):
                Varijabla += Znak
                break                
        for i in range(65,91):
            if (ord(Znak) == i):
                Varijabla += Znak
                break
        for i in range(63,92):
            if (ord(Znak) == i):
                Varijabla += Znak
                break
        for i in range(93,127):
            if (ord(Znak) == i):
                Varijabla += Znak
                break
        for i in range(40,48):
            if (ord(Znak) == i):
                if (Varijabla != ""):
                    Provjera = Provjera_varijable(Varijabla)
                    if (Provjera == 0):
                        break
                    Varijabla = "v"
                    Izraz.append(Varijabla)
                    Varijabla = ""
                Izraz.append(Znak)
                break
        if ((Znak == "<") or (Znak == ">")):
            if (Varijabla != ""):
                Provjera = Provjera_varijable(Varijabla)
                if (Provjera == 0):
                    break
                Varijabla = "v"
                Izraz.append(Varijabla)
                Varijabla = ""
                Pom = ""
            Izraz.append(Znak)
            Pom = Znak
        if (Znak == "!"):
            if (Varijabla != ""):
                Provjera = Provjera_varijable(Varijabla)
                if (Provjera == 0):
                    break
                Varijabla = "v"
                Izraz.append(Varijabla)
                Varijabla = ""
                Pom = ""
            Pom = Znak
        if ((Znak == "=") and ((Pom == "<") or (Pom == ">"))):
            if (Varijabla != ""):
                Provjera = Provjera_varijable(Varijabla)
                if (Provjera == 0):
                    break
                Varijabla = "v"
                Izraz.append(Varijabla)
                Varijabla = ""
                Pom = ""
            Izraz.pop()
            Pom += Znak
            Izraz.append(Pom)
            Pom = ""
            continue
        if ((Znak == "=") and (Pom == "!")):
            if (Varijabla != ""):
                Provjera = Provjera_varijable(Varijabla)
                if (Provjera == 0):
                    break
                Varijabla = "v"
                Izraz.append(Varijabla)
                Varijabla = ""
                Pom = ""
            Pom += Znak
            Izraz.append(Pom)
            Pom = ""
            continue
        if (Znak == "="):
            if (Varijabla != ""):
                Provjera = Provjera_varijable(Varijabla)
                if (Provjera == 0):
                    break
                Varijabla = "v"
                Izraz.append(Varijabla)
                Varijabla = ""
                Pom = ""
            Izraz.append(Znak)
            continue
        if (Provjera == 0):
            break
    if(Provjera):
        if (Varijabla != ""):
            Provjera = Provjera_varijable(Varijabla)
            if (Provjera == 1):
                Varijabla = "v"
                Izraz.append(Varijabla)
                Varijabla = ""
    Izraz.append("$")
    if (Provjera != 0):
        Valjanost = GlavniProgram(Izraz)
        if (Valjanost):
            print "Izraz ",Upisano," je aritmeticki izraz!"
        else:
            print "Izraz ",Upisano," nije aritmeticki izraz!"
        print time.time() - t0, "sekunda"
        print("\n\n")
    else:
        print "Varijabla mora zapocinjati slovom!\n","Program se ne pokrece.\n"
f.close()
raw_input("Pritisnuti enter za izlaz.")
