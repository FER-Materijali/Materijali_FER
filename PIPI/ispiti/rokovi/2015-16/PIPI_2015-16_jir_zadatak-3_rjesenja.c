void generiraj(char *ulaz, char *rezultat){
	int duljina, i;
	duljina=strlen(ulaz);
	for(i=0; i<duljina; ++i){
		rezultat[i]=niz[rand()%duljina];
	}
	rezultat[i]='\0';
}

int main (void){
	srand((unsigned)time(NULL));
	int i;
	char niz, rezultat[MAX];
	gets(niz);
	for(i=0; i<5; ++i){
		generiraj(niz, rezultat);
		puts(rezultat);
	}
	return 0;
}