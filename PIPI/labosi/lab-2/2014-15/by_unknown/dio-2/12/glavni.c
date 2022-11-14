#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char tekst[1501], najc1, najc2;
	gets(tekst);
	najcesci(tekst, &najc1, &najc2);
	printf("\nJezik na kojem je tekst vjerojatno napisan je: ");
	if (najc1=='A' || najc1=='I') {
		printf("Hrvatski\n");
	} else if (najc1=='E' && najc2=='T') {
		printf("Engleski\n");
	} else if (najc1=='E' && najc2=='N') {
        printf("Njemacki\n");	
	} else {
		printf("Nepoznat\n");
	}
	return 0;
}