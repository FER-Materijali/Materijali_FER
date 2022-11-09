#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dodaj(){
    char    ulaz[20+1];
    char*   izlaz;
    int     n = 0;

    izlaz = (char *) malloc(sizeof(char));
    izlaz[0] = '\0';

    do{
        printf("Unesi niz: ");
        gets(ulaz);
            if (ulaz[0] == '.' && ulaz[1] == '\0') break; // npr. niz ".m&m" ne oznacava da kraj izvodjenja :)
        if ( strlen(ulaz) > 20 ) exit (1);
        n += strlen(ulaz);
        izlaz = (char *) realloc (izlaz, (n+1) * sizeof(char));
        strcat(izlaz, ulaz);
    } while (1);

return izlaz;
}

int main()
{
char* x;
    x = dodaj();
    puts(x);
    free(x);
return 0;
}
