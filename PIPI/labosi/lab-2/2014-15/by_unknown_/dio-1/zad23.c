#include<stdio.h>
int main(void){
	float x1, x2, y;
	printf("Upisi dva realna broja x1 i x2, s uvjetom da je x2 razlicit od nule:");
	scanf("%f %f", &x1, &x2);
	if (x1<x2)
		y = x1/x2;
	else if (x1==x2)
		y = x1*x1 - 3;
	else 
		y = 4*x1 + 3*x2;
	printf("y = %.3f", y);
	return 0;
}