#include<stdio.h>
int main(void){
	float a, b, c, max, min;
	printf("Upisi tri realna broja: ");
	scanf("%f %f %f", &a, &b, &c);
	max = a;
	min = a;
	if ((b>a) && (b>c))
		max = b;
	else if ((c>a) && (c>b))
		max = c;
	if (((a>b)>c) | ((b>a)>c))
		min = c;
	else if (((a>c)>b) | ((c>a)>b))
		min = b;
	printf("Broj %.1f je najmanji, a %.1f najveci od ucitanih brojeva.", min, max);
	return 0;
}