#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXNIZ 40

struct at {
	char element[MAXNIZ +1];
	struct at *sljed;
};
typedef struct at cvor;

int upis(cvor **glava, char element[]){
	cvor *novi, *p;
	novi=(cvor*)malloc(sizeof(cvor));

	if (novi==NULL) return 0;

	strcpy(novi->element, element);
	if ( *glava==NULL || strcmp((*glava)->element, element) >=0){
		novi->sljed=*glava;
		*glava=novi;
	} else {
		for ( p=*glava; p->sljed && strcmp((p->sljed)->element, element) <0; p=p->sljed);
		novi->sljed=p->sljed;
		p->sljed=novi;			
	}
	return 1;	
}

void ispis(cvor *glava){
	cvor *p;
	for (p=glava; p != NULL; p=p->sljed) printf("%s \n", p->element);
}

int main (void) {
	int i, n;
	cvor *glava=NULL;
	char element[MAXNIZ+1];

	printf("Unesite koliko clanova <=10 : ");
	scanf("%d", &n);

	for (i=0; i<n; i++){
		printf("Unesite %d. element: \n", i+1);
		scanf("%s", &element);
		upis(&glava, element);
	}
	printf("Ispis: \n");
	ispis(glava);
	return 0;
}