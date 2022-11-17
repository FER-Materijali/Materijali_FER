#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void append(char* s, char c)                                   // napisana funkcija omoguæuje spajanje pojedinaènih znakova u string
{                                                              // što nam je olakšava rad
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
int main(int argc, char *argv[]) {
    int b=0,niz[10],hell=0,niz1[10],i=-1,j=0,k=0,max=0,Max;    // deklariramo i inicijaliziramo varijable
        FILE *tokpod3,*tokpod1,*tokpod2;                       // deklariramo tokove podataka
   
    struct TipStructa                                          // deklariramo potrebnu strukturu
{   
    char znak;
    char kod[256];

}ArrayStructChar[256];
struct TipStructa znakovi[256] = {{0}};
char s[256],c;s[0]='\0';
    tokpod1=fopen(argv[2],"r");
    if (tokpod1 == NULL){                                   // otvaramo ulazni tok podataka tokpod1 koji sadrži simbole i njihove kodove
               printf("Greška pri otvaranju\n");            // u sluèaju nemoguænosti otvaranja javljamo grešku
               exit(-99);
               }
    tokpod2=fopen(argv[1],"r");
    if (tokpod2 == NULL){                                   // otvaramo ulazni tok podataka tokpod2 koji sadrži kodiranu poruku
               printf("Greška pri otvaranju\n");            // u sluèaju nemoguænosti otvaranja javljamo grešku
               exit(-99);
               }        
    tokpod3=fopen(argv[3],"w");              
    if (tokpod3 == NULL){                                   // otvaramo izlazni tok podataka 
               printf("Greška pri otvaranju\n");            // u sluèaju nemoguænosti otvaranja javljamo grešku
               exit(-99);
               }         
    while ((c=fgetc(tokpod1)) != EOF){                      // uèitavamo jedan po jedan znak do kraja datoteke
          
          znakovi[j].znak=c;                                // spremamo simbol na njegovo odgovarajuæe mjesto u strukturi
          k=0;
          while ((c=fgetc(tokpod1)) != '\n'){               // nakon spremljenog simbola 
                if (c!='=') {
                            append(znakovi[j].kod,c);       // uèitavamo kod simbola 
                            k++;                            // brojimo duljinu koda
                }
                }
                if (k>=max) max=k;                          // spremamo najveæu duljinu koda
                j++;
          }   
     k=0; 
    while ((c=fgetc(tokpod2)) != EOF){                      // uèitavamo jedan po jedan znak iz tokpod2(kodiranu poruku)
          append(s,c);                                      // uèitani znak stavljamo u string
          if (k<=max){                                      // provjeravamo dali je broj znakova u stringu prekoraèio maksimalnu duljinu koda
          for (i=0;i<j;i++)   {                             // prolazimo kroz niz struktura
              int res = strncmp(s, znakovi[i].kod, 100);    // i usporeðujemo uèitani niz sa kodom
              if(res == 0)                         {
                 fputc(znakovi[i].znak,tokpod3);            // ukoliko pronaðemo odgovarajuæi niz koda simbol tog koda spremamo u odredišnu datoteku
                 s[0]='\0';                                 // inicijaliziramo string i duljinu koda
                 k=0;
                                                   }
                 
                              }
                              k++;                          // ukoliko nismo pronašli odgovarajuæi kodni niz povaæavamo broj uèitanih znakova
                   }
                  else {fputc('#',tokpod3); s[0]='\0';}     // ako premašimo maksimalnu duljinu koda stavljamo #
                                     }     
     if (k!=0) fputc('#',tokpod3);                          // ako po izvršenju petlje je preostao niz znakova manji od maksimalne duljine koda, ali nije pronaðen u nizu struktura takoðer stavljamo #
                                                            // ali nije pronaðen u nizu struktura takoðer stavljamo #
    fclose(tokpod1);                                        // zatvaramo tokove podataka
    fclose(tokpod2);
    fclose(tokpod3);
    return 0;
}
