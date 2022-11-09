#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct cvor {
	int broj;
	struct cvor* sljedeci;
	}cvor;

int upis(cvor **glava, cvor **rep, int *broj) {
	cvor* novi;
	novi = (cvor*)malloc(sizeof(cvor));
	if (novi) {
		novi->broj = *broj;
		novi->sljedeci = NULL;
		if ((*glava) == NULL) {
			*glava = novi;
			*rep = novi;
			
			}
		else {
			(*rep)->sljedeci = novi;
			*rep = novi;
			}
		return 1;
		}
	return 0;
	}

void ispis(cvor* glava) {
	for (; glava; glava = glava->sljedeci) printf("-> %d\n", glava->broj);
	}

int main(void) {
	int n, i, broj;
	cvor* glava; cvor* rep;
	rep = NULL;
	glava =	NULL;
	do {
		scanf("%d",&n);
		} while (n<=0 || n>10);
	for (i = 0; i < n; i++) {
		scanf("%d", &broj);
		printf("-> %d\n", upis(&glava, &rep, &broj));
		}
	printf("\n");
	ispis(glava);
	cvor* k;
	while (glava) {
		k = glava->sljedeci;
		free(glava);
		glava = k;
		}
	return 0;
	}