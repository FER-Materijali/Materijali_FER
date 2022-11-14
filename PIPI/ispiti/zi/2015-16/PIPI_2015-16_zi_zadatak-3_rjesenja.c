#include <stdio.h>

typedef struct{
	int sifra;
	char imeprez[20+1];
	float dohodak;
	float porez;
}zapis;

int main (void){
	FILE *ul, *il;
	zapis z1;
	int sifra, brojac, rbrzapisa;
	char indentifikator[17+1];
	float iznos, suma=0.f;
	ul=fopen("porezi.bin", "r+b");
	il=fopen("troskovi.txt", "r");
	while(fread(z1, sizeof(z1), 1, ul)!=EOF){
		++rbrzapis;
		if(rbrzapis==z1.sifra){
			suma+=z1.dohodak;
			++brojac;
		}
	}
	suma/=brojac;
	while(fscanf(il, "%d%s%f", &sifra, &indentifikator, &iznos)==3){
		fseek(ul, (long)sizeof(z1)*(sifra-1), SEEK_SET);
		fread(z1, sizeof(z1), 1, ul);
		if(z1.dohodak<suma){
			if(z1.porez-iznos>=0)
				z1.porez-=iznos;
			else
				z1.porez=0;
			fseek(ul, (long)sizeof(z1)*(-1), SEEK_CUR);
			fwrite(z1, sizeof(z1), 1, ul);
		}
	}
	fclose(il);
	fclose(ul);
	return 0;
}