#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define POMAK 1

int Provjeri (char *ulaz){
    FILE *fp;
    
    fp=fopen("definicija.txt","r");
    
    char zapis[200];
    
    
    do {
        
         fscanf(fp,"%s",zapis);
         
         if (strstr(&zapis[0],ulaz)!=0) {
                                        
                   return 0;
                   
                   }
                   
                   }
                   
    while (!feof(fp));
    
    fclose(fp);
    
    return 1;
    
}                     

void resursizacija(char *niz, char *resursi, int dubina, int brRes, char *stranica, FILE *fp) {
     
     char spremnik2[200000]={0}, zapis[20000]={0};
     char *string,resurs2[20000]={0},*resurs3,testresursa[20000]={0},a[20000]={0};
     int i,k;
     
     if (dubina == 1) {
                strcpy (resurs2,resursi);
    
                string = strtok(niz,",");
                
                while (string != NULL)
    {
           
    if(k==brRes){
                           strncat(&spremnik2[0],",",1);
                           
                           }      
    
      for (k=0;k<brRes;k++) {
          
            strcpy(&zapis[0],string);  
            strncat(&zapis[0],":",1);   
            resurs3=strstr(resurs2,",");
              
              if (resurs3!=NULL) {
                                 
                                 strncpy(&testresursa[0],resurs2,strlen(resurs2)-strlen(strstr(resurs2,",")));
                                 
                                 if (strstr(string,testresursa)!=NULL) {
                                                                      
                                 strcpy(a,strstr(resurs2,",")+1);
                                 strcpy(resurs2,a);
                                                         
                                                          continue;
                                 
                                                          }
                                               
                                 else {         
                                 
                                 strncat(&zapis[0],resurs2,strlen(resurs2)-strlen(strstr(resurs2,",")));
                                 strncat(&zapis[0],":",1);
                                 strcat(&zapis[0],stranica);
                                 strcpy(a,strstr(resurs2,",")+1);
                                 strcpy(resurs2,a);
                                 
                                 }
                                 
                                 }
              else {
                   
                   strncpy(&testresursa[0],resurs2,strlen(resurs2));
                   
                   if (strstr(string,testresursa)!=NULL) {
                                                    
                                                    continue;
                                                    
                                                    }
                                                    
                   strncat(&zapis[0],resurs2,strlen(resurs2));
                   strncat(&zapis[0],":",1);
                   strcat(&zapis[0],stranica);
                   
                   }
                           
               strcat(&zapis[0],"\n");
               fputs(&zapis[0], fp);                  
              
              }
              
              strcpy(resurs2,resursi);
              string=strtok(NULL,",");
              
             }
              
                return;
                                
                }
    
    strcpy (resurs2,resursi);
    string = strtok(niz,",");
     
     while (string != NULL)
    {
           
    if(k==brRes){
                           strncat(&spremnik2[0],",",1);
                           
                           }      
    
      for (k=0;k<brRes;k++) {
          
            strcpy(&zapis[0],string);
            strncat(&zapis[0],":",1);
            resurs3=strstr(resurs2,",");
              
              if (resurs3!=NULL) {
                                 
                                 strncpy(&testresursa[0],resurs2,strlen(resurs2)-strlen(strstr(resurs2,",")));
                                 
                                 if (strstr(string,testresursa)!=NULL) {
                                                                      
                                 strcpy(a,strstr(resurs2,",")+1);
                                 strcpy(resurs2,a);
                                 continue;
                                 
                                                                        }
                                               
                                 else {            
                                 
                                 strncat(&zapis[0],resurs2,strlen(resurs2)-strlen(strstr(resurs2,",")));
                                 strncat(&zapis[0],":",1);
                                 strcat(&zapis[0],string);
                                 strncat(&zapis[0],resurs2,strlen(resurs2)-strlen(strstr(resurs2,",")));
                                 strcat(&spremnik2[0],string);
                                 strncat(&spremnik2[0],resurs2,strlen(resurs2)-strlen(strstr(resurs2,",")));
                                 strncat(&spremnik2[0],",",1);
                                 strcpy(a,strstr(resurs2,",")+1);
                                 strcpy(resurs2,a);
                                 
                                 }
                                 
                                 }
              else {
                   strncpy(&testresursa[0],resurs2,strlen(resurs2));
                   
                   if (strstr(string,testresursa)!=NULL) {
                                                    
                                                    continue;
                                                    
                                                    }
                                                    
                   strncat(&zapis[0],resurs2,strlen(resurs2));
                   strncat(&zapis[0],":",1);
                   strcat(&zapis[0],string);
                   strncat(&zapis[0],resurs2,strlen(resurs2));
                   strcat(&spremnik2[0],string);
                   strncat(&spremnik2[0],resurs2,strlen(resurs2));
                   }
                 
               strcat(&zapis[0],"\n");
               fputs(&zapis[0], fp);                  
              
              }
              strcpy(resurs2,resursi);
              
             string=strtok(NULL,",");
             }
             i=strlen(spremnik2);         
             *(spremnik2+i-1)='\0';
             
             resursizacija(spremnik2,resursi,(dubina-1), brRes, stranica, fp);         
         
     }
     
