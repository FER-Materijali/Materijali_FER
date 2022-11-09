#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct struktura {
	char niz[41];
	struct struktura *sljed;
} cvor;

int upis (cvor **glava, char *niz);
void ispis (cvor *glava);
void brisi (cvor *glava);

int main (void) {
	int n = 0, i;
	char pom[41], c;
	cvor *glava = 0;
	
	glava = 0;
	while (n < 1 || n > 10) {
		printf("n: ");
		scanf("%d%c", &n, &c);
	}
	
	for (i = 0; i < n; i++) {
		printf("Upisite %d. niz:\n", i+1);
		fgets(pom, 41, stdin);
		if (!upis(&glava, pom)) {
			printf("Nema dovoljno memorije!\n");
			return 1;
		}
	}
	
	printf("\n");
	ispis(glava);
	
	brisi(glava);
	
	return 0;
}

int upis (cvor **glava, char *niz) {
	cvor *novi;
	
	novi = (cvor *)malloc(sizeof(cvor));
	if (!novi) {
		return 0;
	}
	
	strcpy(novi->niz, niz);
	novi->sljed = *glava;
	*glava = novi;
	
	return 1;
}

void ispis (cvor *glava) {
	for (;glava != 0; glava = glava->sljed) {
		printf("%s", glava->niz);
	}
}

void brisi (cvor *glava) {
	cvor *prvi, *drugi;
	
	for (prvi = glava, drugi = prvi->sljed; drugi;prvi = drugi, drugi = drugi->sljed) {
		free(prvi);
	}
	free(prvi);
}