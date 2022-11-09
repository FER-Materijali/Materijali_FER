#include<stdio.h>
typedef struct {
	int posbr;
	char naziv[40 + 1];
} zapis;

void insertionSort(zapis* A, int n){
	int i, j;
	zapis pom;
	for (i = 1; i < n; i++)
	{
		pom = A[i];
		for (j = i; i >= 1 && A[j - 1].posbr > pom.posbr; j--){
			A[j] = A[j - 1];
		}
		A[j] = pom;
	}
}

int main(void){
	zapis grad[10];
	int n, i;
	printf("Upisite broj gradova manji od 11: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Upisite postanski broj %d. grada i njegovo ime: ", i + 1);
		scanf("%d %s", &grad[i].posbr,&grad[i].naziv);
	}
	insertionSort(grad, n);
	for (i = 0; i < n; i++)
	{
		printf("%d %s \n", grad[i].posbr, grad[i].naziv);
		
	}
}