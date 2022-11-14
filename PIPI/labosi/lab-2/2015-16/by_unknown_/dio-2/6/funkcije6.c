#include <ctype.h>

int brRijeci(char *tekst)
{
	int i = 0, broj = 0;
	while (*(tekst + i) != '\0') {
		if (isalnum(*(tekst + i)))
			if (*(tekst + (i + 1)) == '\0')							/*uveæava broj rijeèi ako je došao do kraja a prethodni znak je znamenka ili slovo*/
				++broj;												
			else {
				++i;
				continue;
		}
		else if ((*(tekst + i) == ' ')) {							/*ako je došao do razmaka a prethodni znak je znamenka ili slovo*/
			if (isalnum(*(tekst + i - 1)))
				++broj;
			else {
				++i;
				continue;
			}
		}
		else if (*(tekst + i) == '.' || *(tekst + i) == '!' || *(tekst + i) == '?')		/*ako je došao do interpunkcijskog znaka*/
			++broj;
		else
			return -1;
		++i;
	}
	return broj;
}

int izbaciBrojeve(char *tekst)
{
	int promjena = 0, i = 0, j = 0;
	while (*(tekst + i) != '\0') {
		if (isdigit(*(tekst + i))) {
			promjena = 1;
		}
		else {
			*(tekst + j) = *(tekst + i);
			++j;
		}
		++i;
	}
	*(tekst + j) = '\0';
	return promjena;
}