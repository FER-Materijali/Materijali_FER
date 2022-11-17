import sys
import re

# ucitavanje podataka
podatci = []
for line in sys.stdin.readlines():
	line = line.strip() 
	if (len(line) > 0):
		podatci.append(line)
		
# tablica prijelaza
def tablicaprijelaza(ulaziprijelazi):
    rezultat = {}
    for prijelaz in ulaziprijelazi:
        r = re.match("^(.+?),(.+?)->(.+)$", prijelaz)

        sadasnje= r.group(1)
        znak = r.group(2)
        # Ignore states that lead to nowhere.
        nova = [stanje for stanje in r.group(3).split(",") if stanje != "#"]

        if (len(nova)):
            rezultat[(sadasnje, znak)] = nova
            
    return rezultat

def ispisuj(ispis):
  rez = ""
  duljina = len(ispis)
  for i in range(duljina):
    medu = ""
    lenMedu = len(ispis[i])
    if (lenMedu == 0):
      medu = "#"
    else:
      for j in range(lenMedu):
        medu += str(ispis[i][j])
        if (j < lenMedu - 1):
          medu += ","

    rez += medu
    if (i < duljina - 1):
      rez += "|"
  return rez

# simulacija automata
def simulacija(niz, tabprij, poc):
    
    rezultat = []
    sadasnjastanja = []
       
    for i in range(-1, len(niz)):

        sljedecastanja = []
        ubrzanje = []

        if (i == -1):
            sljedecastanja = []
            ubrzanje = [poc]
        else:
            for trenutno in sadasnjastanja:
                prijelazi=tabprij.get((trenutno, niz[i]),[])
                for mogucast in prijelazi:
                    if (not mogucast in sljedecastanja):
                        sljedecastanja.append(mogucast)
                        epsiloni=tabprij.get((mogucast, "$"),[])
                        for ubrzan in epsiloni:
                            ubrzanje.append(ubrzan)

        while(len(ubrzanje)):
            ubrzan = ubrzanje.pop()

            if (not ubrzan in sljedecastanja):
                sljedecastanja.append(ubrzan)

            for mogucast in tabprij.get((ubrzan, "$"), []):
                if (not mogucast in sljedecastanja):
                    ubrzanje.append(mogucast)

        rezultat.append(sorted(sljedecastanja))
        sadasnjastanja = sljedecastanja

    return rezultat


ulazcijeli=(podatci[0])
ulaz=[]
ulazcijeli=ulazcijeli.split("|")
for niz in ulazcijeli:
    niz=niz.split(",")
    nizl=[]
    for znak in niz:
        nizl.append(znak)
    ulaz.append(nizl)
    
tabprij = tablicaprijelaza(podatci[5:])
pocetno = podatci[4]

for niz in ulaz:
    ispis=simulacija(niz,tabprij,pocetno)
    print ispisuj(ispis)



