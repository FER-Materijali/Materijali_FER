#include <stdio.h>
int main(void) {
	int a;
	printf("Unesite troznamenkasti broj");
	scanf("%d", &a);
	if (((a/100)*(a/100)*(a/100))+((a/10%10)*(a/10%10)*(a/10%10))+((a%10)*(a%10)*(a%10))==a)
		printf("Broj %d je Armstrongov broj", a);
	else
		printf("Broj %d nije Armstrongov broj", a); 
	return 0;
}

		