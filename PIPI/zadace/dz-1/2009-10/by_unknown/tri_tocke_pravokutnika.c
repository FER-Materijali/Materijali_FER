/*
Unose se koordinate tocaka, redom: x1,y1,x2,y2,x3,y3, s tipkovnice
- program treba provjeriti jesu li tocke vrhovi pravokutnika
	- ispis u skladu s otkrivenim
*/

#include <stdio.h>

int main () {
int x1,y1,x2,y2,x3,y3;

scanf ("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

if (((y2-y1)*(y3-y2)==-(x2-x1)*(x3-x2)) || ((y3-y2)*(y3-y1)==-(x3-x2)*(x3-x1)) || ((y2-y1)*(y3-y1)==-(x2-x1)*(x3-x1)))
	printf ("Tocke su tri vrha pravokutnika"); /*provjerili smo jesu li okomiti pravci napravljeni od po dvije unesene tocke*/
else
	printf ("Tocke nisu tri vrha pravokutnika");

return 0; }