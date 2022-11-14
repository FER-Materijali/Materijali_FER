#include <stdio.h>
#define MAX 15

int main(){
	int red, stup, i, j, najveci, pozicija;
	int mat[MAX][MAX], pom[MAX]={0};

	printf("Unesi dimenzije matrice (maksimalno 15x15):");
	printf("\n  Unesi broj redaka : ");
	scanf("%d", &red);
	printf("  Unesi broj stupaca: ");
	scanf("%d", &stup);

	if(red<1 || red>15 || stup<1 ||stup>15) return 0;

	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("Unesi element (%d,%d): ", i+1, j+1);
			scanf("%d", &mat[i][j]);
			if(mat[i][j]==0) pom[j]++;
		}
	}
	najveci = pom[0];
	pozicija = 0;
	for(i=0;i<stup;++i){
		if(pom[i]>najveci){
			najveci=pom[i];
			pozicija=i;
		}
	}
	printf("\n\nNajvise nula nalazi se u %d stupcu (%d).\n\n", pozicija+1, najveci);
    
	return 0;
}
