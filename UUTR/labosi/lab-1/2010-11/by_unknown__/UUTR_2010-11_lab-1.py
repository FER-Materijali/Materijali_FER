#nadopuni epsilon prijelazima, to jest, $-prijelazima
#---------------------------------------------------------------
#funkcije:
def nadopuni_stanja_epsilonima(pocetna,def_prijelazi):
    nova_pocetna = []
    nova_pocetna = pocetna
    pomocni = ""
    lista = []
    ispis = []
    for i in range(len(def_prijelazi)):
        for j in range(len(nova_pocetna)):
                pomocni = str(def_prijelazi[i].rstrip())[:4]
                if str(nova_pocetna[j]) in pomocni:
                    #print "\tSTANJE U PRIJELAZIMA?:", nova_pocetna[j], def_prijelazi[i]
                    if "$" in pomocni:
                        lista = def_prijelazi[i].split("->")
                        #print "\tNOVA STANJA:",lista[1].split(",")
                        ispis = lista[1].split(",")
                        for z in range(len(ispis)):
                            if str(ispis[z]) not in str(nova_pocetna):
                                    print "\t$-prijelaz:",def_prijelazi[i]
                                    nova_pocetna += "0"
                                    nova_pocetna[len(nova_pocetna)-1] = str(ispis[z])
                        
#ovdje treba rekurzija
#ako je nova_pocetna isto ko i pocetna, vrati rezulat,
#znaci da nije bilo promjene
#ako nije isto, pozovi istu funkciju, ovako:
#                        nadopuni_epsilonima(nova_pocetna,def_prijelazi)
    if pocetna == nova_pocetna:
        return pocetna
    else:
        return nadopuni_stanja_epsilonima(nova_pocetna,def_prijelazi)

def obradi_niz(trenutna,niz,def_prijelazi,sva_stanja):
    iz_cega = []
    zadnja = []
    iduca = []
    print "\nObradujemo niz:",niz
    for i in range(len(niz)):
        print "Obradujemo znak:",niz[i]
        if niz[i] == "$":
            print "\tZa znak",niz[i],"i skup pocetnih stanja", trenutna,"prelazimo u ",trenutna
            continue
        iduca = obradi_znak(niz[i],trenutna,def_prijelazi,sva_stanja)
        print "\tZa znak",niz[i],"i skup pocetnih stanja", trenutna,"prelazimo u ",iduca
        trenutna = iduca
    zadnja = trenutna    
    return zadnja

def obradi_znak(znak,stanje,prijelazi,sva_stanja):
    jedan = []
    dva = []
    novo = []
    k = 0
    prazno = []
    for i in range(len(stanje)):
        for j in range(len(prijelazi)):
            jedan,dva = rastavi_prijelaz(prijelazi[j])
            prazno=jedan.split(",")
            if stanje[i] in jedan:
                if znak in str(prazno[1]):
                    print "\tPrijelaz:",prijelazi[j]
                    novo += str(dva).split(",")
                    kontrola=1
    nadopuni_stanja_epsilonima(novo,prijelazi)
    for k in range(len(sva_stanja)):
        if str(sva_stanja[k]) in novo:
            while novo.count(str(sva_stanja[k]))<>1:
                novo.remove(str(sva_stanja[k]))
        else:
            continue
    novo.sort()    
    return novo

def rastavi_prijelaz(prijelaz):
    pocetni = []
    zavrsni = []
    pomocni = []
    pomocni = prijelaz.split("->")
    pocetni = pomocni[0]
    zavrsni = pomocni[1]
    return pocetni,zavrsni

def provjera(stanja):
    dobar = 0
    for i in range(len(dobra_stanja)):
        for j in range(len(stanja)):
            if str(dobra_stanja[i]) in str(stanja[j]):
                dobar = 1
    return dobar
#---------------------------------------------------------------
print "\t$-NKA AUTOMAT"
print "________________________________________________"
#definiranje praznih lista
sva_stanja = []
svi_ulazi = []
dobra_stanja = []
stanje_automata = []
prijelazi = []
ulazni_niz = []
niz_obrada = 0
pocetna = []
#---------------------------------------------------------------
#ucitavanje definicije automata u listu i ispis svih lista
kak_sad = raw_input("Koja definicija?")
print "Ucitavamo definiciju automata iz '",kak_sad,"': "
definicija = open(kak_sad,"r")
linije = definicija.readlines()
i = 0
for linija in linije:
    if i==0:
        sva_stanja += linija[:len(linija)-1].split(",")
    elif i==1:
        svi_ulazi += linija[:len(linija)-1].split(",")
    elif i==2:
        dobra_stanja += linija[:len(linija)-1].split(",")
    elif i==3:
        stanje_automata += linija[:len(linija)-1].split(",")
    else:
        if i<len(linije)-1:
            prijelazi += linija[:len(linija)-1].split(",|->")
    i += 1
definicija.close()
print "----------------------------------"
print "Ucitano..."
print "LISTA STANJA: ",sva_stanja,"\n" \
      "LISTA ULAZNIH ZNAKOVA: ",svi_ulazi,"\n" \
      "LISTA PRIHVATLJIVIH STANJA: ",dobra_stanja,"\n" \
      "POCETNO STANJE: ", stanje_automata,"\n"
print "FUNKCIJE PRIJELAZA: "
k = 0
while k < len(prijelazi):
    print "\t",prijelazi[k]
    k += 1  
#---------------------------------------------------------------
print "________________________________________________"
#ucitavanje datoteke ulaz.txt u varijablu ulaz
kak_tu = raw_input("Koji ulaz?")
print "Ucitavamo ulaze iz '",kak_tu,"': "
ulaz = open(kak_tu, "r")
linijeu = ulaz.readlines()
j = 0
for linijau in linijeu:
    ulazni_niz += linijau[:len(linijau)].rstrip().split(",")
    j += 1
ulaz.close()
print "----------------------------------"
print "Ucitano..."
print "ULAZI: "
ul = 0
while ul < len(ulazni_niz):
    print "\t",ulazni_niz[ul]
    ul += 1  
#---------------------------------------------------------------
print "________________________________________________"
#poziv funkcije za nadopunu stanja
for l in range(len(ulazni_niz)):
    da_ili_ne = 0
    iduca = []    
    pocetna=stanje_automata
    print "----------------------------------"
    print "------------[Granica]-------------"
    print "----------------------------------"
    print "Citam niz: ", ulazni_niz[l]
    print "Nadopunjujem pocetna stanja epsilon prijelazima...."
    trenutna = nadopuni_stanja_epsilonima(pocetna,prijelazi)
    print "POCETNA STANJA AUTOMATA SA EPSILON PRIJELAZIMA:", trenutna    
    iduca = obradi_niz(trenutna,ulazni_niz[l],prijelazi,sva_stanja)
    print "\nKONACNA STANJA AUTOMATA:",iduca
    da_ili_ne = provjera(iduca)    
    if da_ili_ne == 0:
        print "Niz '", ulazni_niz[l],"' nije prihvacen."
    else:
        print "Niz '", ulazni_niz[l],"' je prihvacen."
raw_input("\n\nPritisnite enter za kraj programa.")






