#include <stdio.h>
#include <string.h>

float slicnostNizova(char* niz1, char* niz2, int ukupna_duljina){
    if (*niz1 == '\0' || *niz2 == '\0') return 0; //osnovni uvjet

    if (*niz1 == *niz2){
        return  ( 2.0 / ukupna_duljina + slicnostNizova(++niz1, ++niz2, ukupna_duljina) );
    } else {
        return slicnostNizova(++niz1, ++niz2, ukupna_duljina);
    }
}

int main(void){
    char niz1[20+1], niz2[20+1];

    printf("Unesi prvi niz: ");
    gets(niz1);

    printf("Unesi drugi niz: ");
    gets(niz2);

    printf("Slicnost prvog i drugog niza je: %f", slicnostNizova(niz1, niz2, strlen(niz1) + strlen(niz2)));

return 0;
}
