#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <string.h>


/* Ispisuje zadani tag i izbacuje atribute iz taga, ako ih je bilo. */
void ispisiSkratiTag(char *tag, unsigned int dubina){
   unsigned int i;
   printf("\n");
   for(i=0; i<dubina; i++)
      printf(" ");
   printf("<");
   for(i=0; i<strlen(tag); i++){
      if (tag[i] == ' '){         
         printf(" %s", &tag[i]);
         tag[i] = 0;
         break;
      }else{
         putch(tag[i]);
      }
   }
   printf(">");
}

/* Provjerava da li je zatvoren zadani tag. */
int xmlOKrek(FILE *f, char *tag, unsigned int dubina){      
   char ctag[500] = {0};   
     
   do {          
      if (fscanf(f, "%*[^<]%*c%[^>]", ctag) != 1)
         return 0;      
      if (ctag[strlen(ctag)-1] == '/'){
         ispisiSkratiTag(ctag, dubina);
      }else if (*ctag  != '/'){
         ispisiSkratiTag(ctag, dubina);
         if (xmlOKrek(f, ctag, dubina+1) == 0)
            return 0;
      }else{
         break;
      }
   } while (1);
        
   
   if (*ctag  == '/' && (strcmp(tag, ctag+1) == 0)){
      ispisiSkratiTag(ctag, dubina);
      return 1;
   }else{
      printf("\nNe valja zavrsni tag %s", ctag);
      return 0;
   }    
}


/* Cita korjenski tag i poziva rekurzivnu funkciju */
int xmlOK(FILE *f){
   char tag[500] = {0};
   char *t;
   if (fscanf(f, "%100[^>]", tag) != 1) 
      return 0;
   else{      
      if ((t = strchr(tag, '<')) == NULL) return 0;      
      ispisiSkratiTag(++t, 1);      
      return xmlOKrek(f,t,1);
   }
      
}



int main(){
   FILE *f;
   f = fopen("d:\\temp\\recipee.xml", "r");
   if (f == NULL) {
      printf("\nPogreska kod otvaranja datoteke");
   } else {
      printf("\nXML je %s \n", (xmlOK(f) == 1) ? "OK" : "!OK" );
   }
   return 0;
}
