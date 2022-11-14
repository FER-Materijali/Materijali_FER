#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, zadnjaZnamenka2;
	float rezultat;
	printf("Unesite 2 prirodna broja: \n");
	scanf("%d %d", &broj1, &broj2);
	zadnjaZnamenka2=broj2%10;
	if(zadnjaZnamenka2==0){
		printf("Dijeljenje nije moguce. \n");
	}
	else{
		rezultat=(float)broj1/zadnjaZnamenka2;
		printf("%d / %d = %.2f", broj1, zadnjaZnamenka2, rezultat);
	}
	return 0;
	
}
