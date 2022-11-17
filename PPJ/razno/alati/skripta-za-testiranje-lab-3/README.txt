// by Martin Sosic

Koraci koje je potrebno napraviti:

1. pozicionirajte se u test_skripta/ direktorij

2. omoguciti izvrsavanje skripta (to treba samo jednom) analyze.sh i compare.sh, a to se radi ovako:
   -upisati u terminal naredbe:
    sudo chmod +x analyze.sh
    sudo chmod +x compare.sh
    
3. prekopirajte svoj izvrsni program u direktorij test_skripta (u njemu se sad nalazite)
   i nazovite ga analizator (bez ikakvih nastavaka tipa .exe ili slicno, samo "analizator")
   
4. Sada krece testiranje, izvrsite sljedece naredbe (i dalje smo u test_skripta direktoriju):
    ./analyze.sh
    ./compare.sh       (tek nakon sto analyze.sh zavrsi s poslom)
    
5. Sada su analiza i usporedba rezultata gotovi. u tvoj_output/ direktoriju se nalaze
   tvoji rezultati tj. ispis iz semantickog analizatora, a u razlike.txt su zapisane razlike izmedju
   tvojih i ocekivanih rezultata.
   Prouci razlike.txt da bi nasao gdje imas greske. Kada naidjes na gresku, najbolje je potraziti taj file gdje je greska
   u direktoriju input/., tj. takav .c file da vidis koji je to kod prouzrocio gresku.

CITANJE razlike.txt dokumenta:
 zapisi su ovog formata:
 
 input/ime_dokumenta.in
 ===========================================
 razlike izmedju tvojeg izlaza i ocekivanog izlaza


 npr. ako pise:
 input/01188136ecbf0c35092d4e1936c83d80.in
 ===========================================
 input/015054ee8a33ec0cd6e56d89f68e9462.in
 ===========================================
 input/0198dde424b1909f562735b85dd8338e.in
 ===========================================
 neka poruka o gresci
 input/01bcb050d3bcd0bd75e95207be2a2783.in
 ===========================================
 
 onda je gresku prouzrokovao program koji pise u 0198dde424b1909f562735b85dd8338e.c 
 
 
 Detaljnije o porukama o gresci:
 Koristio sam diff naredbu, pa proucite njen ispis.
 Uglavnom ako pise:
 
  0a1:
   <ocekivan ispis>
 To onda znaci tvoj analizator nije ispisao nista, a trebao je ispisati <ocekivan ispis>.
 
  1d0:
    <tvoj ispis>
 To znaci da je tvoj analizator ispisao <tvoj ispis>, a nije trebao ispisati nista.
 
  1c1:
    <tvoj_ispis>
    ----
    <ocekivani_ispis>
 To znaci da je tvoj analizator ispisao <tvoj_ispis>, a trebao je ispisati <ocekivani_ispis>.


Kada u razlike.txt ne bude ispisano nikakvih pogresaka, to onda znaci da je sve u redu.
  
