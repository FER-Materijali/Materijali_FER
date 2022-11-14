#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen(int *polje, int m, int n, int stup){
	int broj, i, j;
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j){
			broj=rand()%2;
			*(polje+i*stup+j)=broj;
		}
	}
}

int main (void){
	int polje[50][100], i, j, k;
	srand((unsigned)time(NULL));
	for(k=0; k<10; ++k){
		gen(polje, 3, 5, 100);
		for(i=0; i<3; ++i){
			for(j=0; j<5; ++j)
				printf("%d ", polje[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}