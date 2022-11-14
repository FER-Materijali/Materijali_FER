#include <stdio.h>
#define PI 3.14159

int main (void){

float r;
printf ("Unesite duljinu kraka: ");
scanf ("%f", &r);

if (r<0) {
	printf ("Duljina stranice mora biti pozitivan broj!");
	return;
	}

printf ("Povrsina trokuta: %.2f\n", r*r/2);
printf ("Povrsina kruga  : %.2f\n",r*r*PI);

return 0;
}
	