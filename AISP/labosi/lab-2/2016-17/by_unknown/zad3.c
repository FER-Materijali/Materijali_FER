#include <stdio.h>

typedef struct {
	int sifra;
	char naziv[50 + 1];
} zapis;

void zamijeni(zapis* prvi, zapis* drugi) {
	zapis pom;
	pom = *prvi;
	*prvi = *drugi;
	*drugi = pom;
	return;
}

void printer(zapis *polje, int n) {
	int i;
	printf("kontrolni ispis\n");
	for (i = 0; i < n; i++)
		printf("%d %s\n", polje[i].sifra, polje[i].naziv);
	return;
}
void obicanBubbleSort(zapis *A, int n, char smjer) {
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < (n - i - 1); j++) {
			if (!smjer) {
				if (A[j].sifra > A[j + 1].sifra)
					zamijeni(A + j, A + j + 1);
			}
			else {
				if (A[j].sifra < A[j + 1].sifra)
					zamijeni(A + j, A + j + 1);
			}
		}
	}
	return;
}

int main(void) {
	zapis polje[10];
	int n=0, f;
	do {
		printf("Unesi sifru i naziv jela (0 0 za kraj): ");
		scanf("%d %s", &polje[n].sifra, polje[n].naziv);
		if (polje[n].sifra == 0) break;
		n++;
	} while (n < 10);

	printf("Uzazno [0], silazno [1]: ");

	scanf("%d", &f);

	obicanBubbleSort(polje, n, f);
	printer(polje, n);

	return 0;

}