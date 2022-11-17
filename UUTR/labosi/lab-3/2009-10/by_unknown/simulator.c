#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *def;
FILE *ulaz;
    
int main(){    
    int i=0,glava=0;
    char traka[100]={0},tmp[10],potraga[10];
    char trenutno_stanje=0,pocetno_stanje='A',novo_stanje=0,upis=0,pomak=0;
    
    def=fopen("definicija_turingovog_stroja.txt", "r");
    ulaz=fopen("pocetno_stanje_trake.txt", "r");
    
    while (!feof(ulaz)){
        fscanf(ulaz,"%c",&traka[i]);  
        i++;
                    }
    i--;
    for(i=i;i<50;i++){
        traka[i]='P';
                     }
    printf("Trenutni izgled trake:%s\n",traka);
    rewind(ulaz);
    i=0;
    trenutno_stanje=pocetno_stanje;  
    printf("Trenutno stanje:%c\n",trenutno_stanje);                             
    printf("Pobuda:%c\n",traka[glava]); 
    while(trenutno_stanje!='I'){                                              
         system("pause");
         tmp[0]=trenutno_stanje;                       
         tmp[1]='-';                       
         tmp[2]=traka[glava];
         tmp[3]='|';
         tmp[4]='\0';
         
         while (!feof(def)){
               fgets (potraga, 10, def);
                      novo_stanje='\0';
                      upis='\0';
                      pomak='\0';
               if(strstr(potraga,tmp)){
                          novo_stanje=potraga[4];
                          upis=potraga[6];
                          pomak=potraga[8];
                          break;
                                       }               
                            }
        if (pomak=='\0') {
                        printf("\nNiz nije ispravno zadan!\n");
                        system ("pause");
                        return 0;
                        }
        rewind(def);                        
        trenutno_stanje=novo_stanje;
        traka[glava]=upis;                        
        printf("Trenutni izgled trake:%s\n",traka);
        printf("Trenutno stanje:%c\n",trenutno_stanje); 
        if(pomak=='R'){glava++;}
        else{if(pomak=='L'){glava--;}}  
        printf("Pobuda:%c\n",traka[glava]);                   
                                }        
    fclose(def);
    fclose(ulaz);
    system("pause");
    return 0;}
