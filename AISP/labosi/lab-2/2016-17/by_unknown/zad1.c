#include <stdio.h>

typedef struct{
	int pb;
	char mjesto[40 + 1];
} zapis;

void printer(zapis *polje, int n){
	int i;
	printf("kontrolni ispis\n");
		for (i = 0; i < n; i++)
			printf("%d %s\n", polje[i].pb, polje[i].mjesto);
	return;
}

void insertionSort(zapis *A, int n, char smjer) {
	int i, j;
	zapis pom;
	for (i = 1; i < n; i++) {
		pom = A[i];
		for (j = i; j >= 1; j--) {
			if (!(smjer) && A[j - 1].pb <= pom.pb) break;
			else if (smjer && A[j - 1].pb >= pom.pb) break;
			A[j] = A[j - 1];
		}
		A[j] = pom;
	}
	return;
}

int main(void) {
	zapis polje[10];
	int i, j, n=0, f;
	do {
		printf("Unesi postanski broj i naziv mjesta (0 0 za kraj): ");
		scanf("%d %s", &polje[n].pb, &polje[n].mjesto);
		if (polje[n].pb == 0) break;
		n++;
	} while (n < 10);
	printf("Uzlazno [0], silazno [1]: ");
	scanf("%d", &f);
	insertionSort(polje, n, f);
	printer(polje, n);
	return 0;
}