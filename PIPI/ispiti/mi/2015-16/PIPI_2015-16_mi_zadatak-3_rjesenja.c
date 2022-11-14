#include <stdio.h>
#define MAX 8

int main (void){
	char polje[MAX][MAX];
	int i, j, a, b;
	scanf("%d %d", &a, &b);
	for(i=0; i<MAX; ++i)
		for(j=0; j<MAX; ++j)
			polje[i][j]='K';
	i=a;
	for(j=0; j<MAX; ++j)
		polje[i][j]='-';
	j=b;
	for(i=0; i<MAX; ++i)
		polje[i][j]='-';
	polje[a][b]='T';
	for(i=0; i<MAX; ++i){
		for(j=0; j<MAX; ++j)
			printf("%c ", polje[i][j]);
		printf("\n");
	}
	return 0;
}