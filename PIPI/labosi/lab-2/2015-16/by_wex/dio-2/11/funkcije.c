#include <stdlib.h>

char* nadjipodniz(char *ulaz, char *uzorak) {
	int i, j;
	int found;
	for (i=0; *(ulaz+i)!=0; i++){
		found = 1;
		for (j=0; *(uzorak+j)!=0; j++) {
			if (*(uzorak+j) != *(ulaz+i+j)) found = 0;
		}
		if (found == 1) return (ulaz+i);
	}
	return NULL;
}

int izbaci(char *ulaz, char *uzorak) {
	int izbacen = 0;
	int duljina = 0;
	int i;
	char *p;
	for (i=0; *(uzorak+i)!=0; i++) duljina++;
	p = nadjipodniz(ulaz, uzorak);
	if (p != NULL) {
		for (i=0; *(p+i)!=0; i++) {
			*(p+i) = *(p+i+duljina);
		}
		izbacen = 1;
	}
	return izbacen;
}