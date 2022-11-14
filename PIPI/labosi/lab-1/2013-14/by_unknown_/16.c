#include <stdio.h>

int main (void){

int minute, sekunde;

printf ("Unesite broj minuta i broj sekundi: ");
scanf ("%d%d", &minute, &sekunde);

if (sekunde>59) {
	printf ("Neispravan broj sekundi!");
	return;
	}
	
printf ("sekunde: %d; sati: %.3f", sekunde+minute*60, 1.*(sekunde+minute*60)/3600);

return 0;
}