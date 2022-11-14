#include <stdio.h>

typedef struct{
	int sifra;
	char ime[30+1];
	char prezime[50+1];
	float brbod;
}zapis;

float zbrojiBodove(int brzad, float polje){
	int i;
	float suma=0.f
	for(i=0; i<brzad; ++i)
		suma+=polje[i];
	if(suma>=30)
		return suma;
	else
		return 0;
}
	
int main (void){
	FILE *ul, *il;
	zapis z1;
	float polje[6]={0.}, sumaprije, sumaposlije;
	int sifra;
	ul=fopen("studentiProg.bin", "r+b");
	il=fopen("ispitniRok_Uvidi.txt", "r");
	while(fscanf(il, "%d %f %f %f %f %f %f", &sifra, &polje[0], &polje[1], &polje[2], &polje[3], &polje[4], &polje[5])==7){
		suma=zbrojiBodove(6, polje);
		fseek(ul, (long)sizeof(z1)*(sifra-1), SEEK_SET);
		fread(&z1, sizeof(z1), 1, ul);
		if(z1.brbod!=suma){
			z1.brbod=suma;
			fseek(ul, (long)sizeof(z1)*(-1), SEEK_CUR);
			fwrite(&z1, sizeof(z1), 1, ul);
		}
	}
	fclose(ul);
	fclose(il);
}