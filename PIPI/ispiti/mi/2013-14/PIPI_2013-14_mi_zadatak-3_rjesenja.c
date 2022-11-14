#include <stdio.h>
#define MAX 10

int main (void){
	float polje[MAX][MAX];
	int i, j, n;
	scanf("%d", &n);
	i=0;
	for(j=0; j<n; ++j)
		scanf("%f", &polje[i][j]);
	for(i=1; i<n; ++i){
		for(j=0; j<n-1; ++j){
			polje[i][j]=polje[i-1][j+1];
		}
		 polje[i][n-1]=polje[i-1][0];
	}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j)
			printf("%.2f  ", polje[i][j]);
		printf("\n");
	}
	return 0;
}