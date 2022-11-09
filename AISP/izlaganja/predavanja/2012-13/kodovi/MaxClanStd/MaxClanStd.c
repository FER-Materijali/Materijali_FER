// MaxClanStd.c
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define MAX 10
typedef int tip; // primjer za viseoblicje

// trazenje najveceg clana u polju A od n clanova
tip maxclan (tip A[], int n) {
  int i, imax;
  imax = 0;	// uzmimo da je prvi najveci
  for (i = 1; i < n; i++) {		// provjerava ostale
	printf ("trenutni A[%d]=%3d ? najveci A[%d]=%3d", 
						i, A[i], imax, A[imax]);
    if (A[i] > A[imax])	{	// i-ti je veci
		imax = i;		// zapamti mu indeks
		printf (" => novi imax=%d", imax);
	}
	printf ("\n");
   }
  return A[imax];	// vrati vrijednost najveceg clana
}

int main () {
  FILE *fi;
  int j, n;
  tip A[MAX];
  fi = fopen ("UlazZaMaxClanStd.txt", "r");
  if (!fi) exit (1);
  n = 0;
  while (n < MAX && fscanf (fi, "%d", &A[n]) != EOF) n++;
  for (j = 0; j < n; j++) printf("A[%d] = %3d\n", j, A[j]);
  printf ("Najveci clan je %d\n", maxclan(A, n));
  fclose (fi);

  return 0;
}
