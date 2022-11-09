#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSTOG 20

typedef struct {
	int vrh;
	int polje[MAXSTOG];
} Stog;

void init_stog(Stog *stog){
	stog->vrh=-1;
}

int dodaj(int broj, Stog *stog){
	if (stog->vrh >= MAXSTOG - 1) return 0;
	stog->vrh++;
	stog->polje[stog->vrh]=broj;
	return 1;
}

int main (void){
	int i, broj;
	Stog stog;

	init_stog(&stog);
	srand((unsigned)time(NULL));

	for (i=0; i<21; i++) {
		broj=rand();
		if (dodaj(broj, &stog)) printf("Broj %d dodan na stog. \n", broj);
		else {
			printf ("Stack overflow!");
			break;
		}
	}
	return 0;
}