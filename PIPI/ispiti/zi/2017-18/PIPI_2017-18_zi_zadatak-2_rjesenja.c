#include <stdio.h>
#include <time.h>

void gen(int *polje, int *red, int *stup, int maxstup){
	int i, j;
	*red=rand()%5+1;
	*stup=rand()%10+1;
	for(i=0; i<*red; ++i)
		for(j=0; j<*stup; ++j)
			*(polje+i*maxstup+j)=rand()%10;
}

int main (void){
	int polje[50][50], i, j, k, red, stup;
	srand((unsigned)time(NULL));
	for(k=0; k<10; ++k){
		gen(polje, &red, &stup, 50);
		printf("%d. matrica\n", k+1);
		for(i=0; i<red; ++i){
			for(j=0; j<stup; ++j)
				printf("%d ", polje[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}