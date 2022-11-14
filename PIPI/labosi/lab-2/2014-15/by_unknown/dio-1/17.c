#include<stdio.h>
#include<string.h>
int main (void) {
int i, max, brojac=0;
char niz1[31], niz2[31];
gets(niz1);
gets(niz2);
max = strlen(niz1)<=strlen(niz2) ? strlen(niz1) : strlen(niz2);
for (i=0; i<max; i+=2) {
	niz1[i]=niz2[i];
	++brojac;
}
printf("\nPromijenjeni niz: %s\nPromijenjeno znakova: %d\n", niz1, brojac);
return 0;
}