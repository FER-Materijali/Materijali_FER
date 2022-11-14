#define MAXRED 200
#define MAXSTUP 400

void generiraj_zrna(int *polje, int n){
	int i;
	srand((unsigned)time(NULL));
	for(i=0; i<n; ++i)
		polje[i]=rand();
}

void puni2d(int *zrna, int *polje, int m, int n){
	int i, j;
	for(j=0; j<n; ++j){
		srand((unsigned)*(zrna+j));
		for(i=0 i<m; ++i){
			*(polje+i*MAXSTUP+j)=rand();
		}
	}
}

int main (void){
	int zrna[MAXSTUP];
	int polje[MAXRED][MAXSTUP], m, n;
	scanf("%d %d", &m, &n);
	generiraj_zrna(zrna, n);
	puni2d(polje, m, n);
	for(i=0; i<m; ++i){
		printf("%3d. broj: ", i+1);
		for(j=0; j<n; ++j){
			printf("%10d ", polje[i][j]);
		}
		printf("\n");
	}
	return 0;
}