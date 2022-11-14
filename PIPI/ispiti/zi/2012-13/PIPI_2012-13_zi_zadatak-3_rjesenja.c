#include <stdio.h>

typedef struct{
	int sifra;
	char ime[20+1];
	char prezime[30+1];
	int brojmin;
}zapis;

int main (void){
	FILE *ul, *il;
	zapis z1;
	int sifra, sati1, minute1, sati2, minute2, suma;
	char znak;
	ul=fopen("sati.bin", "r+b");
	il=fopen("dnevnik.txt", "r");
	while(fscanf(il, "%5d %2d:%2d %2d:%2d", &sifra, 
	&sati1, &minute1, &sati2, &minute2)==5){
		suma=(sati1*60+minute1)-(sati2*60-minute2);
		fseek(ul, (long)sizeof(z1)*(sifra-1), SEEK_SET);
		fread(&z1, sizeof(z1), 1, ul);
		z1.brojmin+=suma;
		fseek(ul, (long) sizeof(z1)*(-1), SEEK_CUR);
		fwrite(z1, sizeof(z1), 1, ul);
	}
	fclose(ul);
	fclose(il);
	return 0;
}