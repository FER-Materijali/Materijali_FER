#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, desetica1, desetica2, jedinica1, jedinica2, suma1, suma2;
	printf("Unesite 2 dvoznamenkasta prirodna broja: \n");
	scanf("%d %d", &broj1, &broj2);
	desetica1=broj1/10;
	jedinica1=broj1%10;
	desetica2=broj2/10;
	jedinica2=broj2%10;
	suma1=desetica1 + jedinica1;
	suma2=desetica2 + jedinica2;
	if(suma1>suma2)
		printf("Broj %d ima vecu sumu znamenaka od broja %d . \n", broj1, broj2);
	else if(suma1<suma2)
		printf("Broj %d ima vecu sumu znamenaka od broja %d . \n", broj2, broj1);
	else
		printf("Brojevi %d i %d imaju jednaku sumu znamenaka. \n", broj1, broj2);
	return 0;
	
}
