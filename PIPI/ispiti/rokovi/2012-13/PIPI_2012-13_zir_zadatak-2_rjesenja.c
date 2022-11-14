#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void igra(int m, int *pobjednik, int *bodovi) {
	int i, izvucen;
	*pobjednik = 1;
	for (i = 0; i < 20; i++) {
		bodovi[i] = 0;
	}
	for (i = 0; i < m; i++) {
		izvucen = rand() % 20 + 1;
		++bodovi[izvucen - 1];
		if (bodovi[izvucen - 1] > bodovi[*pobjednik - 1]) {
		*pobjednik = izvucen;
		}
	}
}
int main() {
	int n, m;
	int i, j;
	int bodovi[20], pobjednik;
	scanf("%d %d", &n, &m);
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++) {
		igra(m, &pobjednik, bodovi);
		printf("%d", pobjednik);
		for (j = 0; j < 20; j++) {
			printf(" %d", bodovi[j]);
		}
		printf("\n");
	}
	return 0;
}