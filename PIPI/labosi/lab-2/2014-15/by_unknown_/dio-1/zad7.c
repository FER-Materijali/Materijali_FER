#include<stdio.h>
int main(void) {
	int broj;
	printf("Upisi neki cijeli broj:");
	scanf("%d", &broj);
	if (broj%6==0) 
		printf("Broj %d je djeljiv sa 6.", broj);
	else if ((broj%2==0) && (broj%3!=0))
		printf("Broj %d nije djeljiv sa 6 jer nije djeljiv s 3", broj);
	else if ((broj%2!=0) && (broj%3==0))
		printf("Broj %d nije djeljiv sa 6 jer nije djeljiv s 2", broj);
	else
		printf("Broj %d nije djeljiv sa 6 jer nije djeljiv ni s 3 ni s 2", broj);		
	return 0;
}