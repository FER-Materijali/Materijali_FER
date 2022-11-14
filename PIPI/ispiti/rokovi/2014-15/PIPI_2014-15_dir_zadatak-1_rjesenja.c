typedef struct {
	int sifra;
	char imeprez[70+1];
}zapis;

void funkcija(int sifra, int god){
	FILE *ul, *il;
	int sifra1, sifra2, brset1, brset2, set, sifra3;
	char datum[10+1];
	zapis z1;
	ul=fopen("igraci.dat", "rb");
	il=fopen("rezultati.txt", "r");
	printf("protivnik     | Rezultat\n");
	printf("------------------\n");
	while(fscanf(il, "%d %d %d %d %d", &sifra1, &sifra2, &brset1, &brset2, &dan, &mjesec, &godina)==7){
		if(godina==god){
			if(sifra1==sifra){
				setprot=brset2;
				sifra3=sifra2;
				set=brset1;
			}
			else if(sifra2==sifra){
				setprot=brset1;
				sifra3=sifra1;
				set=brset2;
			}
			fseek(ul, (long)sizeof(z1)*(sifra3), SEEK_SET);
			fread(&z1, sizeof(z1), 1, ul);
			printf("%d %s | %d : %d ", sifra3, z1.imeprez, set, setprot);
		}
	}
	fclose(ul);
	fclose(il);