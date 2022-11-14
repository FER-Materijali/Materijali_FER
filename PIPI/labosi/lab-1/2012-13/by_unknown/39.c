#include <stdio.h>
#define MAX 100
int main() {
	int broj, polje[MAX]; 
	int i, n=1, l, broj_znamenki, min, zapamti;
	printf("Ucitati poitivan cijeli broj: \n");
	scanf("%d", &broj);
	zapamti=broj;
	for(i=0; broj!=0; i++)
		broj=broj/10;
	broj_znamenki=i;
	for(i=1; i<=broj_znamenki; i++)
		n*=10;
	for(i=0, n, l=10; i<broj_znamenki; i++, n/=10){
		if(i==0)
			polje[i]=zapamti/n;
		else
			polje[i]=zapamti/n%l;
	}
	for(i=0; i<broj_znamenki; i++){
		if(polje[i]!=0)
			min=polje[i];
	}
	for(i=0; i<broj_znamenki; i++){
		if(polje[i]!=0){
			if(polje[i]<min)
				min=polje[i];
		}
	}
	if(zapamti%min)
		printf("Broj %d nije djeljiv sa svojom najmanjom znamenkom %d\n", zapamti, min);
	else
		printf("Broj %d je djeljiv sa svojom najmanjom znamenkom %d\n", zapamti, min);

	return 0;
}