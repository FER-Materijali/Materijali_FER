#include <stdio.h>
int main(void) {
	int a;
	printf("Unesite troznamenkasti broj");
	scanf("%d", &a);
	if ((a/100)==(a%10))
		printf("Broj %d je palindrom", a);
	else
		printf("Broj %d nije palindrom", a);
	return 0;
}