#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
char *IzbaciRazmak(char *niz) {
	char *noviniz;
	int brojZnakova = strlen(niz), i, j=0;
	noviniz = (char*)malloc(brojZnakova*sizeof(char));
	for (i = 0; i < brojZnakova; i++) {
		if (!isspace(*(niz + i))) *(noviniz + j++) = *(niz + i);
	}
	*(noviniz + j) = '\0';
	return noviniz;
}
int main(void) {
	int n, i;
	char niz[100], *novi;
	printf("Unesi niz:\n");
	gets(niz);
	novi = IzbaciRazmak(niz);
	for (i = 0; i < strlen(novi); i++) printf("%c", *(novi + i));
	free(novi);
	return 0;
}