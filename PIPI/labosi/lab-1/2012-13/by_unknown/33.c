#include <stdio.h>
int main() {
	int broj, brojac[10]={0}, i, polje[5];
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
	for(i=0; i<n; i++)
		brojac[polje[i]]++;
	for(i=0; i<10; i++){
		if(brojac[i]>0)
			printf("znamenka %d : %d\n", i, brojac[i]);
	}

			
		return 0;
}