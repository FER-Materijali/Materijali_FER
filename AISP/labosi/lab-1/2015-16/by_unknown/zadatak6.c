#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
char *malaSlova(char *niz) {
	char *noviniz;
	int i;
	noviniz = (char*)malloc(strlen(niz) * sizeof(char));
	if (noviniz == NULL) return 0;
	for (i = 0; i < strlen(niz)+1; i++) *(noviniz + i) = tolower(*(niz + i));
	return noviniz;
}
int main(void) {
	char niz[] = "asp_i_ASP";
	char *noviniz;
	noviniz = malaSlova(niz);
	printf("Novi niz: %s\n", noviniz);
	free(noviniz);
	return 0;
}