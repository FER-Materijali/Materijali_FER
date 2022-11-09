#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include<math.h>
#pragma warning(disable:4996)
#define M 256
#define C1 0
#define C2 1

struct zp 
{
	int broj;			//strukutra zapis
};
typedef struct zp zapis;

unsigned long int adresa(unsigned short int k)
{
	unsigned long long A = 2654435769;		//konstanta A
	unsigned int pomak = 31;				//pomak 31 jer se radi od 32-bitnom zapisu
	unsigned int maska = (1 << (int)ceil((log2(M)))) - 1;		//maska ovisna o velicini hasha
	return ((unsigned int)((A*k) >> pomak)& maska);				//sam pomak za slijedeci podatak
}
int upis(int k, zapis **hash)		//rijesavanje kolizije kvadratnog ispitivanja
{
	int i, adr;
	adr = adresa(k);
	for (i = 0; i<M && hash[(adr + C1*i + C2*i*i) % M]; i++);
	if (hash[(adr + C1*i + C2*i*i) % M]) return 0;
	hash[(adr + C1*i + C2*i*i) % M] = (zapis*)malloc(sizeof(zapis));
	if (hash[(adr + C1*i + C2*i*i) % M] == NULL) return 0;
	hash[(adr + C1*i + C2*i*i) % M]->broj = k;
	return 1;

}

int main(void) {
	int i;
	zapis *hash[M];

	for (i = 0; i<M; i++) hash[i] = NULL;
	srand((unsigned)time(NULL));
	for (i = 0; i<257; i++) 
	{
		upis(rand(), hash);		//upis podataka u hash
	}

	for (i = 0; i<M; i++) 
	{
		if (hash[i] == NULL)
		{
			printf("prazan\n");
		}
		else
		{
			printf("%d\n ", hash[i]->broj);				//ispis podataka iz hasha
		}
	}

	getchar();
	getchar();
	return 0;
}