#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, pomocnaVarijabla;
	printf("Unesite 2 cijela broja, pri cemu drugi broj mora biti veci od prvoga: \n");
	scanf("%d %d", &broj1, &broj2);
	if(broj1>=broj2){
		printf("Brojevi nisu dobro zadani. \n");
	}
	else{
		pomocnaVarijabla=broj1;
		broj1=broj2;
		broj2=pomocnaVarijabla;
		printf("x= %d  y=%d", broj1, broj2);
	}
	return 0;
	
}
