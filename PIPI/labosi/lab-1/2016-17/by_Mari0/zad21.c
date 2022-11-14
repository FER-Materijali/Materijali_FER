#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	float x, y;
	printf("Unesite jedan realan broj: \n");
	scanf("%f", &x);
	if(x<0){
		y=fabs(x);
	}
	else if(x==0){
		y=x;
	}
	else{
		y=(2./3)*x+3;
	}
	printf("x= %.2f   y= %.2f \n", x, y);
	return 0;
	
}
