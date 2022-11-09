// GomiluPodesi.c
#include <stdio.h>
#include <math.h>
#define MAXGOM 100
typedef int tip;
// potpuna binarna stabla s korijenima A[2*i]
// i A[2*i+1]kombiniraju se s A[i] formirajuci
// jedinstvenu gomilu
// 1 <= i <= n     
void podesi (tip A[], int i, int n) {
  int j; 
  tip stavka;
  j = 2*i;
  stavka = A[i];
  while (j <= n ) {
    // Usporedi lijevo i desno dijete (ako ga ima)
    if ((j < n) && (A[j] < A[j+1])) j++;
    // j pokazuje na vece dijete
    if (stavka >= A[j]) break;	// stavka je na dobrom mjestu
    A[j/2] = A[j];				// vece dijete podigni za razinu
    j *=2;
  }
  A[j/2] = stavka; // pohrani stavku
}
// premjesti elemente A[1:n] da tvore gomilu 
void StvoriGomilu (tip A[], int n) {
  int i;
  for (i = n/2; i >= 1; i--) 
		podesi (A, i, n);
}
int main(void) {
	FILE *fi;
	int i, j, k, n;
	tip A[MAXGOM]; // gomila
	// citanje podataka
	fi = fopen ("UlazZaGomilu.txt", "r");
	if (fi) {
		j = 1;
		while (j < MAXGOM && fscanf (fi, "%d", &A[j]) != EOF) {
			printf ("%d. ulazni podatak je %d \n", j, A[j]);
			j++;
		}
		fclose (fi);
		// podesi broj elemenata i stvori gomilu
		n = j - 1;
		StvoriGomilu (A, n);
		// ispisi gomilu po retcima
		i = 1;
		k = 1;
		while (i < j) { // petlja do zadnjeg u gomili
			// pisi do maksimalnog u gomili razine k
			for (; i <= pow (2, k) - 1 && i < j; i++) {
				printf(" %d ", A[i]);
			}
			k++; // povecaj razinu
			printf ("\n");
		}
	} else {
		printf ("Nema ulazne datoteke\n");
	}
	getchar();
	return 0;
}
