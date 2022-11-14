typedef struct {
	char datum [10+1];
	char jmbag[10+1];
	int sifra;
	int ocjena;
}zapis;

typedef struct{
	int sifrapredmeta;
	char naziv[95+1];
}bin;

void(char *predmet, char *datum){
	FILE *ul, *il;
	int ocjene[6]={0};
	zapis z1;
	bin b1;
	ul=fopen("ocjene.txt", "r");
	il=fopen("predmeti.bin", "rb");
	while(fread(&b1, sizeof(b1), 1, il)!=EOF){
		if(strcmp(b1.naziv, predmet)==0)
			break;
	}
	while(fscanf(ul, "%s %s %d %d", &z1.datum, &z1.jmbag, &z1.sifra, &z1.ocjena)==4){
		if(strcmp(z1.datum, datum)==0 && z1.sifra==b1.sifrapredmeta){
			ocjene[z1.ocjena]++;
			ocjene[0]++;
		}
	}
	printf("broj ocjenjenih: %d\n izvrstan: %d\n vrlo dobar: %d\n,
			dobar: %d\n dovoljan: %d\n nedovoljan: %d\n", ocjene[0], ocjene[5], 
			ocjene[4], ocjene[3], ocjene[2], ocjene[1]);
	fclose(ul);
	fclose(il);
}