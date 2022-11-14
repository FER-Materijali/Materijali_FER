#include"funkcije.h"
int brojPonavljanja(char niz[], char znak) {
	int i, brojac=0;
	for (i=0; niz[i]!='\0'; ++i) {
		if (niz[i]==znak) {
			++brojac;
		} else if (brojac>0) {
			break;
		}
	}
	return brojac;
}
void kodiraj(char src[], char dest[]) {
	int i, j=0;
	char tmp='\0';
	for (i=0; src[i]!='\0'; ++i) {
		if (src[i]!=tmp) {
			dest[j++]=src[i];
			dest[j++]=brojPonavljanja(&src[i], src[i])+'0';
			tmp=src[i];
		}
	}
}