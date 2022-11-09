/* StogPoljem.c */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/***** IMPLEMENTACIJA STOGA POLJEM **************/

#define MAXSTOG 5 /* maksimalna velicina stoga */

typedef struct {
	int vrh, polje[MAXSTOG];	
} Stog;

void init_stog(Stog *stog){
	stog->vrh = -1;	
}

int dodaj(int stavka, Stog *stog){
	if (stog->vrh >= MAXSTOG-1) return 0;   /* dosegnut kapacitet stoga */
	stog->vrh++;	
	stog->polje[stog->vrh] = stavka;
	return 1;
}


int skini(int *stavka, Stog *stog){
	if (stog->vrh < 0) return 0;
	*stavka = stog->polje[stog->vrh];
	stog->vrh--;
	return 1;
}


/* nije nuzna za funkcioniranje stoga, 
vec samo sluzi za provjeru ispravnosti rada programa*/
void ispis_stoga(Stog *stog){ 
	int i;
	if (stog->vrh == -1) {
			printf ("(prazan stog)");
	} 
	else {
		printf ("Stog:");
		for (i=0; i <= stog->vrh; ++i) 
			printf (" %d", stog->polje[i]);
	}
}

/************* KRAJ IMPLEMENTACIJE STOGA ******************/

int main () {
	int novi, stari; 
	Stog stog;	
	init_stog(&stog);
	printf ("Slucajno se generiraju nenegativni cijeli brojevi.\n");
	printf ("Neparni brojevi upisuju se na stog\n");
	printf ("Parni broj simulira skidanje sa stoga\n");
	printf ("Za obavljanje jednog koraka pritisnuti ENTER, za kraj CTRL-C\n\n");
	/* Inicijalizacija generatora pseudoslucajnih brojeva
	   na temelju sistemskog vremena */
	srand ((unsigned) time (NULL));
	while (1) {	
		ispis_stoga(&stog);
		putchar ('\n');	
		getchar ();
		novi = rand ();
		if (novi%2) {		/* Neparni se upisuju na stog */
			printf ("Dodaj %d\n", novi);
			if (!dodaj (novi, &stog)) 
				printf("Stog je pun!\n");
    	} else {			/* Parni broj simulira skidanje sa stoga */
			  printf ("Skini...");
			  if (skini (&stari, &stog))	
				  printf ("Skinut %d\n", stari);
			  else 
				  printf("Stog je prazan!\n");
		}
	}
	return 0;
}
