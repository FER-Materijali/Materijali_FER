#include "asp_massh.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main() {
	int n, *p, i;
	srand(time(NULL));
	
	scanf("%d", &n);
	
	p = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; ++i) {
			p[i] = rand() % 500;
			printf("%d ", p[i]);
	}
	return 0;
}
