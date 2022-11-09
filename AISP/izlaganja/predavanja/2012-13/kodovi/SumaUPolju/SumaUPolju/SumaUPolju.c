#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float zbroj_poz (int brred, int brstup, int maxstup, float *p ) {
/* brred, brstup, int maxstup – ulazni parametri funkcije; njihova eventualna promjena u funkciji
 neæe biti saèuvana nakon povratka u glavni program. 
 Buduæi da se polje uvijek prenosi u funkciju kao pokazivaè, 
 vrijednost èlanova polja moguæe je u funkciji mijenjati */
	int i, j;
	float suma;
	suma = 0.0;
	for( i=0; i < brred; i++ )
		for( j = 0; j < brstup; j++ )
			if (p [i*maxstup + j] > 0) suma += p[i*maxstup + j]; 
			/* može i suma += *(p + i*maxstup + j)
 			 nije dozvoljeno p(i,j), p[i][j] i slièno */
	return suma;
}

#define MAXRED	 100
#define MAXSTUP	 20
int main() {
	int i, j, red, stup;
	float zbroj, mat[MAXRED][MAXSTUP];
	/* ovdje slijedi postavljanje stvarnog broja redova i stupaca 
	(red<=MAXRED, stup<=MAXSTUP, punjenje polja */
  srand ((unsigned) time(NULL));
  red = rand() % MAXRED + 1;
  stup = rand() % MAXSTUP + 1 ;
  for (i = 0; i < red; ++i) 
    for (j = 0; j < stup; ++j)
      mat[i][j] = (float) rand() - RAND_MAX;

	zbroj = zbroj_poz(red, stup, MAXSTUP, (float *) mat); 
	return 0;
}
