#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char niz[201], lijevi='\0', desni='\0', novired;
	printf("Upisite izraz koji zelite provjeriti: ");
	gets(niz);
	while (lijevi!='\\' && desni!='\\') {
            printf("Upisite lijevi i desni granicnik: ");
	    scanf("%c%c%c", &lijevi, &desni, &novired);
	    if (izrazJeIspravan(niz, lijevi, desni)) {
		   printf("\nIzraz %s JE ispravan obzirom na granicnike %c %c.\n\n", niz, lijevi, desni);
	    } else {
			printf("\nIzraz %s NIJE ispravan obzirom na granicnike %c %c.\n\n", niz, lijevi, desni);
		}
	}
	return 0;
}