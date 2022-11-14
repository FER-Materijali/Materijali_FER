1. Napisite jednostavn program za cenzuriranje. Program cita rijeci (podnizove) koje treba
cenzurirati iz datoteke cenzurirano.txt te cenzurira datoteku ulaz.txt.
Za trazenje podniza u nizu napisite vlastitu funkciju prototipa
char *trazi(char *niz, char *podniz) koja vraca pokazivac na prvi znak pronadenog podniza u nizu
ili NULL ako isti nije pronadjen
Cenzuriranje se obavlja tako da se svaki podniz pronadjen u niz zamjeni sa znakovima * (onoliko puta 
kolika je duljina podniz)

Pretpostavka da su rijeci odvojene jednim razmakom

2. Potrebno je sljednu formatiranu datoteku ulaz.txt pretvoriti u direktnu neformatiranu izlaz.bin
Datoteka je direktna po ID-u. U datoteci ulaz.txt nece biti vise od 100 zapisa. Zapise sa IDem koji ne postoje,
moraju biti postavljeni na 0
Datoteka ulaz je u formatu
id ime prezime prosjek
id - broj
ime - znakovni niz ne dulji od 20 znakova
prezime - znakovni niz ne dulji od 20 znakova
prosjek - brojcana vrijednost dvostruke preciznosti

3. Za datoteku izlaz.bin je potrebno korisniku omoguciti izmjenu prosjeka. Korisnik unosi
ID osobe koja se trazi i novi prosjek. Provjeru prosjeka se ne mora raditi, no ako
ID ne postoji, potrebno je ispisati pogresku. Kada korisnik unese za ID 0, ispisuju se
sve osobe iz datoteke sa pripadajucim prosjekom
Potrebno je osigurati da se program ne srusi

4. Napisati program koji ce od korisnika traziti dimenzije matrica
(max je 20x20). Nakon toga ce ucitati elemente matrice (brojevi iz intervala 0-99)
i zapisati tu matricu kao sljednu formatiranu datoteku u matricaPrva.txt.

Napisati funkciju koja ima prototip
void stvori(int *mat, int brRed, int brStup, int maksStup, int poElementuBajtova)

koja ce citati matricu iz datoteke ulazna i popuniti matricu mat po sljedecem algoritmu

Elemente druge matrice treba
izračunati na temelju elemenata prve matrice, na način da element druge matrice u
retku r i stupcu s ima vrijednost koja odgovara razlici sume elemenata prve matrice
koji se nalaze u stupcu s iznad elementa na mjestu (r,s) i sume elemenata u retku r
lijevo od elementa na mjestu (r,s)

Nije dozvoljeno cijelu matricu ucitati u program!

Nakon stvaranja nove matrice, istu (cijelu!) je potrebno ispisati i spremiti u direktnu neformatiranu datoteku matricaDruga.bin

Za pregledavanje binarnih datoteka, skinite bilo koji Hex editor