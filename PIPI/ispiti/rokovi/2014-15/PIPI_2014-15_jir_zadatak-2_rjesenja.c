#define MAX 10

float prosjek(int *polje, int m, int n, int maxstup, int broj){
	int i, j;
	float prosjek, suma=0;
	if(broj==-1){
		for(i=0; i<m; i++){
			for(j=0; j<n; ++j){
				suma+=*(polje+i*maxstup+j);
			}
		}
		prosjek=suma/(i*j);
	return prosjek;
	}
	else{
		for(i=0; i<m; ++i){
			suma+=*(polje+i*maxstup+broj);
		}
		prosjek=suma/i;
		return prosjek;
	}
}

int main (void){
	int m, n, polje[MAX][MAX];
	float ukprosjek, obprosjek;
	do{
		scanf("%d %d", &m, &n);
	}while(m<1 || m>10 || n<3 || n>10);
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
			scanf("%d", &polje[i][j]);
	ukprosjek=prosjek(polje, m, n, MAX, -1);
	for(j=0; j<n; ++j){
		obprosjek=prosjek(polje, m, n, MAX, j);
		if(obprosjek>ukprosjek)
			printf("%d. obracunsko razdoblje s prosjekom %.2f kWh iznad ukupnog prosjeka od %.2f kWh", j+1, obprosjek, ukprosjek);
	}
	return 0;
}