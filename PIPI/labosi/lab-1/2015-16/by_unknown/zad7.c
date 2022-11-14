#include <stdio.h>
int main(void) {
	int a;
	printf("Unesite cijeli broj:");
	scanf("%d", &a);
	if (a%6==0)
		printf("Broj %d je djeljiv sa 6", a);
	if ((a%3==0) && (a%2!=0))
		printf("Broj %d nije djeljiv sa 6 jer nije djeljiv sa 2", a);
	if ((a%3!=0) && (a%2==0))
		printf("Broj %d nije djeljiv sa 6 jer nije djeljiv sa 3", a);
	if ((a%3!=0) && (a%2!=0))
		printf("Broj %d nije djeljiv sa 6 jer nije djeljiv ni sa 3 ni sa 2", a);
	return 0;
}