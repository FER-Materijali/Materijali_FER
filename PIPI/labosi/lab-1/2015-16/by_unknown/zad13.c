#include <stdio.h>
int main(void) {
	int x,y,c;
	printf("Unesite 2 broja (Drugi mora biti veci od prvog): ");
	scanf("%d %d", &x, &y);
	printf("x= %d y= %d\n", x, y);
	if (y<x)
		printf("Brojevi nisu dobro zadani");
	else {
		c=x;
		x=y;
		y=c;
		printf("x= %d y= %d", x, y);	
	}
	return 0;
}
	
	