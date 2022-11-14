#include <stdio.h>
int main() {
	int broj, i, polje[5], brojac[10]={0};
	int k, l, n, m=0;
	do{
		scanf("%d", &broj);
	}while(broj<1 && broj>99999);
	if(broj>=1 && broj<=9){
		polje[0]=broj;
		n=1;
	}
	if(broj>=10 && broj<=99){
		for(i=0, k=10, l=10; i<2; i++, k=k/10){
			if(i==0)
				polje[i]=broj/k;
			else
				polje[i]=broj/k%l;
		}
		n=2;
	}
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
	for(i=0; i<n; i++)
		brojac[polje[i]]++;
	for(i=0; i<n; i++){
		if(brojac[polje[i]]==1)
			m+=polje[i];
	}
	printf("Broj %d - suma znamenaka koje se jednom pojavljuju: %d\n", broj, m);
	return 0;
}