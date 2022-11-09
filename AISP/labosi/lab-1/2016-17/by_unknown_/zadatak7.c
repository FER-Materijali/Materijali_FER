#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void zamjeni(int *a, int *b){
	int pom = *a;
	*a = *b;
	*b = pom;
}

int *f(int *p, int n){
	int *np = malloc(sizeof(int)*n), i, j;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
		j = rand()%(n-i);
		*(np+i) = (*(p+j))*(*(p+j));
		zamjeni(p+j, p+n-1-i);
	}
	return np;
	
}

int main(void){
	int n, *p, i;
	printf("Unesite broj clanova niza > ");
	scanf("%d", &n);
	p = malloc(sizeof(int)*n);
	printf("\nUcitajte clanove niza > ");
	for(i=0;i<n;i++) scanf("%d", p+i);
	p = f(p, n);
	printf("\nNovi niz: ");
	for(i=0;i<n;i++) printf("%d ", *(p+i));
	return 0;
}