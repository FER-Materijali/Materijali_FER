#include "source.h"
double odrediKof(){
	return (((float)M_predmet) / (P - 1));
}
int adresa_predmet(char sifra[]){
	int i, prod = 0, B = 11, j = 0, broj, zbroj = 0;
	for (i =0 ; i < strlen(sifra); ++i){
		zbroj += sifra[i];
	}
	do{
		broj = zbroj % 10;
		zbroj /= 10;
		prod += broj*pow(B, j);
		++j;
	} while (zbroj != 0);
	return ((int)(prod % 100)*odrediKof());

}

int upis_predmeti(predmet_zapis predmet, FILE *predmet_out){
	predmet_zapis pretinac[C_predmet];
	int i, j, poc;
	i = poc = adresa_predmet(predmet.sifra);
	do{
		fseek(predmet_out, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, predmet_out);
		for (j = 0; j < C_predmet; ++j){
			if (pretinac[j].sifra[0] == '\0'){
				pretinac[j] = predmet;
				fseek(predmet_out, i*BLOK, SEEK_SET);
				fwrite(pretinac, sizeof(pretinac), 1, predmet_out);
				return 1;
			}
		}
		i = (i + 1) % M_predmet;
	} while (i != poc);
	return 0;
}
