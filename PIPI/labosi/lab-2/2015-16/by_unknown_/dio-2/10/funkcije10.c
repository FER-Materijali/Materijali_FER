static int k = 0;				/*pozicija znaka u prvom nizu*/

int brojPonavljanja(char niz[], char znak)
{
	int broj = 0, i;		
	for (i = k; niz[i] != '\0'; ++i) {			/*zapoèinje od odreðene pozicije kako bi zanemarilo prethodna pojavljivanja istog znaka*/
		if (niz[i] == znak)
			++broj;
		else if (niz[i - 1] == znak)
			break;
	}
	return broj;
}

void kodiraj(char src[], char dest[])
{
	int broj, j = 0;
	while (src[k] != '\0') {
		broj = brojPonavljanja(src, src[k]);
		dest[j++] = src[k];
		dest[j++] = broj + 48;
		k += broj;
	}
	dest[j] = '\0';
}