#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <string.h>

int potez(int dg, int gg){
   int sredina;
   char odg;
   if (gg == dg) {
      printf("\nTrazeni broj je %d", dg);
      return 1;
   }else{
      sredina = (gg + dg)/2;
      printf("\nDa li je %d [D/V/M]?", sredina);
      odg = tolower(getche());
      if (odg == 'd'){
         printf("\n!! Trazeni broj je %d", sredina);
         return 1;
      }else if (odg == 'v'){
         return potez(sredina + 1, gg);
      }else if (odg == 'm'){
         return potez(dg, sredina - 1);
      }
   }

}


/*****************************************************************************/

int main(){
  potez(0, 100);
  system("pause"); 
}


/*****************************************************************************/
int slucajniBroj;

char student(int broj){
   /*
   static int slucajniBroj = 0;
   if (broj<0) slucajniBroj = rand()%101;
   */
   if (broj == slucajniBroj){
      return 'd';
   }else if (broj < slucajniBroj){
      return 'v';
   }else{
      return 'm';
   }
}

int potez2(int dg, int gg){
   int sredina;
   char odg;
   if (gg == dg) {
      printf("\nTrazeni broj je %d", dg);
      return 1;
   }else{
      sredina = (gg + dg)/2;      
      odg = student(sredina);
      printf("\n   Da li je %d - odgovor je %c", sredina, odg);
      if (odg == 'd'){
         printf("\n!! Trazeni broj je %d", sredina);
         return 1;
      }else if (odg == 'v'){
         return potez2(sredina + 1, gg);
      }else if (odg == 'm'){
         return potez2(dg, sredina - 1);
      }
   }

}

int main2(){
   int i;

   for(i=1;i<=10;i++){
      slucajniBroj = rand()%101;
      printf("\n\nZamisljen je %d\n", slucajniBroj);
      potez2(0, 100);  
   }
   system("pause"); 
}


/*****************************************************************************/

int potez3(int dg, int gg){
   int sredina;
   char odg;
   if (gg == dg) {
      // printf("\nTrazeni broj je %d", dg);
      return 1;
   }else{
      sredina = (gg + dg)/2;      
      odg = student(sredina);
      // printf("\n   Da li je %d - odgovor je %c", sredina, odg);
      if (odg == 'd'){
         // printf("\n!! Trazeni broj je %d", sredina);
         return 1;
      }else if (odg == 'v'){
         return 1 + potez3(sredina + 1, gg);
      }else if (odg == 'm'){
         return 1 + potez3(dg, sredina - 1);
      }
   }

}
/*****************************************************************************/

int main3(){
   int i, j, suma = 0, gg;



   for (j=1; j<=6;j++){
      suma = 0;
      gg = (int) pow(10, j);
      for(i=1;i<=100;i++){
         slucajniBroj = rand()%(gg+1);
         // printf("\n\nZamisljen je %d\n", slucajniBroj);
         suma += potez3(0, gg);  
      }
      printf("\nProsjecan broj pokusaja za gg=%d jest:%f", gg, suma / 100.);
   }

   system("pause");    
   return 0;
}



/*****************************************************************************/


int main4(){
   int i, j, suma = 0, gg;



   for (j=1; j<=40;j++){
      suma = 0;
      gg = (int)pow(2, j);
      for(i=1;i<=100;i++){
         slucajniBroj = rand()%(gg+1);
         // printf("\n\nZamisljen je %d\n", slucajniBroj);
         suma += potez3(0, gg);  
      }
      printf("\nProsjecan broj pokusaja za gg=%d jest:%f", gg, suma / 100.);
   }
   system("pause"); 
   return 0;
}
