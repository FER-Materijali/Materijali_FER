#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char ulaz[201] = {0};
	char rijec[202] = {0}; /*skuzi logiku*/
	int i, j;
	short saz;
	
	printf("Upisite znakovni niz: ");
	scanf(" %200[^\n]", ulaz);
	
	for (i=0; ulaz[i]!=0; i++) {
		if (i == 0 || ulaz[i-1] == ' ') {
			for (j=0; ulaz[i+j]!=' ' && ulaz[i+j]!=0; j++) {
				rijec[j] = ulaz[j+i];
			}
			printf("%s ", rijec);
			saz = sazetak(rijec); 
			printf("%d ", saz);
			dodajZnak(rijec, saz);
			printf("%s\n", rijec);
			for (j=0; j<202; j++) rijec[j] = 0;	/*ono kad imas vise od 12 pa moras cistit za sobom*/
		}
	}
	
	return 0;
}