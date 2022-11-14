#include <stdio.h>
#define DAT1 "artikl.dat"
#define DAT2 "narudzba.txt"
#define MODE1 "rb"
#define MODE2 "r"
#define MAXDIM 50

int main(){

	struct artikli{
	
		int sifra;
		double cijena;
		char naziv[MAXDIM + 1];
	
	}artikl;

	int sifra;
	double minCijena;
	char naziv[MAXDIM + 1];
	
	FILE *tok1 = fopen(DAT1, MODE1);
	FILE *tok2 = fopen(DAT2, MODE2);
	
	fscanf(tok2, "%d", &sifra);
	
	fseek(tok1, (long)sizeof(artikl)*(sifra-1), SEEK_SET);
	fread(&artikl, sizeof(artikl), 1, tok1);
	
	minCijena = artikl.cijena;
	strcpy(naziv, artikl.naziv);
	
	while(fscanf(tok2, "%d", &sifra) == 1){
	
		fseek(tok1, (long)sizeof(artikl)*(sifra-1), SEEK_SET);
		fread(&artikl, sizeof(artikl), 1, tok1);
		
		if(artikl.cijena < minCijena){
			minCijena = artikl.cijena;
			strcpy(naziv, artikl.naziv);
		}
	
	}
	
	printf("Najjeftiniji artikl u datoteci jest: %s", naziv);
	
	fclose(tok1);
	fclose(tok2);
	
	return 0;
}