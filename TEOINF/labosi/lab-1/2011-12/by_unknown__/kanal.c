#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[])
{ 
    
srand ( time(NULL) );

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
char chr;

while (1)
{
//Uèitaj znak, ako se desi pogreška zamjeni ga sa suprotnim bitom
chr = fgetc (f);
if(chr == EOF)break;
else
{
    if(rand()%1000 == 0)
    {
    if(chr == 48)fprintf(fp, "1");else fprintf(fp, "0");
    }
    else
    {
    fprintf(fp, "%c", chr);
    }
}
}     
system("PAUSE");	
return 0;
}
