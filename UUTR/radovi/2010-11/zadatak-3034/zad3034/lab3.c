#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRIJELAZI 100
#define TRAKA 60

			
typedef struct {
	char trenutnoStanje[5]; 
	char ulazniZnak; 
	char novoStanje[5]; 
	char noviZnak; 
	char pomakGlave;
} prijelaz;

int main(){
	FILE *input;
    prijelaz nadjeniPrijelaz;
    prijelaz *tablicaPrijelaza = malloc(PRIJELAZI * sizeof(prijelaz));
    char ulazniZnakPom;
	char trenutnoStanjePom[5];
    char novoStanjePom[5];
    char trakaStroja[TRAKA]; 
    char trakaStrojaPom[TRAKA];
	char noviZnakPom;
    char pomakGlavePom;
	int polozajGlave,pauza,brojac;
	int brojPrijelaza=0;
	
	input = fopen("def.txt", "r");
	if (input == NULL) {
		printf("Greška kod otvaranja datoteke sa definicijama! Provjerite putanju!");
        exit(1);
	}
	while (fscanf(input, "%s %c %s %c %c", trenutnoStanjePom, &ulazniZnakPom, novoStanjePom, &noviZnakPom, &pomakGlavePom) == 5) {
		prijelaz pomocniPrijelaz;
        strncpy(pomocniPrijelaz.trenutnoStanje, trenutnoStanjePom, 3);
		pomocniPrijelaz.trenutnoStanje[4] = '\0';
		pomocniPrijelaz.ulazniZnak = ulazniZnakPom;
		strncpy(pomocniPrijelaz.novoStanje, novoStanjePom, 3);
		pomocniPrijelaz.novoStanje[4] = '\0';
		pomocniPrijelaz.noviZnak = noviZnakPom;
		pomocniPrijelaz.pomakGlave = pomakGlavePom;

		if (brojPrijelaza == PRIJELAZI) {
			printf("Datoteka sa definicijama sadrži previše prijelaza! Poveæajte konstantu PRIJELAZI!");
            exit(1);
		}
		tablicaPrijelaza[brojPrijelaza++] = pomocniPrijelaz;
	}
	fclose(input);

	for (brojac = 0; brojac < TRAKA; brojac++) trakaStroja[brojac] = 'B';
	trakaStroja[TRAKA - 1] = '\0';
	
    input = fopen("ulaz.txt", "r");
	if (input == NULL) {
        printf("Greška kod otvaranja datoteke sa ulaznim podacima!");
		exit(1);
	}
	fscanf(input, "%s", trakaStrojaPom);
	for (brojac = 0; trakaStrojaPom[brojac] != '\0'; brojac++) {
		trakaStroja[brojac] = trakaStrojaPom[brojac];
	}
	fclose(input);

	strcpy(trenutnoStanjePom, "q0");
	polozajGlave = 0;
	while (1) {
		int prijelazJeNadjen = 0;

		printf("Stanje:  %s\n", trenutnoStanjePom);
		printf("Traka:   %s\n", trakaStroja);
		for (brojac = 0; brojac < polozajGlave+9; brojac++) {
			printf(" ");
		}
		printf("^\n---------------------------------------------------------------------\n");

		ulazniZnakPom = trakaStroja[polozajGlave];
		
		for (brojac = 0; brojac < brojPrijelaza; brojac++) {
			prijelaz pomocniPrijelaz = tablicaPrijelaza[brojac];
			if (!strcmp(pomocniPrijelaz.trenutnoStanje, trenutnoStanjePom) && pomocniPrijelaz.ulazniZnak == ulazniZnakPom) {
				nadjeniPrijelaz = pomocniPrijelaz;
				prijelazJeNadjen = 1;
				break;
			}
		}
		if (prijelazJeNadjen == 0) {
			printf("Nema definitanih prijelaza prijelaza. TS je stao!\n");
			break;
		}

		strcpy(trenutnoStanjePom, nadjeniPrijelaz.novoStanje);
		trakaStroja[polozajGlave] = nadjeniPrijelaz.noviZnak;
		if (nadjeniPrijelaz.pomakGlave == 'R') {
			polozajGlave++;
		} else {
			polozajGlave--;
		}
	}
	
	free(tablicaPrijelaza);
	scanf("%d", &pauza);
	return 0;
}
