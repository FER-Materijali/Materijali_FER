#include<stdio.h>
int main(void){
	float x, y;
	printf("Upisi realan broj x:");
	scanf("%f", &x);
	if (x<0)
		y = 3*x;
	else if (x>=1)
		y = x*x +3;
	else 
		y = (3./4)*x + 1;
	printf("x = %.3f y = %.3f", x, y);
	return 0;
}