#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int b=0,c,r=0;                         // deklariramo i inicijaliziramo varijable koje koristimo
    FILE *ulazkanala,*izlazkanala;         // deklariramo tokove podataka
    
    izlazkanala=fopen(argv[2],"w");        // otvaramo izlazni tok podataka
    if (izlazkanala == NULL){
               printf("Greška pri otvaranju\n");
               getchar();                  // u sluèaju nemoguænosti otvaranja javljamo grešku
               exit(-99);
               }
    ulazkanala=fopen(argv[1],"r");         // otvaramo ulazni tok podataka
    if (ulazkanala == NULL){
               printf("Greška pri otvaranju\n");
               getchar();                  // u sluèaju nemoguænosti otvaranja javljamo grešku
               exit(-99);
               }
   
    srand( time(NULL));                    // inicijaliziramo  generator sluèajnih brojeva
    while ((c=fgetc(ulazkanala)) != EOF) { // uèitavamo jedan po jedan znak do kraja ulazne datoteke
         b=(b+1)%1000;                     // brojimo broj uèitanih znakova u setovima po tisuæu.
         r=rand()%1000;                    // generiramo grešku na na mjestu r s vjerojatnošæu 1/1000
                                           // ukoliko se mjesto greške r poklapa s mjestom trenutno uèitanog bita b, radimo zamjenu bita
           if (b==r){                      
            if (c=='1')                    // iz 1 u 0
               c='0';
            else if (c=='0')               // iz 0 u 1
                 c='1';
                 }
                 
         fputc(c,izlazkanala);             // spremamo jedan po jedan znak u izlaznu datoteku
         }
    fclose(ulazkanala);                    // zatvaramo ulazni tok podataka
    fclose(izlazkanala);                   // zatvaramo izlazni tok podataka
    return 0;
}

