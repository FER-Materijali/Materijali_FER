#include <stdio.h>
int main (void) {
	/* S tipkovnice učitati niz znakova 
	(string) x koji sigurno neće biti dulji od 60 znakova.

	Znamo sa sigurnošću da nam treba polje od 60 znakova */

	char x[60];
	int len=0, i=0;
	printf("unesite niz\n");
	gets(x);
	/* određivanje duljine niza */
	while (x[len] != '\0') {
		len++;
	}

	if (len < 10) {
		printf("prekratak niz\n");
		return 0;
	}
	/* čitaj od početka pa dok ne dođeš do kraja stringa */
	while (x[i] != '\0') {
		/* ako je znak na parnoj adresi eg niz[0], niz[2]..
		provjeri je li pisano malim slovom, ako ne razumijete ovo
		pogledajte ascii tablicu */
		if ((i%2==0) && (x[i] >= 'a') && (x[i] <= 'z')) 
			printf("%c\n", x[i]);
		/* šetaj dalje */
		i++;
	}
	return 0;
}