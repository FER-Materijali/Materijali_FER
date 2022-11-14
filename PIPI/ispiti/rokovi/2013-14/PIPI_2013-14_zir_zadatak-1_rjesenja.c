#include <stdio.h>

typedef struct {
	int sifra;
	char naziv[51];
	float cijena;
	int kolicina;
	int kategorija;
}zapis;

int main (void){
	FILE *ul, *il;
	zapis z1;
	int zbroj, sifra1, sifra2;
	float ukupno, max=0, sumamali=0, sumaveliki=0, max2=0;
	char niz[
	ul=fopen("skladiste.bin", "r+b");
	il=fopen("report.txt", "w");
	while(fread(&z1, sizeof(z1), 1, ul)!=EOF){
		if(z1.kategorija==0){
			sumamali+=z1.cijena*z1.kolicina;
			if(max<=z1.cijena){
				max=z1.cijena;
				sifra1=z1.sifra;
			}
		}
		else{
			sumaveliki+=z1.cijena*z1.kolicina;
			if(max2<=z1.cijena){
				max2=z1.cijena;
				sifra2=z1.sifra;
			}
		}
	}
	fprintf(il, "# | Kategorija                | Vrijednost\n");
	fprintf(il, "0 | Mali predmeti       | %11.3f |\n", sumamali);
	fprintf(il, "0 | Veliki predmeti       | %11.3f |\n", sumaveliki);
	fclose(il);
	fseek(ul, (long) sizeof(z1)*(sifra-1), SEEK_SET);
	fread(&z1, sizeof(z1), 1, ul);
	z1.cijena*=0.9;
	fseek(ul, (long) sizeof(z1)*(-1), SEEK_CUR);
	fwrite(z1, sizeof(z1), 1, ul);
	fseek(ul, (long) sizeof(z1)*(sifra-1), SEEK_SET);
	fread(&z1, sizeof(z1), 1, ul);
	z1.cijena*=0.9;
	fseek(ul, (long) sizeof(z1)*(-1), SEEK_CUR);
	fwrite(z1, sizeof(z1), 1, ul);
	fclose(ul);
	return 0;
}