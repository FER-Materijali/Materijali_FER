#include<stdio.h>
int main (void) {
	char niz[31];
	int slova=0, znam=0, i;
	gets (niz);
	for (i=0; niz[i]!='\0'; ++i) {
		if (niz[i]>='a' && niz[i]<='z') {
			++slova;
		}
		if (niz[i]>='0' && niz[i]<='9') {
			++znam;
		}
	}
	if (slova>=7 && znam>=2) {
		printf("Zadovoljava uvjete");
	} else {
		printf ("Ne zadovoljava uvjete");
	}
}