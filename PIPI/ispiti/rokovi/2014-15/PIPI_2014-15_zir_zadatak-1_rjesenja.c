int fudaljenost(int *polje, int *polje2, int maxstup, int k){
	int i, j, l, udaljenost=0;
	for(i=0; i<k-1; ++i){
		j=polje2[i];
		l=polje2[i+1];
		udaljenost+=*(polje+j*maxstup+l);
		if(*(polje+j*maxstup+l)==0)
			return 0;
	}
	return udaljenost;
}

int main (void){
	int m, n, polje[MAX][MAX], polje2[MAX], brojgradova, udaljenost;
	scanf("%d %d %d", &m, &n, &brojgradova);
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
			scanf("%d", &polje[i][j]);
	for(i=0; i<brojgradova; ++i)
		scanf("%d", &polje2[i]);
	udaljenost=fudaljenost(polje, polje2, MAX, brojgradova);
	if(udaljenost==0)
		printf("zadani gradovi se nemogu posjetiti");
	else
		printf("%d", udaljenost);
	return 0;
}