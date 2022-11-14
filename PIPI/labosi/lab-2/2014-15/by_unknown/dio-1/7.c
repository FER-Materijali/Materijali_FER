#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void) {
    int i, slovo=0;
	char niz[21];
	gets(niz);
	for(i=0; i<=strlen(niz); ++i) {
		if (isalpha(niz[i])) {
			slovo=1;
			break;
		}
	}
	if (strlen(niz)<8) {
		printf("Prekratak");
	} else if (slovo==0) {
		printf("Ne sadrzi slovo");
	} else {
		printf("Zadovoljava uvjete");
	}
	return 0;
}