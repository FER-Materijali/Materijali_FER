#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct cv {
	char element[40 + 1];
	struct cv *sljed;
};
typedef struct cv cvor;

void printer(cvor* glava) {
	while (glava) {
		printf("%s ", glava->element);
		glava = glava->sljed;
	}
	return;
}

int upis(cvor ** glava, char* element) {
	cvor *pom, *pom2;
	pom = (cvor*)malloc(sizeof(cvor));
	if (pom == NULL) return 0;
	strcpy(pom->element, element);
	if ((*glava) == NULL) {
		pom->sljed = *glava;
		*glava = pom;
		return 1;
	}
	for (pom2 = (*glava); pom2->sljed != NULL; pom2 = pom2->sljed);
	pom->sljed = pom2->sljed;
	pom2->sljed = pom;
	return 1;
}

int main(void) {
	cvor *glava = NULL;
	char elem[40 + 1];
	int f = 0;
	do {
		printf("Unesi znakovni niz (0 za kraj): ");
		gets(elem);
		if (strcmp(elem, "0")==0) break;
		upis(&glava, elem);
		f++;
	} while (f < 10);
	printer(glava);
	return 0;
}