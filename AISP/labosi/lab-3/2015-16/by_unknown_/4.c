#include <stdio.h>
#include <malloc.h>
#define MAXRED 10

typedef struct {
	int polje[MAXRED];
	int ulaz, izlaz;
} Red;

void init_red(Red *red) {
	red->ulaz=0;
	red->izlaz=0;
}

int dodaj(double broj, Red *red){
	if ((red->ulaz+1) % MAXRED == red->izlaz) return 0;

	red->ulaz++;
	red->ulaz %= MAXRED;
	red->polje[red->ulaz]=broj;
	return 1;
}

int brisi(double *broj, Red *red){
	if (red->ulaz == red->izlaz) return 0;

	red->izlaz++;
	red->izlaz %= MAXRED;
	*broj = red->polje[red->izlaz];
	return 1;
}

int main (void){
	int n, i;
	double broj, skini;
	Red red;

	init_red(&red);
	printf("Unesite koliko zelite clanova <=10: ");
	scanf ("%d", &n);

	for (i=0; i<n; i++) {
		printf("Unesite %d. broj: ", i+1);
		scanf ("%lf", &broj);
		if (dodaj(broj, &red)) {
			printf("Element dodan. \n");
		} else {
			printf("Red je pun.");
			break;
		}
	}

	printf("Ispis: \n");

	for (i=0; i<n; i++){
		if (brisi(&skini, &red)) {
			printf ("Podatak %f je skinut iz reda. \n", skini);
		} else {
			printf ("Red je prazan.");
			break;
		}
	}
	return 0;
}