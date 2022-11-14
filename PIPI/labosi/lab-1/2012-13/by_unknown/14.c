#include <stdio.h>
#include <math.h>
#define MAX 1000
int main() {
	double niz[MAX], suma=0; double jedan, apPogreske;
	int i, j, n;
	do{
		printf("Unesite broj clanova niza:\n");
		scanf("%d", &n);
	}while(n<1 || n>1000);
	for(i=0, j=1; i<n; i++, j++){
		niz[i]=1./(j*(j+1));
		suma+=niz[i];
	}
	jedan=suma;
	printf("jedan = %7.6f\n", jedan);
	apPogreske=jedan-1;
	printf("Apsolutna vrijednost pogreske = %7.6f\n", apPogreske);
	return 0;
}

	