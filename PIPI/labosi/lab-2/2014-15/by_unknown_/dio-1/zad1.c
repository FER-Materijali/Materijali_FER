#include <stdio.h>
int main(void){
	int a;
	printf("upisi troznamenkasti broj:");
	scanf("%d", &a);
	if (a%10<5) printf("Zadnja znamenka broja %d je %d", a, a%10);
	else printf("Zadnje dvije znamenke broja %d su %d", a, a%100);
	return 0;
}