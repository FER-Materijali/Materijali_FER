#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define M 100

typedef struct zp{
	int broj;
	struct zp *sljed;
};
typedef struct zp zapis;

int adresa(int k) {
	return k%97;
}

int upis(zapis **hash, int k){
	zapis *novi;
	int adr;
	novi=(zapis*)malloc(sizeof(zapis));
	if (novi==NULL) return 0;
	adr=adresa(k);
	novi->sljed=hash[adr];
	novi->broj=k;
	hash[adr]=novi;
	return 1;
}

int main(void){
	int i;
	zapis *hash[M];
	zapis *clan;
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<M; i++) hash[i]=NULL;
	for (i=0; i<101; i++) {
		upis(hash, rand());
	}

	for (i = 0; i < M; i++) {
		clan = hash[i];
		while (clan) {
			printf("%d  ", clan->broj);
			clan = clan->sljed;
		}
		printf("\n");
	}


	return 0;
}
