#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>



int main(int argc, char *argv[])
{
    //Uèitavanje izvorišta
    *argv++;
    FILE *fa = fopen (*argv, "r");
    if(fa==NULL)
    { 
           printf("Nemoguce otvoriti datoteku: %s...", *argv);
           return 0;
    }
    
    //Inicijalizacija varijabla
    char codemap[250][250];
    char symmap[250];
    char sym[250];
    int i = 0;
    int j = 0;
    
    
    //Uèitavanje datoteke sa kodnim rijeèima
    *argv++;
    FILE* f = fopen(*argv,"r");
    
    //Uèitavanje kodnih rijeèi u array codemap
    //Uèitavanje simbola u array symmap
    if (f != NULL)
    {
       char line[250];
       //Uèitavanje linije teksta u string line
       while (fgets(line, sizeof line, f) != NULL)
       {
             symmap[j] = line[0];
             for(i=2; i<strlen(line); i++)
             { 
                  codemap[j][i-2] = line[i];
             }
       j++;
       }
    }
    else
    {
        printf("Nemoguce otvoriti datoteku: %s...", *argv);
        return 0; 
    }
    
    
    
  
    //Otvaranje i stvaranje izlazne datoteke
    *argv ++;
    FILE* fp = fopen(*argv,"w");
    
    //Algoritam za uèitavanje i pronalazak kodnih rijeèi, te ispis simbola u izlaznu datoteku 
    while(1)
    {
        i=0;
        j=0;
                
        while(1)
        {
                sym[i] = getc(fa);
                if(sym[i] == EOF)break;
                while(1)
                {
                        //Traženje simbola pomoæu kodnih rijeèi
                        if(codemap[j][i] == sym[i])
                        {
                            break;
                        }
                        else
                        {
                            j+=1;
                        }
                        
                            
                }
                if(strlen(codemap[j])-2 == i)break;
                i+=1;
        }
        //U sluèaju greške ispiši #
        if(sym[i] == EOF)
        {
            if(i>0) fprintf(fp, "#");     
            break;      
        }
        fprintf(fp, "%c", symmap[j]);
        
          
          
    }
    
    
    
       
   
    
    
  fclose (f);
  system("PAUSE");	
  return 0;
}
