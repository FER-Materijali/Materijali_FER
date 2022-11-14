#include<stdio.h>
int main(void){
	float y, x;
	printf("Upisi realan broj x:");
	scanf("%f", &x);
	if (x<0)
		y = -x;
	else if (x==0)
		y = x;
	else 
		y = (2./3)*x + 3;
	printf("x = %.2f y = %.2f", x, y);
	return 0;
}