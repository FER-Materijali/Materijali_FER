#include <stdio.h>

int main (void) {
	char niz1[30], niz2[30];
	int len1=0, len2=0, brojac=0, i;
	gets(niz1);
	gets(niz2);

	/*utvrdi koji je duži*/
	while (niz1[len1]!='\0') len1++;
	while (niz2[len2] != '\0') len2++;
	
	/* promjena počinje na dužem nizu i traje koliko je 
	dugačak kraći niz */	
	if (len1 > len2) {
		for (i =0 ; i< len2; i++) {
			if (i%2 == 0) {
				niz2[i] = niz1[i];
				brojac++;
			}
		}
		printf("Promijenjeni niz: %s\n", niz2);;
		printf("Promijenjeni znakovi: %d\n", brojac);
	} else {
		for (i =0 ; i< len1; i++) {
			if (i%2 == 0) {
				niz1[i] = niz2[i];
				brojac++;
			}
		}
		printf("Promijenjeni niz: %s\n", niz1);;
		printf("Promijenjeni znakovi: %d\n", brojac);
	}
	return 0;
}
