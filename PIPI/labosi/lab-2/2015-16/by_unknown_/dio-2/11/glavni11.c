#include <stdio.h>
#include "funkcije11.h"
#define MAXULAZ 100
#define MAXUZOR 10

int main(void)
{
	char ulaz[MAXULAZ + 1], uzorak[MAXUZOR + 1];
	printf("Sadrzaj niza ulaz je: ");
	gets(ulaz);
	printf("Sadrzaj niza uzorak je: ");
	gets(uzorak);

	while(izbaci(ulaz, uzorak));
	printf("Nakon izvodenja glavnog programa sadrzaj niza ulaz je: %s\n", ulaz);

	return 0;
}