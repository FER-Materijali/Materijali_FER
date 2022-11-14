#define MAX 10
#define MAXSTUP 20

int pobjednik(int *polje, int maxsutp, int m, int n, int *k){
	int i, j, suma, max=0;
	for(j=0; j<n; ++j){
		suma=0;
		for(i=0; i<m; ++i){
			suma+=*(polje+i*maxstup+j);
		}
		if(suma>max){
			max=suma;
			k=j;
		}
	}
	return max;
}

int main (void){
	int polje[MAX][MAXSTUP], max, suma=0, i, j=0, m, n, k;
	scanf("%d %d", &m, &n);
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j){
			scanf("%d", &polje[i][j]);
		}
	}
	i=0;
	max=pobjednik(polje, MAXSTUP, m, n, &k);
	printf("%d. pobjednik sa %d bodova\n", k, max);
	return 0;
}