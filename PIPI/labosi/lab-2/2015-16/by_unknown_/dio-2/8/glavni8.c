#include <stdio.h>
#include "funkcije8.h"
#define MAXLEN 200

int main(void)
{
	char unos[MAXLEN + 1], granicnici[3];
	printf("Upisite izraz koji zelize provjeriti: ");
	gets(unos);
	for (;;) {
		printf("Upisite lijevi i desni granicnik: ");
		gets(granicnici);
		if (granicnici[0] == '\\' || granicnici[1] == '\\')
			break;
		printf("Izraz %s %s ispravan ozbirom na granicnike %c %c.\n", unos, izrazJeIspravan(unos, granicnici[0], granicnici[1]) ? "JE" : "NIJE", granicnici[0], granicnici[1]);
	}
	return 0;
}