void generirajiZapisiPocetno(char *ulaz, FILE *fp){
    
     char zapis[200];
     
     strcpy(&zapis[0],"P:");
     strncat(&zapis[0],strstr(&ulaz[0],"www"),((strstr(&ulaz[0],"|"))-(strstr(&ulaz[0],"www"))));
     strcat(&zapis[0],":");
     strcat(&zapis[0],"ucit");
     strncat(&zapis[0],strstr(&ulaz[0],".")+1,3);
     strcat(&zapis[0],"\n");
     fputs(&zapis[0], fp);
     
}

void generirajPrijelazeResursa(char *ulaz, FILE *fp){
     
     char *j,*stranica,*crta,zapis[200]={0};
     char resursi[200]={0};
     char resursi2[200]={0};
     char resursi3[200]={0};
     char stranicaUnos[200]={0};
     int i,k,brResursa=0;
     
     crta=strstr(ulaz,"|")+1;
     crta=strstr(crta,"|")+1;
     
     i=strlen(crta);
     
     k=strlen(ulaz);
     
     i=k-i;
     
     for (i;i<k;i++) {
         if (*(ulaz+i)==',') {
                             brResursa++;
                             }
                             }
      
     brResursa++;
          
     if (brResursa==1) {
                       
                        strcpy(&zapis[0],"ucit");
                        strncat(&zapis[0],strstr(&ulaz[0],".")+1,3);
                        strcat(&zapis[0],":");
                        strcat(&zapis[0],strrchr(&ulaz[0],'|')+1);
                        strcat(&zapis[0],":");
                        strncat(&zapis[0],strstr(&ulaz[0],".")+1,(strrchr(&ulaz[0],'.') - strstr(&ulaz[0],"."))-1);
                        strcat(&zapis[0],"\n");
                        
                        
     if(Provjeri(&zapis[0])) {
                             
                             fputs(&zapis[0],fp);
                                  
                                  }
                                  
                                  }
     
      else {    
           
         strcpy(&resursi[0],strrchr(&ulaz[0],'|')+1);
         strcpy(&resursi2[0],&resursi[0]);
         stranica=strstr(ulaz,".")+1;
         strncpy(stranicaUnos,stranica,strlen(stranica) -strlen(strstr(stranica,".")));
                         
          for (k=0;k<brResursa;k++) {
              
              strcpy(&zapis[0],"ucit");
              strncat(&zapis[0],strstr(&ulaz[0],".")+1,3);
              strcat(&zapis[0],":");
              
              do {
                  
                  char a[200]={0};
                  char *b;
                  
                  b=strstr(resursi,",");
                  
                  if (b!=NULL){
                                                                 
                  strncat(&zapis[0],resursi,strlen(resursi)-strlen(strstr(resursi,",")));
                  strncat(&zapis[0],":",1);
                  strncat(&zapis[0],stranica,3);
                  strncat(&zapis[0],resursi,strlen(resursi)-strlen(strstr(resursi,",")));
                  strncat(&resursi3[0],stranicaUnos,3);
                  strncat(&resursi3[0],resursi,strlen(resursi)-strlen(strstr(resursi,",")));
                  strncat(&resursi3[0],",",1);
                  strcat(a,strstr(resursi,",")+1);
                
                  strcpy(resursi,a);
                  
                  }
                  
                  else {
                       
                  strncat(&zapis[0],resursi,strlen(resursi));
                  strncat(&zapis[0],":",1);
                  strncat(&zapis[0],stranica,3);
                  strncat(&zapis[0],resursi,strlen(resursi));
                  strncat(&resursi3[0],stranicaUnos,3);
                  strncat(&resursi3[0],resursi,strlen(resursi));
                  }
                  
                  break;
                  
                  }
                  
                  while(1);
                                  
              strcat(&zapis[0],"\n");
              fputs(&zapis[0], fp);
                
                                     }
                                     
                resursizacija(resursi3,resursi2,brResursa-1,brResursa, stranicaUnos, fp);             
            
       }
       }

