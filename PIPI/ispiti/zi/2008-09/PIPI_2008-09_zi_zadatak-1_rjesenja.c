#include <stdio.h>
#include <string.h>

void zamijeni (char *nizStari, char *nizNovi);

int main()
{
	char unos[100 + 1], izlaz[100 + 1];

	gets(unos);

	zamijeni(unos, izlaz);

	puts(izlaz);

	return 0;
}

void zamijeni (char *nizStari, char *nizNovi)
{
	char *ime;

	ime = strchr(nizStari, ' ') + 1;

	strcpy(nizNovi, ime);
	strcat(nizNovi, " ");
	strncat(nizNovi, nizStari, strlen(nizStari) - strlen(ime) - 2);
}
