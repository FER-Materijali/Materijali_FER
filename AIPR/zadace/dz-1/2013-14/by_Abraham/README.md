 Zadatak za prvu lab. vježbu

U okviru ove vježbe potrebno je izraditi odgovarajući program, dok će se izrada skripte u MATLAB-u pokazati na auditornim vježbama. MATLAB-om možete provjeriti ispravnost rada vašega programa.

1. Implementirati razred Matrica (ili tako nekako) koji omogućava jednostavnije rukovanje objektima tipa dvodimenzionalne matrice. Razred mora imati barem sljedeće elemente:



     public metode za zbrajanje, oduzimanje, množenje i transponiranje matrica, te metode koje obavljaju C operatore "+=" i "-=". Preporuča se da budu implementirane kao nadgrađeni operatori.


Razredu Matrica treba dodati:

    metode koje izvode supstituciju unaprijed i supstituciju unatrag. Metode neka kao ulazni parametar (slobodni vektor s desne strane znaka jednakosti) primaju vektor čija je duljina jednaka dimenziji kvadratne matrice, a koji je i sam ostvaren objektom razreda Matrica. Također trebaju vraćati vektor kao objekt tipa Matrica (u kojemu će biti upisano rješenje odgovarajućeg postupka).

    metodu (metode) koje izvode LU i LUP dekompoziciju (kvadratne) matrice koristeći isti memorijski prostor za spremanje rezultantnih matrica L i U. Izbor odgovarajuće metode može se riješiti nekim dodatnim kontrolnim parametrom. Obratiti pažnju na mogućnost pojave nule kao stožernog (pivot) elementa (metode moraju imati neki mehanizam otkrivanja pogreške!).

    operator == za usporedbu matrica; kakva treba biti usporedba double brojeva kako bi uspoređivanje dalo očekivane rezultate? Isprobajte operator sa elementima matrice kao necijelim brojevima, pomnožite i podijelite sa realnim brojem i usporedite s originalom.

    nije obvezatno, ali može pomoći: metode koje manipuliraju stupcima matrice (postavljaju i vraćaju određeni stupac matrice pomoću objekta istoga tipa), jer se operacije te vrste često koriste u opisanim postupcima.

Obratiti pažnju na situacije u kojima se kao stožerni element može pojaviti nula ili neka jako mala vrijednost (i kod LU i kod LUP dekompozicije). Program treba 'preživjeti' pojavu takvih okolnosti i prijaviti grešku.

Po želji je moguće (nije obvezatno) definirati i novi razred koji predstavlja sustav jednadžbi te ima ugrađene metode koje automatiziraju rješavanje sustava (tj. pozivanje dekompozicije i obje supstitucije).

Glavni program na laboratorijskim vježbama treba iz zadanih datoteka pročitati matricu sustava i slobodni vektor u zadanom formatu (vidi primjer na dnu stranice) te riješiti takav sustav. Rješavanje sustava se treba odvijati u koracima i u svakom koraku moraju se moći vidjeti međurezultati. Rješenje također mora biti prikazano u datoteci ili na zaslonu.



Primjer ulazne datoteke matrice (elementi matrice 4x3 po retcima):

12.5 3.0 9 2
4 5 6 7
8 9 10 11

1) Primjer ulaznih datoteka sustava jednadžbi (ovaj sustav se može riješiti samo LUP dekompozicijom! Primjere za LU uzmite sa auditornih vježbi):

"A.txt"
3 9 6
4 12 12
1 -1 1

"b.txt"
12
12
1

2) Primjer matrice sustava koja je singularna (sustav zadan ovom matricom nema rješenja):

"A.txt"
1 2 3
4 5 6
7 8 9 