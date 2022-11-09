#include <stdio.h>
#include <stdlib.h>

#include "algoritam.h"
#include "nadji.h"
#include "osnovni.h"

int main(void){
    FILE *fpodaci=NULL, *ftest=NULL, *fizlaz=NULL;
    char test_word[SIZE_LIMIT+1]={0}, outputter[SIZE_LIMIT+1]={0};
    long blok=0;
    if(!(fpodaci=fopen(DATOTEKA_PODACI, "rb"))){
        fprintf(stderr, "Ne mogu otvoriti datoteku %s za citanje\n", DATOTEKA_PODACI);
        exit(-1);
    }
    if(!(ftest=fopen(DATOTEKA_TEST, "r"))){
        fprintf(stderr, "Ne mogu otvoriti datoteku %s za citanje\n", DATOTEKA_TEST);
        exit(-1);
    }
    if(!(fizlaz=fopen(DATOTEKA_IZLAZ, "w"))){
        fprintf(stderr, "Ne mogu otvoriti datoteku %s za pisanje\n", DATOTEKA_IZLAZ);
        exit(-1);
    }
    inicijaliziraj(fpodaci);	/*pozove funkciju inicijaliziraj, funkcija odredi velicine potrebne za rad ostalih funkcija*/
    while(fscanf(ftest, "%s", test_word)>0){	/*cita ulaznu rijec iz datoteke ftest i sprema je u test_word*/
        blok=0;	/*resetira pocetnu adresu pretrazivanja*/
        fputs("***********\n", fizlaz);	/*upisuje svakom iteracijom petlje zadani niz znakova izmedu rijeci u datoteci fizlaz*/
        if(test_word[0]!='_') blok=nadji_blok(test_word[0], fpodaci);	/*ako je pocetni znak razlicit od _ koristimo bin. search da nademo pocetni blok za pretragu*/
        while(1){
            if((blok=nadji(test_word, blok, fpodaci))==-1) break;	/*slijedna pretraga datoteke fpodaci od zadanog pocetnog bloka, blok moze bit 0 u slucaju da je prvi znak nepoznat, pa moramo cijelu datoteku slijedno pretraziti*/
            else{
                fseek(fpodaci, blok, SEEK_SET);	/*pozicioniranje na adresu zapisa koji sadrzi elemente ulazne rijeci*/
                if(fread(outputter, sizeof(outputter), 1, fpodaci)!=1){	/*citanje zapisa u buffer, ako nije uspjelo ispise "reading errror" i vrati 1*/
                    printf("reading error\n");
                    return 1;
                }
                fputs(outputter, fizlaz);	/*zapise sadrzaj buffera i \n u datoteku fizlaz*/
                fputs("\n", fizlaz);
            }
            blok+=sizeof(element);	/*nova pocetna adresa je adresa sjedeceg zapisa*/
        }
    }
    fclose(fizlaz);
    fclose(ftest);
    fclose(fpodaci);
    return 0;
}