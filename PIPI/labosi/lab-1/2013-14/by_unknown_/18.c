#include <stdio.h>

int main (void){

int a,b,c;

printf ("Unesite tri prirodna broja: ");
scanf ("%d%d%d", &a, &b, &c);

if (c==a+b) printf ("%d + %d = %d", a,b,c);
else if (b==a+c) printf ("%d + %d = %d", a,c,b);
else if (a==b+c) printf ("%d + %d = %d", b,c,a);
else printf ("Niti jedan broj nije jednak zbroju preostalih brojeva.");

return 0;
}