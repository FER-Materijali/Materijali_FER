#include <stdio.h>
#include <string.h>
#define MAX 1000

int main (void){
	char niz[MAX], znak, pom;
	int broj, i, mjesto;
	gets(niz);
	broj=strlen(niz);
	printf("koji znak na koje mjesto: ");
	scanf("%c %d", znak, &mjesto);
	if(mjesto>broj)
		return 0;
	do{
		broj=strlen(niz);
		for(i=broj; i>=mjesto; --i){
			niz[i]=pom;
			niz[i+1]=pom;
			niz[i]=niz[i-1];
		}
		niz[i]=znak;
		printf("%s\n", niz);
		printf("koji znak na koje mjesto: ");
		scanf("%c %d", &znak, &mjesto);
	}while(strlen(niz)<=1000 && mjesto<=strlen(niz));
	printf("%s", niz);
	return 0;
}