#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Kontrola (char JMBG[]) {
  int i, kz;
  long suma;
  char tez [12+1] = "765432765432";
  suma = 0; 
  for (i = 0; i < 12; i++) {
    suma += (JMBG[i] - '0') * (tez[i] - '0');
  }
  kz = 11 - (suma  % 11);
  if (kz == 10) kz = -1; // pogr. kontrolna znamenka
  if (kz == 11) kz = 0;
  return kz;
}

char * datum (char *JMBG) {
	int d, m, g; // lokalne varijable – vrijede samo unutar funkcije
	char *p; // pokazivaè je deklariran, ali nije inicijaliziran!
	// Citanje iz niza
	// JMBG ima oblik DDMMYYYXXXXXX
	sscanf (JMBG, "%2d%2d%3d", &d, &m, &g); 
	// Ispis u niz treba biti oblika DD.MM.GGGG.
  p = (char *) malloc (11 * sizeof(char));
  //* pokazivaè je inicijaliziran i naredbom malloc zauzeta je memorija potrebna za pohranu datuma u formatu DD.MM.GGGG */
	// 21. stoljece?
	if (g < 100){
		g += 2000;
	} else {
		g += 1000;
	}
	sprintf (p, "%02d.%02d.%04d", d, m, g); 
  // datum je zapisan na adresu na koju pokazuje pokazivaè p
	return p;
}

int main () {
	int kz;
	char JMBG [13+1], *p;
	while (1) {
		printf ("\nUpisite JMBG >");
		scanf ("%13s", JMBG);
		kz = Kontrola (JMBG);
		if ((JMBG [12] - '0') == kz){
			p = datum (JMBG);
			printf ("\nDatum rodjenja je %s", p);
            free(p);
		} else {
			printf ("\nNeispravan JMBG: %s:\n", JMBG);
			break;
		}
	}
	return 0;
}
		 


