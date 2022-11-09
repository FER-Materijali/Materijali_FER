#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int zbrojiKvadrate(int *polje, int n){
	if (n==0) return 0;
	if ((float)sqrt(*polje) == sqrt(*polje))
		return (*polje + zbrojiKvadrate(polje+1, --n));
	return zbrojiKvadrate(polje+1, --n);
}

int main(void){
	int n, *p, i;
	printf("Unesite broj elemenata polja > ");
	scanf("%d", &n);
	p = malloc(sizeof(int)*n);
	printf("Polje = [ ");
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
		*(p+i)=rand()%100+1;
		printf("%d ", *(p+i));
	}
	printf("]\nZbroj clanova: %d", zbrojiKvadrate(p, n));
	return 0;
}