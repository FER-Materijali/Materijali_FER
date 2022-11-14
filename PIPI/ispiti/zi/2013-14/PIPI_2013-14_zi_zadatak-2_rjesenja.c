#include <stdio.h>

typedef struct{
	int sifra;
	char naziv[50+1];
	int za;
	int protiv;
	int nevazeci;
}zapis;

int main (void){
	FILE *ul, *il;
	zapis z1;
	char vrijeme[5+1], znak;
	int sifra;
	int vrijednost;
	ul=fopen("C:/europa/referendum.txt", "r");
	il=fopen("C:/statistika/rezGlMjesto.bin", "r+b");
	while(fscanf(ul, "%5s%c%d%c%d", &vrijeme, &znak, &sifra, &znak, &vrijednost)==5){
		fseek(il, (long)sizeof(z1)*(sifra-1), SEEK_SET);
		fread(&z1, sizeof(z1), 1, il);
		if(vrijednost==0)
			++z1.protiv;
		else if(vrijednost==1)
			++z1.za;
		else
			++z1.nevazeci;
		fseek(il, (long)sizeof(z1)*(-1), SEEK_CUR);
		fwrite(z1, sizeof(z1), 1, il);
	}
	fclose(ul);
	fclose(il);
	return 0;
}