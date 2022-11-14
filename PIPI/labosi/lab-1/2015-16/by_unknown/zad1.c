#include <stdio.h>
int main(void) {
	int a,z;
	printf("Ucitajte troznamenkasti broj");
	scanf("%d", &a);
	z=a%10;
	if (z<=5) {
		printf("Zadnja znamenka broja %d je %d", a, z);
	}else {
		printf("zadnje dvije znamenke broja %d su %d%d", a, a/10%10, a%10);
	}
	return 0;
}
