#include <stdio.h>
#define MAX 5
int main() {
	int broj, min=0, i=0, rezultat, pomocna=0;
	do{
		scanf("%d", &broj);
		if(broj>=0 && broj<=100){
			pomocna=1;
			if(i==0 && broj%4==0){
				min=broj;
				i++;
			}
			else if(broj<min && broj%4==0)
				min=broj;
			if(min==broj)
				rezultat=min;
		}
		else if(pomocna==0){
			printf("Nije unesen niti jedan broj iz trazenog intervala.\n");
			break;
		}
	}while(broj>=0 && broj<=100);
	if(i)
		printf("Najmanji uneseni broj djeljiv s 4 je %d\n", rezultat);
	return 0;
}