#include <stdio.h>
#include <string.h>
#include "funkcije15.h"
#define MAX 200

int main(void)
{
	char niz[MAX + 1], pomNiz[MAX + 1];
	int i, j, broj;
	gets(niz);
	for (i = 0, j = 0; i <= strlen(niz); ++i) {
		if (niz[i] == ' ' || niz[i] == '\0') {
			pomNiz[j] = '\0';
			broj = sazetak(pomNiz);
			printf("%s %d ", pomNiz, broj);
			dodajZnak(pomNiz, broj);
			printf("%s\n", pomNiz);
			j = 0;
		}
		else
			pomNiz[j++] = niz[i];
			
	}
	return 0;
}
