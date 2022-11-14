#include<stdio.h>
int main(void){
	int min, sek;
	float sat;
	printf("Upisi vrijeme u minutama i sekundama: ");
	scanf("%d %d", &min, &sek);
	if (sek<=59){
		sek = sek + min*60;
		sat = sek/3600.;
		printf("sekunde: %d; sati: %.3f", sek, sat);
	}
	else
		printf("Neispravan broj sekundi.");
	return 0;
}