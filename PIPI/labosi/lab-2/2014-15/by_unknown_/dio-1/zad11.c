#include<stdio.h>
int main(void){
	int broj;
	printf("Upisi troznamenkasti prirodni broj:");
	scanf("%d", &broj);
	if (broj/100==broj%10)
		printf("Broj %d je palindrom", broj);
	else
		printf("Broj %d nije palindrom", broj);	
	return 0;
}