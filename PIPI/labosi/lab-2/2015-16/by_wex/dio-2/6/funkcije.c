#include <ctype.h>

int brRijeci(char *tekst) {
	int i;
	int br = 0;
	for (i=0; tekst[i]!=0; i++) {
		if (!isalpha(tekst[i]) && !isdigit(tekst[i]) && tekst[i] != ' ' && tekst[i] != ',' && tekst[i] != '!' && tekst[i] != '?' && tekst[i] != '.') return -1;
		else if (ispunct(tekst[i]) && tekst[i+1] != ' ') br++;
		else if (tekst[i] == ' ' && tekst[i+1] != ' ') br++;
		else if (tekst[i+1] == 0) br++;
	}
	return br;
}

int izbaciBrojeve(char *tekst) {
	int i, j;
	int promjenjen = 0;
	for (i=0; tekst[i]!=0; i++) {
		if (isdigit(tekst[i])) {
			if (promjenjen == 0) promjenjen = 1;
			for (j=i; tekst[j]!=0; j++) {
				tekst[j] = tekst[j+1]; /* povlači i terminator za sobom */
			}
			i--; /*da se uvjerimo da slijedeći znak nije broj*/
		}
	}
	return promjenjen;
}