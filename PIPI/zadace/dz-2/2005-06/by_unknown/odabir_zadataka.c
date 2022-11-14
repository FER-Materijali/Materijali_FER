#include <stdio.h>

int main (){
	int mat, mat1, znam1, mat2, znam2, mat3, znam3, zad1, zad2, zad3;
	int i, n=20;
	for(i=0; i<n;++i){
		int suma1 = 0, suma2 = 0, suma3 = 0;
		printf("Unesi PUNI maticni broj: ");
		scanf("%d", &mat);
		mat1 = mat2 = mat3 = mat;
		while (mat1>0){
			znam1 = mat1%10;
			mat1 /=10;
			suma1 +=znam1;
		}
		while (mat2>0){
			znam2 = mat2%10;
			mat2 /=10;
			if (znam2%2 == 0) suma2 +=znam2;
		}

		while (mat3>0){
			znam3 = mat3%10;
			mat3 /=10;
			if (znam3%2 != 0) suma3 +=znam3;
		}
		zad1=(suma1%22)+1;
		zad2=(suma2%22)+1;
		zad3=(suma3%22)+1;
		if (zad2==zad1)++zad2;
		if (zad3==zad2 || zad3==zad1) ++zad3;

		printf ("\nTrebate rijesiti zadatke: \n%5d. \n%5d. \n%5d.\n\n", zad1, zad2, zad3);
		printf("------------------------------------------------------------\n\n");
	}
	return 0;
}