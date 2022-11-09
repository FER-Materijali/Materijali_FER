#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spojiPolja(int A[], int B[], int Rez[], int n1, int n2) {
	int i, j,k, suma;
	suma = n1 + n2;
	for (i = 0, j = 0, k = 0;k<suma ; ++k)
	{
		if (i < n1 && j < n2) {
			if (A[i] <= B[j]) {
				Rez[k] = A[i];
				++i;
			}
			else {
				Rez[k] = B[j];
				++j;
			}
		}
		else if (i < n1){
			Rez[k] = A[i];
		++i;
		}
		else{
			Rez[k] = B[j];
		++j;
		}
	}
}

int main()
{
	int *rez;
	int A[] = { 1,3,5,7,9 };
	int B[] = { 0,2,4,6,8 };
	int n = sizeof(A) / 4 + sizeof(B) / 4;
	rez = (int*)malloc(n * 4);
	spojiPolja(&A[0], &B[0], &rez[0], 5, 5);
	for (int i = 0; i < n; ++i) {
		printf("%3d", rez[i]);
		
	}
	puts(" ");
	return(1);

}