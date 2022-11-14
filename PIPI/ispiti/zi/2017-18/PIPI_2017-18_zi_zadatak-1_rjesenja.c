#include <stdio.h>

typedef struct{
	int sifra;
	char imeprez[40+1];
	float prosjocj;
}zapis;

int main (void){
	FILE *ul, *il;
	int sifra;
	float max=0;
	zapis z1;
	ul=fopen("osoba.bin", "rb");
	il=fopen("kandidat.txt", "r");
	while(fread(&z1, sizeof(z1), 1, ul)==1){
		if(z1.prosjocj>max)
			max=z1.prosjocj;
	}	
	while(fscanf(il, "%d", &sifra)==1){
		fseek(ul, (long)sizeof(z1)*(sifra-1), SEEK_SET);
		fread(&z1, sizeof(z1), 1, ul);
		if(z1.prosjocj==max)
			printf("%d %s\n", sifra, z1.imeprez);
	}
	fclose(ul);
	fclose(il);
	return 0;
}