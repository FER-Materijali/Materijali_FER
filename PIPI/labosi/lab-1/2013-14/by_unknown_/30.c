#include <stdio.h>

int main (){

int a,b,c;
printf ("Unesite 3 razlicita cijela broja: ");
scanf ("%d%d%d", &a, &b, &c);

if (a<=b && b<=c){
	if ((c-b)==(b-a)) printf ("Brojevi %d, %d, %d su poredani uzlazno (razlika izmedju susjednih brojeva je %d).", a,b,c,(c-b));
		else printf ("Brojevi %d, %d, %d su poredani uzlazno (razlika izmedju susjednih brojeva nije jednaka).", a,b,c);
}
else printf ("Brojevi %d, %d, %d nisu poredani uzlazno.", a,b,c);

return 0;
}