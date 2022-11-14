#include"funkcije.h"
#include<ctype.h>
#include<string.h>
int brojNeSlova (char *niz) {
	int i, brojac=0;
	for (i=0; i<strlen(niz); ++i) {
		if (!isalpha(niz[i])) {
			++brojac;
		}
	}
	return brojac;
}
void caesarEncrypt (char *nizUlaz, char *nizIzlaz, int kljucKriptiranja) {
	int i, kr;
	for (i=0; i<strlen(nizUlaz); ++i) {
		kr=nizUlaz[i]+kljucKriptiranja;
		if ((kr>'Z' && kr<'a') || (kr>'z')) {
			nizIzlaz[i]=kr-26;
		} else {
			nizIzlaz[i]=kr;
		}
	}
	nizIzlaz[i]='\0';
}