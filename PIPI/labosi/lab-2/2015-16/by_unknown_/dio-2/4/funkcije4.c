#include <stdio.h>

void generirajNiz(char *znakovi, int duljinaNiza, char *genNiz)
{
	int duljina = 0, i, j;
	for (i = 0; *(znakovi + i) != '\0'; ++i, ++duljina);		/*raèuna duljinu unesenog niza*/
	if (duljinaNiza <= duljina) {
		for (i = duljina - duljinaNiza, j = 0; i <= duljina; ++i, ++j)		/*preslikava odreðen broj zadnjih znakova u genNiz ukluèujuæi i '\0'*/
			*(genNiz + j) = *(znakovi + i);
	}
	else {
		for (i = 0; i < duljina; ++i)
			*(genNiz + i) = *(znakovi + i);
		j = 0;
		while (i < duljinaNiza) {
			*(genNiz + i) = *(znakovi + j);
			++i, ++j;
			if (j == duljina)
				j = 0;
		}
		*(genNiz + i) = '\0';
	}
}

int dobarNiz(char *znakovi)
{
	int dobar = 1, i, j;
	for (i = 0; *(znakovi + i) != '\0'; ++i)
		for (j = i + 1; *(znakovi + j) != '\0'; ++j)
			if (*(znakovi + i) == *(znakovi + j))
				dobar = 0;
	return dobar;
}
