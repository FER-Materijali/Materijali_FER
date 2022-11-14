#include <ctype.h>

int string_to_int (char ulaz[]) {
	int integer = 0;
	int i;
	for (i=0; ulaz[i]!=0; i++) {
		if (!isdigit(ulaz[i])) return -1;
	}
	for (i=0; ulaz[i]!=0; i++) {
		integer = integer*10 + (ulaz[i] - 48);
	}
	return integer;
}

float division(int m, int n) {
	return (float)m/(float)n;
}