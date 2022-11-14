#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	float x1, x2, y;
	printf("Unesite 2 realna broja pri cemu drugi mora biti razlicit od 0: \n");
	scanf("%f %f", &x1, &x2);
	if(x1<x2){
		y=x1/x2;
	}
	else if(x1>x2){
		y=4*x1 + 3*x2;
	}
	else{
		y=pow(x1, 2) - 3;
	}
	printf("y= %.3f \n", y);
	return 0;
	
}
