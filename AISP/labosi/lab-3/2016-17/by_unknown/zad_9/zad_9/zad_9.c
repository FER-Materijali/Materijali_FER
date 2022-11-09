#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <math.h>
#define M 128

#pragma warning(disable:4996)

struct zp 
{
	int broj;					//strukutra zapis
	struct zp *sljed;
};
typedef struct zp zapis;


	
unsigned long int adresa(unsigned short int k) 
{
		unsigned long long A = 2654435769;  //konstanta A
		unsigned int pomak =31;				//pomak 31 jer se radi od 32-bitnom zapisu
		unsigned int maska = (1 << (int)ceil((log2(M)))) - 1;  //maska ovisna o velicini hasha
		return ((unsigned int)((A*k) >> pomak)& maska);			//sam pomak za slijedeci podatak
}


int upis(zapis **hash, int k)			//rijesavanje kolizije metodom ulanèavanja
{
	zapis *novi;
	int adr;
	novi = (zapis*)malloc(sizeof(zapis));
	if (novi == NULL) return 0;
	adr = adresa(k);
	novi->sljed = hash[adr];
	novi->broj = k;
	hash[adr] = novi;
	return 1;
}

int main(void)
{
	int i;
	zapis *hash[M];
	zapis *clan;

	srand((unsigned)time(NULL));

	for (i = 0; i<M; i++) hash[i] = NULL;
	for (i = 0; i<129; i++) 
	{
		upis(hash, rand());			//upis podataka u hash
	}

	for (i = 0; i < M; i++)
	{
		clan = hash[i];
		while (clan) 
		{
			printf(" %d ", clan->broj);			//ispis podataka iz hasha
			clan = clan->sljed;
			
		}
		printf("\n");
		printf("\n");
		
	}

	getchar();
	return 0;
}
