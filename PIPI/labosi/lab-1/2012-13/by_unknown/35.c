#include <stdio.h>
int main() {
	int broj, i, polje[5], max;
	int k, l, n;
	do{
		scanf("%d", &broj);
	}while(broj<100 && broj>99999);
	if(broj>=100 && broj<=999){
		for(i=0, k=100, l=10; i<3; i++, k=k/10){
			if(i==0)
				polje[i]=broj/k;
			else
				polje[i]=broj/k%l;
		}
		n=3;
	}
	if(broj>=1000 && broj<=9999){
		for(i=0, k=1000, l=10; i<4; i++, k=k/10){
			if(i==0)
				polje[i]=broj/k;
			else
				polje[i]=broj/k%l;
		}
		n=4;
	}
	if(broj>=10000 && broj<=99999){
		for(i=0, k=10000, l=10; i<5; i++, k=k/10){
			if(i==0)
				polje[i]=broj/k;
			else
				polje[i]=broj/k%l;
		}
		n=5;
	}
	
	if(polje[n-1]>polje[0])
		printf("Broj %d: prva znamenka manja od zadnje.\n", broj);
	else if(polje[n-1]<polje[0])
		printf("Broj %d: prva znamenka veca od zadnje.\n", broj);
	else
		printf("Broj %d: prva i zadnja znamenka su jednake.\n", broj);
		return 0;
}