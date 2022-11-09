#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define maxn 40

typedef struct cvor{
	char niz[maxn + 1];
	struct cvor *sljedeci;
	}cvor;

void ispis(cvor *glava);

int upis(cvor **glava, char *niz) {
	cvor* novi;
	novi = (cvor*)malloc(sizeof(cvor));
	if (novi != NULL) {
		strcpy(novi->niz, niz);
		if ((*glava) == NULL) {
			(*glava) = novi;
			novi->sljedeci = NULL;
			}
		else {
			if (strcmp((*glava)->niz, niz) > 0) {
				novi->sljedeci = *glava;
				*glava = novi;
				}
			else {
				cvor* glavap = *glava;
				while (glavap && glavap->sljedeci && strcmp(glavap->sljedeci->niz, niz) < 0) glavap = glavap->sljedeci;
				novi->sljedeci = glavap->sljedeci;
				glavap->sljedeci = novi;
				}
			}
		ispis(*glava);
		return 1;
		}
		return 0;
	}

void ispis(cvor* glava){
	for (; glava != NULL; glava = glava->sljedeci) printf("-> %s\n", glava->niz);
	}

int main(void) {
	cvor* glava = NULL;
	int n, i;
	char niz[maxn + 1];
	do {
		scanf("%d", &n);
	} while (n <= 0 || n > 10);
	for (i = 0; i < n; i++) {
		scanf("%s", niz);
		printf("%d\n", upis(&glava, niz));
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
