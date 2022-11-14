#include <stdio.h>

char *prviZnak(char *niz1, char *niz2)
{
	char *p = NULL;
	int i = 0, j = 0;

	while ((*(niz1 + i) != '\0') && !p) {			/*Uspoređuje svaki član prvog niza sa svakim članom drugog niza*/
		while(*(niz2 + j) != '\0' && !p) {			/*prekida izvođenje kada dođe do kraja ili ako pronađe isti član*/
			if (*(niz1 + i) == *(niz2 + j)) 
				p = (niz2 + j);
			++j;
		}
		j = 0;
		++i;
	}
	return p;
}

int brojRecenica(char *niz)
{
	int broj = 0;
	char *ptr;
	char znakovi[] = ".!?";
	ptr = prviZnak(znakovi, niz);					/*provjerava ima li uopće jedan od znakova*/
	if (ptr) {										/*ako pronađe gleda ima li još znakovi*/
		while (ptr) {
			ptr = prviZnak(znakovi, ptr + 1);		/*poziva funkciju prviZnak tako da započne s drugim nizom jedno mjesto poslije prošlog pronađenog znaka*/
			++broj;
		}
	}
	return broj;
}