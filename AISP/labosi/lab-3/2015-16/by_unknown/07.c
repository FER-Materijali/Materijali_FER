#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define maxn 100

typedef struct zapis {
	int redni;
	int broj;
	struct zapis* prethodni;
	}zapis;

typedef struct Stog {
	zapis* vrh;
	}Stog;

void stog_init(Stog* stog) {
	stog->vrh = NULL;
	}

void dodaj(Stog* stog, int broj) {
	printf("Dodajem broj -> %d\n", broj);
	zapis* novi;
	novi = (zapis*)malloc(sizeof(zapis));
	if (stog->vrh && stog->vrh->redni == 100) printf("Stog je pun!\n");
	else {
		if (stog->vrh == NULL) novi->redni = 1;
		else novi->redni = stog->vrh->redni + 1;
		novi->broj = broj; 
		novi->prethodni = stog->vrh;
		stog->vrh = novi;
		}	
	}

void ispis(Stog* stog) {
	printf("\n");
	zapis* pom;
	while (stog->vrh != NULL) {
		pom = stog->vrh;
		printf("-> %d\n", stog->vrh->broj);
		stog->vrh = stog->vrh->prethodni;
		free(pom);
	}
	printf("Stog je prazan!\n");
	}


int main(void) {
	Stog* stog;
	int i;
	stog = (Stog*)malloc(sizeof(Stog));
	stog_init(stog);
	srand((unsigned)time(NULL));
	for (i = 0; i < maxn + 1; i++) {
		dodaj(stog, rand() % (10001));
		}
	ispis(stog);
	return 0;
	}