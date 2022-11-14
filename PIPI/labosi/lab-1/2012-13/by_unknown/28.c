#include <stdio.h>
#include <math.h>
#define MAX 31
int main() {
	int broj, brojac[MAX]={0};
	int i;
	do{
		scanf("%d", &broj);
		if(broj>=1 && broj<=30){
			brojac[broj]++;
		}
	}while(broj>=1 && broj<=30);
	for(i=1; i<MAX; i++){
		if(brojac[i]>=2)
			printf("Broj %2d: %1d\n", i, brojac[i]);
	}
	return 0;
}