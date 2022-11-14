#include"funkcije.h"
void najcesci (char *niz, char *najc1, char *najc2) {
	int i, max1=0, max2=0, frekv[26]={0};
	for (i=0; niz[i]!='\0'; ++i) {
		if (niz[i]>='A' && niz[i]<='Z') {
			++frekv[niz[i]-'A'];
		} else if (niz[i]>='a' && niz[i]<='z') {
		           ++frekv[niz[i]-'a'];
		}
	}
	for (i=0; i<26; ++i) {
		if (frekv[i]>=max1) {
			max1=frekv[i];
			*najc1=i+'A';
		} else if (frekv[i]>=max2) {
			max2=frekv[i];
			*najc2=i+'A';
		}
	}
}