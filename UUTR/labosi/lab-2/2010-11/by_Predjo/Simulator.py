'''
Created on 14.4.2011.

@author: Predjo
'''
import time

class ulazninizovi: #citanje nizova iz datoteke i stvaranje liste ulaznih nizova
    def __init__(self,imedat):
        self.dat=open(imedat,"r",)
        self.niz=self.dat.readlines()
        for i in range(len(self.niz)):
            self.niz[i]=self.niz[i].strip('\n')
            if not self.niz[i]:
                self.niz[i]='$'
                pass
    def ispis(self):
        print(strip(self.niz))

class defdatoteka: #citanje definicijske datoteke i ostalo
    def __init__(self,imedat):
        self.dat=open(imedat,"r",)
        self.niz=self.dat.readlines()
        for i in range(len(self.niz)):
            self.niz[i]=self.niz[i].strip('\n')

        self.skupstanja=self.niz[0].split(',')
        self.skupznakova=self.niz[1].split(',')
        self.skupznakova.append('$')
        self.skupznakovastoga=self.niz[2].split(',')
        self.skupznakovastoga.append('$')
        self.pocetno=self.niz[3].split(',')
        self.znakdnastoga=self.niz[4].split(',')
        self.prihvtstanja=self.niz[5].split(',')
        self.funkcije=dict()

        #lista funkcija
        for s in self.skupstanja:
            self.funkcije[s]=dict()
        for s in self.skupstanja:
            for m in self.skupznakova:
                self.funkcije[s][m]=dict()

        for i in range(6,len(self.niz)):

            trenutnoStanje=self.niz[i].split(',')[0]                #trenutno stanje
            ulazniZnak=self.niz[i].split('->')[0].split(',')[1]     #ulazniznak
            sljedeceStanje=self.niz[i].split('->')[1]               #sljedece stanje
            znakstoga=self.niz[i].split('->')[0].split(',')[2]      #znak stoga

            self.funkcije[trenutnoStanje][ulazniZnak][znakstoga]=sljedeceStanje  #funkcije prijelaza kao trodimenzionalni dictionary


#funkcija da lijepo izgleda ispis lista
def strip(niz):
    pomniz=str(niz)
    pomniz= pomniz.replace('[','')
    pomniz= pomniz.replace(']','')
    pomniz= pomniz.replace('\'','')
    return pomniz

#funkcija da lijepo igleda ispis liste stoga 
def stoglike(niz):
    if not niz:
        niz.append('$')
    pomniz=str(niz)
    pomniz= pomniz.replace('[','')
    pomniz= pomniz.replace(']','')
    pomniz= pomniz.replace('\'','')
    pomniz= pomniz.replace(',','')
    pomniz= pomniz.replace(' ','')
    return pomniz[::-1]

#funkcija za stavljanje znakova na stog
def staviNaStog(znak,stack):
    if znak!="$":
        znak=list(znak)
        znak.reverse()
        stack.extend(znak)
    if not stack:
        stack=list("$")
    return list(stack)


def ePrijelazi(stanje,stack,funkcije):

    i=0
    while i<len(stanje):

            stackbackup=list(stack[i])
            st=stackbackup.pop()
            trenutnoStanje=str(stanje[i])
                
            if st in funkcije[stanje[i]]['$']:
                pomocniNiz=funkcije[stanje[i]]['$'][st].split('#')
                
                    
                for j in range(len(pomocniNiz)):
                    preskoci=0
                    for g in range(len(stanje)):
                        #print  stanje[g],pomocniNiz[j].split(',')[0],stack[g]
                        
                        if (stanje[g]==pomocniNiz[j].split(',')[0])  and (stack[g]==staviNaStog(pomocniNiz[j].split(',')[1],list(stackbackup))):
                            preskoci=1
                            
                            
                                                                            
                    if preskoci!=1:  
                        
                        stanje.append(pomocniNiz[j].split(',')[0])
                        stack.append(staviNaStog(pomocniNiz[j].split(',')[1],list(stackbackup)))
                        print "%s,$,%s|%s => %s" % (trenutnoStanje,st,stoglike(stackbackup),funkcije[trenutnoStanje]['$'][st]) 

            
            i+=1
    #print stanje,stack 
    return stanje,stack
                    
                    


