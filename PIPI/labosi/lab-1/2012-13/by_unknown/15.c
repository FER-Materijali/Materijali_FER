#include <stdio.h>
#include <math.h>
#define MAX 100
int main() {
	double niz[MAX], suma=0; double tri_cetvrtine, apPogreske;
	int i, j, n;
	do{
		printf("Unesite broj clanova niza:\n");
		scanf("%d", &n);
	}while(n<1 || n>100);
	for(i=0, j=1; i<n; i++, j++){
		niz[i]=1./(j*(j+2));
		suma+=niz[i];
	}
	tri_cetvrtine=suma;
	printf("tri cetvrtine = %7.6f\n", tri_cetvrtine);
	apPogreske=tri_cetvrtine-0.75;
	printf("Apsolutna vrijednost pogreske = %7.6f\n", apPogreske);
	return 0;
}