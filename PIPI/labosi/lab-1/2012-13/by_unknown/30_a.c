#include <stdio.h>
#include <math.h>
#define MAX 41
int main() {
	int broj, brojac[MAX]={0}, i=0, polje[MAX]={0};
	do{
		scanf("%d", &broj);
		if(broj>=1 && broj<=40){
			brojac[broj]++;
			if(brojac[broj]==1){
				polje[i]=broj;
			}
			i++;
		}
	}while(broj>=1 && broj<=40);
	for(i=0; i<MAX; i++){
		if(polje[i]>0)
			printf("Broj %2d : %d\n", polje[i], i+1);
		}
	return 0;
}
