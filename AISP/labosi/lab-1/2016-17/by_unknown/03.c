#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

double pi(int n);

int main (void) {
	int n, i;
	float *p;
	
	printf("n: ");
	scanf("%d", &n);
	p = (float *)malloc(sizeof(float) * n);
	
	for (i = 0; i < n; i++) {
		*(p + i) = pi(i+1);
		printf("%3d: %f\n", (i+1), *(p+i));
	}
	
	free(p);
	return 0;
}

double pi(int n) {
	if (n%2) {
		if (n == 1) {
			return 4;
		} else {
			return ((float)4/((n-1)*2 + 1) + pi(n-1));
		}
	} else {
		return ((float)-4/(2*n - 1) + pi(n-1));
	}
}