#include <stdio.h>
#define MAX 100
#define MAX2 200

int main (void){
	int polje[MAX][MAX2], m, n, min=0, i, j, red, suma;
	scanf("%d %d", &m, &n);
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
			scanf("%d", &polje[i][j]);
	for(j=0; j<n; ++j){
	    suma=0;
		for(i=0; i<m; ++i)
			suma+=polje[i][j];
		if (j == 0)
             min=suma; 
		if(min>suma){
			min=suma;
			red=j;
		}
	}
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j)
			printf("%d  ", polje[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0; i<m; ++i)
		printf("%d\n", polje[i][red]);
	return 0;
}