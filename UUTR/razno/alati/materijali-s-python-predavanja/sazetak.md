# Python

## Uvod
### Varijable

```python
x = 5
b = 'Hello'
c = "World"
d = b + c
```

### Operacije

```python
2 + 5 == 7
2 * 5 == 10
2 ** 5 == 32
2 / 5 == 0
2 / 5.0 == 0.4
'2' * 5 = '22222'
```

### Formatiranje stringova
```python
ime = 'Ferko'
prezime = 'Kompjuter'
'Pozdrav {0} {1}! Kako si?'.format(ime, prezime) == 'Pozdrav Ferko Kompjuter! Kako si?'
```

### Izvlačenje podataka iz stringova

#### Rastavljanje po nizu (delimiteru)
```python
niz = 'Lijeva strana -> Desna strana'
lijeva, desna = niz.split(' -> ')
lijeva == 'Lijeva strana'
desna == 'Desna strana'
```

#### Izvlačenje pomoću regularnih izraza (regex)

* .\* označava proizvoljan niz znakova (duljine 0 ili više)
* (.\*) označava da niz koji bude prepoznat bude grupiran kako bi kasnije do njega mogli doći

```python
import re

niz = 'A>>B<<C'
m = re.match(r'(.*)>>(.*)<<(.*)', niz)
m.group(1) == 'A'
m.group(2) == 'B'
m.group(3) == 'C'
```

## Unos sadržaja

### input

```python
x = input("Unesite broj: ")
```

Učitava unos kao Python izraz

### raw_input (input u Python 3.0+)

```python
x = raw_input("Unesite broj: ")
```

Učitava unos kao string

### sys.stdin.read()

```python
#import sys
sys.stdin.read()
```

### sys.stdin.readlines()

```python
#import sys
sys.stdin.readlines()
```

### Čitanje datoteka

```python
f = open('datoteka.dat', 'r')

f.read()
f.seek(0)
f.readlines()
```

### fileinput modul

```python
import fileinput

inp = fileinput.input()
inp.readline()

for line in inp:
    print(line)
```

### Strip funkcija

```python
'    Hello world    \n'.strip() == 'Hello world'
```

## Ispis sadržaja

### Direktno na stdout

```python
import sys

sys.stdout.write('Hello world!\n')
```

### Print

```python
print('Hello world!')
```

Implicitno pretvara argument u string. Ukoliko je potrebno to ručno odraditi, može se koristiti naredba str.

```python
str(25) == '25'
```

## Kontrola toka

### Grananje

```python
if x < 5:
    print('X je manji od 5')
elif x == 5:
    print('X je 5')
else:
    print('X je veći od 5')
```

### Iteracija
```python
for i in range(5):
    print('Redak #{0}'.format(i))
    print('Redak #' + str(i))
```

### Petlja
```python
x = 5
while x > 1:
    print('X = {0}'.format(x))
    x = x - 1
```

## Funkcije

```python
def zbroji(a, b, c=0):
    return a + b + c

zbroji(1, 2) == 3
zbroji(1, 2, 3) == 6
zbroji(b = 2, c = 1, a = 6) == 9
```

## Podatkovne strukture

### N-torke / tuples

Nepromijenjiva lista podataka. Služi za jednostavno pakiranje povezanih podataka.

```python
t = 1, 2, 3
t == (1, 2, 3)

t[0] == 1
t[1] == 2
t[1] = 5 # greška

a, b, _ = t
a == 1
b == 2

a, b = b, a
a == 2
b == 1
```

### Liste / list

Niz promjenjivih podataka proizvoljne duljine

```python
l = [1, 2, 3, 3]
l[0] == 1
l[0] = 5
l == [5, 2, 3, 3]
l.append(6)
l == [5, 2, 3, 3, 6]

5 in l == True
10 in l == False
range(4) == [0, 1, 2, 3]
```

### Skupovi / set

Skup jedinstvenih nepromijenjivih podataka

```python
s = {1, 2, 3, 3}
s == {1, 2, 3}
s[0] == 1
s[0] = 4 # greška
s == {1, 2, 3}
```

### Rječnici / dictionary

Skup ključ-vrijednost parova

```python
d = {'fer': 'Fakultet elektrotehnike i računarstva', 'pmf': 'Prirodoslovno matematički fakultet'}
d['fer'] == 'Fakultet elektrotehnike i računarstva'
d['ffzg'] = 'Filozofski fakultet Zagreb'
d.get('ffzg') == d['ffzg']
d.get['kif'] == None
```

Ključ može biti bilo koji objekt, uključujući i parove. Isto vrijedi i za vrijednost.

Metoda iteritems() pretvara rječnik u niz (ključ, vrijednost) objekata što nam kasnije omogućava lakšu iteraciju.

