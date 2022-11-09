/**
Napišite funkciju čiji je prototip:
char *ostaviSlova (string ulaz);
koja kao argument prima std::string ulaz, a vraća pokazivač na početak novog znakovnog niza za koji
je dinamički alocirana memorija u funkciji (možete koristiti operator new ili funkciju malloc). Novi niz treba
sadržavati samo znakove engleske abecede u istom poretku kao u ulaznom stringu.
Primjer: za ulazni string "asp12_i_ASP13", funkcija treba vratiti pokazivač na novi niz "aspiASP“.
Napišite glavni program u kojem će biti definiran string (varijabla ulaz) sadržaja "asp12_i_ASP13" te
ispisati znakovni niz koji je rezultat poziva funkcije ostaviSlova s argumentom niz.
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char *ostaviSlova (string ulaz){
    int charCount = 0;
    for (char c : ulaz){
        if (isalpha(c)){
                charCount++;
        }
}
    char* novi = new char[charCount];
    int i = 0;

    for (char c : ulaz) {
        if (isalpha(c)){
            novi[i] = c;
            i++;
        }
    }
    return novi;
}

int main() {

    string ulaz = "asp12_i_ASP13";
    char *niz = ostaviSlova(ulaz);

    for(int i = 0; i < strlen(niz); i++)
    {
        cout << niz[i];
    }

    delete[] niz;

    return 0;
}