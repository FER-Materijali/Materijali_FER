#učitaj datoteku i makni nepotrebni '\n'
datoteka=open("Qgramatika.txt",'r') #otvori datoteku
produkcije=datoteka.readlines() #pročitaj red po red iz datoteke
datoteka.close()# zatvori datoteku
for i,element in enumerate(produkcije):
    produkcije[i]=element.rstrip('\n') #ukloni '\n' koji je posljedica čitanja s readlines()

#ukloni prazne retke
if('' in produkcije):
    produkcije.remove('')

#pronađi završne i nezavršne znakove
nezavrsni=set()
zavrsni=set()
gramatika=[]# lista za produkvije, oblik:[(nezavrsni,zavrsni)]
for i,element in enumerate(produkcije):
    temp=element.split('->') #ukloni '->' i rastavi na nezavrsne i zavrsne
    temp[0]=temp[0].lstrip() #ukloni lijeve praznine
    temp[0]=temp[0].rstrip() #ukloni desne praznine
    temp[1]=temp[1].lstrip()
    temp[1]=temp[1].rstrip()
    gramatika.append((temp[0],temp[1]))
    nezavrsni.add(temp[0])
    #pretraži produkcije za nezavršne znakove
    for j, podniz in enumerate(temp[1]):
        if(podniz.isprintable() and not podniz.isupper() and not podniz=='|'):
            zavrsni.add(podniz)
#pretraži gramatiku za produkcije A->b i dodaj taj znak u set nezavrsnih
for i, produkcija in enumerate(gramatika):
    for j, zavr in enumerate(zavrsni):
        if(zavr in produkcija[1][1:]):
            nezavrsni.add(zavr)

nezavrsni=list(nezavrsni) #pretvori set u listu
nezavrsni.sort() # sortiraj listu
zavrsni=list(zavrsni)
zavrsni.sort()
zavrsni.append('┴')

print("Ulazna gramatika:",gramatika,'\n')              

tablica=[]

#popuni tablicu s 'Odbaci'
for i in range(0,len(nezavrsni)+1):
    for j in range(0,len(zavrsni)+1):
        tablica.append('Odbaci')


epsilon=set() # set za nezavršne znakove koje s desne strane imaju '|'
zamijeneProdukcija=[] # lista za zapis Zamijeni-Pomakni, oblik: [(redniBrZamijene,'Zamijeni(xy);Pomakni;')]
redniBrZamijene=0;

#punjenje tablice, zamijenuje se 'Odbaci' s jednim od 4 moguća scenarija  
for i, nezavr in enumerate(nezavrsni):
    for j,zavr in enumerate(zavrsni):
        for k, produkcija in enumerate(gramatika):
            if(nezavr==produkcija[0] and zavr==produkcija[1][0]):
                if(len(produkcija[1])>1):#produkcije oblika A->bα
                    #print("produkcija:",produkcija,"k;",k,"\nnezavr:",nezavr,"i:",i,"\nzavr:",zavr,"j:",j,"\n")
                    redniBrZamijene=redniBrZamijene+1
                    zamijeneProdukcija.append((redniBrZamijene,str('Zamijeni(\''+produkcija[1][:0:-1]+'\'); Pomakni;')))
                    tablica[i*len(zavrsni)+j]='('+str(redniBrZamijene)+')'
                if(len(produkcija[1])==1):#produkcije oblika A->b
                   tablica[i*len(zavrsni)+j]='Izvuci; Pomakni;'
            if('|' in produkcija[1]):#produkcije oblika A->|
                epsilon.add(produkcija[0])
            if(zavr==nezavr):#produkcije oblika A->αb
                tablica[i*len(zavrsni)+j]='Izvuci; Pomakni;'
#ako u gramatici postoje '|' zamijeni sve 'Odbaci' s 'Izvuci;Zadrzi'
for epsilonProd in epsilon:
    for i, nezavr in enumerate(nezavrsni):
        for j, zavr in enumerate(zavrsni):
            if(nezavr in epsilonProd and tablica[i*len(zavrsni)+j]=='Odbaci'):
                tablica[i*len(zavrsni)+j]='Izvuci; Zadrzi;'

#dodaj u tablicu na skroz donje mijesto 'Prihvati'                
tablica[len(nezavrsni)*len(zavrsni)+len(zavrsni)-1]='Prihvati'

nezavrsni.append('$')
#'lijepi' ispis
# ispis zavrsnih znakova
print('\t\t',end='')
for zavr in zavrsni:
    print(zavr.ljust(18),end='')
print()
#ispis elemenata tablice
for i, nezavr in enumerate(nezavrsni):
    print(nezavr,end='\t')
    for j, zavr in enumerate(zavrsni):
        print(tablica[i*len(zavrsni)+j].ljust(16) ,end='|')
    print('')
#ispis zamijenjenih produkcija [(1),(2),...]
print()
for i, zamijenjeneProd in enumerate(zamijeneProdukcija):
    print('('+str(zamijenjeneProd[0])+') =>\t',zamijenjeneProd[1])
#zaustavi program kako bi se očitali rezultati
input("\nPritisni 'Enter' za kraj...")
