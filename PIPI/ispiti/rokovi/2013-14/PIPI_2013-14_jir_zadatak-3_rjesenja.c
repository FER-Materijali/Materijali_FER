typedef struct {
	int sifra;
	char jmbag[10+1];
	char ime[30+1];
	char prezime[40+1];
}zapis;

void funkcija(char *dat1, char *dat2){
	FILE *ul, *il1, *il2;
	srand((unsigned)time(NULL));
	int i;
	zapis z1;
	ul=fopen("ispitPIPI.dat", "rb");
	il1=fopen(dat1, "w");
	il2=fopen(dat2, "w");
	fprintf(il1, "JMBAG    |  Prezime, Ime\n ----------|----------\n");
	fprintf(il2, "JMBAG    |  Prezime, Ime\n ----------|----------\n");
	while(fread(&z1, sizeof(z1), 1, ul)!=EOF){
		i=rand();
		if(i%2==0){
			fprintf(il1, "%s| %s, %s\n", z1.jmbag, z1.prezime, z1.ime);
		}
		else
			fprintf(il2, "%s| %s, %s\n", z1.jmbag, z1.prezime, z1.ime);
	}
	fclose(ul);
	fclose(il1);
	fclose(il2);
}