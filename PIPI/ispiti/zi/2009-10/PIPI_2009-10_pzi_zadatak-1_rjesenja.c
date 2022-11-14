#include <stdio.h>
#include <string.h>

#define MAX 100 + 1

int zamjena(char *niz, const char *zamijenisto, const char *zamijenisa)
{
    int brojZamjena = 0;

    niz = strstr(niz, zamijenisto);

    if (niz != NULL) {
        niz += 3;
    }

    for (; (niz = strstr(niz, zamijenisto)) != NULL; niz += 3) {
        brojZamjena++;
        strncpy(niz, zamijenisa, strlen(zamijenisa));
    }

    return brojZamjena;    

}

int main(int argc, char *argv[])
{
    char niz[MAX], zamijeni[MAX], zamijeniSa[MAX], znak;
    
    scanf("%[^\n]%c%[^\n]%c%[^\n]", niz, &znak, zamijeni, &znak, zamijeniSa);

    if (zamjena(niz, zamijeni, zamijeniSa) > 0) {
        puts(niz);
    }

    return 0;

}
