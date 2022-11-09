#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int zbrojiKvadrate(int *polje, int n);

int main(void) {
	int n, i, *p, zbroj;
	
	printf("n: ");
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int) * n);
	srand((unsigned)time(NULL));
	
	for(i = 0; i < n; i++) {
		*(p + i) = rand()%100 + 1;
		printf("%d ", *(p+i));
	}
	
	zbroj = zbrojiKvadrate(p, n);
	printf("\nzbroj = %d\n", zbroj);
	
	free(p);
	return 0;
}

int zbrojiKvadrate(int *polje, int n) {
	int rez = 0;
	
	if ((int)pow((int)sqrt(*polje), 2) == *polje) {
		rez = *polje;
	}
	
	if (n == 1) {
		return rez;
	} else {
		return (rez + zbrojiKvadrate((polje+1), (n-1)));
	}
}