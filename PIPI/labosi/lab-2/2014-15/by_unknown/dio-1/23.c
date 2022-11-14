#include<stdio.h>
#include<string.h>
int main (void) {
char niz[11];
int i, ispravan=1;
gets(niz);
for (i=0; i<strlen(niz); ++i) {
	if (niz[i]!='0' && niz[i]!='1') {
		printf("Ucitani niz nije ispravno zadan.\n");
		ispravan=0;
		break;
	}
}
if (ispravan) {
for (i=0; i<strlen(niz)-1; ++i) {
	if (niz[i]=='0' && niz[i+1]=='0') {
		printf("Ucitani binarni broj sadrzi dvije ili vise uzastopnih znamenki 0.");
		break;
	} else if (i==strlen(niz)-2) {
		printf("Ucitani binarni broj ne sadrzi dvije ili vise uzastopnih znamenki 0.");
	}
}
}
return 0;
}