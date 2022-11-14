#include"funkcije.h"
#include<stdlib.h>
char *prviZnak(char *niz1, char *niz2) {
	int i, j;
	for (i=0; niz2[i]!='\0'; ++i) {
		for (j=0; niz1[j]!='\0'; ++j) {
			if (niz2[i]==niz1[j]) {
				return niz2+i;
			}
		}
	}
	return NULL;
}
int brojRecenica(char *niz) {
	int n=0;
	char *tmp=niz;
	while ((tmp=prviZnak(".!?", tmp))!=NULL) {
	++tmp;
	++n;
	}
	return n;
}