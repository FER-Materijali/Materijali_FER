#include <stdio.h>
#include <malloc.h>

#define maxn 40

typedef struct cvor {
	char niz[maxn+1];
	struct cvor* sljedeci;
	}cvor;

int upis(cvor **glava, char *niz) {
	cvor* novi;
	novi = (cvor*)malloc(sizeof(cvor));
	if (novi) {
		strcpy(novi->niz, niz);
		novi->sljedeci = *glava;
		*glava = novi;
		return 1;
		}
	return 0;
	}

void ispis(cvor* glava) {
	for (; glava; glava = glava->sljedeci) printf("-> %s\n",glava->niz);
	}

int main(void) {
	int n, i;
	char niz[maxn + 1];
	cvor* glava = NULL;
	do {
		scanf("%d\n",&n);
		} while (n<=0 || n>10);
	for (i = 0; i < n; i++) {
		scanf("%s", niz);
		printf("-> %d\n", upis(&glava, niz));
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
