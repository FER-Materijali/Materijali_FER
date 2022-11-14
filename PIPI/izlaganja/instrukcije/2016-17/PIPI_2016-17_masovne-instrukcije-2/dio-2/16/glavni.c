#include "funkcije.h"
#include <stdio.h>
#define XMAX 20
#define YMAX 20

int main(void) {
	int ary[XMAX][YMAX];
	int x, y, i, j;
	int max, min;
	
	do {
		printf("Upisite dimenzije: ");
		scanf("%d %d", &x, &y);
	} while (!dobreDimenzije(x, y, XMAX, YMAX));
	
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++){
			scanf("%d", &ary[i][j]);
		}
	}
	
	minmax(&min, &max, &ary[0][0], x, y, XMAX, YMAX);
	
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++){
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	
	printf("%d %d", min, max);
	
	return 0;
	
	
}