#include <stdio.h>

int main (void){
	int suma, i, broj;
	scanf("%d", &broj);
	suma=0;
	i=10;
	if(broj>i){
		do{
			suma+=i;
			i+=2;
		}while(i<broj);
	}
	printf("%d", suma);
	return 0;
}