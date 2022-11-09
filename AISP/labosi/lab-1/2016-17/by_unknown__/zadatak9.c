#include <stdio.h>
#include <math.h>
#include <malloc.h>

void f(int *polje, int n, int m){
	if (n == 0) return;
	*(polje+n-1) =  pow(m, n-1);
	f(polje, n-1, m);
}

int main(void){
	int m, n, *p, i;
	printf("Unesite broj velicine polja n > ");
	scanf("%d", &n);
	printf("\nUnesite parametar m > ");
	scanf("%d", &m);
	p = malloc(sizeof(int)*n);
	f(p, n, m);
	for(i=0; i<n;i++) printf("[%d] = %d\n", i, *(p+i));
	return 0;
}