#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 
int main(int argc, char *argv[]){
    int i=0,j,k,n,x,y,z;
    int brojac_znakova=0;
    int encoded[8],syndrome[3];
    FILE *ulaz,*izlaz;
    char ucitani_znak, data[5];
    char *polje_znakova;
    char gmatrix[4][8]={"0111000","1010100","1100010","1110001"};//matrica za generiranje Hammingovog koda
    
    izlaz=fopen(argv[2],"w+"); 
    ulaz=fopen(argv[1],"r"); 
    
    //provjera je li ulazna datoteka uspješno otvorena
    if (ulaz==NULL){
         //printf("Greska kod otvaranja datoteke!");
         exit(1);
    }
    
    while (1) {
      	ucitani_znak = fgetc(ulaz);
      	if (ucitani_znak == EOF) {
          	break;
	    }
	    brojac_znakova++;
    }
    //printf("Broj ucitanih znakova: %d", brojac_znakova);
    
    fclose(ulaz);
    ulaz=fopen(argv[1],"r");
    
    polje_znakova=(char *) malloc((brojac_znakova+1)*sizeof(char));
    
    if(polje_znakova==NULL){
           //printf("\nPolje nije uspjesno alocirano!}");
           exit(1);
    }
    //else printf("\nPolje je uspjesno alocirano!\n");
    
    while (1) {
      	ucitani_znak = fgetc(ulaz);
      	//printf("%c", ucitani_znak);
      	if (ucitani_znak == EOF) {
          	break;
	    }
	    else{
            polje_znakova[i]=ucitani_znak;
            i++;     
             
        }
    }
    polje_znakova[brojac_znakova]='\n';
    //for(i=0;i<brojac_znakova;i++) printf("%c", polje_znakova[i]);
    //printf("\n");
    for(z=0;z<7;z++) encoded[z]=0;
    
    for(i=0;i<(brojac_znakova/4);i++){
        for(j=0;j<4;j++){
           data[j]=polje_znakova[i*4+j];               
        }
        data[4]='\n';
        //for(k=0;k<4;k++) printf("%c", data[k]);
        //printf(":");
        
        //kodiranje
        for(x=0;x<7;x++){
           for(y=0;y<4;y++) encoded[x]+=((data[y]-'0')*(gmatrix[y][x]-'0'));
           encoded[x]=encoded[x]%2;
           //printf("%d",encoded[x]);
           fprintf(izlaz,"%d",encoded[x]);
        }                               
        //printf("\n");
        encoded[7]='\n';
        for(z=0;z<7;z++) encoded[z]=0;                              
    }
    
    //printf("\n");
    //for(i=0;i<brojac_znakova;i++) printf("%c", izlazno_polje[i]);
    
    //getch();
    fclose(ulaz);
    fclose(izlaz);
    free(polje_znakova);
    return 0;
}
