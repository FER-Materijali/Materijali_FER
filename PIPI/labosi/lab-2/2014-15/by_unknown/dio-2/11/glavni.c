#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char ulaz[101], uzorak[11];
	gets(ulaz);
	gets(uzorak);
	while (izbaci(ulaz, uzorak)) {
	}
	printf("%s", ulaz);
	return 0;
}