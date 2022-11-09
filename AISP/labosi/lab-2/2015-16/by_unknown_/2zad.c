#include<stdio.h>
void zamjeni(int *a, int *b){
	int pom;
	pom = *b;
	*b = *a;
	*a = pom;
}

void selection2Sort(int *A, int n){
	int i, j, max, min;
	for (i = 0; i <= n/2; i++){
		max = n-i;
		min = i;
		for (j = i; j < n - i; j++){
			if (A[min] > A[j]) min = j;
			if (A[max] < A[j]) max = j;
		}
		zamjeni(&A[min], &A[i]);
		zamjeni(&A[max], &A[n-i]);
	}
}
int main(void){
	int i,n,a[10];
	printf("Upisite n manji od 11: ");
	scanf("%d",&n);
	for (i = 0; i < n; i++){
		printf("Upisite %d. broj: ", i + 1);
		scanf("%d", &a[i]);
	}
	selection2Sort(a, n);
	printf("Sortirani niz: ");
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}