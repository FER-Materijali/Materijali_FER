#include <stdio.h>
#define MAX 100

int main (void){
	int i, j, m, n, suma, polje[MAX][MAX], max;
	printf("upisi m, n: ");
	scanf("%d %d", &m, &n);
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
			scanf("%d", &polje[i][j]);
	for(j=1; j<n; ++j){
		suma=polje[0][j-1];
		max=polje[0][j];
		for(i=1; i<m; ++i){
			suma+=polje[i][j-1];
			if(max<polje[i][j])
				max=polje[i][j];
		}
		if(suma==max)
			printf("indeks: %d\n", j);
	}
	return 0;
}