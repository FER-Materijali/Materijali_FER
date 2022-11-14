#include"funkcije.h"
#include<ctype.h>
#include<string.h>
int brRijeci(char *tekst) {
	int i, br=0;
	for (i=0; i<strlen(tekst); ++i) {
	    if (isalnum(tekst[i])) {
			if (tekst[i+1]==' ' || tekst[i+1]==',' || tekst[i+1]=='.' || tekst[i+1]=='!' || tekst[i+1]=='?' || tekst[i+1]=='\0') {
				++br;
			}
		} else if (tekst[i]!=' ' && tekst[i]!=',' && tekst[i]!='.' && tekst[i]!='!' && tekst[i]!='?') {
			      return -1;
		  }
	}
	return br;
}
int izbaciBrojeve(char *tekst) {
	int i, j=0, promijenjen=0;
	for (i=0; i<strlen(tekst); ++i) {
		if (!isdigit(tekst[i])) {
			tekst[j++]=tekst[i];
		} else {
			promijenjen=1;
		}
	}
	tekst[j]='\0';
	if (promijenjen) {
		return 1;
	} else {
		return 0;
	}
}
