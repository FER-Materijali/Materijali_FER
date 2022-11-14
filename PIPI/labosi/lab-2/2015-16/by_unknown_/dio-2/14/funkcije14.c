#include <ctype.h>

unsigned int nizUInt(char *ulaz)
{
	unsigned int i, broj = 0;
	for (i = 0; ulaz[i] != '\0'; ++i) {
		if (!isdigit(ulaz[i]))
			return -1;
		broj *= 10;
		broj += ulaz[i] - '0';
	}
	return broj;
}

float dijeljenje(int m, int n)
{
	return (float)m / n;
}