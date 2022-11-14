#include <stdio.h>

char *prviZnak(char *niz1, char *niz2) {
	int i, j;
	for (i=0; niz2[i]!=0; i++) {
		for (j=0; niz1[j]!=0; j++)
			if (niz1[j] == niz2[i]) return &niz2[i];
	}
	return NULL;
}

int brojRecenica(char *niz) {
	char punct[] = ".!?\0";
	int broj = 0;
	char *start = niz;
	do {
		printf("pointer/znak: %c\n", *start);
		start = prviZnak(punct, start);
		if (start != NULL) {
			printf("pointer/znak: %c\n", *start);
			broj++;
			start++;
		}
	} while (start != NULL);
	return broj;
}