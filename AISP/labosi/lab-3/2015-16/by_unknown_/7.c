#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSTOG 10

struct at {
	int element;
	struct at *sljed;
};
typedef struct at atom;

typedef struct {
	atom *vrh;
} Stog;

void init_stog(Stog *stog){
	stog->vrh=NULL;
}

int dodaj (int broj, Stog *stog){
	atom *novi;
	novi=(atom *)malloc(sizeof(atom));
	if (novi==NULL) return 0;
	novi->element=broj;
	novi->sljed=stog->vrh;
	stog->vrh=novi;
	return 1;
}

int main(void){
	int i, broj;
	Stog stog;

	init_stog(&stog);
	srand((unsigned)time(NULL));
	
	for (i=0; i<MAXSTOG; i++) {
		broj=rand();
		if (dodaj(broj, &stog)) printf("Broj %d dodan na stog.\n", broj);
		else {
			printf("Stog je pun.");
			break;
		}
	}
	return 0;

}