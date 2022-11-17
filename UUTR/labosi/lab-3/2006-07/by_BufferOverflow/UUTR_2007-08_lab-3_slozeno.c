#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define		TRAKA				128			// (velicina trake) osigurajte da je ovaj broj dovoljno velik

int Prijelaz(int *st, char zn, char *noviZnak, char *smjer);
void Prihv(int st);

void main() {
	FILE *iTrack;
	int Glava = 0, trenStanje = 0, trenZnak, i; 
	char noviZnak, smjer, Traka[TRAKA] = {0};;
	
	iTrack = fopen("input.txt", "r");
	if (iTrack == NULL) { 
		printf("error: can\\'t open output file."); 
		exit(1); 
	}
	fscanf(iTrack, "%s", Traka); 
	fclose(iTrack); // ucitaj traku iz datoteke
	
	for(i=0; i<TRAKA; i++) 
		if (Traka[i] == 0) Traka[i] = \\'B\\'; 
	
	Traka[TRAKA-1] = 0; // ispuni traku praznim celijama
	
	while (1) {
		trenZnak = Traka[Glava]; // procitaj trenutni znak koji glava cita
		printf("\n "); 
		for(i=0; i<Glava; i++) 
			printf("%c", Traka[i]);		// pokazi dio trake ispred glave
		printf(" [q%d] ", trenStanje);						// pokazi trenutno stanje
		for(i=Glava; i<TRAKA; i++) 
			printf("%c", Traka[i]);	// pokazi ostatak trake

		if (Prijelaz(&trenStanje, trenZnak, &noviZnak, &smjer)) // pozovi funkciju prijelaza
			Traka[Glava] = noviZnak; // zapisi novi znak na traku (ovo se odvija samo ako je definiran prijelaz)
		else { 
			printf("\n\n\n Nema odgovarajuceg prijelaza. TS zaustavljen\n\n"); 
			break; 
		}
		if (smjer == \\'R\\')	Glava++; 
		else				Glava--; // pomakni glavu u lijevo ili desno (paziti na veliko slovo R)
		if (Glava < 0 || Glava > TRAKA-1) { // ako se ovo dogodi zbog izlaska s desne strane, povecajte velicinu trake
			printf("\n\n\n Glava izasla iz trake. TS zaustavljen.\n\n"); 
			break; 
		}
	}
	Prihv(trenStanje); // je li stanje prihvatljivo u trenutku kad stroj stane.
	getch(); // press any key to continue (getch.h)
}

void Prihv(int st) {
	if (st == 18)	printf("\n ------------------\n TS prihvaca niz.\n\n\n\n");
	else			printf("\n ------------------\n TS ne prihvaca niz.\n\n\n\n");
}


