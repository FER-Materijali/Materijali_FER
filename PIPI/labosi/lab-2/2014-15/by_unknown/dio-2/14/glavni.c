#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char niz1[10], niz2[10];
	int ispravni=1, m, n;
	gets(niz1);
	gets(niz2);
	if (nizUInt(niz1)<0) {
	    printf("Niz \"%s\" je neispravan.", niz1);
		ispravni=0;
	}
	if (nizUInt(niz2)<0) {
	    printf("Niz \"%s\" je neispravan.", niz2);
		ispravni=0;
	} else if (nizUInt(niz2)==0) {
		printf("Nazivnik je nula.");
		ispravni=0;
	}
	if (ispravni) {
	    m=nizUInt(niz1);
		n=nizUInt(niz2);
		printf("%d : %d = %f", m, n, dijeljenje(m, n));
	} else {
		printf("Prekidam.");
	}
	return 0;
}