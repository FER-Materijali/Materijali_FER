// GomiluStvori.c
#include <stdio.h>
#include <math.h>
#define MAXGOM 100
typedef int tip;
// ubacuje vrijednost iz A[k] na gomilu pohranjenu u A[1:k-1]
void ubaci (tip A[], int j) { 
  int i, k; 
  tip novi;
  k = j; 
  i = j/2; 
  novi = A[j];
  while ((i > 0) && (A[i] < novi)) {
    A[k] = A[i]; // spusti roditelja na vecu razinu
    k = i; 
    i /= 2;	   // roditelj od A[i] je na A[i/2]
  }
  A[k] = novi;
}
int main () {
  FILE *fi;
  int i, j, k;
  tip A[MAXGOM];
  // citaj i ubacuj u gomilu
  fi = fopen ("UlazZaGomilu.txt", "r");
  if (fi) {
		j = 1;
		while (j < MAXGOM && fscanf(fi, "%d", &A[j]) != EOF) {
			printf ("%d. ulazni podatak je %d\n", j, A [j]);
			ubaci (A, j);
			j++;
		}
		fclose (fi);
		// ispisi gomilu po retcima
		i = 1;
		k = 1;
		while (i < j) { // petlja do zadnjeg u gomili
			// pisi do maksimalnog u gomili razine k
			for (; i <= pow (2, k) - 1 && i < j; i++) {
				printf(" %d ", A[i]);
			}
			k++; // spusti se na vecu razinu
			printf ("\n");
		}
	} else {
		printf ("Nema ulazne datoteke\n");
	}
	getchar();
	return 0;
}




