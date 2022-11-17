def dodajB(traka, pozicija):    #funkcija za dodavanje praznih mjesta na traci
    temp = pozicija
    if(pozicija < 0):           #kada je se treba pozicijonirati prije niza
        pozicija=0
        while(temp < 0):
            traka = "B" + traka
            temp = temp + 1
    elif(pozicija > len(traka) - 1):    #kada se treba pozicijonirati poslje niza
        temp=temp - len(traka)
        while(temp >= 0):
            traka = traka + "B"
            temp = temp - 1
    return (traka, pozicija)

#******Deterministički Turingov stroj******#


lokacija="TS2.txt"
try:
    dat=open(lokacija,"r")
except IOError:
    print("Datoteka/putanja {0} ne postoji!".format(lokacija))
    lokacija=input("Upiši novu putanju:")
    dat=open(lokacija,"r")

sve=dat.read()          #otvori i učitaj cijeli fajl u jedan string
dat.close()             #zatvori datoteku

prijelazi=sve.split()   #podijeli na niz stringova i stvori listu
stanje=sve[0]           #uzmi prvi string koji predstavlja p.stanje
del(prijelazi[0])       #i ukloni ga iz liste

traka=input("Niz trake:") #učitaj niz trake
pozicija=int(input("Položaj glave (naprema krajnje lijevom znaku trake):"))
prihStanja=input("Prihvatljivo/a stanje/a TS-a je/su:")

relativnapozicija=pozicija
lista_Koristenih_Celija=set() #stvori listu za upise pozicije glave, set() pamti samo različite elemente

(traka,pozicija)=dodajB(traka,pozicija) #dodaj B-ove
print("Niz trake:",traka)

vremenskaSlozenost = 0  #broj obavljenih prijelaza

promjena = 1
while(promjena != 0):   #ako u prošloj interaciji nije napravljen ni jedan
    promjena = 0        #prijelaz onda potrgaj petlju
    for i in range(len(prijelazi)): #od 0 do broja količine prijelaza
        trenutni_prijelaz = prijelazi[i].split("#") #napravi novu listu, nacjepaj string na elemente. '#' je separator

        lista_Koristenih_Celija.add(relativnapozicija)
        
        if(stanje == trenutni_prijelaz[0] and traka[pozicija] == trenutni_prijelaz[1]):
            stanje = trenutni_prijelaz[2]
            traka = traka[:pozicija] + trenutni_prijelaz[3] + traka[pozicija + 1:]

            lista_Koristenih_Celija.add(relativnapozicija)
            
            if(trenutni_prijelaz[4] == "D"):
                pozicija = pozicija + 1 #ako je nova pozicija veća ili manja od traka dodaj B-ove
                relativnapozicija=relativnapozicija+1
                (traka, pozicija) = dodajB(traka,pozicija)
                
            elif(trenutni_prijelaz[4] == "L"):
                pozicija = pozicija - 1 #ako je nova pozicija veća ili manja od traka dodaj B-ove
                relativnapozicija=relativnapozicija-1

                (traka, pozicija) = dodajB(traka, pozicija)
                
            print("prijelaz: δ(q{0},{1})==>δ(q{2},{3},{4})".
                  format(trenutni_prijelaz[0],
                         trenutni_prijelaz[1],
                         trenutni_prijelaz[2],
                         trenutni_prijelaz[3],
                         trenutni_prijelaz[4]))
            print("pozicija TS-a:",pozicija)
            print("Niz trake:",traka)
            print("stanje: q{0}".format(stanje),"\n")
            promjena = 1 #obavljen prijelaz
            vremenskaSlozenost = vremenskaSlozenost + 1
            break
        
prostornaSlozenost = max (1,len(lista_Koristenih_Celija)) #količina korištenih znakova trake
print("Vremenska složenost:",vremenskaSlozenost)
print("Prostorna složenost:",prostornaSlozenost)
if(stanje in prihStanja):
    print("Niz se prihvaća")
else:
    print("Niz se ne prihvaća")
