#include <stdio.h>
#include <stdlib.h>

#include "algoritam.h"
#include "nadji.h"
#include "osnovni.h"

int poz=-1;

int main(void){
    FILE *fpodaci=NULL, *ftest=NULL, *fizlaz=NULL;
    char test_word[SIZE_LIMIT+1]={0}, outputter[ SIZE_LIMIT+1 ]={0};
    long blok=0;
    int prvi=0;
    if(!(fpodaci=fopen(DATOTEKA_PODACI, "rb"))){
        fprintf(stderr, "Ne mogu otvoriti datoteku %s za citanje\n", DATOTEKA_PODACI);
        exit(-1);
    }
    if(!(ftest=fopen(DATOTEKA_TEST, "r"))){
        fprintf(stderr, "Ne mogu otvoriti datoteku %s za citanje\n", DATOTEKA_TEST);
        exit(-1);
    }
    if(!(fizlaz=fopen(DATOTEKA_IZLAZ2, "w"))){
        fprintf(stderr, "Ne mogu otvoriti datoteku %s za pisanje\n", DATOTEKA_IZLAZ2);
        exit(-1);
    }
    while(fscanf(ftest, "%s", test_word)>0){
        fputs("***********\n", fizlaz);
        blok=-1;
        for(prvi=0; test_word[prvi] && test_word[prvi]=='_'; ++prvi);   /*otkriva se pozicija prvog poznatog slova u testnoj rijeci i sprema u varijablu poz*/
        if(poz!=prvi){
            poz=prvi;
            inicijaliziraj(fpodaci);
        }
        while(1){
            if((blok=nadji(test_word, blok, fpodaci))==-1) break;
            else{
                fseek(fpodaci, blok, SEEK_SET);
                if(fread(outputter, sizeof(outputter), 1, fpodaci)!=1){
                    printf("reading error\n");
                    return 1;
                }
                fputs(outputter, fizlaz);
                fputs("\n", fizlaz);
            }
        }
    }
    fclose(fizlaz);
    fclose(ftest);
    fclose(fpodaci);
    return 0;
}