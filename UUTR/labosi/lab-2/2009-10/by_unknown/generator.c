#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    FILE *dat;
    FILE *def_a;

void rekurzija (char *stanje, char *ime, FILE *def_a) {
     char *prvi_zarez;
     char tmp[20], prijelaz[20], *sljed_stanje;
     int i=0, j=0, z=0, x=0, br_zarez=0, t=0;
     
     while (stanje[i]!='\0') {
                if (stanje[i]==',') br_zarez++;
                i++;
     }
    
     prvi_zarez = strchr (stanje, ',');
     i=prvi_zarez - stanje;

     if (br_zarez==1) {
        sljed_stanje=ime;
        for (i+=1; i<strlen(stanje); i++) {
            prijelaz[t]=stanje[i];
            t++;
        }
        prijelaz[t]='\0';
        fprintf (def_a, "%s-%s-%s\n", stanje, prijelaz, sljed_stanje);
        printf ("%s-%s-%s\n", stanje, prijelaz, sljed_stanje);
        return;
                      }
     
     for(i; i<strlen(stanje); i++) {
            if (stanje[i]==',') {
               x=0;
               for (j=0; j<i; j++) {
                   tmp[x]=stanje[j];
                   x++;
               }
               
               for (j=i+1; stanje[j]!=',' && j<strlen(stanje); j++) {
                   prijelaz[z]=stanje[j];
                   z++;
               }
               prijelaz[z]='\0';
               z=0;
               
               for (j; j<=strlen(stanje); j++) {
                   tmp[x]=stanje[j];
                   x++;
               }
               fprintf (def_a, "%s-%s-%s\n", stanje, prijelaz, tmp);
               printf ("%s-%s-%s\n", stanje, prijelaz, tmp);
               rekurzija (tmp, ime, def_a);
            }
     }
}

int poveznice(){
    int a=0,y,z,i,j,k,h,br_red=0;
    char tmp[100]={0},*broj, *ime, *resursi, *veze,*pom,*prijelaz;
    char ulaz[10][100]={0},name[20]={0},cross[20]={0},red[100]={0},poljeMB_2[100]={0};
    
    
    rewind(dat);
    fgets (poljeMB_2, 100, dat);    
    
    while (!feof(dat)) {
          fgets (red, 100, dat);
          br_red++;
    }
    rewind (dat);  
    fgets (poljeMB_2, 100, dat);    
    
    while (!feof(dat)) {
          fgets (ulaz[a], 100, dat);
          i=strlen(ulaz[a]);
          if(a!=br_red-1) ulaz[a][i-1]='\0';
          a++;
    }
        
    for(a=0;a<10 && ulaz[a][0]!=0;a++){
             
             for(j=0;j<100&&ulaz[a][j]!=0;j++){    
                 tmp[j]=ulaz[a][j];
                                            }
                 tmp[j]='\0';
             
                 broj=strtok(tmp,":|");
                 ime=strtok(NULL,":|"); 
                 for (k=0; k<20 && ime[k]!='\0'; k++) {
                     name[k]=ime[k];
                 } 
                 name[k]='\0';               
                 veze=strtok(NULL,":|");
                 resursi=strtok(NULL,":|");
                 
                 
                 z=strlen(veze)/2+1;

                 for(k=0;k<z;k++){
                          if(k==0){
                               pom=strtok(veze,",");
                               y=atoi(pom);
                               
                               for(h=0;h<100&&ulaz[y-1][h]!=0;h++){
                                              tmp[h]=ulaz[y-1][h];                     
                                                                   }
                                              tmp[h]='\0';
                               broj=strtok(tmp,":");
                               prijelaz=strtok(NULL,"|");
                               for (h=0; h<20 && prijelaz[h]!='\0'; h++) {
                                   cross[h]=prijelaz[h];
                               } 
                               cross[h]='\0';
                               fprintf(def_a, "%s-%s-%s,\n",name, cross,broj);  
                               printf("%s-%s-%s,\n",name, cross,broj);  
                          }                         
                          else {
                               pom=strtok(NULL,",");
                               y=atoi(pom); 
                               
                               for(h=0;h<100&&ulaz[y-1][h]!=0;h++){
                                              tmp[h]=ulaz[y-1][h];                     
                                                                   }
                                              tmp[h]='\0';                               
                               broj=strtok(tmp,":|");
                               prijelaz=strtok(NULL,":|");
                               for (h=0; h<20 && prijelaz[h]!='\0'; h++) {
                                   cross[h]=prijelaz[h];
                               } 
                               cross[h]='\0';
                               fprintf(def_a, "%s-%s-%s,\n",name, cross,broj);
                               printf("%s-%s-%s,\n",name, cross,broj);  
                               }                                            
                                                   }
                 }
    return 0;
    }

int main() {
    int a=0,i,br_red=0;
    char *broj=0, *ime=0, *resursi=0, *veze=0;
    char red[100]={0},ulaz[10][100]={0}, stanje[20]={0}, tren_stanje[20]="S0",
    poljeMaxB[100]={0},poljeMB_2[100]={0};
    dat=fopen("ulaz.txt", "r");
    def_a=fopen("definicija_automata.txt", "r+");
    
    
    //prepisati MAXBACK u definiciju automata
    fgets (poljeMaxB, 100, dat);
    fprintf(def_a,"%s", poljeMaxB);
    printf("%s", poljeMaxB);
    
    fprintf(def_a,"#%s\n", tren_stanje);    
    printf("#%s\n", tren_stanje);
    
    rewind (dat);
    fgets(poljeMB_2, 100, dat);
            
    while (!feof(dat)) {
          fgets (red, 100, dat);
          br_red++;
    }
    rewind (dat);
    fgets (poljeMB_2, 100, dat);    

    while (!feof(dat)) {
          fgets (ulaz[a], 100, dat);
          i=strlen(ulaz[a]);
          if(a!=br_red-1) ulaz[a][i-1]='\0';
          a++;
    }
    a=0;   
    while (ulaz[a][0]!=0) {
        broj=strtok(ulaz[a], ":|");
        ime=strtok(NULL, ":|");
        veze=strtok(NULL, ":|");
        resursi=strtok(NULL, ":|");
        
        strcpy (stanje, broj);
        strcat(stanje,",");
        strcat (stanje,resursi);
        
        fprintf (def_a, "%s-%s-%s\n", tren_stanje, ime, stanje);
        printf ("%s-%s-%s\n", tren_stanje, ime, stanje);
        rekurzija(stanje, ime, def_a);
        fprintf (def_a, "#%s\n", ime);
        printf ("#%s\n", ime);
        a++;
    }
    i=poveznice();
    fprintf(def_a," ");
    fclose (def_a);
    fclose (dat);
    system ("pause");
    return 0;
}
