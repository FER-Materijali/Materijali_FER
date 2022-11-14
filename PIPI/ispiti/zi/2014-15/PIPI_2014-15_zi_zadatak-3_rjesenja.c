#include <stdio.h>

typedef struct{
	int sifra;
	char naziv[20+1];
	int brmjer;
}zapis;

int main (void){
	FILE *ul, *il;
	int dan, mjesec, godina, sifra;
	float temp;
	ul=fopen("mMjesta.bin", "r+b");
	il=fopen("mjerenja.txt", "r");
	while(fscanf(il, "%d%c%2d%2d%4d%c%f", &sifra, &znak, &dan, &mjesec, &godina, &znak, &temp)==7){
		if(godina==2014){
			fseek(ul, (long)sizeof(z1)*(sifra-1), SEEK_SET);
			fread(&z1, sizeof(z1), 1, ul);
			++z1.brmjer;
			fseek(ul, (long)sizeof(z1)*(-1), SEEK_CUR);
			fwrite(z1, sizeof(z1), 1, ul);
		}
	}
	fclose(ul);
	fclose(il);
	return 0;
}