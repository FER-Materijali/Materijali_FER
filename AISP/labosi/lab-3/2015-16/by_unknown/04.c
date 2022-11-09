#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define maxn 10

typedef struct Red {
	double niz[maxn];
	int ulaz, izlaz;
	}Red;

void init_red(Red* red) {
	red->ulaz = -1;
	red->izlaz = -1;
	}

int dodajURed(double broj, Red *red) {
	if ((red->ulaz + 1) % maxn == red->izlaz) return 0;
	else {
		red->ulaz = (red->ulaz + 1) % maxn;
		red->niz[red->ulaz] = broj;
		return 1;
		}
	}

int skiniIzReda(double *broj, Red *red) {
	if (red->izlaz == red->ulaz) return 0;
	else {
		red->izlaz = (red->izlaz + 1) % maxn;
		*broj = red->niz[red->izlaz];
		return 1;
		}
	}

int main(void) {
	int n, i;
	double broj;
	Red* red;
	red = (Red*)malloc(sizeof(Red));
	do {
		scanf("%d",&n);
		} while (n<=0 || n>10);
	init_red(red);
	for (i = 0; i < n; i++) {
		scanf("%lf",&broj);
		printf("-> %d\n", dodajURed(broj, red));
		}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("-> %d\n", skiniIzReda(&broj, red));
		printf("----> %f\n", broj);
		}
	free(red);
	return 0;
	}

