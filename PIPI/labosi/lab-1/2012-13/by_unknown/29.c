#include <stdio.h>
#include <math.h>
#define MAX 31
int main() {
	int broj, brojac[MAX]={0}, i=0, polje[MAX], pomocna, procitano;
	do{
		scanf("%d", &broj);
		if(broj>=1 && broj<=30){
			i++;
			procitano=i;
			if(brojac[broj]==1){
				pomocna=broj;
				break;
			}
			else {
				polje[i]=broj;
				brojac[broj]++;
			}
		}
	}while(1);
	for(i=0; i<MAX; i++){
		if(polje[i]==pomocna)
			printf("Broj %d bio je %d. procitan broj.\n", pomocna, i);
	}
	printf("Ukupno procitano brojeva: %d\n", procitano);
	return 0;
}
