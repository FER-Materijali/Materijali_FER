#include <stdio.h>
int main(void) {
	float x,y;
	printf("Unesite vrijednost x: ");
	scanf("%f", &x);
	if (x<0)
		y=-x;
	if (x==0)
		y=x;
	if (x>0)
		y=((2.f/3.f)*x)+3;
	printf("x= %.2f ; y= %.2f", x, y);
	return 0;
}
	
	