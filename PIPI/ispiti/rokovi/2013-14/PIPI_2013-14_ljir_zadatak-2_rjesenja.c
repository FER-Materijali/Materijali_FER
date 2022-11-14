#define MAX 100

int funkcija(int *polje, int n, int maxstup){
	int i, j, polje2[MAX/2][MAX/2];
	for(i=0; i<n/2; ++i){
		for(j=0; j<n/2; ++j){
			suma=*(polje+2*i*maxstup+j*2)+*(polje+2*i*maxstup+2*j+1)+
					*(polje+(i*2+1)*maxstup+j*2)+*(polje+(2*i+1)*maxstup+j*2+1);
			suma/=4;
			polje2[i][j]=suma;
		}
	}
	return polje2;
}

int main (void){
	int i, j, m, n, polje[MAX][MAX];
	do{
		scanf("%d", &n);
	}while(n%2!=0);
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			scanf("%d", &polje[i][j]);
	polje2=funkcija(polje, n, MAX);
	for(i=0; i<n/2; ++i)
		for(j=0; j<n/2; ++j)
			printf("%d", polje2[i][j]);
	return 0;
}