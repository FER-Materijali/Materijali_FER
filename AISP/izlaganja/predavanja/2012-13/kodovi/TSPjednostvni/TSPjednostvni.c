#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXGRAD 15       // i to je previše s obzirom na n! 
// c – matrica udaljenosti izmeðu gradova (i, j)
int c[MAXGRAD][MAXGRAD]; // da ne kompliciramo s prijenosom 2D polja

// ispis znaka c u zadanoj duljini n
void nznak (int c, int n) {
  while (--n >= 0) putchar(c);
}

// operacija \ (skup \ element)
void minus (int skup[], int n, int element){
	int i, j;
	for (i = 0; i < n; i ++) 
    if (skup[i] == element) break;
  for (j = i; j < n - 1; j ++)
   	skup[j] = skup[j + 1];
}

// ispisuje tekst pa vrijednosti clanova
void PisiPolje(char *s, int *p, int n) {
  int i;
  printf("%s ", s);
  for (i=0; i < n; ++i) 
    printf ("%d ", p[i]);
  printf("\n");
}

int TSP (int IzGrada, int *gradovi, int n) {
	int *lgradovi, minTSP, pomTSP, i;
	lgradovi = malloc (n * sizeof(int));
  memcpy (lgradovi, gradovi, n * sizeof(int));
	minus (lgradovi, n, IzGrada);

  //PisiPolje("gradovi", gradovi, n);
  //PisiPolje("lgradovi", lgradovi, n);

  -- n;
  nznak(' ', 5-n); printf("> %d\n", IzGrada);
  if (n == 1) {
   	minTSP = c[IzGrada][lgradovi[0]];
  } else {
  	minTSP = c[IzGrada][lgradovi[0]] 
			+ TSP (lgradovi[0], lgradovi, n);
   	for (i = 1; i < n; i++) {
   		pomTSP = c[IzGrada][lgradovi[i]] 
			+ TSP (lgradovi[i], lgradovi, n);
      if (pomTSP < minTSP) { 
        minTSP = pomTSP;
      }
		}
	}

  nznak(' ', 5-n); printf("< %d (%d)\n", IzGrada, minTSP);
	free (lgradovi);
	return minTSP;
}

int main () {
  int gradovi[MAXGRAD], n, i, j, minTSP;
	srand (time(NULL));
	do {
		printf ("Unesite broj gradova: ");
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
	printf ("Najmanji trosak je: %d\n", minTSP);
	return 0;
}

