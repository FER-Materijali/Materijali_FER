#include<stdio.h>
int main(void){
	int a,b;
	printf("Upisi dvoznamenkasti broj:");
	scanf("%d", &a);
	if (a<0) b=-a;
	else b=a;
	if (b/10!=5) printf("Prva znamenka broja %d je %d", a, b/10);
	else printf("Zadnja znamenka broja %d je %d", a, b%10);
	return 0;
}