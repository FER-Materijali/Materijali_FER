#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <limits.h>

//Funkcija za odreðivanje mjesta u dijelu array-a int map[] gdje razlika zbroja frekvencija simbola, koje se dijele u dvije grupe, najbliža nuli.
int distance(int map[], int start, int length)
{
    //Inicijalizacija varijabla
    int a=0, b=0, i=0, j=0, N=0;
    int temp = INT_MAX;
    
    //Traženje razlike zbroja frekvencija simbola koja je najbliža nuli
    for(i=start; i<(length-1); i++)
    {
         a=0;
         b=0;
         
         //Zbrajanje frekvencija do granice
         for(j=start; j<i+1; j++)
         {
            a+=map[j];  
         }
         
         //Zbrajanje frekvencija iza granice
         for(j=i+1; j<length; j++)
         {
            b+=map[j];  
         }
         
         //Usporedba apsolutne vrijednosti razlike zbroja frekvencija sa varijablom temp
         //U varijabli temp se sprema razlika zbroja frekvencija koja je najbliža nuli
         if(abs(a-b) < temp)
         {
         temp = abs(a-b);
         //varijabla N je brojèanik koji se vraæa kako bi se znalo mjesto u arrayu gdje se treba napraviti 
         //granica radi Shannon-Fanoovog kodiranja
         N = i+1;         
         }
         
         
                  
    }
    return N;
}


//Rekurzivna funkcija koja stvara kodne rijeèi za dane frekvencije simbola pomoæu Shannon-Fanoovog kodiranja
void code(char *codemap, int map[], int start, int length, int rep)
{
     int i;
     //Pozivanje funkcije distance radi odreðivanja granice
     int N = distance(map, start, length);
         
         
         if (length - start > 1)
         {
                    
            //Upisivanje 1 iznad granice
            for(i=start; i<N; i++)
            {
                 codemap[i*250+rep] = '1';      
            }
         
            //Upisivanje 0 ispod granice
            for(i=N; i<length; i++)
            {
                 codemap[i*250+rep] = '0';        
            }
         
            rep++;
         
         
            if(N>=1 && (length-start > 1))
            {
                 //Rekurzivni poziv
                 code(codemap, map, start, N, rep);
                 code(codemap, map, N, length, rep);
            }
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
    
    //Inicijalizacija varijabla
    char symmap[250];
    char codemap[250][250];
    int countmap[250];
    
    int i =0;
    
    char *chr;
    char sym;
    
    //Raèunanje broja i upis simbola iz ulazne datoteke;
    while (1)
    {
        sym = fgetc (f); 
        if (sym == EOF)break ;
        else
        {
            //Traženje ulaznog simbola u mapi simbola
            chr=strchr(symmap, sym);
            if (chr != NULL)   
            {
               //U sluèaju da postoji ulazni simbol u mapi simbola poveæaj brojèanik za taj simbol za 1
               countmap[chr-symmap]++;
                     
            }
            else
            {
                //U sluèaju da ne postoji ulazni simbol u mapi simbola dodaj ga u mapu i poveæaj brojèanik za zaj simbol za 1
               symmap[i] = sym;
               symmap[i+1] = '\0';
               i++;
               countmap[strlen(symmap)-1] = 1;
                
            }
        }
    }
    
    
  
    
  
    //Inicijalizacija varijabla
    int temp, j;
    char ctemp;
    
    //Silazno sortiranje frekvencija simbola
    for(i=1; i<strlen(symmap); i++)
	{
		 temp = countmap[i];
		 ctemp = symmap[i];
		 j = i-1;
		 while(temp>countmap[j] && j>=0)
		 {
			 countmap[j+1] = countmap[j];
			 symmap[j+1] = symmap[j];
			 j = j-1;
		 }
		 countmap[j+1] = temp;
		 symmap[j+1] = ctemp;
	 }
     
     
     
    //Pozivanje funkcije koja puni mapu sa kodnim rijeèima
    code(&codemap[0][0], countmap, 0,  strlen(symmap), 0); 
    
    //Zatvaranje datoteka
    fclose(f);
    
    //Ponovno uèitavanje izvorišta radi prevoðenja simbola u kodne rijeèi u izlaznu datoteku
    f = fopen(*argv,"r");
    if(f==NULL)
    { 
           printf("Nemoguce otvoriti datoteku: %s...", *argv);
           return 0;
    }
    //Otvaranje i stvaranje izlazne datoteke 
    *argv ++;
    FILE* fp = fopen(*argv,"w");
    if(fp==NULL)
    { 
           printf("Nemoguce otvoriti datoteku: %s...", *argv);
           return 0;
    }
    //Ispis izlaznog niza (Prijevod simbola u kodne rijeèi)
    while (1)
    {
        sym = fgetc (f); 
        if (sym == EOF)break;
        else
        {
            //Traženje ulaznog simbola u mapi simbola
            chr=strchr(symmap, sym);
            if (chr != NULL)   
            {
            //Ispis u izlaznu datoteku
            fprintf(fp, "%s", codemap[(chr-symmap)]);        
            }
        }
    }
    //Zatvaranje datoteka
    fclose(f);
    fclose(fp);
    
    //Otvaranje i stvaranje izlazne datoteke za ispis kodnih rijeèi
    *argv++;
    fp = fopen(*argv,"w");
    if(fp==NULL)
    { 
           printf("Nemoguce otvoriti datoteku: %s...", *argv);
           return 0;
    }
    
    //Ispis kodnih rijeèi
    for(i=0; i<strlen(symmap); i++)
    { 
        fprintf(fp, "%c=%s\n", symmap[i], codemap[i]);
    }
    //Zatvaranje datoteka
    fclose(fp);
    
  system("PAUSE");	
  return 0;
}



