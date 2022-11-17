# UTR Test Script
Daklem, budući da je većina ljudi impresionirana pajtonom (ubi me bože) onda evo jedna jednostavna pajton skripta za testiranje labosa.

Ova skripta se može koristiti i za ostale labose, ne samo za prvi labos. Maknite stare testove i stavite nove za novi vježbu.

## Upute za korištenje
1. Prvo provjerite dali imate datoteku "test.py" u folderu "UTRT" koji ste odzipali.
2. Kopirajte svoj automat u "UTRT"
3. Otvorite folder "UTRT" u terminalu (za windows, [shift + desni_klik] na folder i dobili bute opciju open in terminal il tak neš)
4. Upišite ovu komandu : test.py moj_uber_automat.py
5. Program će vam ispisati statistiku za svaki od testova

## Napomene
Izlaz vašeg programa za svaki test sprema se u direktorij testa kao datoteka "test.u" tako da možete inspicirati svoje izlaze do mile volje.

Pazite da vam program ne ispisuje negdje višak spaceova ili višak novih linija. Samo jedna prazna linija smije ići na kraj, tako da ako vam je test failo a pogledali ste očekivanu datoteku "test.b" i vaš izlaz "test.u" i izgledaju identično, onda vam negdje stoji višak spaceova ili na kraju datoteke imate jednu praznu liniju viška.

Mislim da vam i SPRUT gleda te stvari pa ispravite to.

Ako je datoteka prazna i test vam je ispao "fail" onda to znaći da vam se srušio program. Ako želite vidjeti ispis errora za taj test onda iz direktorija "UTRT" pokrenite ovu naredbu:

moj_uber_automat.py < testXX/test.a (testXX zamjenite sa pravim testom)

Ako ne možete pokrenuti svoj program kao "moj_program.ekstenzija < definicija_automata.a" onda vam ne štima primanje podataka i to morate ispraviti inače bu vas SPRUT failo.



# Tips and tricks
Ova skripta se može koristiti i za ostale labose, samo maknite stare testove i stavite nove.

Ako želite spremiti log koji vam ispisuje moj test program ga morate pokrenuti ovako : test.py automat.py > log.txt

Možete dodati nove testove. Samo napravite novi folder "moj_novi_test" i u njemu datoteku sa definicijom automata nazvanu "test.a", i datoteku s očekivanim izlazom "test.b"

Pazite da imate na kraju jednu praznu liniju, inače vam možda ne bude dobro ocjenjivao.

♠ Jinx ♦