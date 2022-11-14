#include <stdio.h>
#define MAX 20
int main() {
	int n, i;
	int polje[MAX];
	do{
		printf("Unesite broj clanova polja: \n");
		scanf("%d", &n);
	}while(n<1 && n>20);
	printf("Unesite clanove polja: \n");
	for(i=0; i<n; i++)
		scanf("%d", &polje[i]);
	printf("\n\n");
	for(i=0; i<n; i++){
		if(polje[i]>=10 && polje[i]<=20)
			printf("%d. %d\n", i, polje[i]);
	}
	return 0;
}