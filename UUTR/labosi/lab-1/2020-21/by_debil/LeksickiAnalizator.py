import sys

keywords = ('za', 'od', 'do', 'az')
operators = ('=', '+', '-', "*", "/", "(", ")")
ulazna_lista = []
konacni_ispis = []
dict_keyworda = {
    '=': 'OP_PRIDRUZI',
    '+': 'OP_PLUS',
    '-': 'OP_MINUS',
    '*': 'OP_PUTA',
    '/': 'OP_DIJELI',
    '(': 'L_ZAGRADA',
    ')': 'D_ZAGRADA',
    'za': 'KR_ZA',
    'od': 'KR_OD',
    'do': 'KR_DO',
    'az': 'KR_AZ',
}

for ulaz in sys.stdin:
    ulazna_lista.append(ulaz.rstrip())

for broj_retka, ulazni_redak in enumerate(ulazna_lista):
    #potrebna varijabla
    pocetni_ulazni_redak = ulazni_redak

    # izbaci nepotrebno
    if ulazni_redak.startswith("//"):
        continue
    if ulazni_redak.find("//") != -1:
        ulazni_redak = ulazni_redak[0:ulazni_redak.find("//")]

    # glavna logika
    if ulazni_redak.strip().startswith(keywords):
        lista_rijeci = ulazni_redak.split(" ")
        for rijec in lista_rijeci:
            if rijec in keywords:
                konacni_ispis.append(f'{dict_keyworda.get(rijec)} {broj_retka + 1} {rijec}')
            else:
                trenutni_izraz = ""
                vrsta_izraza = ""
                for broj, znak in enumerate(rijec):
                    if znak == " ":
                        if trenutni_izraz != "":
                            if vrsta_izraza == "num":
                                konacni_ispis.append(
                                    f'BROJ {broj_retka + 1} {trenutni_izraz}')
                            elif vrsta_izraza == "var":
                                konacni_ispis.append(
                                    f'IDN {broj_retka + 1} {trenutni_izraz}')
                        vrsta_izraza = ""
                        trenutni_izraz = ""
                    elif znak in operators:
                        if vrsta_izraza == "var":
                            konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')
                            trenutni_izraz = ""
                            vrsta_izraza = ""
                        if vrsta_izraza == "num":
                            konacni_ispis.append(
                                f'BROJ {broj_retka + 1} {trenutni_izraz}')
                            trenutni_izraz = ""
                            vrsta_izraza = ""
                        konacni_ispis.append(
                            f'{dict_keyworda.get(znak)} {broj_retka + 1} {znak}')
                    elif znak.isnumeric():
                        if vrsta_izraza == "var":
                            konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')
                            trenutni_izraz = ""
                        trenutni_izraz += znak
                        vrsta_izraza = "num"
                    elif znak.isalpha():
                        if vrsta_izraza == "num":
                            konacni_ispis.append(
                                f'BROJ {broj_retka + 1} {trenutni_izraz}')
                            trenutni_izraz = ""
                        trenutni_izraz += znak
                        vrsta_izraza = "var"
                    if broj + 1 == len(rijec):
                        if vrsta_izraza == "num":
                            konacni_ispis.append(
                                f'BROJ {broj_retka + 1} {trenutni_izraz}')
                        if vrsta_izraza == "var":
                            konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')

    else:
        trenutni_izraz=""
        vrsta_izraza=""
        for broj, znak in enumerate(ulazni_redak):
            if znak == " ":
                if trenutni_izraz != "":
                    if vrsta_izraza == "num":
                        konacni_ispis.append(f'BROJ {broj_retka + 1} {trenutni_izraz}')
                    elif vrsta_izraza == "var":
                        konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')
                vrsta_izraza = ""
                trenutni_izraz = ""
            elif znak in operators:
                if vrsta_izraza == "var":
                    konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')
                    trenutni_izraz = ""
                    vrsta_izraza = ""
                if vrsta_izraza == "num":
                    konacni_ispis.append(f'BROJ {broj_retka + 1} {trenutni_izraz}')
                    trenutni_izraz = ""
                    vrsta_izraza = ""
                konacni_ispis.append(f'{dict_keyworda.get(znak)} {broj_retka + 1} {znak}')
            elif znak.isnumeric():
                if vrsta_izraza == "var":
                    konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')
                    trenutni_izraz = ""
                trenutni_izraz+=znak
                vrsta_izraza="num"
            elif znak.isalpha():
                if vrsta_izraza == "num":
                    konacni_ispis.append(f'BROJ {broj_retka + 1} {trenutni_izraz}')
                    trenutni_izraz = ""
                trenutni_izraz+=znak
                vrsta_izraza="var"
            if broj + 1 == len(ulazni_redak):
                if vrsta_izraza == "num":
                    konacni_ispis.append(f'BROJ {broj_retka + 1} {trenutni_izraz}')
                if vrsta_izraza == "var":
                    konacni_ispis.append(f'IDN {broj_retka + 1} {trenutni_izraz}')

for red in konacni_ispis:
    print (red)