#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(int argc, char *argv[]){
   
   FILE *ulaz, *izlaz;
   char *polje_znakova;//polje u koje se prepisuje sadrzaj ulazne datoteke
   char procitani_znak;//procitani znak iz datoteke
   int x,i=0,j,k,l,brojac_znakova=0;
   int edata[7], syndrome[3];
   int hmatrix[3][7] = {
                    1,0,0,0,1,1,1,
                    0,1,0,1,0,1,1,
                    0,0,1,1,1,0,1
                    };
   
   ulaz=fopen(argv[1],"r");
   izlaz=fopen(argv[2],"w+");
   
   //provjeravamo je li datoteka uspjesno otvorena
   if (ulaz==NULL){
         //printf("Greska kod otvaranja datoteke!");
         exit(1);
   }
   
   //brojenje znakova u ulaznoj datoteci
   while (1) {
      	procitani_znak = fgetc(ulaz);
      	if (procitani_znak == EOF) {
          	break;
	    }
	    brojac_znakova++;
   }
   //printf("Broj ucitanih znakova: %d", brojac_znakova);
   
   polje_znakova=(char *) malloc((brojac_znakova+1)*sizeof(char));//dinamicka alokacija memorije ovisno o broju znakova u ulaznoj datoteci
    
   fclose(ulaz);
   ulaz=fopen(argv[1],"r");
    
   //prepisivanje sadrzaja datoteke u polje_znakova
   while (1) {
      	procitani_znak = fgetc(ulaz);
      	//printf("%c", ucitani_znak);
      	if (procitani_znak == EOF) {
          	break;
	    }
	    else{
            polje_znakova[i]=procitani_znak;
            i++;     
             
        }
    }
    polje_znakova[brojac_znakova]='\n';
    //for(i=0;i<brojac_znakova;i++) printf("%c", polje_znakova[i]);
    //printf("\n");
      
   //dekodiranje
   for(k=0;k<6;k++){ //citamo 7 po 7 znakova
        for(l=0;l<7;l++){
            edata[l]=(polje_znakova[k*7+l]-48);//polje_znakova je char a edata int pa moramo oduzeti 48             
        }   

        //for(x=0;x<7;x++) printf("%d",edata[x]);
        
        //ispravljanje greške
        for(x=0;x<3;x++) syndrome[x]=0;
        for(i=0;i<3;i++){
              for(j=0;j<7;j++) syndrome[i]+=(edata[j]*hmatrix[i][j]);
              syndrome[i]=syndrome[i]%2;
        }
        
        for(j=0;j<7;j++) //zavrsava kad dodje do kraja edata ili kada nadje gresku
           if((syndrome[0]==hmatrix[0][j]) && (syndrome[1]==hmatrix[1][j])&& (syndrome[2]==hmatrix[2][j]))
              break;
        if(j!=7){
              //printf("\nGreska na bitu %d",j+1);
              edata[j]=!edata[j];
              //printf("\nIspravno bi trebalo biti : ");
              //for(i=0;i<7;i++)
              //printf("%d",edata[i]);
              //printf("\n");
        }
        //else printf("\nNema greske\n");//ako nije nasao gresku
        
        fprintf(izlaz,"%d",edata[2]);
        fprintf(izlaz,"%d",edata[4]);
        fprintf(izlaz,"%d",edata[5]);
        fprintf(izlaz,"%d",edata[6]);
        for(x=0;x<3;x++) syndrome[x]=0;
   }
    
    
   fclose(ulaz);
   fclose(izlaz);
   free(polje_znakova); 
   //getch();
   return 0;
}
