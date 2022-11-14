#include <stdio.h>
#define MAX 20
int main() {
	int x, i, j; char polje[MAX+1][MAX+1]={0};
	printf("Ucitati cijeli broj x:\n");
	scanf("%d", &x);
	printf("Ucitani broj = %d \n", x);
	printf("\n");
	if(x<5 || x>20)
		printf("Neispravan broj\n");
	else {
		for(i=0; i<=x; i++){
			printf("%d. red:", i);
			for(j=0; j<=x; j++){
				if(i==j){
				polje[i][j]=j;
				printf(" %d ", polje[i][j]);
				}
				else{
					polje[i][j]='-';
					printf(" %c ", polje[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}