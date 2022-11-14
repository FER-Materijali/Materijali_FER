#include<stdio.h>
int main(void){
	int a,b;
	printf("Upisi troznamenkasti broj:");
	scanf("%d", &a);
	b=a;
	if (a<0) b=-a;
	printf("Srednja znamenka broja %d je %d", a, (b%100)/10);
	return 0;
}