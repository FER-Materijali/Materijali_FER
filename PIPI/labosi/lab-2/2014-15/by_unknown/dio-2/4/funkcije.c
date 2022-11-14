#include"funkcije.h"
#include<string.h>
void generirajNiz(char *znakovi, int duljinaNiza, char *genNiz) {
    int i, len;
	len=strlen(znakovi);
	if (duljinaNiza<=len) {
		for (i=0; i<duljinaNiza; ++i) {
			*(genNiz+i)=*(znakovi+(len-duljinaNiza)+i);
		}
		*(genNiz+i)='\0';
	} else if (duljinaNiza>len) {
		for (i=0; i<duljinaNiza; ++i) {
			*(genNiz+i)=*(znakovi+(i%len));
		}
		*(genNiz+i)='\0';
	}
}
int dobarNiz (char *niz) {
	int i, j;
	for (i=0; i<strlen(niz)-1; ++i) {
		for (j=i+1; j<strlen(niz); ++j) {
			if (niz[i]==niz[j]) {
				return 0;
			}
		}
	}
	return 1;
}