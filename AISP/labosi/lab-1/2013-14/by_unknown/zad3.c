/*
Ovaj program je vise nego potrebno iskomentiran.
To je zapravo lose komentiranje programa, ali svrha mu je da Vi sto bolje razumijete ga i naucite nesta iz njega.
Mjenjajte konstante (pocetna_vrijednost i mnozitelj) , pokusajte dobiti bolji rezultat tj. manje preljeva.
Kôd je dopusteno i preporuceno izmjenjivat, copy-pasteat bla bla..
*/

#include <stdio.h>
#include <stdlib.h>

#define BLOK 4096L //velicina bloka
#define N 100000 // broj zapisa
#define C ( (int) ( BLOK / sizeof(struct zapis)) ) //broj zapisa u pretincu
#define M ( (int) ( N / C * 1.3 )) //broj pretinaca
#define POCETNA_VRIJEDNOST 8249 // za ove vrijednosti sam dobio
#define MNOZITELJ 14 // najbolje rezultate (6)

struct zapis {
    char naziv[30+1];
    char ip[15+1];
    };
struct zapis domena, ulaz, pretinac[C]; // globalne varijable koje ce se koristiti kroz program

unsigned long Hash(char * niz)
{
    unsigned long hash = POCETNA_VRIJEDNOST;
    char c;

    while (c = *niz++)
        hash = MNOZITELJ * hash + c;

return hash;
}

int BrojPreljeva(FILE *ulaz){
    int i,upisan,preljev, poc;
    int broj_preljeva = 0;
    int* polje;

    polje = (int*) calloc(M,sizeof(int)); //inicijaliziraj polje i postavi sve elemente na vrijednost 0
    fseek(ulaz, 0L, SEEK_SET);

    while (fscanf (ulaz, "%s %s", domena.naziv, domena.ip) != EOF){ // citaj iz datoteke odk ne dodjes do kraja
        i = Hash(domena.naziv) % M; // odredi adresu
        poc = i;
        upisan = 0; // zapis nije upisan u datoteku
        preljev = 0; // nije doslo do preljeva
        do{
            if (polje[i] < C){
                ++polje[i];
                if (preljev == 1) ++broj_preljeva;
                upisan = 1; // zapis je upisan
            }
            if (upisan) break; //ako je zapis upisan, idi na iduci zapis

            i = (i + 1) % M ; // predji ciklicki u iduci pretinac
            preljev = 1; // doslo je do preljeva

        } while( i != poc);
          if ( (i == poc) && (upisan == 0) ) return -10000; //nisu svi podatci upisani
    }
    free(polje);
return broj_preljeva;
}


int Upis(struct zapis ulaz, FILE *fhashTablica){ //vraca 0 ako nije uspjela zapisati sve zapise, inace vraca 1
    int i,j,poc;
    i = Hash(ulaz.naziv) % M;
    poc = i;
    do{
       fseek(fhashTablica, i*BLOK, SEEK_SET);
       fread (pretinac, sizeof(pretinac), 1, fhashTablica);
       for (j = 0; j < C; ++j){
            if(pretinac[j].naziv[0] != '\0'){ //Ako zapis nije prazan
                if (strcmp (pretinac[j].naziv, ulaz.naziv) == 0) { //Ako je upravo taj zapis vec upisan
                    return 1;
                }
            } else { // Ako je mjesto slobodno
                pretinac[j] = ulaz;
                fseek (fhashTablica, i*BLOK, SEEK_SET);
                fwrite(pretinac, sizeof(pretinac), 1, fhashTablica);
                return 1;
            }
       }
       i = (i + 1) %M ; // ciklicki prijelaz na iduci pretinac
    } while( i != poc);

return 0;
}

int main(void){
    FILE* du; //datoteka ulazna
    FILE* di; // datoteka izlazna

    du = fopen("domene.txt", "r");
        if (du == NULL) printf("Ne mogu otvoriti datoteku \"domene.txt\".");
    di = fopen("binarna.dat", "w+b");
        if (di == NULL) printf("Ne mogu otvoriti datoteku \"binarna.dat\".");

    while (fscanf (du, "%s %s", ulaz.naziv, ulaz.ip) != EOF){ // citaj iz "domene.txt" redak po redak dok ne dodjes do kraja
        if(!Upis(ulaz,di)) printf("Tablica puna. Nema mjesta za daljnji upis.");
    }
    printf("Zapis u Hash tablicu je obavljen!\n");
    printf("Broj ocekivanih preljeva s konstantama POCETNA VRIJEDNOST = %d i MNOZITELJ = %d: %d", POCETNA_VRIJEDNOST, MNOZITELJ, BrojPreljeva(du));

    fclose(du);
    fclose(di);
return 0;
}
