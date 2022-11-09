#include <stdio.h>
#include <malloc.h>

int binarnoTrazi(float *polje, int n, float x){
	int dg = 0, gg = n-1, srednja;
	do {
		srednja = (dg+gg)/2;
		if (x == *(polje+srednja)) return srednja;
		else if (x > *(polje+srednja)) dg = srednja+1;
		else gg = srednja - 1;
	} while(dg <= gg);
	return -1;
}

int main (void){
	int n, i, indeks;
	float x, *p;
	printf("Unesite broj clanova n te realni broj x > ");
	scanf("%d %f", &n, &x);
	p = malloc(sizeof(float)*n);
	printf("\nPolje: ");
	for(i=0;i<n;i++) {
		*(p+i) = 1.1*i;
		printf("%.2f ", *(p+i));
	}
	indeks = binarnoTrazi(p, n, x);
	if(indeks==-1) printf("\nBroj se ne nalazi u polju.");
	else printf("\nBroj pronaden! Indeks clana: %d", indeks);
	return 0;
}