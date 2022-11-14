#include<stdio.h>
#include<ctype.h>
#include"funkcije.h"
int main (void) {
	unsigned int seed, duljina, i;
	char slovo;
	printf("Upisite sjeme: ");
	scanf("%u", &seed);
	while (seed!=0) {
		setSeed(seed);
		duljina=getRand();
		i=0;
		while (i<duljina) {
		    slovo=getRand();
			if (isalpha(slovo) || slovo==' ' || slovo==',') {
				printf("%c", slovo);
				++i;
			}
		}
		printf(".\n\n");
		printf("Upisite sjeme: ");
		scanf("%u", &seed);
	}
	return 0;
}