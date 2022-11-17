#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


//Funkcija raèunanja pariteta za hamingov koder
//Vraæa 0 ili 1 ovisno o zbroju 3 bita uèitana u a, b i c
int parity(int a, int b, int c)
{
   if((a+b+c == 0) || (a+b+c == 2))
   {
   return 0;
   }
   else
   {
   return 1;
   }    
}

int main(int argc, char *argv[])
{  
    //Uèitavanje izvorišta
    *argv++;
    FILE* f = fopen(*argv,"r");
    if(f==NULL)
    { 
           printf("Nemoguce otvoriti datoteku: %s...", *argv);
           return 0;
    }
    //Otvaranje i stvaranje izlazne datoteke 
    *argv++;
    FILE* fp = fopen(*argv,"w");
    if(fp==NULL)
    { 
           printf("Nemoguce otvoriti datoteku: %s...", *argv);
           return 0;
    }
    //Inicijalizacija varijabla
    int i;
    char sym[4];
    char ham[7];
    
    //Poèetak algoritma Hammingovog kodiranja
    while (1)
    {
        //Uèitavanje 4 znaka u datoteci 
        sym[0] = fgetc (f); 
        sym[1] = fgetc (f);
        sym[2] = fgetc (f);
        sym[3] = fgetc (f);
        
        //Ako ima manje od 4 znaka koja se kodiraju dopiši nule na kraj
        if (sym[0] == EOF && sym[1] == EOF && sym[2] == EOF && sym[3] == EOF)
        {
           break;
        }
        else if (sym[1] == EOF && sym[2] == EOF && sym[3] == EOF)
        {
           sym[1] = 48;
           sym[2] = 48;
           sym[3] = 48;
        }
        else if (sym[2] == EOF && sym[3] == EOF)
        {
          sym[2] = 48;
          sym[3] = 48;
        }
        else if (sym[3] == EOF)
        {
          sym[3] = 48;
        }
       //Algoritam Hammingovog kodera
       ham[0] = parity(sym[0]-48, sym[1]-48, sym[3]-48);
       ham[1] = parity(sym[0]-48, sym[2]-48, sym[3]-48);
       ham[2] = sym[0]-48;
       ham[3] = parity(sym[1]-48, sym[2]-48, sym[3]-48);
       ham[4] = sym[1]-48;
       ham[5] = sym[2]-48;
       ham[6] = sym[3]-48;
        
         //Ispis u izlaznu datoteku
         for(i=0; i<7; i++)
         { 
              fprintf(fp, "%d", ham[i]);
         }
   } 
    
    
    
  system("PAUSE");	
  return 0;
}
