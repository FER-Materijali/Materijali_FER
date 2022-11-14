#include<stdio.h>
int main(void){
	int broj, znam1, znam2, znam3, sum;
	printf("Upisi troznamenkasti prirodni broj:");
	scanf("%d", &broj);
	znam1 = broj/100;
	znam2 = (broj - broj%10 - broj/100*100)/10;
	znam3 = broj%10;
	sum = znam1*znam1*znam1 + znam2*znam2*znam2 + znam3*znam3*znam3;
	if (sum==broj)
		printf("Broj %d je Armstrongov broj.", broj);
	return 0;
}