#include<stdio.h>
#include<string.h>
#include<malloc.h>
void InsertionSort(char **A, int N){
	int i, j;
	char *pom;
	for (i = 1; i < N; i++){
		pom = A[i];
		for ( j= i;  j >0 && (strcmp(A[j-1], pom))>0;  j--)
		{
			A[j] = A[j-1];
		}
		A[j] = pom;
	}
}
int main(void){
	char **A[10];
	int n,i;
	printf("Upisite broj nizova: ");
	scanf("%d",&n);
	for ( i = 0; i < n; i++){
		A[i] =(char*) malloc(50 + 1);
		printf("Upisite %d. niz: ",i + 1);
		scanf("%s", A[i]);
	}
	InsertionSort(A,n);
	for (i = 0; i < n; i++){
		printf("%s\n", A[i]);
		free(A[i]);
	}
	free(A);
	return 0;
}