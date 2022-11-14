#include <stdio.h>
#include <math.h>
#define MAX 41
int main() {
	int broj, brojac[MAX]={0}, i=0, j, polje[MAX]={0};
	do{
		scanf("%d", &broj);
		if(broj>=1 && broj<=40){
			i++;
			brojac[broj]++;
			if(brojac[broj]==1){
				polje[i]=broj;
			}
			
		}
	}while(broj>=1 && broj<=40);
	for(j=1; j<MAX; j++){
		if(brojac[j]>0){
			for(i=1; i<MAX; i++){
				if(polje[i]==j)
					printf("Broj %2d : %d\n", j, i);
			}
		}
	}
	return 0;
}