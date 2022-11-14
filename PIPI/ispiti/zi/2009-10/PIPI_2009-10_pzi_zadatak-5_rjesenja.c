#include<stdio.h>
#include<stdlib.h>

int main()
{ 

    FILE *f;
    f=fopen("proba.bin","r");

    int niz[10]; //To im fali u onom šta oni imaju definirano!!!

    if (f == NULL) {
        printf("greška"); 
        exit(1);
    }
    
    fread(niz, sizeof(int) * 10, 1,f); /*učitava cijeli niz */
    
    niz[5] = niz[4]*niz[6];
    
    fseek(f, -5 * sizeof(int), SEEK_CUR);

    fwrite(&niz[5], sizeof(int), 1, f);
    
    fclose(f);

    return 0;

}
