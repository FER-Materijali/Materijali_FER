#include <stdio.h>
#include <malloc.h>

struct cv {
	int element;
	struct cv* sljed;
};
typedef struct cv cvor;

void printer(cvor *glava) {
	while (glava) {
		printf("%d ", glava->element);
		glava = glava->sljed;
	}
	return;
}


int upis(cvor ** glava, int element) {
	cvor *pom, *pom2;
	pom = (cvor*)malloc(sizeof(cvor));
	if (pom == NULL) return 0;
	pom->element = element;
	if ((*glava) == NULL||(*glava)->element > element) {
		pom->sljed = *glava;
		*glava = pom;
		return 1;
	}
	for (pom2 = (*glava); pom2->sljed!=NULL && pom2->sljed->element < element; pom2 = pom2->sljed);
	pom->sljed = pom2->sljed;
	pom2->sljed = pom;
	return 1;
}

int main(void) {
	cvor *glava = NULL;
	int n=0, elem;
	do {
		printf("Upisi broj (0 za kraj): ");
		scanf("%d", &elem);
		if (elem == 0) break;
		upis(&glava, elem);
		n++;
	} while (n < 10);

	printer(glava);

	return 0;
}