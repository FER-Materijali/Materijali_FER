#include <stdio.h>
#include"funkcije10.h"
#define MAXLEN 100

int main(void)
{
	char unos[MAXLEN + 1], kodiran[MAXLEN +1];
	printf("Unesite niz za kodiranje: ");
	gets(unos);
	kodiraj(unos, kodiran);
	printf("Originalni niz: %s\nKodirani niz: %s\n", unos, kodiran);

	return 0;
}