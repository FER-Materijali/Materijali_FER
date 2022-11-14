/*
Unosi se pozitivni cijeli broj
- ako uneseni broj nije iz intervala [16, 255], program ispisuje "Izvan intervala"
- ako broj pripada intervalu, prebaciti ga u heksadekadski sustav i ispisati u formatu "%c%c"
*/


#include <stdio.h>
int main () {
int n,k,z1,z2;
char j,d;

scanf ("%d", &n);

if (n>15 && n<256) {
	k = n / 16;
	z1 = n % 16;
	z2 = k % 16;

	if (z1>=0 && z1<=9)
		j = z1 + 48;
	else j = z1 + 55;

	if (z2>=0 && z2<=9)
		d = z2 + 48;
	else d = z2 + 55;
	
	printf ("%c%c", d, j);
	}
else printf ("Izvan intervala");

return 0; }