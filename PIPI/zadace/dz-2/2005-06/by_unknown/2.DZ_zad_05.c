#include <stdio.h>
#define MAX 100

int main(){
	int i, n;
	int polje[MAX], brojac[MAX+1]={0};
	
	do{
		printf("Unesi duljinu polja [1,100]: ");
		scanf("%d", &n);
	}while(n<1 || n>100);

	for(i=0;i<n;++i){
		do{
			printf("Unesi %2d. element polja: ", i+1);
			scanf("%d", &polje[i]);
		}while(polje[i]<10 || (polje[i]>20 && polje[i]<50) || polje[i]>100);
		brojac[polje[i]]++;
	}
	
	printf("\n\nBroj ponavljanja pojedinih brojeva:");
	for(i=0;i<100;++i){
		if(((i>=10 && i<=20) || (i>=50 && i<=100)) && !(brojac[i+1]==0)){
			printf("\nBroj %3d pojavio se %2d puta.", i+1, brojac[i+1]);
		}
	}
	
	printf("\n\n");
	return 0;
}
