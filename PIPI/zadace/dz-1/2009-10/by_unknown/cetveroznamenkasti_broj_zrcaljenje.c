/*
Unosi se cetveroznamenkasti broj sa tipkovnice
- program treba zrcaljeno ispisati uneseni broj
- primjer: za uneseno 2009, program treba ispisati 9002
- primjer: za uneseno 4365, program treba ispisati 5634
- napomena: nije potrebno provjeravati jesu li uneseni brojevi 4-znamenkasti
*/

#include <stdio.h>
int main () {
int n,j,d,s,t;

scanf ("%d", &n);

j = n % 10;
d = (n % 100) / 10;
s = (n % 1000) / 100;
t = n / 1000;

printf ("%d", j*1000 + d*100 + s*10 + t);

return 0; }