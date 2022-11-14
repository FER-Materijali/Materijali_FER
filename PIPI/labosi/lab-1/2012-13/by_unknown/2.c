#include <stdio.h>
#define MAX 20
int main() {
	int x, i, j; float polje[MAX+1][MAX+1]={0};
	printf("Ucitati cijeli broj x:\n");
	scanf("%d", &x);
	printf("Ucitani broj = %d \n", x);
	printf("\n");
	if(x<5 || x>20)
		printf("Neispravan broj\n");
	else {
		for(i=0; i<=x; i++){
			printf("%d. red:", i);
			for(j=0; j<=i; j++){
				polje[i][j]=j/10.;
				printf(" %.1f ", polje[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}