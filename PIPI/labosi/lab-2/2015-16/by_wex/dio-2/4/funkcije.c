#include <stdio.h>
void generirajNiz(char *znakovi, int duljinaNiza, char *genNiz) {
	int duljina = 0;
	int i, j = 0;
	for (i=0; znakovi[i]!=0; i++) duljina++;
	printf("%d\n", duljina);
	if (duljina >= duljinaNiza) {
		for (i=duljina-duljinaNiza; znakovi[i]!=0; i++) {
			*genNiz = znakovi[i];
			genNiz++;
		}
	} else {
		do {
			for (i=0; znakovi[i]!=0; i++) {
				*genNiz = znakovi[i];
				genNiz++;
				j++;
				if (j == duljinaNiza) break;
			}
		} while (duljinaNiza != j);
	}
	return;
}

int dobarNiz(char niz[]) {
	int i, j;
	for (i=0; niz[i]!=0; i++) {
		for (j=0; niz[j]!=0; j++) {
			if (i != j && niz[i] == niz[j]) return 0;
		}
	}
	return 1;
}