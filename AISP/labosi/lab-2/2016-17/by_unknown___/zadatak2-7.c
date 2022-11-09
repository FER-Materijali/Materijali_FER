#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 40

struct at {
	char niz[MAX+1];
	struct at *sljed;
};
typedef struct at cvor;

int upis(cvor **glava, char *niz){
	cvor *novi;
	if((novi = malloc(sizeof(cvor)))== NULL)
		return 0;
	else {
		strcpy(novi->niz, niz);
		novi->sljed = *glava;
		*glava = novi;
		return 1;
	}
}

int main(void){
	cvor *glava = NULL, *pom;
	char znakovniNiz[MAX+1];
	int i,n;
	do{
		printf("\nUnesite broj znakovnih nizova manji ili jednak 10 > ");
		scanf("%d", &n);
	}while(n>10);
	printf("\nUnesite %d znakovnih nizova: ", n);
	getchar();
	for(i=0;i<n;i++){
		gets(znakovniNiz);
		if (upis(&glava, znakovniNiz)) 
			printf("Niz upisan!  ");
		else printf("Niz neuspjesno upisan."  );
	}
	printf("\nLista: ");
	for(pom = glava; pom != NULL; pom = pom->sljed){
		printf("\n%s", pom->niz);
	}
	return 0;
}