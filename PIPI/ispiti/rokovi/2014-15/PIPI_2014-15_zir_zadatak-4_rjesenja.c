typedef struct {
	int sifra;
	float bodovi[4];
	float ukupni;
}zapis;

int main (void){
	FILE *ul, *il;
	zapis z1;
	float suma=0;
	int brojac=0;
	char c;
	ul=fopen("rezultati.txt", "r");
	il=fopen("ukupno.dat", "w+b");
	while(fscanf(ul, "%d%c%f%c%f%c%f%c%f", &z1.sifra, &c, &z1.bodovi[0], &c, &z1.bodovi[1], &c, &z1.bodovi[2], &c, &z1.bodovi[3])==9){
		z1.ukupni=bodovi[0]+bodovi[1]+bodovi[2]+bodovi[3];
		suma+=z1.ukupni;
		++brojac;
		fseek(il, (long)sizeof(z1)*(z1.sifra-100000), SEEK_SET);
		fwrite(z1, sizeof(z1), 1, il);
	}
	suma/=brojac;
	fseek(ul, 0L, SEEK_SET);
	while(fread(&z1, sizeof(z1), 1, il)!=EOF){
		if(z1.ukupni>suma)
			printf("%d#iznad\n", z1.sifra+100000);
		else
			printf("%d#ispod\n", z1.sifra+100000);
	}
	fclose(ul);
	fclose(il);
	return 0;
}