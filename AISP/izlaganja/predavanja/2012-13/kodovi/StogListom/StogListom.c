/* StogListom.c */
#include <stdio.h>
#include <stdlib.h>

/***** IMPLEMENTACIJA STOGA LISTOM **************/

typedef int tip;
struct at {
  tip element;
  struct at *sljed; 
};

typedef struct at atom;

typedef struct{
	atom *vrh;
} Stog;

void init_stog(Stog *stog){
	stog->vrh = NULL;
}

int dodaj (tip element, Stog *stog) { 
	atom *novi; // pokazivac na novi atom
	if ((novi = (atom *) malloc(sizeof(atom))) != NULL) { 
		novi->element = element; 
		novi->sljed = stog->vrh;		
		printf("Na adresu %p dodao sam %d, a sljedeci je %p\n",
												novi, element, stog->vrh);
		stog->vrh = novi;
		return 1;
	}
	else
		return 0;  
}

int skini (tip *element, Stog *stog) {
	atom *pom;				
    if (stog->vrh == NULL) return 0;
	*element = stog->vrh->element; 
	printf ("\t Skidam s adrese %p ", stog->vrh);
	pom = stog->vrh->sljed; /* adresa novog vrha vrha */
	free(stog->vrh);		/* obriši stari vrh */	
	stog->vrh = pom; /* postavi novi vrh */
	return 1;
}

/************* KRAJ IMPLEMENTACIJE STOGA ******************/

int  main () {
	FILE *fi;		/* ulazna datoteka */
	int j;			/* brojac ulaznih podataka */
	tip element;	/* element stoga */
	Stog stog;
	init_stog(&stog);	
	/* Upis podataka na stog */
	fi = fopen ("UlazZaStogListom.txt", "r");
	if (fi) {
		/* inicijalizacija */
		j = 0;
		/* citanje podataka i stavljanje na stog */
		while (fscanf (fi, "%d", &element) == 1) {
			printf ("%d. ulazni podatak je %d \n\t", ++j, element);			
			if (!dodaj (element, &stog)) {				
				printf("Nema vise mjesta za stog!!\n");
				break;
			}
		}
		fclose (fi);
		
		/* Skidanje elemenata sa stoga */

		printf("\nSkidanje elemenata sa stoga: \n");
		while (skini(&element, &stog)) {			
			printf ("%d\n", element);
		}
	} else {
		printf ("Nema ulazne datoteke\n");
		return 1;
	}
	return 0;
}
