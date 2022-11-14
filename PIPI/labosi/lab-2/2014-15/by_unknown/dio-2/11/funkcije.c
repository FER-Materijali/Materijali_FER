#include"funkcije.h"
#include<stdlib.h>
char *nadjiPodniz(char *ulaz, char *uzorak) {
	int i, j=0;
	for (i=0; ulaz[i]!='\0'; ++i, j=0) {
		while (ulaz[i+j]==uzorak[j] && uzorak[j]!='\0') {
			++j;
		}
		if (uzorak[j]=='\0') {
			return ulaz+i;
		} 
	}
	return NULL;	
}
int izbaci(char *ulaz, char *uzorak) {
	int i=0, j=0;
	ulaz=nadjiPodniz(ulaz, uzorak);
	if (ulaz!=NULL) {
		while (uzorak[j]!='\0') {
			++j;
		}
	    while (ulaz[i+j]!='\0') {
		      ulaz[i]=ulaz[i+j];
		      ++i;
	    }
		ulaz[i]='\0';
	    return 1;
	} else {
		return 0;
	}
}
