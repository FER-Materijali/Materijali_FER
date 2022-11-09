#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100
#define c1 1
#define c2 1

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
	int adresa, pom, k = 1, i = 0;
	adresa = hash_adresa(broj, prosti_broj);
	pom = adresa;
	printf("Dodajem broj -> %d na poziciju -> %d\n", broj, adresa);
	while (hash[(adresa + c1*i + c2*i*i) % M] != -1) {
		i++;
		if ((adresa + c1*i + c2*i*i) % M == pom) {
			k = 0;
			printf("Hash tablica je popunjena ili nije moguce pristupiti slobodnoj adresi formulom -> adresa + %d*i + %d*i^2 !\n", c1, c2);
			break;
			}
		}
	if (k) hash[(adresa + c1*i + c2*i*i) % M] = broj;
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