#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define maxn 100

typedef struct Stog {
	unsigned int vrh;
	int polje[maxn];
	}Stog;

void stog_init(Stog* stog) {
	stog->vrh = -1;
	}

void dodaj(Stog* stog, int broj) {
	printf("Dodajem broj -> %d\n", broj);
	if (stog->vrh == 99) printf("Stog je pun!\n");
	else stog->polje[++(stog->vrh)] = broj;
	}

void ispis(Stog* stog) {
	printf("\n");
	while (stog->vrh != -1) {
		printf("-> %d\n", stog->polje[stog->vrh]);
		stog->vrh--;
		}
	printf("Stog je prazan!\n");
	}


int main(void) {
	Stog* stog;
	int i;
	stog = (Stog*)malloc(sizeof(Stog));
	stog_init(stog);
	srand((unsigned)time(NULL));
	for (i = 0; i < maxn+1; i++) {
		dodaj(stog, rand()%(10001));
		}
	ispis(stog);
	return 0;
	}