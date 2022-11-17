//simulator

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char stanje[15]="P";

int main () {
    
    FILE *ulazNiz, *definicija;
    ulazNiz=fopen("ulazniniz.txt","r");
    definicija = fopen("definicija.txt","r");
    char ulaz[200]={0},ulazDefinicija[200]={0}, provjera[200]={0};
    
    while (fscanf(ulazNiz,"%s",ulaz)!=EOF) {
          printf("ucitavam: %s\n", ulaz);
          sleep(1000);
           if (strstr(ulaz,"€")!=NULL){
                                printf("Stanje je ostalo nepromijenjeno: %s\n",stanje);
                                sleep(5000);
                                continue;
                                }
           strcpy(provjera,stanje);
           strncat(provjera,":",1);
           strncat(provjera,ulaz,strlen(ulaz));
           strncat(provjera,":",1);
           
           while (1) {
                 fscanf(definicija,"%s",ulazDefinicija);
                 
                 if (strstr(ulazDefinicija,provjera)==NULL) {
                                                            if (feof(definicija)){
                                                                                   printf("ne postoji prijelaz, kraj programa");
                                                                                   sleep(5000);
                                                                                   exit(0);
                                                                                   }
                                                            
                                                            continue;
                                                            }
                 else {
                      
                      strncpy(stanje,strrchr(ulazDefinicija,':')+1,strlen(strrchr(ulazDefinicija,':')));
                      printf("Trenutno stanje je: %s\n", stanje);
                      sleep(5000);
                      rewind(definicija);
                      break;
                      
                      }
                      }
                      }
    return 0;
}
