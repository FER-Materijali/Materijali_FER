#include <stdio.h>
#include <math.h>
#pragma warning (disable: 4996)

int main()
{
	float x0, x1;
	float a0, a1;
	float an;
	float C1, C2;
	int n;
	int o;
	int i;

	printf("Unesite prvo rjesenje x_0 karakteristicne jednadzbe:");
	scanf("%f", &x0);
	fflush(stdin);
	printf("Unesite drugo rjesenje x_1 karakteristicne jednadzbe:");
	scanf("%f", &x1);
	fflush(stdin);
	printf("Unesite vrijednost nultog clana niza a0:");
	scanf("%f", &a0);
	fflush(stdin);
	printf("Unesite vrijednost prvog clana niza a1:");
	scanf("%f", &a1);
	fflush(stdin);
	printf("Unesite redni broj n trazenog clana niza:");
	scanf("%d", &n);
	fflush(stdin);
	printf("\n");
	printf("Odaberite metodu rjesavanja:\n");
	printf("---------------------------------------------------------------\n");
	printf("1 - formulom za opce rjesenje homogene rekurzivne relacije\n");
	printf("2 - odredjivanjem relacije i rekurzivnim racunanjem n-tog clana\n");
	printf("---------------------------------------------------------------\n");
	scanf("%d", &o);

	if (o == 1)
	{
		printf("Odabrali ste metodu 1 (formula)\n");
		C2 = -(a1 - a0 * x0) / (x0 - x1);
		C1 = a0 - C2;
		an = C1 * powf(x0, n) + C2 * powf(x1, n);
		printf("Vrijednost %d. clana je %f", n, an);
	}
	else if (o == 2)
	{
		printf("Odabrali ste metodu 2 (rekurzija)\n");
		for (i = 0; i <= n-2; i++)
		{
			an = (x0+x1)*a0 + (-x0*x1)*a1;
			a0 = a1;
			a1 = an;
		}
		printf("Vrijednost %d. clana je %f", n, an);
	}
	else
		printf("Neispravan odabir! Ponovno pokrenite program!");

	getchar();
	getchar();
	return 0;
}