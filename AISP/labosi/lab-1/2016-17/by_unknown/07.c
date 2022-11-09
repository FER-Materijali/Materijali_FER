#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int *sqShuffle(int *p, int n);

int main(void) {
	int n, *p, *rez, i;
	
	printf("n: ");
	scanf("%d", &n);
	
	p = (int *)malloc(sizeof(int) * n);
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		exit(1);
	}
	
	printf("Clanovi polja:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", (p + i));
	}
	
	rez = sqShuffle(p, n);
	
	for(i = 0; i < n; i++) {
		printf("%d\n", *(rez + i));
	}
	
	free(p);
	free(rez);
	return 0;
}

int *sqShuffle(int *p, int n) {
	int *rez, i, brojShuffleova, n1, n2, pom;
	rez = (int *)malloc(sizeof(int) * n);
	if(!rez) {
		printf("Nema dovoljno memorije!\n");
		exit(2);
	}
	
	srand((unsigned)time(NULL));
	
	for (i = 0; i < n; i++) {
		*(rez + i) = *(p + i) * *(p + i);
	}
	
	/*broj shuffleova se moze proizvoljno mijenjati 
	ovisno o tome koliko 'dobar' zelimo shuffle*/
	brojShuffleova = n*n;
	for (i = 0; i < brojShuffleova; i++) {
		n1 = rand()%n;
		n2 = rand()%n;
		pom = *(rez + n1);
		*(rez + n1) = *(rez + n2);
		*(rez + n2) = pom;
	}
	
	return rez;
}