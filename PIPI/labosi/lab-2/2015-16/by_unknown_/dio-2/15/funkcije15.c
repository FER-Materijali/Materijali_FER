#include <string.h>

int sazetak(char *ulaz)
{
	int i, zbroj = 0;
	if (strlen(ulaz) == 0)
		return 0;

	for (i = 0; ulaz[i] != '\0'; ++i)
		zbroj += ulaz[i];
	return zbroj % 128;
}

void dodajZnak(char *ulaz, int broj)
{
	int i = strlen(ulaz);
	ulaz[i++] = broj;
	ulaz[i] = '\0';
}