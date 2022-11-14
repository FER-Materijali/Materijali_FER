#include"funkcije.h"
#include<string.h>
void brojacGranicnihZnakova (char *znNiz, char lijevi, char desni, int *brLijevih, int *brDesnih) {
	int i;
	for (i=0; i<strlen(znNiz); ++i) {
		if (znNiz[i]==lijevi) {
			++*brLijevih;
		} else if (znNiz[i]==desni) {
			++*brDesnih;
		}
	}
}
int izrazJeIspravan(char *znNiz, char lijevi, char desni) {
	int brlijevih=0, brdesnih=0;
	brojacGranicnihZnakova(znNiz, lijevi, desni, &brlijevih, &brdesnih);
	if (brlijevih==brdesnih) {
		return 1;
	} else {
		return 0;
	}
}