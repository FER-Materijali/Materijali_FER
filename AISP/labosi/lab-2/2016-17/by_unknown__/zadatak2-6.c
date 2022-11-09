#include <stdio.h>
#include <malloc.h>

struct atom {
	int element;
	struct atom *sljed;
};
typedef struct atom cvor;

int upis(cvor **glava, int element){
	cvor *p, *novi;
	if ((novi = malloc(sizeof(cvor))) == NULL)
		return 0;
	if (*glava == NULL || (*glava)->element >= element) {
		novi->element = element;
		novi->sljed = *glava;
		*glava = novi;
  } else {
	for (p = *glava; p->sljed && (p->sljed)->element < element; p = p->sljed);
		novi->element = element;
		novi->sljed = p->sljed;
		p->sljed = novi;
  }
  return 1;
}

int main(void){
	cvor *glava = NULL, *pom;
	int n, broj, i;
	printf("Unesite broj clanova polja > ");
	scanf("%d", &n);
	printf("\nUnesite clanove: ");
	for(i=0;i<n;i++){
		scanf("%d", &broj);
		if(upis(&glava, broj)==0) {
			printf("Cvor %d. neuspjesno nadodan.", i);
			exit(1);
		}
	}
	printf("\nIspis liste: \n");
	for(pom = glava; pom != NULL; pom = pom->sljed)
		printf("Na adresi %p je %d koji gleda na %p\n", pom, pom->element, pom->sljed);
	return 0;
}