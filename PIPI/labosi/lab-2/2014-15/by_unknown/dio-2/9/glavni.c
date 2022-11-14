#include<stdio.h>
#include<string.h>
#include"funkcije.h"
int main (void) {
	char niz1[301], niz2[301], podniz[301];
	int n, len1, len2, i, brpod=0, brsadr=0;
	float slicnost;
	printf("\nPrvi niz : ");
	gets(niz1);
	printf("Drugi niz: ");
	gets(niz2);
	len1=strlen(niz1);
	len2=strlen(niz2);
	do {
	    printf("\nDuljina podniza za usporedbu nizova: ");
		scanf("%d", &n);
	} while (n<2 || n>5 || n<1 || n>len1 || n>len2);
	for (i=0; i<len1-(n-1); ++i) {
		genPodniz(niz1, podniz, i, n);
		++brpod;
		if (sadrziPodniz(niz2, podniz)) {
			++brsadr;
		}
	}
	slicnost=(float)brsadr/brpod;
	printf("\nSlicnost nizova %s i %s iznosi %f\n", niz1, niz2, slicnost);
	return 0;
}