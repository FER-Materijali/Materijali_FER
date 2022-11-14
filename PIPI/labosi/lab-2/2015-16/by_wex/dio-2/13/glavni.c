#include <stdio.h>
#include <string.h> /* moze i bez ovog => vrijeme[2 odnosno 5] = ':'*/
#include "funkcije.h"

int main(void) {
	int sati, minute, sekunde;
	int ukup;
	char vrijeme[9] = {0};
	char temp[2];
	int internal = 0;
	
	printf("upisite vrijeme u sekundama: ");
	scanf(" %d", &ukup);
	
	s_time(ukup, &sati, &minute, &sekunde);
	
	if (convert(sati, temp)) {
		append(vrijeme, temp);
		vrijeme[strlen(vrijeme)] = ':';
		if (convert(minute, temp)) {
			append(vrijeme, temp);
			vrijeme[strlen(vrijeme)] = ':';
			if (convert(sekunde, temp)) {
				append(vrijeme, temp);
			} else internal = 1;
		} else internal = 1;
	} else internal = 1;
	
	if (internal) printf("Prevelik/neispravan broj sekundi!\n");
	else printf("%s\n", vrijeme);
	
	return 0;
}