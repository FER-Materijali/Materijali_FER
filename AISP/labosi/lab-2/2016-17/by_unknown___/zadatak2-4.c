#include <stdio.h>
#define MAX 5

void spojiPolja(int *A, int *B, int *Rez, int n1, int n2){
	int i = 0, j = 0, k = 0;
	while(i<n1 && j<n2) {
		if(*(A+i) > *(B+j)) {
			*(Rez+k) = *(A+i);
			k++;
			i++;
		}
		else {
			*(Rez+k) = *(B+j);
			k++;
			j++;
		}
	}
	if(i>=n1)
		while(j<n2){
			*(Rez+k) = *(B+j);
			k++;
			j++;
		}
	else if (j>=n2)
		while(j<n2){
			*(Rez+k) = *(A+i);
			k++;
			i++;
		}
}

int main(void){
	int A[MAX] = {9, 7, 5, 3, 1};
	int B[MAX] = {8, 6, 4, 2, 0};
	int Rez[MAX*2], i;
	spojiPolja(A, B, Rez, MAX, MAX);
	for (i=0; i<MAX*2;i++)
		printf("%d ", Rez[i]);
	return 0;
}