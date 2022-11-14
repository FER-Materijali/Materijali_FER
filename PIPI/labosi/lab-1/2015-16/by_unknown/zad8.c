#include <stdio.h>
int main(void) {
	int a;
	printf("Ucitati troznamenkasti broj:");
	scanf("%d", &a);
	printf("Obrnitu poredak znamenki broja %d je %d%d%d", a, a%10, a/10%10, a/100);
	return 0;
}