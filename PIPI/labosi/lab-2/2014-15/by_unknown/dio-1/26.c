#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void) {
char niz[6], max='0';
int i, ispravan=1;
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
        if (toupper(niz[i])>toupper(max)) {
			max=niz[i];
		}
	}
    printf("Najveca heksadekadska znamenka u ucitanom broju je %c.", max);
}
return 0;
}