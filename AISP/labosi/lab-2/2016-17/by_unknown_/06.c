#include <stdio.h>
#include <malloc.h>

typedef struct struktura{
	int vrijednost;
	struct struktura *sljed;
} cvor;

int upis (cvor **glava, int element);
void ispis (cvor **glava);
void brisi (cvor **glava);

int main (void) {
	int n, i, vr;
	cvor *glava, *pom;
	
	printf("n: ");
	scanf("%d", &n);
	while (n < 1 || n > 10) {
		printf("n: ");
		scanf("%d", &n);
	}
	
	printf("\nclanovi liste:\n");
	scanf("%d", &vr);
	pom = (cvor *)malloc(sizeof(cvor));
	if (!pom) {
		printf("Nema dovoljno memorije!\n");
		return 1;
	}
	pom->vrijednost = vr;
	pom->sljed = 0;
	glava = pom;
	for (i = 1; i < n; i++) {
		scanf("%d", &vr);
		if (!upis(&glava, vr)) {
			printf("Nema dovoljno memorije!\n");
			return 2;
		}
	}
	
	printf("\n");
	ispis(&glava);
	
	brisi(&glava);
	
	return 0;
}

int upis (cvor ** glava, int element) {
	cvor *a, **prosli, *pom;
	
	a = (cvor *)malloc(sizeof(cvor));
	if (!a) {
		return 0;
	}
	a->vrijednost = element;
	if ((*glava)->vrijednost >= element) {
		a->sljed = (*glava);
		*glava = a;
		return 1;
	}
	for (prosli = glava; (*glava) != 0 && (*glava)->vrijednost < element;
		prosli = glava, glava = &((*glava)->sljed));
	
	pom = (*prosli)->sljed;
	(*prosli)->sljed = a;
	a->sljed = pom;
	
	return 1;
}

void ispis (cvor **glava) {
	
	for (;*glava; glava = &((*glava)->sljed)) {
		printf("%d\n", (*glava)->vrijednost);
	}
}

void brisi (cvor **glava) {
	cvor *prvi, *drugi;
	
	for (drugi = *glava, prvi = drugi->sljed; prvi != 0; drugi = prvi, prvi = prvi->sljed) {
		free(drugi);
	}
	free(drugi);
}