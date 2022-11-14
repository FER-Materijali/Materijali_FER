#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int HammingovaUdaljenost(char *s, char *t)
{
	int razlika = 0;
	int i;
	for(i = 0; s[i] != '\0'; ++i)
		if(s[i] != t[i])
			++razlika;
		
	return razlika;
}

void odrediSlucajniNiz(int n, char *s)
{
	int i, veliko;
	
	for (i = 0; i < n; ++i) {
		veliko = rand() % 2;
		if (veliko)
			s[i] = rand() % 26 + 'A';
		else
			s[i] = rand() % 26 + 'a';
	}
	s[i] = '\0';
}