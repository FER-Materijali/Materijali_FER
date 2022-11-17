#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int main(int argc, char *argv[]){
   
   FILE *ulaz, *izlaz;
   char *polje_znakova;//polje u koje se prepisuje sadrzaj ulazne datoteke
   char procitani_znak;
   int i=0,slucajan_broj,brojac_znakova=0;
   
   ulaz=fopen(argv[1],"r");
   izlaz=fopen(argv[2],"w+");
   
   //provjera je li ulazna datoteka ispravno ucitana
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
    
   srand(time(NULL));
   
    
   if(polje_znakova==NULL){
           //printf("\nPolje nije uspjesno alocirano!}");
           exit(1);
   }
   //else printf("\nPolje je uspjesno alocirano!\n");
   
   //prepisivanje sadrzaja ulazne datoteke u polje_znakova 
   while (1) {
      	procitani_znak = fgetc(ulaz);
      	//printf("%c", procitani_znak);
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
   
   //vjerojatnost za pojavu pogreske je je 1/1000
   //vjerojatnost da odaberemo odredeni broj medu 1000 brojeva je takoder 1/1000
   //stoga za svaki bit ulazne datoteke(odnosno polja u koje je ta datoteka ucitana)
   //nasumicno biramo broj u intervalu 0 do 999
   //ukoliko je izabrani broj 500 namjerno radimo pogresku na tom bitu
   for(i=0;i<24;i++){
         slucajan_broj=(rand()%1000);
         if(slucajan_broj==500){
             if(polje_znakova[i]=='0') polje_znakova[i]='1';
                 else polje_znakova[i]='0';           
         }                              
   }
   
   //zapisujemo polje_znakova sa potencijalnim greskama u izlaznu datoteku
   for(i=0;i<brojac_znakova;i++) fprintf(izlaz,"%c",polje_znakova[i]);
   
   fclose(ulaz);
   fclose(izlaz);
   free(polje_znakova);  
   //getch(); 
   return 0;    
}
