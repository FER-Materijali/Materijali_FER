#include<stdio.h>
#include<string.h>
#include<malloc.h>
void spojiPolja(int *A, int *B, int *Rez, int n1, int n2){
	int i,j;
	for (i = 0, j = 0; i != n1 || j != n2;){
		if (j == n1) Rez[i + j] = A[i++];
		else if (i == n2) Rez[i + j] = B[j++];
		else if (A[i] < B[j]) Rez[i + j] = A[i++];
		else Rez[i + j] = B[j++];
	}
}
int main(void){
	int A[5] = { 1, 3, 5, 7, 9 }, B[5] = {0,2,4,6,8,}, *R, n1, n2, i;
	n1 = sizeof(A) / sizeof(int);
	n2 = sizeof(B) / sizeof(int);
	R = (int*)malloc(sizeof(int)*(n1 + n2));
	spojiPolja(A,B,R,n1,n2);
	printf("Spojeni nizovi: ");
	for (i = 0; i < n1+n2; i++){
		printf("%d", R[i]);
	}
	return 0;
}