#include <stdio.h>
#define MAX 20
int main() {
	int n, i;
	float polje[MAX];
	do{
		printf("Unesite broj clanova polja: \n");
		scanf("%d", &n);
	}while(n<1 && n>20);
	printf("Unesite clanove polja: \n");
	for(i=0; i<n; i++)
		scanf("%f", &polje[i]);
	printf("\n\n");
	for(i=n-1; i>=0; i--){
		if(polje[i]>=6.5 && polje[i]<=10.5)
			printf(" %2d.  %6.3f\n", i, polje[i]);
	}
	return 0;

}
