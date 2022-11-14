#include <stdio.h>

typedef struct{
	short sifra;
	int datum;
	int vrijeme;
	char vrata;
}zapis;

typedef struct{
	short sifra;
	char jmbag[10+1];
	char imeprez[100+1];
}zapis1;

int brminuta(char *jmbag, int dan){
	int i, j, minuta, ulaz=1;
	FILE *ul, *il;
	zapis1 z1;
	zapis z2;
	ul=fopen("prolasci.dat", "rb");
	il=fopen("zaposlenici.dat", "rb");
	while(fread(&z1, sizeof(z1), 1, il)!=EOF){
		if(strcmp(z1.jmbag, jmbag)==0)
			break;
	}
	fclose(il);
	fseek(ul, (long)sizeof(z2)*z1.sifra, SEEK_SET);
	while(fread(&z2, sizeof(z2), 1, ul)!=EOF){
		if(z2.datum==dan){
			if(ulaz==1){
				minuta=z2.vrijeme;
				ulaz=0;
			}
			else{
				brojsek+=(z2.vrijeme-minuta);
				ulaz=1;
			}
		}
	}
	fclose(ul);
	return brsek%60;
}