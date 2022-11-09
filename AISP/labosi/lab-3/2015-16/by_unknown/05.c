#include <stdio.h>
#include <malloc.h>

typedef struct cvor {
	double broj;
	struct cvor* sljedeci;
	}cvor;

typedef struct Red {
	cvor* ulaz;
	cvor* izlaz;
	}Red;

void init_red(Red *red) {
	red->ulaz = NULL;
	red->izlaz = NULL;
	}

int dodajURed(double broj, Red *red) {
	cvor* novi;
	novi = (cvor*)malloc(sizeof(cvor));
	if (novi) {
		if (!(red->izlaz) && !(red->ulaz)) {
			red->ulaz = novi;
			red->izlaz = novi;
			}
		else {
			if (red->ulaz == red->izlaz) {
				red->ulaz = novi;
				red->izlaz->sljedeci = red->ulaz;
				}
			else {
				red->ulaz->sljedeci = novi;
				red->ulaz = novi;
				}
			}
		novi->broj = broj;
		novi->sljedeci = NULL;
		return 1;
		}
	return 0;
	}

void ispis(cvor* izlaz) {
	for (; izlaz; izlaz = izlaz->sljedeci) printf("-> %f\n",izlaz->broj);;
	}

int main(void) {
	int n, i;
	double broj;
	Red* red;
	red = (Red*)malloc(sizeof(Red));
	init_red(red);
	do {
		scanf("%d",&n);
		} while (n<=0 || n>10);
	for (i = 0; i < n; i++) {
		scanf("%lf",&broj);
		printf("-> %d\n", dodajURed(broj, red));
		}
	printf("\n");
	ispis(red->izlaz);
	cvor* k;
	while (red->izlaz) {
		k = red->izlaz->sljedeci;
		free(red->izlaz);
		red->izlaz = k;
		}
	free(red);
	return 0;
	}