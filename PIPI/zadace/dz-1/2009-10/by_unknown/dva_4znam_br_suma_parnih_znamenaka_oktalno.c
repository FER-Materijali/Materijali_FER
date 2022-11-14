/*
Unose se dva pozitivna 4-znamenkasta broja s tipkovnice
- program treba ispisati sumu svih parnih znamenaka ta dva broja u oktalnom obliku
- ako nema parnih znamenaka, program ispisuje "0"
*/

#include <stdio.h>

int main () {
int xj,xd,xs,xt;
int yj,yd,ys,yt;
int sumap,bro,x,y,d,j;

sumap = 0;
scanf ("%d %d", &x, &y);

xj = x % 10;
xd = (x / 10) % 10;
xs = (x / 100) % 10;
xt = x / 1000;
yj = y % 10;
yd = (y / 10) % 10;
ys = (y / 100) % 10;
yt = y / 1000;

if ((xj % 2) == 0)
	sumap += xj;
if ((xd % 2) == 0)
	sumap += xd;
if ((xs % 2) == 0)
	sumap += xs;
if ((xt % 2) == 0)
	sumap += xt;
if ((yj % 2) == 0)
	sumap += yj;
if ((yd % 2) == 0)
	sumap += yd;
if ((ys % 2) == 0)
	sumap += ys;
if ((yt % 2) == 0)
	sumap += yt;

if (sumap<64) {
	j = sumap % 8;
	d = (sumap / 8) % 8; 
	bro = d*10 + j;
	printf ("%d", bro);
	}
else if (sumap==0)
	printf ("0");
else {
	bro = 100;
	printf ("%d", bro);
	}
return 0; }