#include <stdio.h>

typedef struct{
	short int rbr;
	char ime[50+1];
	int zbroj;
}zapis;

int main (void){
	FILE *ul, *il;
	short int rbr;
	char znak;
	int brnovih;
	zapis z1;
	ul=fopen("zivotinjsko_carstvo.bin", "r+b");
	il=fopen("nove_slicice.txt", "r");
	while(fscanf(il, "%3hd%c%2hd", &rbr, &znak, &brnovih)==3){
		fseek(ul, (long)(rbr-1)*sizeof(zapis), SEEK_SET);
		fread(&z1, sizeof(zapis), 1, ul);
		z1.zbroj+=brnovih;
		fseek(ul, (long)(-1)*sizeof(z1), SEEK_CUR);
		fwrite(&zapis, sizeof(zapis), 1, ul);
	}
	fclose(ul);
	fclose(il);
	return 0;
}