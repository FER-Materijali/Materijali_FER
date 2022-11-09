Spremiti sve ove datoteke u isti folder!

Veæina primjera koristi "asp_massh.h" header. On služi za neke formatirane ispise da ne gubim vrijeme tijekom masovnih
na tipkanje ogrmonih printfova.

Za kompajliranje garantiram da radi s mingwom na ovaj naèin:

g++ -Wall <ime programa>

Neki æe izbaciti neka upozorenja, ali to je uredu.

hash_input_generator.c ispisuje N random primjera koji se mogu koristiti za primjer 09. Koristiti ovako:

g++ -Wall hash_input_generator.c
a 100 > test.txt

Na taj naèin æe se stvoriti datoteka test.txt koja ima 100 zapisa u sebi.

Have fun!