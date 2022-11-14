#include <stdio.h>
#include "funkcije2.h"

int main(void)
{
	int duljina, i;
	unsigned int sjeme;
	char znak;
	scanf("%u", &sjeme);
	while (sjeme != 0) {
		setSeed(sjeme);
		duljina = getRand();
		i = 0;
		while (i < duljina) {
			znak = getRand();
			if (znak >= 'a' && znak <= 'z' || znak >= 'A' && znak <= 'Z' || znak == ',' || znak == ' ') {
				printf("%c", znak);
				++i;
			}
		}
		printf(".\n");
		scanf("%u", &sjeme);
	}
	return 0;
}