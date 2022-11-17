print "\tPARSER TEHNIKOM REKURZIVNOG SPUSTA ZA ARITMETICKE IZRAZE\n"
print "\t\t\t\t\t\tAutor: Telefunken\n\n\n"
print "Koristena gramatika:\n"
print "A -> {B $}"
print "B -> {C + | - | * | / C}"
print "C -> {D + | - | * | / B}"
print "D -> {E = | != | < | > | <= | >= B } | { E }"
print "E -> { (B) } | { v }\n"
print "Varijable u izrazu moraju zapocinjati slovom!"
print "Osim navedenog ogranicenja, mogu sadrzavati bilo koji znak.\n"
print "Dopusteni operatori:\n"
print "+  -  *  /  <  >  =  <=  >=  !=\n"
print "Dopustene zagrade ( i ).\n"
print "Dopusteni razmaci.\n"

import time

def B(Izraz,Ulaz):
    print "Funkcija B prihvaca znak '",Ulaz,"' i parser odlazi u funkciju C.\n"
    Ulaz = C(Izraz,Ulaz)
    print "Funkcija B iz funkcije C prihvaca znak '",Ulaz,"' ."
    if ((Ulaz == "+") or (Ulaz == "-") or (Ulaz == "/") or (Ulaz == "*")):
        Ulaz = Izraz.pop(0)
        print "\tZnak je operator i zato parser cita sljedeci znak u izrazu (,a to je znak '",Ulaz,"' ) i odlazi u funkciju C.\n"
        Ulaz = B(Izraz,Ulaz)
    print "\tZnak '",Ulaz,"' nije operator i zato parser vraca znak '",Ulaz,"' .\n"
    return Ulaz

def C(Izraz,Ulaz):
    print "Funkcija C prihvaca znak '",Ulaz,"' i parser odlazi u funkciju D.\n"
    Ulaz = D(Izraz,Ulaz)
    print "Funkcija C iz funkcije D prihvaca znak '",Ulaz,"' ."
    if ((Ulaz == "=") or (Ulaz == "!=") or (Ulaz == "<=") or (Ulaz == ">=") or (Ulaz == "<") or (Ulaz == ">")):
        Ulaz = Izraz.pop(0)
        print "\tZnak je operator jednakosti i zato parser cita sljedeci znak u izrazu (,a to je znak '",Ulaz,"' ) i odlazi u funkciju B.\n"
        Ulaz = B(Izraz,Ulaz)
    print "\tZnak '",Ulaz,"' nije operator jednakosti i zato parser vraca funkciji B znak '",Ulaz,"' .\n"
    return Ulaz    

def D(Izraz,Ulaz):
    print "Funkcija D prihvaca znak '",Ulaz,"' ."
    if (Ulaz == "("):
        Ulaz = Izraz.pop(0)
        print "\tZnak je ' ( ' i zato parser cita sljedeci znak u izrazu (,a to je znak '",Ulaz,"' ) i odlazi u funkciju B.\n"
        Ulaz = B(Izraz,Ulaz)
        print "Funkcija D iz funkcije B prihvaca znak '",Ulaz,"' ."
        if (Ulaz != ")"):
            print "Znak '",Ulaz,"' nije ' ) ' ! i zato funkcija D  vraca 0!\n"
            return 0
        else:
            Ulaz = Izraz.pop(0)
            print "Znak je ' ) ' i zato parser cita sljedeci znak u izrazu (,a to je znak'",Ulaz,"') i vraca se funkciji C znak '",Ulaz,"' .\n"
            return Ulaz
    if (Ulaz == "v"):
        Ulaz = Izraz.pop(0)
        print "Znak je ' v ' i zato parser cita sljedeci znak u izrazu i vraca funkciji C znak '",Ulaz,"' .\n"
        return Ulaz

def A(Izraz,Ulaz):
    print "Funkcija A prihvaca '",Ulaz,"' i parser odlazi u funkciju B.\n"
    Ulaz = B(Izraz,Ulaz)
    print "Funkcija A prihvaca iz funkcije B znak '",Ulaz,"' ."
    if (Ulaz != "$"):
        print "\tZnak '",Ulaz,"' nije ' $ ' ! i zato funkcija A vraca 0!\n"
        return 0
    print "\tZnak je $ i funkcija A ga vraca funkciji GlavniProgram.\n"
    return Ulaz

def GlavniProgram(Izraz):
    print "\nGlavniProgram"
    Pom = ""
    for i in Izraz:
        Pom += i
    print "\tPrimljen izraz (ureden za parsiranje):",Pom,"."
    Pom = ""
    Ulaz = Izraz.pop(0)
    print "\tParser cita znak",Ulaz,"i odlazi u funkciju A.\n"
    Ulaz = A(Izraz,Ulaz)
    print "Funkcija Glavni Program je gotova!"
    if (Ulaz != "$"):
        print "Prihvaceni znak iz funkcije A je '",Ulaz,"',a trebao bi biti $!"
        return 0
    else:
        print "Prihvaceni znak iz funkcije A je ' $ ' i time se prihvaca izraz!"
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
        print "Varijabla",Varijabla,"nije ispravno napisana!"
        return 0


Provjera = 1
Nastavak = 1
while(Nastavak):
    Izraz = []
    Varijabla = ""
    Pom = ""
    Upisano = raw_input("Upisite izraz:\n")
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
            print "Izraz",Upisano,"je aritmeticki izraz!"
        else:
            print "Izraz",Upisano,"nije aritmeticki izraz!"
        print time.time() - t0, "sekunda"
        print("\n\n\n\n\n\n")
    else:
        print "Varijabla mora zapocinjati slovom!\n"
    Nastavak = int(raw_input("Novi izraz: da (1) / ne (0) ?\n"))
