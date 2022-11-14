#include <stdio.h>
#include "funkcije13.h"

int main(void)
{
	char izlaz[13] = { '\0' }, nizPom[4];
	int h, m, s, sekunde;
	scanf("%d", &sekunde);
	hms(sekunde, &h, &m, &s);

	intUNiz(h, nizPom);
	dodajNiz(izlaz, nizPom);
	dodajNiz(izlaz, ":");

	intUNiz(m, nizPom);
	dodajNiz(izlaz, nizPom);
	dodajNiz(izlaz, ":");

	intUNiz(s, nizPom);
	dodajNiz(izlaz, nizPom);

	printf("%s\n", izlaz);
	return 0;
}