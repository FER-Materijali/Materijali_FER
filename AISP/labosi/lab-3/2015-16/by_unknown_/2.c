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
	novi->sljed=*glava;
	*glava=novi;
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