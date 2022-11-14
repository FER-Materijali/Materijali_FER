#include<stdio.h>
#include<string.h>
int main (void) {
char niz[6];
int i, brojac=0, ispravan=1;
gets(niz);
for (i=0; i<strlen(niz); ++i) {
	if (niz[i]<'0' || niz[i]>'7') {
		printf("Ucitani niz nije ispravno zadan.\n");
		ispravan=0;
		break;
	}
}
if (ispravan) {
for (i=0; i<strlen(niz); ++i) {
	if (niz[i]=='4') {
		++brojac;
	}
}
printf("Znamenka 4 se u ucitanom broju pojavljuje %d puta.", brojac);
}
return 0;
}