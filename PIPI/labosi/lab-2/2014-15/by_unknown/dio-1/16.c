#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void) {
    int i, pom;
	char niz[21];
	gets(niz);
	for(i=0; i<=strlen(niz); ++i) {
		if (islower(niz[i])) {
			pom=niz[i];
			niz[i]=niz[strlen(niz)-1];
			niz[strlen(niz)-1]=pom;
			break;
		}
	}
	printf("%s", niz);
	return 0;
}