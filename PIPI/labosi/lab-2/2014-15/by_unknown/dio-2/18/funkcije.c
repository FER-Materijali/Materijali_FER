#include"funkcije.h"
#include<stdlib.h>
#include<time.h>
int HammingovaUdaljenost (char *s, char *t) {
	int razlika=0, i;
	for (i=0; s[i]!='\0'; ++i) {
		if (s[i]!=t[i]) {
			++razlika;
		}
	}
	return razlika;
}
void odrediSlucajniNiz(int n, char *s) {
	int i, broj;
	static int seedset=0;
	if (!seedset) {
	   srand((unsigned)time(NULL));
	   seedset=1;
	}
	for (i=0; i<n; ++i) {
		broj=rand()%(2*26);
		if (broj>=0 && broj<=25) {
			s[i]=broj+'A';
		} else {
			s[i]=broj-26+'a';
		}
	}
	s[i]='\0';
}