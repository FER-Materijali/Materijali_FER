#include <stdio.h>
#define MAX 5
int main() {
	int broj, min=0, i=0, rezultat,rezultat1, rezultat2, pomocna=0, max=0;
	do{
		scanf("%d", &broj);
		if(broj>=0 && broj<=100){
			pomocna=1;
			if(i==0 && broj%4==0){
				min=broj;
				max=broj;
				i++;
			}
			else if(broj<min && broj%4==0)
				min=broj;
			else if(broj>max && broj%4==0)
				max=broj;
			if(min==broj)
				rezultat1=min;
			if(max==broj)
				rezultat2=max;
		}
		else if(pomocna==0){
			printf("Nije unesen niti jedan broj iz trazenog intervala.\n");
		}
	}while(broj>=0 && broj<=100);
	if(i){
		rezultat=rezultat1+rezultat2;
		printf("Najveci = %d i Najmanji = %d\n\n", rezultat2, rezultat1); 
		printf("Zbroj najveceg i najmanjeg broja djeljivog s 4 je %d.\n", rezultat);
	}
	return 0;
}
