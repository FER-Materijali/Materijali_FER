#define MAX 100

void generirajSifru(int brslova, int brznamenki, char *sifra){
	int i, j;
	for(i=0; i<brslova; ++i)
		sifra[i]=rand()%('Z'-'A')+'A';
	for(j=i; j<brznamenki+i; ++j)
		sifra[j]=rand()%('9'-'0')+'0';
}

int main (void){
	int n, i;
	char sifra[MAX];
	srand((unsigned)time(NULL);
	scanf("%d", &n);
	for(i=0; i<=n; ++i){
		generirajSifru(i, n-i, sifra);
		printf("%s", sifra);
	}
	return 0;
}