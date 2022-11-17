import sys

gramatika = {}
primjeni = {}
tablica = {}
stog = []
stogLinija = []
ulaz = []

genStablo = []
genStabloRazmak = []

kraj = 0
linija = 0
ispis = ''

lZagrada = []
za = []
od = []

def zamijeni(lijevo, desno, primjeni):
    global stog
    global linija
    global genStablo
    global genStabloRazmak
    x = stog.pop()
    linija = stogLinija.pop()
    genStablo.append(x)
    genStabloRazmak.append(linija)
    for znak in reversed(desno):
        stog.append(znak)
        stogLinija.append(linija+1)

def pomakni(lijevo, desno, primjeni):
    global ulaz
    global linija
    global genStablo
    global genStabloRazmak
    s = ulaz[0][0] + ' ' + ulaz[0][1] + ' ' + ulaz[0][2]
    if( ulaz[0][0] == "L_ZAGRADA" ):
        lZagrada.append(linija)
    elif( ulaz[0][0] == "KR_ZA" ):
        za.append(linija)
    elif( ulaz[0][0] == "KR_OD" ):
        od.append(linija)
    elif( ulaz[0][0] == "D_ZAGRADA" ):
        linija = lZagrada.pop()
    elif( ulaz[0][0] == "KR_AZ" ):
        linija = za.pop()
    elif( ulaz[0][0] == "KR_DO" ):
          linija = od.pop()
    genStablo.append(s)
    genStabloRazmak.append(linija + 1)
    ulaz = ulaz[1:]

def izvuci(lijevo, desno, primjeni):
    global stog
    global linija
    global genStablo
    global genStabloRazmak
    lin = stogLinija.pop()
    x = stog.pop()
    if( x != ulaz[0][0] ):
        linija = lin
        genStablo.append(x)
        genStabloRazmak.append(linija)

def izvuciE(lijevo, desno, primjeni):
    global stog
    global linija
    global genStablo
    global genStabloRazmak
    x = stog.pop()
    linija = stogLinija.pop()
    genStablo.append(x)
    genStabloRazmak.append(linija)
    genStablo.append('$')
    genStabloRazmak.append(linija + 1)

def zadrzi(lijevo, desno, primjeni):
    pass

def prihvati(lijevo, desno, primjeni):
    global kraj
    kraj = 1
    
def obradiEpsilon(lijevo, desno, primjeni):
    for element in primjeni:
        tablica[(lijevo, element)] = ((izvuciE, lijevo, desno, primjeni), (zadrzi, lijevo, desno, primjeni))
    
def obradiZavrsni(lijevo, desno, primjeni):
    if( len(desno) > 1 ):
        tablica[(lijevo, desno[0])] = ((zamijeni, lijevo, desno[1:], primjeni), (pomakni, lijevo, desno, primjeni))
    else:
        tablica[(lijevo, desno[0])] = ((izvuci, lijevo, desno[1:], primjeni), (pomakni, lijevo, desno, primjeni))
    
def obradiNezavrsni(lijevo, desno, primjeni):
    for element in primjeni:
        tablica[(lijevo, element)] = ((zamijeni, lijevo, desno, primjeni), (zadrzi, lijevo, desno, primjeni))

def parser():
    global kraj
    global ispis
    while(kraj == 0):
        if stog:
            stanje = stog[-1]
        else:
            stanje = 'empty'
        if ulaz:
            ulazniNiz = ulaz[0]
            znak = ulazniNiz[0]
        else:
            znak = 'endIn'
        if (stanje, znak) in tablica:
            funkcije = tablica[(stanje, znak)]
            for par in funkcije:
                par[0](par[1], par[2], par[3])
        else:
            if znak == 'endIn':
                ispis = "err kraj\n"
            else:
                s = ulaz[0][0] + ' ' + ulaz[0][1] + ' ' + ulaz[0][2]
                ispis = "err " + s + "\n"
            kraj = 2
            break
    
f = open("grammar.txt", "r");

line = f.readline().replace('\n','')
while line != '':
    primjeniSkup = line.split("->")[1].split(" ");
    pravilo = line.split("->")[0].split("::=");
    desno = (pravilo[1].split(" "), primjeniSkup)
    if( pravilo[0] not in gramatika ):
        gramatika[pravilo[0]] = []
    lista = list(gramatika[pravilo[0]])
    lista.append(desno)
    gramatika[pravilo[0]] = lista
    line = f.readline().replace('\n','')

for lijevo in gramatika:
    for produkcija in gramatika[lijevo]:
        desno = produkcija[0]
        primjeni = produkcija[1]

        b = desno[0]
        if( b == '$' ):
            obradiEpsilon(lijevo, desno, primjeni)
        elif( b[0] == '<' ):
            obradiNezavrsni(lijevo, desno, primjeni)
        else:
            obradiZavrsni(lijevo, desno, primjeni)
            
znakoviStoga = ['KR_OD', 'KR_DO', 'KR_AZ', 'D_ZAGRADA', 'OP_PRIDRUZI', 'IDN']
for znak in znakoviStoga:
    tablica[(znak, znak)] = ((izvuci, lijevo, desno, primjeni), (pomakni, lijevo, desno, primjeni))

tablica[('empty', 'endIn')] = ((prihvati, lijevo, desno, primjeni), (prihvati, lijevo, desno, primjeni))

    

stog.append('<program>')
stogLinija.append(linija)

line = sys.stdin.readline().replace('\n','')
while line != '':
    ulaz.append(line.split(" "))
    line = sys.stdin.readline().replace('\n','')

parser()

if( kraj != 2 ):
    for i in range(0, len(genStablo)):
        s = ''
        for j in range(0, genStabloRazmak[i]):
            s += ' '
        s += genStablo[i]
        ispis += s + "\n"

ispis = ispis[:-1]
print ispis

