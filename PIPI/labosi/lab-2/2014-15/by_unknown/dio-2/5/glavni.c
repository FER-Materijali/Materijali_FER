#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char tekst[201];
	int rec;
	gets(tekst);
	rec=brojRecenica(tekst);
	if (rec==0) {
		printf("\nTekst\n'%s'\nne sadrzi niti jednu potpunu recenicu.", tekst);
	} else {
		printf("\nBroj recenica u tekstu:\n'%s'\nje %d", tekst, rec);
	}
	return 0;
}