### Iteracija

```python
l = [0, 1, 2, 3]

for i in l:
    print(i)
    
for index, element in enumerate(l):
    print('Na mjestu {0} se nalazi element {1}'.format(index, element))

s = {0, 1, 2, 3}

for i in s:
    print(i)

d = {'klj': 'vrijednost', 'broj2': 'x'}

for key in d:
    print('{0} - {1}'.format(key, d[key]))

for key, value in d.iteritems():
    print('{0} - {1}'.format(key, value))

```

### Sortiranje

```python
sorted([1, 3, 2]) == [1, 2, 3]
```

### Comprehensions

Izrazi za građenje novih struktura podataka

#### Transformacija

```python
[ x**2 for x in [1, 2, 3]] == [1, 4, 9] # kvadriran svaki element niza

{ v:k for k, v in {'k1':'v1', 'k2':'v2'}.iteritems()} # obrnuti ključ i vrijednost rječnika
```

#### Filtriranje

```python
[ x for x in [1, 2, 3, 4, 5] if x % 2] == [1, 3, 5] # filtrirani samo neparni elementi
```

### Izravnavanje (flatten) liste lista
```python
sum([[1, 2, 3], [4, 5, 6]], []) == [1, 2, 3, 4, 5, 6]
```

### Ispis struktura

```python
'|'.join(['1', '2', '3', '4']) == '1|2|3|4'
```

# Implementacija DKA

## Struktura programa

<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" width="423px" height="73px" version="1.1"><defs/><g transform="translate(0.5,0.5)"><rect x="140" y="11" width="120" height="60" rx="9" ry="9" fill="#ffffff" stroke="#000000" pointer-events="none"/><g transform="translate(142,33)"><switch><foreignObject pointer-events="all" width="116" height="15" requiredFeatures="http://www.w3.org/TR/SVG11/feature#Extensibility"><div xmlns="http://www.w3.org/1999/xhtml" style="display: inline-block; font-size: 12px; font-family: Helvetica; color: rgb(0, 0, 0); line-height: 1.26; vertical-align: top; width: 116px; white-space: normal; text-align: center;">Program</div></foreignObject><text x="58" y="14" fill="#000000" text-anchor="middle" font-size="12px" font-family="Helvetica">[Not supported by viewer]</text></switch></g><path d="M 80 41 L 134 41" fill="none" stroke="#000000" stroke-miterlimit="10" pointer-events="none"/><path d="M 139 41 L 132 44 L 134 41 L 132 37 Z" fill="#000000" stroke="#000000" stroke-miterlimit="10" pointer-events="none"/><g fill="#000000" font-family="Helvetica" text-anchor="middle" font-size="11px"><rect fill="#ffffff" stroke="none" x="98" y="35" width="25" height="14" stroke-width="0"/><text x="110" y="44">stdin</text></g><path d="M 260 25 L 324 26" fill="none" stroke="#000000" stroke-miterlimit="10" pointer-events="none"/><path d="M 329 26 L 322 30 L 324 26 L 322 23 Z" fill="#000000" stroke="#000000" stroke-miterlimit="10" pointer-events="none"/><g fill="#000000" font-family="Helvetica" text-anchor="middle" font-size="11px"><rect fill="#ffffff" stroke="none" x="280" y="20" width="32" height="14" stroke-width="0"/><text x="295" y="30">stdout</text></g><path d="M 260 56 L 324 57" fill="none" stroke="#000000" stroke-miterlimit="10" pointer-events="none"/><path d="M 329 57 L 322 61 L 324 57 L 322 54 Z" fill="#000000" stroke="#000000" stroke-miterlimit="10" pointer-events="none"/><g fill="#000000" font-family="Helvetica" text-anchor="middle" font-size="11px"><rect fill="#ffffff" stroke="none" x="280" y="51" width="31" height="14" stroke-width="0"/><text x="295" y="60">stderr</text></g><rect x="0" y="1" width="70" height="30" fill="#ffffff" stroke="#00ff00" pointer-events="none"/><g transform="translate(2,8)"><switch><foreignObject pointer-events="all" width="66" height="15" requiredFeatures="http://www.w3.org/TR/SVG11/feature#Extensibility"><div xmlns="http://www.w3.org/1999/xhtml" style="display: inline-block; font-size: 12px; font-family: Helvetica; color: rgb(0, 0, 0); line-height: 1.26; vertical-align: top; width: 66px; white-space: normal; text-align: center;">SPRUT</div></foreignObject><text x="33" y="14" fill="#000000" text-anchor="middle" font-size="12px" font-family="Helvetica">[Not supported by viewer]</text></switch></g><rect x="0" y="41" width="70" height="30" fill="#ffffff" stroke="#00ff00" pointer-events="none"/><g transform="translate(2,48)"><switch><foreignObject pointer-events="all" width="66" height="15" requiredFeatures="http://www.w3.org/TR/SVG11/feature#Extensibility"><div xmlns="http://www.w3.org/1999/xhtml" style="display: inline-block; font-size: 12px; font-family: Helvetica; color: rgb(0, 0, 0); line-height: 1.26; vertical-align: top; width: 66px; white-space: normal; text-align: center;">konzola</div></foreignObject><text x="33" y="14" fill="#000000" text-anchor="middle" font-size="12px" font-family="Helvetica">[Not supported by viewer]</text></switch></g><rect x="350" y="26" width="70" height="30" fill="#ffffff" stroke="#00ff00" pointer-events="none"/><g transform="translate(352,33)"><switch><foreignObject pointer-events="all" width="66" height="15" requiredFeatures="http://www.w3.org/TR/SVG11/feature#Extensibility"><div xmlns="http://www.w3.org/1999/xhtml" style="display: inline-block; font-size: 12px; font-family: Helvetica; color: rgb(0, 0, 0); line-height: 1.26; vertical-align: top; width: 66px; white-space: normal; text-align: center;">SPRUT</div></foreignObject><text x="33" y="14" fill="#000000" text-anchor="middle" font-size="12px" font-family="Helvetica">[Not supported by viewer]</text></switch></g></g></svg>

