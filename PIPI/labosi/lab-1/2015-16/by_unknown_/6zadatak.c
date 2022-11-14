#include <stdio.h>

int main(void){
	int broj1,broj2;
	scanf("%d %d",&broj1,&broj2);
	int suma1=(broj1/10)+(broj1%10); 
	int suma2=(broj2/10)+(broj2%10);
	if (suma1>suma2){
	printf ("Broj %d ima vecu sumu znamenaka od broja %d.",broj1,broj2);
	} else {
		if (suma1<suma2){
		printf ("Broj %d ima vecu sumu znamenaka od broja %d.",broj2,broj1);
		} else {
		printf ("Brojevi %d i %d imaju jednaku sumu znamenaka.",broj2,broj1);
		}
	}
	return 0;
}