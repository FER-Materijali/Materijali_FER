#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void) {
char niz[11];
int i, brojac=0, ispravan=1;
gets(niz);
for (i=0; i<strlen(niz); ++i) {
	if (!isdigit(niz[i]) && (niz[i]<'A' || niz[i]>'F') && (niz[i]<'a' || niz[i]>'f')) {
		printf("Ucitani niz nije ispravno zadan.\n");
		ispravan=0;
		break;
	}
}
if (ispravan) {
   for (i=0; i<strlen(niz); ++i) {
	   if (niz[i]>='0' && niz[i]<='7') {
		  ++brojac;
	   }
   }
   printf("Broj unesnih oktalnih znamenki: %d", brojac);
}
return 0;
}