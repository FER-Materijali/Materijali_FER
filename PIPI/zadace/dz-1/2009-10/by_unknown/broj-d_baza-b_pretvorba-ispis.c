/*
Unose se dva cijela broja - pozitivni dekadski d i baza b
- broj bi trebao biti u intervalu od [b,b^2-1], a baza u intervalu od [2,16]
	- u suprotnom javlja poruku "Izvan intervala"
- nakon što su brojevi uneseni, program treba prebaciti uneseni dekadski broj d u unesenu bazu b
- prebaceni broj (u bazu b) treba ispisati u formatu "%c%c"
*/


#include <stdio.h>

int main () {
int d,b,z1,z2,de,j;

scanf ("%d %d", &d, &b);

if ((d<b || d>b*b-1) || (b<2 || b>16))
	printf ("Izvan intervala");
else {
	z1 = d % b;
	z2 = (d / b) % b;
		
	if (z1>=0 && z1<=9)
		j = z1 + 48;
	else j = z1 + 55;
	
	if (z2>=0 && z2<=9)
		de = z2 + 48;
	else de = z2 + 55;
	
	printf ("%c%c", de, j);
	}

return 0; }