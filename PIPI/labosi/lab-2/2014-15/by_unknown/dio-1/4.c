#include<stdio.h>
int main (void) {
int n, i, polje[20];
do {
	scanf("%d", &n);
} while (n<1 || n>20);
for (i=0; i<n; ++i) {
	scanf("%d", &polje[i]);
}
for (i=0; i<n; ++i) {
	if (polje[i]>=10 && polje[i]<=20) {
		printf("%2d. %d\n", i, polje[i]);
	}
}
	return 0;
}