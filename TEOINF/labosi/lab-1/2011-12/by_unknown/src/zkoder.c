#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int b=0,c,niz[10],niz1[10],i=-1,j=0;            // deklariramo i inicijaliziramo varijable koje koristimo
    FILE *tokpod,*tokpod1,*tokpod2;                 // deklariramo tokove podataka
    tokpod=fopen(argv[1],"r");                      // otvaramo ulazni tok podataka tokpod
    if (tokpod == NULL){
               perror("Greška pri otvaranju\n");
               exit(-99);                           // u sluèaju nemoguænosti otvaranja javljamo grešku
               }
    tokpod2=fopen(argv[2],"w");                     // otvaramo izlazni tok podataka tokpod2
    if (tokpod2 == NULL){
               printf("Greška pri otvaranju\n");
               exit(-99);                           // u sluèaju nemoguænosti otvaranja javljamo grešku
               }                   
               
    while ((c=fgetc(tokpod)) != EOF)                // uèitavamo jedan po jedan znak do kraja ulazne datoteke
          b++;                                      // brojimo koliko ima znakova u datoteci
          fclose(tokpod);                           // zatvaramo ulazni tok podataka tokpod
                                                    // postoje tri sluèaja u kojima je potrebno dodati nule kako bi koder mogao izvršiti kodiranje
          if (b%4==3){                              // u sluèaju kada nedostaje jedan znak dodajemo jednu nulu
          tokpod1=fopen(argv[1],"a");               // otvaramo tok podataka tokpod1    
             fputc('0',tokpod1);                    // dodajemo znak koji nedostaje
          fclose(tokpod1);                          // zatvaramo tok podataka tokpod1
          }  
          if (b%4==2){                              // u sluèaju kada nedostaju dva znaka dodajemo dvije nule
          tokpod1=fopen(argv[1],"a");               // otvaramo tok podataka tokpod1
             fputc('0',tokpod1);fputc('0',tokpod1); // dodajemo znakove  koji nedostaju
          fclose(tokpod1);                          // zatvaramo tok podataka tokpod1
          }  
          if (b%4==1){                              // u sluèaju kada nedostaju tri znaka dodajemo tri nule
          tokpod1=fopen(argv[1],"a");               // otvaramo tok podataka tokpod1
             fputc('0',tokpod1);fputc('0',tokpod1);fputc('0',tokpod1);// dodajemo znakove  koji nedostaju
          fclose(tokpod1);                          // zatvaramo tok podataka tokpod1
          }  
          
          
     tokpod=fopen(argv[1],"r");                     // otvaramo tok podataka tokpod
         
    while ((c=fgetc(tokpod)) != EOF){               // uèitavamo jedan po jedan znak do kraja ulazne datoteke
    i++;                                            
    niz[i]=c;                                       // uèitavamo èetiri znaka u niz jedan po jedan
    
    if (i==3){                                      // nakon što uèitamo èetiri znaka vršimo kodiranje
       niz1[0]=(niz[0]+niz[1]+niz[3]-144)%2+48;     // raèunamo prvi zaštitni bit ( raèunamo na naèin da uèitavamo ascii vrijednosti znakova te ih zbrojimo i dijelimo s ostatkom)
       niz1[1]=(niz[0]+niz[2]+niz[3]-144)%2+48;     // raèunamo drugi zaštitni bit
       niz1[2]=niz[0];                              // prvi podatkovni bit
       niz1[3]=(niz[1]+niz[2]+niz[3]-144)%2+48;     // raèunamo treæi zaštitni bit
       niz1[4]=niz[1];                              // drugi podatkovni bit
       niz1[5]=niz[2];                              // treæi podatkovni bit
       niz1[6]=niz[3];                              // èetvrti podatkovni bit
       
       for (j=0;j<7;j++)                            // set od sedam znakova zapisujemo u izlaznu datoteku
           fputc(niz1[j],tokpod2);
        i=-1;                                       // inicijaliziramo brojaè
       }
       
       }
       
    fclose(tokpod);                                 // zatvaramo ulazni tok podataka tokpod
    fclose(tokpod2);                                // zatvaramo izlazni tok podataka tokpod2
    return 0;
}
