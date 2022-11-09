#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXNIZ 40

struct at {
	int element;
	struct at *sljed;
};
typedef struct at cvor;

int upis(cvor **glava, cvor **rep, int *broj){
	cvor *novi;
	novi=(cvor*)malloc(sizeof(cvor));
	if (novi==NULL) return 0;

	novi->element=*broj;
	novi->sljed=NULL;

	if (*glava==NULL){
		*glava=novi;
		*rep=novi;
	} else {
		(*rep)->sljed=novi;
		*rep=novi;
	}
	return 1;
}

void ispis(cvor *glava){
	cvor *p;
	for (p=glava; p != NULL; p=p->sljed) printf("%d \n", p->element);
}

int main (void) {
	int i, n;
	cvor *glava=NULL;
	cvor *rep=NULL;
	int element;

	printf("Unesite koliko clanova <=10 : ");
	scanf("%d", &n);

	for (i=0; i<n; i++){
		printf("Unesite %d. element: \n", i+1);
		scanf("%d", &element);
		upis(&glava, &rep, &element);
	}
	printf("Ispis: \n");
	ispis(glava);
	return 0;
}