typedef struct {
	int broj;
	int uv;
	char niz[20+1];
}zapis;

int main (void){
	FILE *ul;
	float suma=0;
	int brojac=0;
	zapis z1;
	ul=fopen("uv_indeks.dat", "r+b");
	while(fread(&z1, sizeof(z1), 1, ul)!=EOF){
		suma+=z1.uv;
		++brojac;
	}
	suma/=brojac;
	fseek(ul, 0L, SEEK_SET);
	while(fread(&z1, sizeof(z1), 1, ul)!=EOF){
		if(z1.uv>suma){
			fseek(ul, (long)sizeof(z1)*(-1), SEEK_CUR);
			z1.niz="visoka";
			fwrite(&z1, sizeof(z1), 1, ul);
		}
		else{
			fseek(ul, (long)sizeof(z1)*(-1), SEEK_CUR);
			z1.niz="niska";
			fwrite(&z1, sizeof(z1), 1, ul);
		}
	}
	fclose(ul);
	return 0;
}