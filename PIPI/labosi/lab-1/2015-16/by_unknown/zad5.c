#include <stdio.h>
int main(void) {
	int a, z;
	printf("Unesite troznamenkasti broj:");
	scanf("%d", &a);
	if ((a/100)==0 || (a/10%10==0) || (a%10==0)) {
		printf("Umnozak znamenaka broja %d je 0",a);
	}else {
		z=(a/100)*(a/10%10)*(a%10);
		printf("Umnozak znamenaka broja %d je %d",a,z);
	}
	return 0;
}
	