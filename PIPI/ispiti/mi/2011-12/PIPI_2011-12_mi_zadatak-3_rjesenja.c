#include <stdio.h>
#define MAX 15

int main (void){
	int m, i, j;
	float mat[MAX][MAX], max;
	printf("unesi podatke: ");
	scanf("%d", &m);
	for(i=0; i<m; ++i){
		for(j=0; j<m; ++j){
			scanf("%f", &mat[i][j]);
			if(i==0 && j==0)
				max=mat[i][j];
			else if((i+j)<(m-1) && mat[i][j]>max)
				max=mat[i][j];
		}
	}
	for(i=0; i<m; ++i)
		for(j=0; j<m; ++j)
			if(mat[i][j]>max)
				mat[i][j]=0.f;
	for(i=0; i<m; ++i){
		for(j=0; j<m; ++j)
			printf("   %7.2f", mat[i][j]);
		printf("\n");
	}
	return 0;
}