#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAXPRIOR 100
typedef int tip;

void podesi (tip A[], int i, int n) {
	// potpuna binarna stabla s korijenima A[2 * i] i A[2 * i + 1]
	// kombiniraju se s A[i] formirajuci jedinstvenu gomilu
	// 1 <= i <= n       
	int j; 
	tip stavka;
	j = 2 * i; stavka = A[i];
	while (j <= n) {
		// Usporedi lijevo i desno dijete (ako ga ima)
		if ((j < n) && (A[j] < A[j + 1])) j++;
		// j pokazuje na vece dijete
		if (stavka >= A[j]) break;	// stavka je na dobrom mjestu
		A[j / 2] = A[j]; // vece dijete podigni za razinu
		j *= 2;
	}
	A[j / 2] = stavka;
}
void ubaci (tip A[], int k) { 
	// ubacuje vrijednost iz A[k] na gomilu pohranjenu u A[1 : k - 1]
	int i; 
	tip novi;
	i = k / 2; 
	novi = A[k];
	while ((i > 0) && (A[i] < novi)) {
		A[k] = A[i]; // spusti roditelja na vecu razinu
		k = i; 
		i /= 2;	   // roditelj od A[i] je na A[i/2]
	}
	A[k] = novi;
}
tip skini (tip A[], int *k) { 
	// izbacuje vrijednost iz A[k] sa prvog mjesta
	// ako je red prazan vraca -1
	tip retVal = -1;
	if (*k <= 1) return retVal;
	retVal = A[1];
	(*k) --;
	A[1] = A[*k];
	podesi (A, 1, *k);
	return retVal;
}
int main() {
	int prior, i, j, k = 1;
	tip A[MAXPRIOR];
	srand((unsigned) time(NULL));
	while(1) {
		if (rand() % 2) {
			if (k >= MAXPRIOR)
				printf("Red prioriteta pun!\n");
			else {
				printf("Dodavanje u red prioriteta: %d\n",
				prior=(int)(rand()/(RAND_MAX + 1.) * 99 + 1));
				A[k] = prior;
				ubaci(A, k);
				k++;
			}
		} else {
			if ((prior = skini(A, &k)) == -1)
				printf("Red prioriteta prazan!\n");
			else
				printf("Skidanje iz reda prioriteta: %d\n", prior);
		}
		for (i = 1, j = 1; i < k; j++) {
			for (; i <= pow (2, j) - 1 && i < k; i++) {
				printf(" %d ", A[i]);
			}
			printf ("\n");
		}
		printf("Jos (d/n)? ");
		if (getchar() == 'n') return 0;
	}
}
