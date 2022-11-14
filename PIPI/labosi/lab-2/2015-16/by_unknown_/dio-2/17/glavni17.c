#include <stdio.h>
#include <string.h>
#include "funkcije17.h"
#define MAXIGRAC 10
#define MAXKRUG 100

int main(void)
{
	int brojIgraca, brojKrugova, bodovi[MAXIGRAC][MAXIGRAC];
	int i;
	memset(bodovi, 0, sizeof(bodovi[0][0]) * MAXIGRAC * MAXIGRAC);
	scanf("%d %d", &brojIgraca, &brojKrugova);
	simulirajIgru(brojIgraca, brojKrugova, bodovi);

	printf("igrac	negativnih bodova\n");
	for (i = 0; i < brojIgraca; ++i) {
		printf("  %d	  %d", i + 1, bodovi[0][i]);
		if (bodovi[1][i] != 0)
			printf(" - ispao u %d. krugu", bodovi[1][i]);
		printf("\n");
	}
	return 0;
}