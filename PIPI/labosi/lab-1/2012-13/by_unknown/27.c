#include <stdio.h>
#include <math.h>
#define MAX 41
int main() {
	int broj, brojac[MAX]={0};
	int i;
	do{
		scanf("%d", &broj);
		if(broj>=1 && broj<=40){
			brojac[broj]++;
			if(brojac[broj]==4)
				break;
		}
		else {
			printf("Ucitali ste broj izvan zadanog intervala.\n"); break;
		}
	}while(1);
	for(i=0; i<MAX; i++){
		if(brojac[i])
			printf("Broj %2d: %1d\n", i, brojac[i]);
	}
	return 0;
}