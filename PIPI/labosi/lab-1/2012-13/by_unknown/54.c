#include <stdio.h>
#define MAX 5
int main() {
	int broj, i=0, max, manji, brojac=0;
	do{
		scanf("%d", &broj);
		if(broj>=0 && broj<=100){
			if(i==1)
				brojac=1;
			if(i==0)
				max=broj;
			else if(broj>max){
				manji=max;
				max=broj;
			}
			if(broj<max && broj>manji)
				manji=broj;
			i++;
		}
		else if(i==0 || i==1){
			printf("Nije uneseno dovoljno brojeva iz trazenog intervala.\n");
			break;
		}
	}while(broj>=0 && broj<=100);
	if(brojac)
		printf("Ostatak pri dijeljenju %d sa %d je %d.\n", max, manji, max%manji);
	return 0;
}