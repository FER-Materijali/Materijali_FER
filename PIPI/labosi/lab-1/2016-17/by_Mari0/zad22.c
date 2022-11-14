#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	float x, y;
	printf("Unesite jedan realan broj: \n");
	scanf("%f", &x);
	if(x<0){
		y=3*x;
	}
	else if(x>=1){
		y=pow(x,2) + 3;
	}
	else{
		y=(3./4)*x +1;
	}
	printf("x= %.3f  y= %.3f", x, y);
	return 0;
	
}
