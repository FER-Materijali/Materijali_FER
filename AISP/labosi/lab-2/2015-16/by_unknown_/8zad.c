#include<stdio.h>
#include<string.h>
#include<malloc.h>
void Zamijeni(char *prvi, char *drugi){
	char p[51];
	strcpy(p, prvi);
	strcpy(prvi, drugi);
	strcpy(drugi, p);
}
void BubbleSortPoboljsani(char **A, int N){
	int i, j,z;
	for (i = 0,z=1;z; i++)
	{
		z = 0;
		for (j = 0; j < N-i-1; j++)
		{
			if (strcmp(A[j], A[j + 1])>0)
			{
				Zamijeni(A[j], A[j + 1]);
				z = 1;
			}
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
	BubbleSortPoboljsani(A, n);
	for (i = 0; i < n; i++){
		printf("%s\n", A[i]);
		free(A[i]);
	}
	free(A);
	return 0;
}