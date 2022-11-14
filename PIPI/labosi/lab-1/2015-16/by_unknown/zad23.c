#include <stdio.h>
int main(void) {
	float x1,x2,y;
	printf("Ucitajte 2 realna broja");
	scanf("%f %f", &x1, &x2);
	if (x2>x1)
		y=x1/x2;
	if (x1==x2)
		y=(x1*x1)-3;
	if (x1>x2)
		y=4*x1+3*x2;
	printf("y= %.3f",y);
	return 0;
}
	