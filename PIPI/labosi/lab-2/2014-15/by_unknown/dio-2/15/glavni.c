#include<stdio.h>
#include<string.h>
#include"funkcije.h"
int main (void) {
	char niz[201], rijec[201];
	int i, j=0, broj;
	gets(niz);
	for (i=0; i<=strlen(niz); ++i) {
		if (niz[i]==' ' || niz[i]=='\0') {
		    rijec[j]='\0';
		    broj=sazetak(rijec);
			printf("%s %d ", rijec, broj);
			dodajZnak(rijec, broj);
			printf("%s\n", rijec);
			j=0;
			} else {
				rijec[j++]=niz[i];
			}
	}
	return 0;
}