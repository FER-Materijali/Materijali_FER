
// Za razliku od TSPJednostavni, ovaj ispisuje i put koji daje najmanji trošak

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXGRAD 15       // i to je previše s obzirom na n! 
// c – matrica udaljenosti izmeðu gradova (i, j)
int c[MAXGRAD][MAXGRAD]; // da ne kompliciramo s prijenosom 2D polja

typedef struct s {
    int cijena;
    int put[MAXGRAD];   // moglo bi sa malloc, ali radi jednostavnosti
} zapis;

void minus (int skup[], int n, int element) {
// operacija (skup \ element)	
	int i, j;
	for (i = 0; i < n; i ++) 
		if (skup[i] == element) break;
	for (j = i; j < n - 1; j ++) 
    	skup[j] = skup[j + 1];
}


zapis TSP (int IzGrada, int *gradovi, int n) {
	int *lgradovi, i;
	zapis minTSP, pomTSP;
	
	lgradovi = malloc (n * sizeof(int));
  	memcpy (lgradovi, gradovi, n * sizeof(int));
	minus (lgradovi, n, IzGrada);
  
	 -- n;
	if (n == 1) {
   		minTSP.cijena = c[IzGrada][lgradovi[0]];
		minTSP.put[0] = lgradovi[0];
		minTSP.put[1] = IzGrada;
  } else {
		minTSP = TSP (lgradovi[0], lgradovi, n);
   		minTSP.cijena += c[IzGrada][lgradovi[0]];
		minTSP.put[n] = IzGrada;
    for (i = 1; i < n; i++) {
		pomTSP = TSP (lgradovi[i], lgradovi, n);
		pomTSP.cijena += c[IzGrada][lgradovi[i]];
		pomTSP.put[n] = IzGrada;
		if (pomTSP.cijena < minTSP.cijena) 
			minTSP = pomTSP;
		}
	}
	free (lgradovi);
	return minTSP;
}

int main () {
 	int gradovi[MAXGRAD], n, i, j;
	zapis minTSP;
	srand (time(NULL));
	while (1) {
		do {
			printf ("\nUnesite broj gradova: ");
			scanf ("%d", &n);
		} while (n < 2 || n > MAXGRAD);
		// generiranje matrice
		for (i = 0; i < n; i++) {
			gradovi[i] = i;
			c[i][i] = 0;
			for (j = i + 1; j < n; j ++) {
#if 0
				c[i][j] = rand() + 1;
#else
				c[i][j] = i*10 + j;
#endif
				c[j][i] = c[i][j];
				printf ("c[%d][%d] = %d\n", i, j, c[i][j]);
			}
		}
 		minTSP = TSP (0, gradovi, n);
 		printf ("Najmanji trosak je: %d\n", minTSP.cijena);
		printf ("Put: ");
		for (i=n-1; i>=0; i--) 
			printf("%d ", minTSP.put[i]);
	}
		return 0;
}

