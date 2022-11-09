#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int tip;
typedef struct podaci
{
	int sifra;
	char naziv[51];
}zapis;
 void zamijeni(tip A[], tip B[]) {
	tip temp = *A;
	*A = *B;
	*B= temp;
	
}
 
void obicanBubble(zapis A[], int n) {
	int i, j;
	char temp[51];
	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < n - i - 1; ++j)
		{
			if (A[j + 1].sifra<A[j].sifra) {
				zamijeni(&A[j + 1].sifra, &A[j].sifra);
				strcpy(temp, &A[j + 1].naziv);
				strcpy(&A[j + 1].naziv, &A[j].naziv);
				strcpy(&A[j].naziv, temp);



			}
				
		}
	}
}

int main()
{
	int n, i;
	zapis *data;
	puts("Upisite n <=10");
	scanf("%d", &n);
	data = (zapis*)malloc(n*sizeof(zapis));
	if (data == NULL) {
		puts("Nema memorije!");
		exit(1);
	}
	for (i = 0; i < n; ++i)
	{
		printf("Upisite sifru i naziv %d aritkla\n", i + 1);
		scanf("%d%s", &data[i].sifra, &data[i].naziv);

		
	}
	puts("Prije Bubble sorta");
	for (i = 0; i < n; ++i) {
		printf("%5d %s\n", data[i].sifra, data[i].naziv);

	}
	obicanBubble(data, n);
	puts("Nakon Bubble sorta");
	for (i = 0; i < n; ++i) {
		printf("%5d %s\n", data[i].sifra, data[i].naziv);

	}
	return 0;
}