#include"funkcije.h"
#include<ctype.h>
#include<string.h>
int nizUInt (char *niz) {
	int i, broj=0;
	for (i=0; i<strlen(niz); ++i) {
		if (isdigit(niz[i])) {
			broj=broj*10+niz[i]-'0';
		} else {
			return -1;
		}
	}
	return broj;
}
float dijeljenje(int m, int n) {
	return m/(float)n;
}