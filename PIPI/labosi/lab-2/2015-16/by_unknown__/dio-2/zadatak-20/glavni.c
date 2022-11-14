#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"
int main(void){
	int a, b, c;
	char izl[33]={0};
	printf("Unesite broj slova borojeva i znakova: ");
	scanf("%d %d %d", &a, &b, &c);
	generirajLozinku(a, b, c, &izl[0]);
	izl[a+b+c]='\0';
	return 0;
}