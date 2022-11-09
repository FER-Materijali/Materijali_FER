#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define M 100

typedef struct zapis {
	int broj;
	struct zapis* sljedeci;
	}zapis;

void hash_init(zapis* hash) {
	int i;
	for (i = 0; i < M; i++) {
		(&hash[i])->sljedeci = NULL;
		(&hash[i])->broj = -1;
		}	
	}

int hash_adresa(int broj, int prosti_broj) {
	return broj % prosti_broj;
	}

int prosti(void) {
	int k = 1;
	int broj = M;
	while (k) {
		int dj = 2;
		k = 0;
		for (; dj != broj / 2; dj++) {
			if (broj%dj == 0) {
				k = 1;
				break;
				}
			}
		if (k) broj--;
		}
	return broj;
	}

void dodaj(zapis* hash, int broj, int prosti_broj) {
	int adresa;
	adresa = hash_adresa(broj, prosti_broj);
	zapis* adr = &hash[adresa];
	while (adr->sljedeci != NULL) adr = adr->sljedeci;
	if (adr->broj == -1) {
		adr->broj = broj;
		adr->sljedeci = NULL;
		}
	else {
		zapis* novi;
		novi = (zapis*)malloc(sizeof(zapis));
		novi->broj = broj;
		novi->sljedeci = NULL;
		adr->sljedeci = novi;
		}
	printf("Dodajem broj -> %d na poziciju -> %d\n", broj, adresa);
	}

void ispis_hasha(zapis* hash) {
	printf("\n");
	int i;
	zapis* adr;
	for (i = 0; i < M; i++) {
		adr = &hash[i];
		printf("Pozicija %d.: ", i);
		while (adr->sljedeci) {
			printf("%d ", adr->broj);
			adr = adr->sljedeci;
			}
		printf("%d ", adr->broj);
		printf("\n");
		}
	}

int main(void) {
	int prosti_broj, i, broj;
	srand((unsigned)time(NULL));
	zapis hash[M];
	hash_init(&hash[0]);
	prosti_broj = prosti();
	for (i = 0; i < M + 1; i++) {
		broj = rand() % 10001;
		dodaj(hash, broj, prosti_broj);
		}
	ispis_hasha(&hash[0]);
	return 0;
	}