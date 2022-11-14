#include <ctype.h>

void najZnak(char *tekst, char *najZnak1, char *najZnak2)
{
	int i, j, brojac = 0, max1 = 0, max2 = 0;
	for (i = 0; i < 26; ++i) {
		for (j = 0; *(tekst + j) != '\0'; ++j)
			if (isalpha(*(tekst + j)))
				if (*(tekst + j) == i + 'A' || *(tekst + j) == i + 'a')
					++brojac;
		if (brojac > max1) {
			max2 = max1;
			max1 = brojac;
			*najZnak2 = *najZnak1;
			*najZnak1 = i + 'A';
		}
		else if (brojac >= max2) {
			max2 = brojac;
			*najZnak2 = i + 'A';
		}
		brojac = 0;
	}
}