void generirajPrijelazeStranica(char *ulaz, FILE *definicija) {
     
     char poveznice[200]={0}, zapis[200]={0}, test[200]={0}, test2[200]={0};
     FILE *ulazni;
     int i;
     ulazni=fopen("ulaz.txt","r");
     char *rastav;
     strncpy(poveznice,strstr(ulaz,"|")+1,strlen(strstr(ulaz,"|"))-strlen(strrchr(ulaz,'|'))-1);
     strcat(poveznice,"");
     rastav = strtok(poveznice,",");
     
     do {
                         strcpy(test,rastav);
                         strncat(test,":",1);
                         do {
                             fscanf (ulazni, "%s", test2);
                             if (strstr(test2,test)!=NULL){
                                                           
                                                       break;
                                                       
                                                        }
                                                        
                                                        }
                         while (!feof(ulazni));
                         strncpy(zapis,strstr(ulaz,".")+1, strlen(strstr(ulaz,"."))-strlen(strrchr(ulaz,'.'))-1);
                         strncat(zapis,":",1);
                         strncat(zapis,strstr(test2,"www"),strlen(strstr(test2,"www"))-strlen(strstr(test2,"|")));
                         strncat(zapis,":",1);
                         strcat(zapis,"ucit");
                         strncat(zapis,strstr(test2,".")+1,3);
                         strncat(zapis,"\n",2);
                         fputs(&zapis[0], definicija);
                         for (i=0; i<200;i++) {
                             zapis[i]=0;
                             }
                         
                         rewind(ulazni);
                         rastav=strtok(NULL,",");
                         }
                         while(rastav!=NULL);
                             
}

int main () {
    
    FILE *fp;
    FILE *fp2;
    
    fp2=fopen("definicija.txt","w");
    fp=fopen("ulaz.txt","r");
    
    
    char ulaz[200];
    
    do {
        
    fscanf (fp, "%s", ulaz);
    generirajiZapisiPocetno(&ulaz[0],fp2);
    
    }
    while(!feof(fp));
    rewind(fp);
    do {
       
        fscanf (fp, "%s", ulaz);  
    
        generirajPrijelazeResursa(&ulaz[0],fp2);
       
        }
        
      while (!feof(fp));
      rewind(fp);

    do {
       
        fscanf (fp, "%s", ulaz);  
    
        generirajPrijelazeStranica(&ulaz[0],fp2);
       
        }
       
        while (!feof(fp));
    
    fclose(fp);
    fclose (fp2);
    
    
    
    return 0 ;
}

