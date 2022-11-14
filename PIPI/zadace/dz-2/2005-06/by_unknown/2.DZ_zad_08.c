#include <stdio.h>
#include <math.h>
#define MAX 10

int main(){
	//int n, i, j,k, neparan;
	int i,j,n,temp, paran_ind,neparan_ind;
	int mat[MAX][MAX];

	do{
		printf("Unesi n iz intervala [1,10]: ");
		scanf("%d", &n);
	}while(n<1 || n>10);

	printf("\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;++j){
			printf("Unesi element (%d,%d): ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n\nIspis matrice prije zamjene elemenata:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;++j){
			printf("%3d   ", mat[i][j]);
		}
		printf("\n");
	}

	/*
	for(i=0;i<n;i++){						//krivo
		for(j=n-1;j>=0;--j){
			if(!(mat[i][j]%2==0)){
				neparan=mat[i][j];
				for(k=n-1;k>=0;--k){
					if(k==j) continue;
					if(mat[i][k]%2==0){
						mat[i][j]=mat[i][k];
						mat[i][k]=neparan;
					}
				}
			}

		}
	}
	*/

	for(i=0;i<n;++i){
		paran_ind = neparan_ind = -1;
		for(j=n-1;j>=0;--j){
			if(mat[i][j]%2){
				if(neparan_ind==-1){
					neparan_ind=j;
					if (paran_ind!=-1){
						break;
					}
				}
			}
			else {
				if(paran_ind==-1){
					paran_ind=j;
					if(neparan_ind!=-1){
						break;
					}
				}
			}
		}
		if((neparan_ind!=-1) && (paran_ind!=-1)){
			temp=mat[i][paran_ind];
			mat[i][paran_ind]=mat[i][neparan_ind];
			mat[i][neparan_ind]=temp;
		}
	}
				


	printf("\n\nIspis matrice nakon zamjene redaka:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;++j){
			printf("%3d   ", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	return 0;
}
