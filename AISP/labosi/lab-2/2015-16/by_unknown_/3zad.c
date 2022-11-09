#include<stdio.h>
typedef struct {
	int sifra;
	char naziv[50 + 1];
}zapis;
void zamjeni(zapis *a, zapis *b){
	zapis pom;
	pom = *b;
	*b = *a;
	*a = pom;
}
void obicanBubbleSort(zapis *A, int n){
	int i, j;
	for ( i = 0; i < n-1; i++){
		for (j = 0; j < n-1-i; j++){
			if (A[j+1].sifra < A[j].sifra) zamjeni(&A[j],&A[j+1]);
		}
	}
}
int main(void){
	zapis a[10];
	int i, n;
	printf("Upisite n manji od 11: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("Upisite sifru i naziv %d. proizvoda: ",i + 1);
		scanf("%d %s", &a[i].sifra, &a[i].naziv);
	}
	obicanBubbleSort(a, n);
	printf("Sortirani porizvodi: \n");
	for (i = 0; i < n; i++){
		printf("%d %s\n", a[i].sifra, a[i].naziv);
	}
	return 0;
}