#include <stdio.h>

int main (void){

int x, y, temp;

printf ("Unesite dva cijela broja: ");
scanf ("%d%d", &x, &y);

if (x>y) {
		printf ("Brojevi nisu dobro zadani!");
		return;
		}

	temp=x;
	x=y;
	y=temp;
	printf ("x=%d y=%d", x, y);


return 0;
}