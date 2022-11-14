#include <stdio.h>

int main (void){

float cijena;
int postotak;

printf ("Unesite cijenu: ");
scanf ("%f", &cijena);

	if (cijena<=0){
		printf ("Cijena mora biti pozitivan broj.\n");
		return;
		}
		
printf ("Unesite postotak: ");
scanf ("%d", &postotak);

	if (postotak<=0){
		printf ("Postotak mora biti prirodni broj.\n");
		return;
		}
	
printf ("Cijena %.2f umanjena za %d posto iznosi %.2f.", cijena, postotak, cijena-cijena*(postotak/100.));

return 0;
}