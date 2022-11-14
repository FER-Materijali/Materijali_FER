#include <stdio.h>
int main(void) {
	int a;
	printf("Ucitajte troznamenkasti broj");
	scanf("%d", &a);
	if (a<0) {
		a=-a;
	}
	printf("Srednja znamenka broja %d je %d", a, a/10%10);
	return 0;
}
