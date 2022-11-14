#include <stdio.h> 

/* u ovom zadatku ću napraviti polje koliko mi treba
elemenata i sve u polju ću inicijalizirati na 0. Vrtit ću for petlju 40
petlju, isto tako sam mogao staviti while (1). U trenutku kad korisnik
učita broj 2 ja ću u polje staviti, "broj 2 prvi put učitan je taj put" i više
neću dirati to polje. Prije ili kasnije će se ponoviti neki broj, ignorirat ću
ponavljanja i onda kad budem trebao pisati rezultat samo ću prošetati po
polju i pogledati kada se koji broji prvi put pojavio */ 

int main (void) {

	int broj, i, upis[40]={0};
/*S tipkovnice učitavati cijele brojeve iz zatvorenog intervala [1, 40]. 
Učitavanje brojeva završiti kada se učita broj izvan navedenog intervala.*/
	for (i = 1; i < 40; ++i) {
		printf("unesi broj: ");
		scanf("%d", &broj);
		/* prekid u slučaju da broj nije iz intervala */
		if ((broj < 1) || (broj > 40)) break;
		if (upis[broj-1] == 0) upis[broj-1]=i;
	}
	for (i=0; i<40; i++) {
		if (upis[i] != 0) {
			printf("Broj %d : %d\n", i+1, upis[i]);
		}
	}
	return 0;
}

len = 0;
while(str[len] != '\0') len++;