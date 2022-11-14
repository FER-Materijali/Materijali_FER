#include <stdio.h>

void traziMinMax(int *mat, int *min, int *max, int brRed, int brStup, int maxStup){

	int i, j;

	*min = *max = *mat;

	for(i = 0; i < brRed; i++){
	
		for(j = 0; j < brStup; j++){
		
			if(*(mat + i*maxStup + j) > *max)
				max = *(i*maxStup + j);
				
			else if(*(mat + i*maxStup + j) < *min)
				min = *(i*maxStup + j);
		}
	
	}
}

int main(){


	int mat1[5][10], mat2[15][5], m1, n1, m2, n2;
	int minZaMat1, maxZaMat1, minZaMat2, maxZaMat2;
	
	printf("Unesite stvarni broj redaka i stupaca prve matrice:");
	scanf("%d %d", &m1, &n1);
	
	printf("Unesite stvarni broj redaka i stupaca druge matrice:");
	scanf("%d %d", &m2, &n2);
	
	traziMinMax(&mat1[0][0], minZaMat1, maxzaMat1, m1, n1, 10);
	
	printf("Najmanji i najveci element u mat1 su %d %d\n", minZaMat1, maxZaMat1);
	
	traziMinMax(&mat2[0][0], minZaMat2, maxzaMat2, m2, n2, 5);
	
	printf("Najmanji i najveci element u mat2 su %d %d\n", minZaMat2, maxZaMat2);
	
	return 0;
}