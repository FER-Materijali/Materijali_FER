#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int broj;
	char mjesto[41];
}zapis;

void insertionSort(zapis *A, int n)
{
	int i, j;
	zapis pom;
	for ( i = 1; i < n; i++)
	{
		pom = A[i];
		for (j = i; j >0  && A[j - 1].broj>pom.broj; --j)
		{
			A[j] = A[j - 1];
			
			
		}
		A[j] = pom;
	}
}

int main() {
	int i, n;
	zapis * niz;
	printf("Upisite N<=10\n");
	scanf("%d", &n);
	niz = (zapis*)malloc(n*sizeof(zapis));
	if (niz == NULL)
	{
		puts("Greska!!! Nema memorije");
		exit(1);
	}
	puts("Upisite postanski broj i naziv za svaki grad");
	for (i = 0; i < n; ++i)
	{
		printf("%d grad\n",i+1);
		scanf(" %d ", &niz[i].broj);
		gets(niz[i].mjesto);
		puts("");
	}
	puts("Prije sortiranj ");
	for (i = 0; i < n; ++i)
	{
		printf(" %3d %s\n", niz[i].broj, niz[i].mjesto);
	}
	insertionSort(&niz[0], n);
	puts("Nakon sorta");
	for (i = 0; i < n; ++i)
	{
		printf(" %3d %s\n", niz[i].broj, niz[i].mjesto);
	}

	return 0;



}