#include<stdio.h>
#include<string.h>
int main (void) {
char niz[6];
int i, ispravan=1;
gets(niz);
for (i=0; i<strlen(niz); ++i) {
	if (niz[i]<'0' || niz[i]>'7') {
		printf("Ucitani niz nije ispravno zadan.\n");
		ispravan=0;
		break;
	}
}
if (ispravan) {
printf("Prva znamenka ucitanog broja je %c\n", niz[0]);
printf("Posljednja znamenka ucitanog broja je %c\n", niz[strlen(niz)-1]);
}
return 0;
}