#include <stdio.h>
#include "funkcije.h"
#define MIN 3
#define MAX 100

int main( void ){
	int n,i,j;
	struct grad{
		int posta;
		double latitude;
		double longitude;
	} polje[MAX];

	do{
		printf("Upisite broj gradova (od 3 do 100): ");
		scanf("%d",&n);
	}while(n<MIN || n>MAX);
	printf("\n");
	for(i=0; i<n; i++){
		printf("Upisite postanski broj i koordinate %d. grada: ",i+1);
		scanf("%d%lf%lf",&polje[i].posta, &polje[i].latitude, &polje[i].longitude);
	}

	printf("\nMedjusobne udaljenosti gradova:\n");
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			printf("%d - %d: %lf km\n", polje[i].posta, polje[j].posta, izracunajUdaljenost( polje[i].latitude, polje[j].latitude, polje[i].longitude, polje[j].longitude ) );

	return 0;
}