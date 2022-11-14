#include <stdio.h>
#define MANJA "prva znamenka manja od zadnje."
#define VECA "prva znamenka veca od zadnje."
#define JEDNAKE "prva i zadnja znamenka su jednake."
int main() {
	int broj, i, polje[5];
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
	printf("Broj %d: %s\n", broj, polje[0]>polje[n-1] ? VECA : (polje[0]==polje[n-1] ? JEDNAKE : MANJA));
	return 0;
}