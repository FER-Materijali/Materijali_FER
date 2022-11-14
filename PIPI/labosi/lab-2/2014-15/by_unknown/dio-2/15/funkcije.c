#include"funkcije.h"
#include<string.h>
#include<stdio.h>
int sazetak(char *ulaz) {
	int i, suma=0;
	for (i=0; ulaz[i]!='\0'; ++i) {
		suma+=ulaz[i];
	}
	return suma%128;
}
void dodajZnak(char *ulaz, int broj) {
    int i=strlen(ulaz);
	ulaz[i++]=broj;
	ulaz[i]='\0';
}