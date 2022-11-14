typedef struct {
	int sifra;
	int brkoseva;
}zapis;

int main (void){
	FILE *ul, *il;
	int broj, brigraca, repka, kosevi, max=0;
	char c;
	zapis z1;
	ul=fopen("zapisnik.txt", "r");
	il=fopen("statistika.dat", "w+b");
	while(fscanf(ul, "%d%c%d%c%d%c%d", &broj, &c, &brigraca, &c, &kosevi, &c, &repka)==7){
		fseek(il, (long)sizeof(z1)*(repka-100000), SEEK_SET);
		fread(&z1, sizeof(z1), 1, il);
		z1.brkoseva+=kosevi;
		fseek(il, (long)sizeof(z1)*(-1), SEEK_CUR);
		fwrite(z1, sizeof(z1), 1, il);
	}
	fclose(ul);
	fseek(il, 0L, SEEK_SET);
	while(fread(&z1, sizeof(z1), 1, il){
		if(z1.brkoseva>max)
			max=z1.brkoseva;
	}
	fseek(il, 0L, SEEK_SET);
	while(fread(&z1, sizeof(z1), 1, il){
		if(z1.brkoseva==max)
			printf("[%d] Broj koseva: %d\n", z1.sifra+100000, z1.brkoseva);
	}
	fclose(il);
	return 0;
}