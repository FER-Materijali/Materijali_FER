#include <stdio.h>

typedef struct{
	int sifra, ocjena;
	char ime[30+1];
	char prezime[50+1];
}zapis;
	
int main (void){
	FILE *ul, *il;
	zapis z1;
	int sifra, ocjena;
	float zad[5]={0.};
	ul=fopen("studentiProg.bin", "r+b");
	il=fopen("ispitniRok1.txt", "r");
	while(fscanf(il, "%d %f %f %f %f %f", &sifra, &zad[0], &zad[1], &zad[2], &zad[3], &zad[4])==6){
		ocjena=izracunajOcjenu(5, zad);
		if(ocjena>1){
			fseek(ul, (long)sizeof(z1)*(sifra-1), SEEK_SET);
			fread(&z1, sizeof(z1), 1, ul);
			z1.ocjena=ocjena;
			fseek(ul, (long)sizeof(z1)*(-1), SEEK_CUR);
			fwrite(&z1, sizeof(z1), 1, ul);
		}
	}
	fclose(ul);
	fclose(il);
	return 0;
}