def simuliraj(testString,skupStanja,skupZnakova,prhStanja,pocStanje,skupZnakovaStoga,znakDnaStoga,funkcijePrijelaza):
    print("Pocinje simulacija niza: %s " % testString)
    print
    stog=list()
    stog.append(list(znakDnaStoga))
    pomocniNiz=list()
    noviStog=list()
    prekid=0
    novaStanja=list()
    nizStanja=list(pocStanje)
    prhihvatljivo=0

    nizStanja,stog=ePrijelazi(list(nizStanja),list(stog),funkcijePrijelaza)
    
    for c in testString: #iteracija kroz slova
        if c in skupZnakova and c!="$": #provjerava dali je ulazni znak prihvatljiv
            for i in range(len(nizStanja)):           #iteracija kroz stanja

                if stog[i] and stog[i][0]!="$":
                    vrhstoga=stog[i].pop()

                    if  vrhstoga in funkcijePrijelaza[nizStanja[i]][c]: #provjera dal postoji funkcija prijelaza

                        pomocniNiz.extend(funkcijePrijelaza[nizStanja[i]][c][vrhstoga].split('#'))

                        for s in pomocniNiz:
                            novaStanja.append(s.split(',')[0])
                            noviStog.append(staviNaStog(s.split(',')[1],list(stog[i])))

                        print "%s,%s,%s|%s => %s"  % (nizStanja[i],c,vrhstoga,stoglike(stog[i]),strip(pomocniNiz))

                        #print novaStanja
                        #print noviStog
                        del pomocniNiz[:]

        
        elif(c=="$"): #slucaj da je ucitan prazan niz
            novaStanja=list(nizStanja)
            noviStog=list(stog)
        else: #slucaj da je ucitan neprihvatljiv ulazni znak
            print("%s nije prihvatljiv ulazni znak, prekinuta simulacija i niz se ne prihvaca!" % c)
            prekid=1
            break

        nizStanja=list(novaStanja)
        stog=list(noviStog)
        nizStanja,stog=ePrijelazi(list(nizStanja),list(stog),funkcijePrijelaza)
        del novaStanja[:]
        del noviStog[:]
    if prekid!=1:
        nizStanja,stog=ePrijelazi(list(nizStanja),list(stog),funkcijePrijelaza)
        #Provjera dali se u listi stanja nalazi prihvatljivo stanje
        for i in range(len(nizStanja)):
            if (nizStanja[i] in prhStanja):
                prhihvatljivo=1
    

    #print nizStanja
    #print stog

    if prekid!=1:        #provjera prihvatljivosti
        #print(nizStanja)
        if prhihvatljivo==1:
            print
            print "Konacno stanje automata je prihvatljivo!"
        else:
            print
            print "Konacno stanje automata nije prihvatljivo!"
        print("Zavrsena simulacija niza: %s " % testString)
        print("-------------------------------------------------------")
        print
        prekid=0


def main():
    
    #a="C2.txt"
    #b="C1.txt"
    b=raw_input("Ime definicijske datoteke: ")


    definicija=defdatoteka(b)


    #Ispisi svih informacija o utomatu
    print "Info o automatu:"
    print
    print "Skup stanja: %s" % strip(definicija.skupstanja)
    print "Pocetna stanja: %s" % strip(definicija.pocetno)
    print "Skup znakova stoga: %s" % strip(definicija.skupznakovastoga)
    print "Znak dna stoga: %s" % strip(definicija.znakdnastoga)
    print "Ulazni znakovi: %s" % strip(definicija.skupznakova)
    print "Prihvatljiva stanja: %s" % strip(definicija.prihvtstanja)
    #print "Funkcije prijelaza: %s" %definicija.funkcije
    print
    a=raw_input("Ime test datoteke: ")
    start_time = time.time()

    test=ulazninizovi(a)
    print
    print "Test nizovi:",
    test.ispis()
    print

    for i in range(len(test.niz)):
        simuliraj(test.niz[i],definicija.skupstanja,definicija.skupznakova,definicija.prihvtstanja,definicija.pocetno,definicija.skupznakovastoga,definicija.znakdnastoga,definicija.funkcije)

    print time.time() - start_time, "seconds"

    raw_input("\nPress enter to exit...")


if __name__ == '__main__':

    main()

