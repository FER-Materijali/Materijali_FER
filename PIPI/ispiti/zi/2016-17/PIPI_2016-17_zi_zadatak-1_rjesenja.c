#include <stdio.h>

typedef struct{
	int sifra;
	char prezime[20+1];
	float koef;
}zapis;

int main (void){
	FILE *ul;
	zapis z1;
	int brojac=0, sifra;
	float suma=0.f;
	char prezime[20+1];
	ul=fopen("osoba.bin", "r+b");
	fread(z1, sizeof(z1), 1, ul);
	prezime=z1.prezime;
	while(fread(&z1, sizeof(z1), 1, ul)!=EOF){
		if(strcmp(z1.prezime, prezime)==0)
			sifra=z1.sifra;
		suma+=z1.koef;
		++brojac;
	}
	if(brojac==0)
		printf("nema zapisa");
	else{
		suma/=brojac;
		fseek(ul, (long)(sizeof(z1)*(sifra-1), SEEK_SET);
		fread(&z1, sizeof(z1), 1, ul)
		z1.koef=suma;
		fseek(ul, (long)(sizeof(z1)*(-1), SEEK_CUR);
		fwrite(z1, sizeof(z1), 1, ul);
		printf("postavljen rbr. %d\n", z1.sifra);
	}
	fclose(ul);
	return 0;
}