#include <stdio.h>
#include <malloc.h>

void f(int* polje, int n, int m);

int main(void) {
	int n, m, i, *p;
	
	printf("n m:\n");
	scanf("%d %d", &n, &m);
	
	p = (int *)malloc(sizeof(int) * n);
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		return 1;
	}
	
	f(p, n, m);
	
	for(i = 0; i < n; i++) {
		printf("%d\n", *(p + i));
	}
	
	free(p);
	return 0;
}

void f(int* polje, int n, int m) {
	if (n == 1) {
		*polje = 1;
	} else {
		f(polje, (n-1), m);
		*(polje + n - 1) = *(polje + n - 2) * m;
	}
}