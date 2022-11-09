#include <stdio.h>
#include <malloc.h>

void ispis(float *polje, int n){
	if (n==0) return;
	else if(*polje < 0) printf("%.2f ", *polje);
	ispis(++polje, --n);
}

int main(void){
	int n, i;
	float *p;
	printf("Unesite broj elemenata polja > ");
	scanf("%d", &n);
	if((p = malloc(sizeof(float)*n)) == NULL){
		printf("Nema dovoljno memorije");
		exit(1);
	}
	printf("Ucitajte elemente polja > ");
	for(i=0;i<n;i++) scanf("%f", p+i);
	ispis(p, n);
	return 0;
}