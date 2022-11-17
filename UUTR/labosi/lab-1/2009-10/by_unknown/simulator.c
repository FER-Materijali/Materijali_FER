#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    FILE *dat;
    FILE *def_a;
    
    void replace(char*tren_s){
         char potraga[100]={0},*kljuc;
         int i;
         
         rewind(def_a);
         while (!feof(def_a)){
               fgets (potraga, 100, def_a);
               kljuc=strtok(potraga,"-");
               if(strstr(kljuc,tren_s)){
                                   
                           for(i=0;kljuc[i]!='\0';i++){             
                               tren_s[i]=kljuc[i];       
                                                      }
                               tren_s[i]='\0';                       
                                        }  
                              }
}    
    int main(){
        char *pom;
        char pobuda[20]={0},potraga[100]={0};
        char tren_s[20]="S0",tren_pob[40]={0},prihvatljivo[20]={0};
        int  i,j;
                
        dat=fopen("ulazni_nizovi.txt", "r");
        def_a=fopen("definicija_automata.txt", "r");

       while (!feof(dat))             
       {         
          fscanf (dat, "%s", pobuda);
          tren_pob[0]='\0'; 
          printf("TRENUTNO STANJE: %s\n",tren_s);
          printf("POBUDA: %s\n",pobuda);   
          strcpy(tren_pob,tren_s);                           
          strcat(tren_pob,"-");
          strcat(tren_pob,pobuda);
          strcat(tren_pob,"-");

          rewind(def_a);
          j=0;
          while (!feof(def_a)){
               fgets (potraga, 100, def_a);

               if(strstr(potraga,tren_pob)){
                 j=1;
                 pom=strtok(potraga,"-");
                 pom=strtok(NULL,"-");
                 pom=strtok(NULL,"-");

                 i=0;
                 while(pom[i]!='\0'){
                        tren_s[i]=pom[i];
                        i++;       }   
                        tren_s[i-1]='\0';
                        
                 if(tren_s[i-2]==',')replace(&tren_s[0]);   
                 printf("SLJEDECE STANJE: %s\n",tren_s);
                                  
                 system("pause");
                 printf("\n");
                 break;
                                            }                                              
                              }
          if(j==0){
                 printf("Niz je pogresno zadan!\n");
                 system("pause");
                 return 0;
                   }                                               
        }                                
               printf("KONACNO STANJE: %s\n",tren_s);            
               rewind(def_a);
               strcpy(prihvatljivo,"#");
               strcat(prihvatljivo,tren_s);
        //       strcat(prihvatljivo,"\n");
               i=0;
               while (!feof(def_a)){
                    fgets (potraga, 100, def_a);
                    if(strstr(potraga,prihvatljivo)){
                                  i=1;
                                  printf("Stanje je prihvatljivo!\n");
                                  break;            
                                              }            
                                   }
               if(i==0)printf("Stanje nije prihvatljivo!\n");                    
        fclose(dat);
        fclose(def_a);
        system("pause");
        return 0;}
