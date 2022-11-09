#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100

void hash_init(int* hash) {
	int i;
	for (i = 0; i < M; i++) {
		hash[i] = -1;
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

void dodaj(int* hash, int broj, int prosti_broj) {
	int adresa, pom, k = 1;
	adresa = hash_adresa(broj, prosti_broj);
	pom = adresa;
	printf("Dodajem broj -> %d na poziciju -> %d\n", broj, adresa);
	while (hash[adresa % M] != -1) {
		adresa++;
		if ((adresa % M) == pom) {
			printf("Hash tablica je popunjena!\n");
			k = 0;
			break;
			}
		}
	if (k) {
		hash[adresa % M] = broj;
		}
	}

void ispis_hasha(int* hash) {
	printf("\n");
	int i;
	for (i = 0; i < M; i++) {
		printf("Pozicija %d.: %d\n", i, hash[i]);
			}
		printf("\n");
	}

int main(void) {
	int prosti_broj, i, broj;
	srand((unsigned)time(NULL));
	int hash[M];
	hash_init(&hash[0]);
	prosti_broj = prosti();
	for (i = 0; i < M + 1; i++) {
		broj = rand() % 10001;
		dodaj(hash, broj, prosti_broj);
	}
	ispis_hasha(&hash[0]);
	return 0;
}