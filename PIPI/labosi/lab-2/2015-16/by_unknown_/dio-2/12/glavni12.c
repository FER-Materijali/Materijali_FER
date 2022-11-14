#include <stdio.h>
#include "funkcije12.h"
#define MAXTEKST 1500

int main(void)
{
	char tekst[MAXTEKST + 1];
	char najZnak1, najZnak2;
	gets(tekst);
	najZnak(tekst, &najZnak1, &najZnak2);

	printf("Jezik na kojem je tekst vjerojatno napisan je: ");
	if ((najZnak1 == 'A' && najZnak2 == 'I') || (najZnak1 == 'I' && najZnak2 == 'A'))
		printf("Hrvatski\n");
	else if (najZnak1 == 'E') {
		if (najZnak2 == 'T')
			printf("Engleski\n");
		else if (najZnak2 == 'N')
			printf("Njemacki\n");
		else
			printf("Nepoznat\n");
	}
	else
		printf("Nepoznat\n");

	return 0;
}