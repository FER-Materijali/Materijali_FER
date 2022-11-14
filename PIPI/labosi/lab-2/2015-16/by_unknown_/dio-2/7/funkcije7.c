#include <ctype.h>

int brojNeSlova(char *tekst)
{
	int broj = 0, i = 0;
	while (*(tekst + i) != '\0') {
		if (!(isalpha(*(tekst + i))))
			++broj;
		++i;
	}
	return broj;
}

void caesarEncrypt(char *nizUlaz, char *nizIzlaz, int kljucKriptiranja)
{
	int i = 0;
	while (*(nizUlaz + i) != '\0') {
		if (*(nizUlaz + i) >= 'A' && *(nizUlaz + i) <= 'Z') {
			if (*(nizUlaz + i) + kljucKriptiranja > 'Z')
				*(nizIzlaz + i) = *(nizUlaz + i) + kljucKriptiranja - 'Z' + 'A' - 1;
			else
				*(nizIzlaz + i) = *(nizUlaz + i) + kljucKriptiranja;
		}
		else if (*(nizUlaz + i) >= 'a' && *(nizUlaz + i) <= 'z') {
			if (*(nizUlaz + i) + kljucKriptiranja > 'z')
				*(nizIzlaz + i) = *(nizUlaz + i) + kljucKriptiranja - 'z' + 'a' - 1;
			else
				*(nizIzlaz + i) = *(nizUlaz + i) + kljucKriptiranja;
		}
		++i;
	}
	*(nizIzlaz + i) = '\0';
}