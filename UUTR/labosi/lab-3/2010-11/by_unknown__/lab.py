'''
Funkcija koju poziva ispitni sustav SPPRUT.

Nemojte mijenjati:
  - naziv datoteke
  - naziv funkcije
  - broj ulaznih parametara
  - tipove ulaznih parametara
  - tip povratne vrijednosti

Ulazni parametri:
  definicijaTS: string s definicijom funkcije prijelaza TS
                oblikovan prema uputama na FERWebu
                
                Format zapisa definicije TS slican je formatu ulazne datoteke
                s definicijom TS za klasicni oblik predaje, uz sljedece razlike:
                  a) umjesto odvajanja pojedinih cjelina TS u nove retke datoteke,
                     ovdje se koristi odvajanje znakom % (znak za postotak)
                  b) na pocetku i na kraju niza takodjer se nalazi znak %
      
                Primjer zapisa TS istovjetnog onom koji je dan kao primjer
                ulazne datoteke u uputi za klasicni oblik predaje:
                
                %q0,q1,q2,q3,q4%0,1,X,Y,B%B%q0%q4%q0,0->q1,X,R%q1,0->q1,0,R%q1,Y->q1,Y,R%q1,1->q2,Y,L%q2,0->q2,0,L%q2,Y->q2,Y,L%q2,X->q0,X,R%q0,Y->q3,Y,R%q3,Y->q3,Y,R%q3,B->q4,B,R%
      
                Moze se pretpostaviti da je niz s definicijom TS ispravno zadan
                prema ovim uputama (nije ga potrebno parsirati i provjeravati ispravnost)                
                
  sadrzajTrake: string s nizom znakova koji su prije pocetka rada TS zapisani na
                ulaznoj traci i za koji TS provjerava da li se prihvaca.
                Svaki znak u nizu predstavlja sadrzaj jedne celije, a pocetni
                znak niza predstavlja sadrzaj krajnje lijeve celije trake.

Povratna vrijednost:
  string oblika N%P: niz znakova koji sadrzi dvije informacije
                     medjusobno odvojene granicnikom %
  N: broj prijelaza (cijeli broj u bazi 10, bez vodecih nula) koje obavi TS
     od pocetka rada do zaustavljanja
  P: oznaka prihvatljivosti niza 
     1 ako TS prihvaca niz
     0 ako TS ne prihvaca niz
     
  Primjeri povratne vrijednosti:
  123%0 - TS je obavio 123 prijelaza, nakon cega je stao i nije prihvatio niz
    8%1 - TS je obavio 8 prijelaza, nakon cega je stao i prihvatio niz
    0%0 - TS nije obavio niti jedan prijelaz, odmah je stao i nije prihvatio niz
    0%1 - TS nije obavio niti jedan prijelaz, odmah je stao i prihvatio niz
'''

def utrlab3(definicijaTS, sadrzajTrake):
  
  definicija = {}
  temp = ''.join(definicijaTS.replace('%', '\n')).strip().split('\n')
  traka = list(sadrzajTrake)
  for counter in range(len(temp)):
      if counter == 2:
          blank = temp[counter]
      if counter == 3:
          tren_stanje = temp[counter]
      if counter == 4:
          prihvatljiva = temp[counter].split(',')
      if counter > 4:
          duljina = temp[counter].split('->')
          definicija[duljina[0]] = duljina[1].split(',')
  
  duljina = len(traka)
  for counter in range(1000-duljina):
      traka.append(blank)
  duljina = 1
  glava = 0
  brojac = 0
  while(duljina):
      temp2 = 0
      for counter in definicija.keys():
          if counter.split(',')[0] == tren_stanje and counter.split(',')[1] == traka[glava]:
              tren_stanje = definicija[counter][0]
              traka[glava] = definicija[counter][1]
              if definicija[counter][2] == 'R':
                  glava = glava + 1
              else:
                  glava = glava - 1
              temp2 = 1
              brojac = brojac + 1
              break
      if temp2 == 0:
          duljina = 0
  
  a1 = 0
  if tren_stanje in prihvatljiva:
      a1 = 1
  
  return str(brojac) + "%" + str(a1)

#print utrlab3(open('definicija.txt', 'r').readline().rstrip(), open('ulazna.txt', 'r').readline().rstrip())