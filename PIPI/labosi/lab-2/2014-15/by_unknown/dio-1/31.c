#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main (void) {
char niz[31];
int i, ispravan=1;
gets(niz);
for (i=0; i<strlen(niz); ++i) {
	if (!isalnum(niz[i])) {
		printf("Ucitani niz nije ispravno zadan.\n");
		ispravan=0;
		break;
	}
}
if (ispravan) {
	printf("\n%s\n", niz);
	for (i=0; i<strlen(niz); ++i) {
		switch (niz[i]) {
			case 'a': niz[i]='9';
			break;
			case 'e': niz[i]='8';
			break;
			case 'i': niz[i]='7';
			break;
		}
	}
	printf("%s\n", niz);
}
return 0;
}