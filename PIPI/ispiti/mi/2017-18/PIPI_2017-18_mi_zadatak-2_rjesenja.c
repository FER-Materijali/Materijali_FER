#include <stdio.h>

int main (void){
	int m, n, max, polje[100+1][100+1], i, j, broj, ponovio, k;
	printf("upisi clanove m, n: ");
	scanf("%d %d", &m, &n);
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j){
			printf("upisi %d clan", j+1);
			scanf("%d", &polje[i][j]);
		}
	}
	for(i=0; i<m; ++i){
		max=polje[i][j];
		for(j=0; j<n; ++j){
			if(max<polje[i][j]){
				max=polje[i][j];
				broj=j;
				ponovio=0;
			}
		}
		for(k=broj+1; k<n; ++k){
			if(max==polje[i][k])
				ponovio=1;
		}
		for(k=broj-1; k>=0; --k){
			if(max==polje[i][k])
				ponovio=1;
		}
		if(ponovio==0)
			printf("(%d, %d): %d\n", i, broj, max);
	}
	return 0;
}