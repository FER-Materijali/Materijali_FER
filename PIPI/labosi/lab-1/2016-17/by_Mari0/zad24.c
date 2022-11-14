#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	float x1, x2, y;
	printf("Unesite 2 realna broja: \n");
	scanf("%f %f", &x1, &x2);
	if(x1>x2){
		y=fabs(x1);
	}
	else{
		y= (pow(x1,2) > pow(x2,2) ? (pow(x1,2)) : (pow(x2,2)) );
	}
	printf("y= %.2f", y);
	return 0;
	
}
