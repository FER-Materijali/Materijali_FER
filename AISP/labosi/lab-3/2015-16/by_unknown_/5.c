#include <stdio.h>
#include <malloc.h>

struct cv {
	double broj;
	struct cv *sljed;
};
typedef struct cv cvor;

typedef struct {
	cvor *ulaz;
	cvor *izlaz;
} Red;

void init_red(Red *red){
	red->ulaz=NULL;
	red->izlaz=NULL;
}

int dodaj(double broj, Red *red){
	cvor *novi;

	novi=(cvor *)malloc(sizeof(cvor));
	if (novi==NULL) return 0;

	novi->broj=broj;
	novi->sljed=NULL;
	if (red->izlaz==NULL) red->izlaz=novi;
	else (red->ulaz)->sljed=novi;
	red->ulaz=novi;
	return 1;
}

int skini(double *broj, Red *red){
	cvor *stari;

	if (red->izlaz) {
		*broj=red->izlaz->broj;
		stari=red->izlaz;
		red->izlaz=red->izlaz->sljed;
		free(stari);
		if (red->izlaz==NULL) red->ulaz=NULL;
		return 1;
	}
	return 0;
}

int main(void){
	int i, n;
	double broj, skinut;
	Red red;

	init_red(&red);
	printf("Koliko clanova zelite unijeti? ");
	scanf("%d", &n);

	for (i=0; i<n; i++){
		printf("Unesite %d. clan: \n", i+1);
		scanf("%lf", &broj);
		if (dodaj(broj, &red)) printf("Clan uspjesno unesen.");
		else {
			printf("Clan nije uspjesno unesen.");
			break;
		}
	}

	printf("Ispis: \n");
	for (i=0; i<n; i++){
		if (skini (&skinut, &red)) printf("%f \n", skinut);
		else {
			printf("Red je prazan.");
			break;
		}
	}
	return 0;
}