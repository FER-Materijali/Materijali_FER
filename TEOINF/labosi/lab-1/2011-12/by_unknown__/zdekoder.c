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
    int sym[7];
    int cnt=0;
    
    //Poèetak algoritma Hammingovog dekodiranja
    while (1)
    {
        //Uèitavanje 7 znaka u datoteci 
        sym[0] = fgetc (f);
        sym[1] = fgetc (f);
        sym[2] = fgetc (f);
        sym[3] = fgetc (f);
        sym[4] = fgetc (f);
        sym[5] = fgetc (f);
        sym[6] = fgetc (f);
        
        if (sym[0] == EOF || sym[1] == EOF ||sym[3] == EOF || sym[4] == EOF || sym[5] == EOF || sym[6] == EOF)
        {
        break;
        }
        else
        {
            //Ispravak grešaka
            //Odreðivanje mjesta simbola koji je pogrešan
            cnt = -1;
            if(sym[0]-48 != parity(sym[2]-48, sym[4]-48, sym[6]-48))
            {
            cnt +=1;
            }
            if(sym[1]-48 != parity(sym[2]-48, sym[5]-48, sym[6]-48))
            {
            cnt +=2;
            }
            if(sym[3]-48 != parity(sym[4]-48, sym[5]-48, sym[6]-48))
            {
            cnt +=4;
            }
            
            if(cnt != -1)
            {
               //Promjena simbola na kojem se dogodila pogreška    
               if(sym[cnt]-48 == 0) sym[cnt] = 49;
               else sym[cnt] = 48; 
            }
            
        }
        
        //Ispis u izlaznu datoteku
        fprintf(fp, "%c", sym[2]);
        fprintf(fp, "%c", sym[4]);
        fprintf(fp, "%c", sym[5]);
        fprintf(fp, "%c", sym[6]);
        
    }

system("PAUSE");	
return 0;
}
