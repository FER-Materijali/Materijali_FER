#include"funkcije.h"
#include<stdio.h>
void genPodniz(char *niz, char *podNiz, int pocPozicija, int duljPodniz) {
	int i;
	for (i=0; i<duljPodniz; ++i) {
		podNiz[i]=niz[pocPozicija++];
	}
	podNiz[i]='\0';
}
int sadrziPodniz(char *niz, char *podNiz) {
	int i, j=0;
	for (i=0; niz[i]!='\0'; ++i, j=0) {
		while (niz[i+j]==podNiz[j] && podNiz[j]!='\0') {
			++j;
		}
		if (podNiz[j]=='\0') {
				return 1;
			}
		}
	return 0;
}