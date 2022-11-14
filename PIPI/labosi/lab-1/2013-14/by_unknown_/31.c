#include <stdio.h>
#include <math.h>

int main (void){

int n,m;


printf ("Unesite dva cijela broja: ");
scanf ("%d%d", &n, &m);


if ((n+m)>0) printf ("Aritmeticka sredina brojeva %d i %d je: %.4f", n,m, (n+m)/2.);
else printf ("Izracunata vrijednost: %.4f", 1./(abs(n))+1./(abs(m)));

return 0;
}

/*Tekst zadatka je krivo definiran. Prema ispisu, zadatak treba glasiti: "Inače ispisati zbroj apsolutnih, 
recipročnih vrijednosti ucitanih brojeva..."
Ako se ide raditi prema tekstu zadatka, dobije se krivi rezultat*/

