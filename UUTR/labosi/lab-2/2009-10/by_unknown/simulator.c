#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    FILE *dat;
    FILE *def_a;
    FILE *stog;
    FILE *stog2;
    void replace(char*tren_s){
         char potraga[100]={0},*kljuc;
         int i;
         
         rewind(def_a);
         while (!feof(def_a)){
               fgets (potraga, 100, def_a);
               kljuc=strtok(potraga,"-");
               if(strstr(kljuc,tren_s)){                                   
                           for(i=0;kljuc[i]!='\0';i++){             
                               tren_s[i]=kljuc[i];    }
                               tren_s[i]='\0';                       
                                        }  
                              }
}    
    int main(){
        int z=0;
        char *pom;
        char pobuda[20]={0},potraga[100]={0},copy[100]={0};
        char tren_s[20]="S0",tren_pob[40]={0},prihvatljivo[20]={0},poljeMaxB[10]={0};
        int  i,j,MaxB,back,br_stog=0,broj;
                
        dat=fopen("ulazni_nizovi.txt", "r");
        def_a=fopen("definicija_automata.txt", "r");
        stog=fopen("stog.txt","w+");

//ucitat prvi red i saznat kolki je MaxBack
        fgets(poljeMaxB,10,def_a);
        strtok(poljeMaxB, ":");
        MaxB=atoi(strtok(NULL, ":"));

       while (!feof(dat))             
       {         
          fscanf (dat, "%s", pobuda);
          if(!pobuda[0]){
                         printf("Nema pobude!\nKONACNO STANJE:S0\nNiz je prihvatljiv!\n");
                         system("pause");
                         return 0;}
          tren_pob[0]='\0';

           printf("TRENUTNO STANJE: %s\n",tren_s);
          
//stavi na stog
        if(z!=1){
          strcpy(prihvatljivo,"#");
          strcat(prihvatljivo,tren_s);
          rewind(def_a);
          while (!feof(def_a)){
                    fgets (potraga, 100, def_a);
                    if(strstr(potraga,prihvatljivo)){
                                  fprintf(stog,"%s\n",tren_s);
                                  br_stog++;
                                  break;    }        
                               }  
                               }
                               z=0;        
/////////////////////////           
          printf("POBUDA: %s\n",pobuda);
//ako je back napravi sto treba
          if(strstr(pobuda,"back")){
                  strtok(pobuda,"_");
                  broj=atoi(strtok(NULL,"_"));
                  if(broj>MaxB){printf("Pobuda nije u abecedi!\n");}
                  else{
                       stog2=fopen("stog2.txt","w+");
                       br_stog-=broj;
                       z=1;
                       if (br_stog<1) br_stog=1;
                       rewind(stog);
                       for(i=0;i<br_stog;i++){
                             fgets(copy,100,stog);
                             fprintf(stog2,"%s",copy);
                             for(j=0;j<100;j++)copy[j]='\0';
                                              }
                       fclose(stog);
                       stog=fopen("stog.txt","w+");                       
                       rewind(stog);
                       rewind(stog2);                       
                       for(i=0;i<br_stog;i++){
                             fgets(copy,100,stog2);
                             fprintf(stog,"%s",copy);
                             for(j=0;j<100;j++)copy[j]=0;
                                              }
                       fclose(stog2);                                             
                       } 
                  rewind(stog);      
                  for (i=0; i<br_stog-1; i++) {
                      fgets(tren_s,20,stog);
                      
                  }  
                  for (i=0; i<20; i++) {
                      tren_s[i]='\0';
                  }           
                  fgets (tren_s,20,stog);
                  pom=strtok(tren_s, "\n");
                  for (i=0; i<20; i++) {
                      tren_s[i]=pom[i];
                  }
                  printf("SLJEDECE STANJE: %s\n", tren_s); 
                  system("pause");        // OVDJE TI PRINTA NOVO TRENUTNO STANJEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                  printf("\n");
                  continue;                  
                                    }
          
          
                     
         
             
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
        fclose(stog);

        system("pause");
        return 0;}
