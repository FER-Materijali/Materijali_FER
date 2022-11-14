typedef struct {
	int brracuna;
	char oib[11+1];
	double stanjeracuna;
	double minus;
}zapis;

void azurirajsaldo(FILE *saldo, int brojracuna, double iznos){
	FILE *ul;
	char c;
	int godina, ostalo, bruplat, brprim;
	float iznos;
	zapis z1;
	ul=fopen("prijenosi.txt", "r");
	while(fscanf(saldo, "%d%c%d%c%d%c%d%c%d%c%d%c%d%c%f", &ostalo, &c, &ostalo, &c, &godina
	&c, &ostalo, &c, &ostalo, &c, &bruplat, &c, &brprim, &c, &iznos)==15){
		if(godina==2015 || godina==2014){
			fseek(saldo, (long)sizeof(z1)*brprim, SEEK_SET);
			fread(&z1, sizeof(z1), 1, ul);
			z1.stanjeracuna+=iznos;
			fseek(saldo, (long)sizeof(z1)*(-1), SEEK_CUR);
			fwrite(&z1, sizeof(z1), 1, ul);
		}
	}
	fclose(ul);
}