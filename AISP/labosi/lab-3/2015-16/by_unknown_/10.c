#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define M 20
#define C1 0
#define C2 1

struct zp {
	int broj;
};
typedef struct zp zapis;

int adresa(int k){
	return k%19;
}

int upis (int k, zapis **hash){
	int i, adr;
	adr=adresa(k);
	for (i=0; i<M && hash[(adr+C1*i+C2*i*i)%M]; i++);
	if (hash[(adr+C1*i+C2*i*i)%M]) return 0;
	hash[(adr+C1*i+C2*i*i)%M]=(zapis*)malloc(sizeof(zapis));
	if (hash[(adr+C1*i+C2*i*i)%M] == NULL) return 0;
	hash[(adr+C1*i+C2*i*i)%M]->broj = k;
	return 1;

}

int main(void){
	int i;
	zapis *hash[M];

	for (i=0; i<M; i++) hash[i]=NULL;
	srand((unsigned)time(NULL));
	for (i=0; i<101; i++) {
		upis(rand(), hash);
	}

	for (i=0; i<M; i++) {
		printf("%d ", hash[i]->broj);
	}

	return 0;
}