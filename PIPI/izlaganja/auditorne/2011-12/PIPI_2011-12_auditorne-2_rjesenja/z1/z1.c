#include <stdio.h>
#include <string.h>

#define MAKS 40

char *trazi(char *niz, char *podniz) {
    int i, podnizLen = strlen(podniz), nasao;
    //Dok god nismo dosli do kraja niza u kojem trazimo nesto
    for (; niz[0] != '\0'; niz += 1) {
        //Pretpostavimo da smo nasli pod niz
        //jer nam je lakse pretpostavit da smo nasli nego da nismo nasli
        //U vecini situacija cete morat nesto pretpostavit
        //i ovisno o tome kako pretpostavite, imat cete vise/manje
        //kodiranja
        nasao = 1;
        //Za svaki znak iz podniza dok god ne dodjemo do kraja
        //podniza ili niza (Bitno!)
        for (i = 0; i < podnizLen && niz[0] != '\0'; i++) {
            //U slucaju da se znamenke razlikuju, sa sigurnoscu mozemo reci
            //da se podniz ne nalazi na trenutnoj poziciji te stoga mozemo 
            //traziti dalje. Radi toga nam treba ova zastavica nasao
            //da mozemo znati jesmo li ili nismo nesto nasli
            if (podniz[i] != niz[i]) { 
                nasao = 0;
                break ;
            }
        }
        //Ako smo nasli podniz, tj for petlja
        //se odvrtila bez da je ispunjen if uvjet
        //znamo da smo nesto nasli
        if (nasao == 1) { return niz; }
    }
    //Ako je i druga for petlja zavrsena do kraja
    //i nije se dogodio return, znamo da podniz nije pronadjen
    //te stoga vracamo NULL
    return NULL;
}

int main(void) {

    FILE *cenzurirano = fopen("cenzurirano.txt", "r");
    FILE *datoteka = fopen("ulaz.txt", "r");
    FILE *izlaz = fopen("izlaz.txt", "w");

    char buffer[MAKS + 1];
    char cenzuriranoBuffer[MAKS + 1];
    char *temp;
    
    int i;
    
    //Dok god mozemo ucitati jednu rijec iz
    //datoteke ulaz.txt
    //Prisjetite se da %s cita do bilo koje prazine (novi red, razmak, tab...)
    while (fscanf(datoteka, "%s", buffer) == 1) {
        //Dok god ima rijeci za cenzurirat u datoteci cenzurirano.txt
        while (fscanf(cenzurirano, "%s", cenzuriranoBuffer) == 1) {
            //Probaj pronaci podniz u nizu
            //Ako smo uspjeli, onda znaci da moramo cenzurirat nasu rijec
            if ((temp = trazi(buffer, cenzuriranoBuffer)) != NULL) {
                //Za duljinu niza cenzurirano buffer moramo postaviti *
                //buduci da je tako dugacka ta rijec
                //Isto tako znamo da temp pokazuje na taj podniz u velikom nizu
                //Te stoga mozemo temp odmicat i samo mjenjat element na prvoj
                //poziciji
                for (i = strlen(cenzuriranoBuffer); i > 0; i --, temp += 1) {
                    temp[0] = '*';
                }
                //Izlazimo iz while petlje. Zasto? Pa napravili smo ovdje dvije pretpostavke
                //koje na zalost nisam definirao u zadatku a to su
                //da u jednoj rijeci se nece vise puta pojavit isti podniz
                //i nece biti vise od jednog podniza kojeg treba cenzurirat
                break ;
            }
        }
        //Prvo resetiramo kursor datoteke na pocetak 
        //tako da opet mozemo citati cenzurirane rijeci
        fseek(cenzurirano, 0, SEEK_SET);
        //Isto tako zapisujemo nasu rijec natrag
        //E sad, nisam htio otezat zadatak pa da se ocuvaju white spaceovi, tj
        //potpuna struktura datoteke, vec sam samo rekao, uvijek ce bit samo
        //jedan razmak
        fprintf(izlaz, "%s ", buffer);
    }
    
    fclose(cenzurirano);
    fclose(datoteka);
    fclose(izlaz);
    
    return 0;
}