int Prijelaz(int *st, char zn, char *noviZnak, char *smjer) {

	if (*st == 0 && zn == \\'O\\') { *st = 0; *noviZnak = \\'O\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'R\\') { *st = 0; *noviZnak = \\'R\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'N\\') { *st = 0; *noviZnak = \\'N\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'E\\') { *st = 0; *noviZnak = \\'E\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'L\\') { *st = 0; *noviZnak = \\'L\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'I\\') { *st = 0; *noviZnak = \\'I\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'J\\') { *st = 0; *noviZnak = \\'J\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'T\\') { *st = 0; *noviZnak = \\'T\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'A\\') { *st = 0; *noviZnak = \\'A\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'K\\') { *st = 1; *noviZnak = \\'1\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'P\\') { *st = 2; *noviZnak = \\'2\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'B\\') { *st = 16; *noviZnak = \\'?\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'C\\') { *st = 3; *noviZnak = \\'Y\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 0 && zn == \\'D\\') { *st = 4; *noviZnak = \\'Y\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'O\\') { *st = 1; *noviZnak = \\'O\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'R\\') { *st = 1; *noviZnak = \\'R\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'N\\') { *st = 1; *noviZnak = \\'N\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'E\\') { *st = 1; *noviZnak = \\'E\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'L\\') { *st = 1; *noviZnak = \\'L\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'I\\') { *st = 1; *noviZnak = \\'I\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'J\\') { *st = 1; *noviZnak = \\'J\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'T\\') { *st = 1; *noviZnak = \\'T\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'A\\') { *st = 1; *noviZnak = \\'A\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'C\\') { *st = 1; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'D\\') { *st = 1; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'K\\') { *st = 1; *noviZnak = \\'K\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'P\\') { *st = 1; *noviZnak = \\'P\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 1 && zn == \\'B\\') { *st = 5; *noviZnak = \\'C\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 2 && zn == \\'O\\') { *st = 2; *noviZnak = \\'O\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'R\\') { *st = 2; *noviZnak = \\'R\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'N\\') { *st = 2; *noviZnak = \\'N\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'E\\') { *st = 2; *noviZnak = \\'E\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'L\\') { *st = 2; *noviZnak = \\'L\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'I\\') { *st = 2; *noviZnak = \\'I\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'J\\') { *st = 2; *noviZnak = \\'J\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'T\\') { *st = 2; *noviZnak = \\'T\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'A\\') { *st = 2; *noviZnak = \\'A\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'C\\') { *st = 2; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'D\\') { *st = 2; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'K\\') { *st = 2; *noviZnak = \\'K\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'P\\') { *st = 2; *noviZnak = \\'P\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 2 && zn == \\'B\\') { *st = 5; *noviZnak = \\'D\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'O\\') { *st = 5; *noviZnak = \\'O\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'R\\') { *st = 5; *noviZnak = \\'R\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'N\\') { *st = 5; *noviZnak = \\'N\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'E\\') { *st = 5; *noviZnak = \\'E\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'L\\') { *st = 5; *noviZnak = \\'L\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'I\\') { *st = 5; *noviZnak = \\'I\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'J\\') { *st = 5; *noviZnak = \\'J\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'T\\') { *st = 5; *noviZnak = \\'T\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'A\\') { *st = 5; *noviZnak = \\'A\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'K\\') { *st = 5; *noviZnak = \\'K\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'P\\') { *st = 5; *noviZnak = \\'P\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'C\\') { *st = 5; *noviZnak = \\'C\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'D\\') { *st = 5; *noviZnak = \\'D\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 5 && zn == \\'1\\') { *st = 0; *noviZnak = \\'K\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 5 && zn == \\'2\\') { *st = 0; *noviZnak = \\'P\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 3 && zn == \\'C\\') { *st = 3; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 3 && zn == \\'D\\') { *st = 3; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 3 && zn == \\'B\\') { *st = 6; *noviZnak = \\'C\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 4 && zn == \\'C\\') { *st = 4; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 4 && zn == \\'D\\') { *st = 4; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 4 && zn == \\'B\\') { *st = 6; *noviZnak = \\'D\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 6 && zn == \\'C\\') { *st = 6; *noviZnak = \\'C\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 6 && zn == \\'D\\') { *st = 6; *noviZnak = \\'D\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 6 && zn == \\'W\\') { *st = 6; *noviZnak = \\'W\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 6 && zn == \\'Y\\') { *st = 7; *noviZnak = \\'Y\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 7 && zn == \\'C\\') { *st = 7; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 7 && zn == \\'D\\') { *st = 8; *noviZnak = \\'W\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 7 && zn == \\'W\\') { *st = 7; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 7 && zn == \\'B\\') { *st = 12; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 8 && zn == \\'C\\') { *st = 8; *noviZnak = \\'C\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 8 && zn == \\'D\\') { *st = 8; *noviZnak = \\'D\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 8 && zn == \\'W\\') { *st = 8; *noviZnak = \\'W\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 8 && zn == \\'Y\\') { *st = 9; *noviZnak = \\'Y\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 9 && zn == \\'D\\') { *st = 9; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 9 && zn == \\'W\\') { *st = 9; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 9 && zn == \\'C\\') { *st = 10; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 9 && zn == \\'B\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 10 && zn == \\'D\\') { *st = 10; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 10 && zn == \\'W\\') { *st = 10; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 10 && zn == \\'C\\') { *st = 11; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 10 && zn == \\'B\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 11 && zn == \\'D\\') { *st = 11; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 11 && zn == \\'W\\') { *st = 11; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 11 && zn == \\'C\\') { *st = 6; *noviZnak = \\'W\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 11 && zn == \\'B\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 12 && zn == \\'C\\') { *st = 12; *noviZnak = \\'C\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 12 && zn == \\'W\\') { *st = 12; *noviZnak = \\'W\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 12 && zn == \\'Y\\') { *st = 13; *noviZnak = \\'Y\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 13 && zn == \\'D\\') { *st = 13; *noviZnak = \\'D\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 13 && zn == \\'W\\') { *st = 13; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 13 && zn == \\'C\\') { *st = 14; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 13 && zn == \\'B\\') { *st = 17; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 14 && zn == \\'C\\') { *st = 14; *noviZnak = \\'C\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 14 && zn == \\'W\\') { *st = 14; *noviZnak = \\'W\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 14 && zn == \\'B\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 15 && zn == \\'C\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 15 && zn == \\'D\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 15 && zn == \\'W\\') { *st = 15; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 15 && zn == \\'Y\\') { *st = 16; *noviZnak = \\'?\\'; *smjer = \\'R\\'; return 1; }
	if (*st == 17 && zn == \\'W\\') { *st = 17; *noviZnak = \\'B\\'; *smjer = \\'L\\'; return 1; }
	if (*st == 17 && zn == \\'Y\\') { *st = 18; *noviZnak = \\'!\\'; *smjer = \\'R\\'; return 1; }
	return 0;
}