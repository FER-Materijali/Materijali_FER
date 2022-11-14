#include <ctype.h>

void brojac(int stat[], char ulaz[]) {
	int i;
	for (i=0; ulaz[i]!=0; i++) {
		if (isalpha(ulaz[i])) {
			if (islower(ulaz[i])) stat[ulaz[i]-97] += 1;
			else if (isupper(ulaz[i])) stat[ulaz[i]-65] +=1;
		}
	}
	return;
}