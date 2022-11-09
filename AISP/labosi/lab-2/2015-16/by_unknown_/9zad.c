#include<stdio.h>
#include<string.h>
#include<malloc.h>
void ShellSort(char **A, int N){
	int i, j, kor;
	char *pom;
	for (kor = N / 2 ; kor > 0 ; kor /= 2)
	{
		for (i = kor;i < N; i++)
		{
			pom = A[i];
			for ( j = i; j >=kor && strcmp(A[j-kor],pom)>0; j -= kor)
			{
				A[j] = A[j - kor];
			}
			A[j] = pom;
		}
	}
}
int main(void){
	int i, n;
	char **A;
	printf("upisite broj nizova: ");
	scanf("%d", &n);
	A = (char**)malloc(n * 4);
	for (i = 0; i < n; i++){
		A[i] = (char*)malloc(50 + 1);
	}
	for (i = 0; i < n; i++){
		printf("Upisite %d. niz: ", i + 1);
		scanf("%s", A[i]);
	}
	ShellSort(A, n);
	for (i = 0; i < n; i++){
		printf("%s\n", A[i]);
		free(A[i]);
	}
	free(A);
	return 0;
}