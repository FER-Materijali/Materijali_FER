#include "asp_massh.h"
#include <stdio.h>

void ispisiMatricu(int *p, int n) {
	int i, j;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) printf("%d ", p[i * n + j]);
		noviRed();
	}
}

int main() {
	int p[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int n = 3;
	
	ispisiMatricu(&p[0][0], n);
	
	return 0;
}
