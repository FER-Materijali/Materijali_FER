import fileinput
import re

inp = fileinput.input()

ulaz = [x.split(',') for x in inp.readline().strip().split('|')]
stanja = inp.readline().strip().split(',')
abeceda = inp.readline().strip().split(',')
pocetno = inp.readline().strip()
prihvatljiva = inp.readline().strip().split(',')

tablicaPrijelaza = {}

for linija in inp:
    m = re.match(r'(.*),(.*)->(.*)', linija)
    # na desnoj strani ce biti skup stanja
    poc, sim, kon = m.group(1), m.group(2), m.group(3)
    tablicaPrijelaza[(poc, sim)] = kon

# ukljuciti epsilon okoline u tablicu prijelaza

for grupaUlaza in ulaz:
    # stanje mora biti skup
    stanje = pocetno
    povijest = [pocetno]
    for simbol in grupaUlaza:
        # iz tablice prijelaza dohvatiti prijelaze za sva stanja
        konacno = tablicaPrijelaza.get((stanje, simbol))
        if not konacno:
            konacno = '#'
        stanje = konacno
        povijest.append(stanje)
    # ispis ce biti lista listi stanja pa ce ju trebati drugacije ispisati
    print('|'.join(povijest))
