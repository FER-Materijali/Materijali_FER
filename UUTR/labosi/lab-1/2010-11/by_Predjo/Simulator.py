'''
Created on 7.3.2011.

@author: Predjo
'''

class ulazninizovi:
    def __init__(self,imedat):
        self.imedat=imedat
        self.dat=open(imedat,"r",)
        self.niz=self.dat.readlines()
        for i in range(len(self.niz)):
            self.niz[i]=self.niz[i].strip('\n')
    def ispis(self):
        print(strip(self.niz))
        
class defdatoteka:
    def __init__(self,imedat):
        self.imedat=imedat
        self.dat=open(imedat,"r",)
        self.niz=self.dat.readlines()
        for i in range(len(self.niz)):
            self.niz[i]=self.niz[i].strip('\n')
            
        self.skupstanja=self.niz[0].split(',')
        self.skupznakova=self.niz[1].split(',')
        self.prihvtstanja=self.niz[2].split(',')
        self.pocetno=self.niz[3].split(',')
        self.funkcije=dict()
        
        #lista funkcija
        for s in self.skupstanja:
            self.funkcije[s]=dict()
            
        for i in range(4,len(self.niz)):
            funkcijskiniz=self.niz[i].split(',')
            trenutnoStanje=funkcijskiniz[0]                 #trenutno stanje
            ulazniZnak=funkcijskiniz[1].split('->')[0]
            sljedeceStanje=self.niz[i].split('->')[1]
            
            self.funkcije[trenutnoStanje][ulazniZnak]=sljedeceStanje

def eokruzenje(nizStanja,funkcije):
    novaStanja=list()
    pomocniNiz=list(nizStanja)
    pomocniNiz.sort()
    for s in pomocniNiz:
        if '$' in funkcije[s]:
            novaStanja=funkcije[s]['$'].split(',')
            for i in range(len(novaStanja)):
                if novaStanja[i] in pomocniNiz:
                    continue
                else: 
                    pomocniNiz.append(novaStanja[i])
            print "%s,$ => %s" % (s,strip(novaStanja))
    pomocniNiz=list(set(pomocniNiz))
    pomocniNiz.sort()
    return pomocniNiz
                
            


def strip(niz):
    pomniz=str(niz)
    pomniz= pomniz.replace('[','')
    pomniz= pomniz.replace(']','')
    pomniz= pomniz.replace('\'','')
    return pomniz
    

def simuliraj(testString,skupStanja,skupZnakova,prhStanja,pocStanje,funkcijePrijelaza):
    print("Pocinje simulacija niza: %s " % testString)
    print
    
    pomocniNiz=list()
    prekid=0
    
    nizStanja=eokruzenje(pocStanje,funkcijePrijelaza)
    #print nizStanja
    
    for c in testString: #iteracija kroz slova
        if c in skupZnakova: #provjerava dali je ulazni znak prihvatljiv
            for s in nizStanja:           #iteracija kroz stanja
                
                if c in funkcijePrijelaza[s]:    #dali postoji funkija prijelaza

                    pomocniNiz.extend(funkcijePrijelaza[s][c].split(','))
                    novaStanja=str(funkcijePrijelaza[s][c].split(','))
                    print "%s,%s => %s" % (s,c,strip(novaStanja))
                    pomocniNiz=eokruzenje(pomocniNiz,funkcijePrijelaza)


        else:
            print("%s nije prihvatljiv ulazni znak, prekinuta simulacija i niz se ne prihvaca!" % c)
            prekid=1
            break
        
        nizStanja=list(set(pomocniNiz))
        nizStanja.sort()
        del pomocniNiz[:]
    if prekid!=1:        #provjera prihvatljivosti
        #print(nizStanja)
        if list(set(prhStanja)&set(nizStanja)):
            print
            print "Konacno stanje automata je prihvatljivo!"
        else:
            print
            print "Konacno stanje automata nije prihvatljivo!"
        print("Zavrsena simulacija niza: %s " % testString)
        print("------------------------------------------")
        print
        prekid=0
            
            

def main():
    #a="Z2.txt"
    #b="Z1.txt"
    b=raw_input("Ime definicijske datoteke: ")
    
    
    definicija=defdatoteka(b)
    
    print "Info o automatu:"
    print 
    print "Skup stanja: %s" % strip(definicija.skupstanja)
    print "Pocetna stanja: %s" % strip(definicija.pocetno)
    print "Ulazni znakovi: %s" % strip(definicija.skupznakova)
    print "Prihvatljiva stanja: %s" % strip(definicija.prihvtstanja)
    #print "Funkcije prijelaza: %s" %definicija.funkcije
    print
    a=raw_input("Ime test datoteke: ")

    
    test=ulazninizovi(a)
    print
    print "Test nizovi:",
    test.ispis()
    print
    
    for i in range(len(test.niz)):
        simuliraj(test.niz[i],definicija.skupstanja,definicija.skupznakova,definicija.prihvtstanja,definicija.pocetno,definicija.funkcije)
    
    
    raw_input("\nPress enter to exit...")

if __name__ == '__main__':
    main()
