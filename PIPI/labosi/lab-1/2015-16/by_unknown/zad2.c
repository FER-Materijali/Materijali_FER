#include <stdio.h>
int main(void) {
	int a,z;
	printf("Unesite dvoznamenkasti broj");
	scanf("%d", &a);
	if ((a/10)==5) {
	printf("Zadnja znamenka broja %d je %d", a, a%10);
	} else {
	z=a/10;
	if (z<0) {
		z=-z;
	}
	printf("Prva znamenka broja %d je %d", a, z);
	}
	return 0;
}