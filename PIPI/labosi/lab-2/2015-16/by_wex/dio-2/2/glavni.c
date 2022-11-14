#include <stdio.h>
#include <ctype.h>
#include "funkcije.h"

int main(void) {
	unsigned sjeme;
	char znak;
	do {
		printf("Upisite sjeme: ");
		scanf(" %u", &sjeme);
		if (sjeme) {
			setSeed(sjeme);
			do {
				znak = getRand();
				if (isalpha(znak)) printf("%c", znak);
				else if (znak == ' ' || znak == ',' || znak == '.') printf("%c", znak);
			} while (znak != '.');
			printf("\n\n");
		}
	} while (sjeme);
	return 0;
}