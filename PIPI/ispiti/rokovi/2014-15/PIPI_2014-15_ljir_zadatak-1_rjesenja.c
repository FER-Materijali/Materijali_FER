void sastavi popis(char *dat_osobe, char *dat_popis, int kapacitet_klinike){
	FILE *ul, *il;
	struct osoba z1;
	int treba;
	ul=fopen("dat_osoba", "rb");
	il=fopen("dat_popis", "w");
	while(fread(&z1, sizeof(z1), 1, ul)!=EOF){
		treba=treba_na_pregled(z1.mat_br_osigurane_osobe);
		if(brojac<kapacitet_klinike){
			if(treba==1){
				if(z1.osigurana==1){
					matbr=z1.max_br_osigurane_osobe;
					fprintf(il, "%s\n", z1.oib);
					++brojac;
				}
			}
		}
	}
	fclose(ul);
	fclose(il);
	return 0;
}