## Ulaz
```
a|a,b|a,b,c
x,y,z
a,b,c
x,z
x
x,a->y
x,b->z
y,a->x
y,c->z
z,a->y
```

## Očekivani izlaz
```
x|y
x|y|y
x|y|y|z
```

## Implementacija

```python
import fileinput
import re

inp = fileinput.input()

ulazni = [x.strip().split(',') for x in inp.readline().split('|')]
stanja = inp.readline().strip().split(',')
abeceda = inp.readline().strip().split(',')
prihvatljiva = inp.readline().strip().split(',')
pocetno = inp.readline().strip()

prijelazi = {}

for linija in inp:
    m = re.match(r'(.*),(.*)->(.*)', linija)
    stanje, simbol, novo = m.group(1), m.group(2), m.group(3)
    prijelazi[(stanje, simbol)] = novo

for grupa in ulazni:
    stanje = pocetno
    povijest = []
    for znak in grupa:
        povijest.append(stanje)
        novo_stanje = prijelazi.get((stanje, znak))
        if novo_stanje:
            stanje = novo_stanje
    povijest.append(stanje)
    print('|'.join(povijest))
```

# Proširenje DKA na NKA

* Umjesto (jednog) trenutnog stanja sada imamo skup trenutnih stanja.
* Desna strana funkcije prijelaza je također skup stanja

Hints

* Dohvat idućeg skupa stanja možemo izvesti comprehensionom tako da filtiramo sve tranzicije koje nam odgovaraju
* Prilikom ispisa ćemo u povijesti imati listu listi pa će ju trebati izravnati

# Proširenje NKA na eNKA

* Uvođenje pojma epsilon prijelaza
* Prijelaz (stanjeX, €) -> [ _popis stanja_ ] izvršava se u istom koraku kada automat dođe u stanjeX
* Budući da jednim epsilon prijelazom automat može doći u stanje za koje također postoji epsilon prijelaz i tako u nedogled, za svako stanje postoji skup stanja u koje će automat doći epsilon prijelazom. Taj skup nazivamo epsilon okolinom.
* Načini izračuna okoline:
    * Prilikom prijelaza
    * Unaprijed, modificiranjem originalne tablice prijelaza
* Preporučen postepeni razvoj automata
    1. eNKA bez epsilon prijelaza
    2. eNKA s epsilon prijelazom jedne razine - nemoj gledati epsilon prijelaz za nova stanja
    3. eNKA s određivanjem epsilon okoline i prijelazom u sva stanja i mogućnošću beskonačne petlje
    4. eNKA s potpuno izvedenim epsilon prijelazima

# Savjeti

* __Performanse nisu bitne__

Ograničenja na SPRUTu su takva da eliminiraju programe koji zapnu u beskonačnoj petlji. U praksi nije potrebno trošiti mnogo vremena na optimiranje algoritama dokle god on radi ispravno.

* __Jezik izrade nije bitan__ - radite u onome što vam odgovara

* __Vrijeme izrade nije bitno isto kao ni broj linija rješenja__

Na FER2 će se uvijek naći nekoliko postova koji se hvale kako je labos riješen u x minuta u y linija koda. Ni x ni y sami po sebi nisu korisna metrika ukoliko sa sobom ne nose informaciju što je dovelo do uštede. Sasvim je normalno da nekome za ovaj labos treba umjesto x minuta x sati. Broj linija je također nebitan, dokle god program ispravno radi.
