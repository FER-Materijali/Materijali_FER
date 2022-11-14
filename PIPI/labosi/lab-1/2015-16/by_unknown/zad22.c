#include <stdio.h>
int main(void) {
	float x,y;
	printf("Unesite vrijednost x: ");
	scanf("%f", &x);
	if (x<0)
		y=3*x;
	if ((x>=0) && (x<=1))
		y=((3.f/4.f)*x)+1;
	if (x>=1)
		y=(x*x)+3;
	printf("x= %.3f ; y= %.3f", x, y);
	return 0;
}