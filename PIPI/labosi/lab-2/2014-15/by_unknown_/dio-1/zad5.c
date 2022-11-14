#include<stdio.h>
int main(void){
	int a,p,a1;
	p=1;
	printf("Upisi troznamenkasti prirodan broj:");
	scanf("%d", &a);
	a1=a;
	while (a>0) {
		p=p*(a%10);
		a=a/10; 
	}
	printf("Umnozak znamenaka broja %d je %d", a1, p);
	return 0;
}