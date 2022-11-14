#include <stdio.h>
#define MAX 3
int main() {
	int broj, i, polje[MAX],polje2[MAX], brojac[10]={0};
	int k, l, j, m=0;
	do{
		scanf("%d", &broj);
	}while(broj<100 && broj>999);
	for(i=0, k=100, l=10; i<MAX; i++, k=k/10){
		if(i==0)
			polje[i]=broj/k;
		else
			polje[i]=broj/k%l;
	}
	for(i=MAX-1, j=0; i>=0; i--, j++)
		polje2[j]=polje[i];
	for(i=0, k=100; i<MAX; i++, k=k/10)
		m=m+(polje2[i]*k);
	if(m>broj)
		printf("Broj %d veci je od ucitanog broja.\n", m);
	else if(m<broj)
		printf("Broj %d manji je od ucitanog broja.\n", m);
	else
		printf("Broj %d jednak je ucitanom broju\n", m);
		if(i==0)

	return 0;
}