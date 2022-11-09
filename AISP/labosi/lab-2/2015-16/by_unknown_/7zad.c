#include<stdio.h>
#include<string.h>
#include<malloc.h>
void Zamijeni(char *prvi, char *drugi){
	char p[51];
	strcpy(p, prvi);
	strcpy(prvi, drugi);
	strcpy(drugi, p);
}
void SelectionSort(char **A, int N){
	int i, j, min;
	for (i = 0; i < N - 1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
		{
			if (strcmp(A[min], A[j])>0) min = j;
		}
		Zamijeni(A[i], A[min]);
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
	SelectionSort(A, n);
	for (i = 0; i < n; i++){
		printf("%s\n", A[i]);
		free(A[i]);
	}
	free(A);
	return 0;
}