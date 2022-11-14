#include"funkcije.h"
void unija (int n1, int *s1, int n2, int *s2, int *nrez, int *rez) {
	int i, j, brojac=0, ponovljen=0;
	for (i=0; i<n1; ++i) {
		*(rez+i)=*(s1+i);
		++brojac;
	}
	for (i=0; i<n2; ++i) {
		for(j=0; j<n1; ++j) {
			if (*(s2+i)==*(s1+j)) {
				ponovljen=1;
				break;
			} else {
				ponovljen=0;
			}
		}
		if (!ponovljen) {
				*(rez+brojac)=*(s2+i);
				++brojac;
			}
	}
	*nrez=brojac;
}