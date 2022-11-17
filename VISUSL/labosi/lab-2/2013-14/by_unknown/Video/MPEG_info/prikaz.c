#include <stdio.h>
#include <string.h>                
#include <stdlib.h>
#include <signal.h>

char *poruka[5] ={"set title \"Karakteristike mpeg streama\"\n" ,
                 "set xlabel \"Broj okvira\"\n",
                 "set ylabel \"Broj bajtova u pojedinom okviru \" \n",
                 "pause -1 \" Za nastavak pritisni enter\"\n",
                };
void prekid()
{
  puts("Kraj rada!");
  exit(1);
}  
int main(int argc,char *argv[])
{
   FILE *in;
   int dg,gg;
   char buf[256];
   int i = 0;
   if(argc != 2)
   {
    printf("Upotreba: ./prikaz ime_datoteke_za_gnuplot\n");
    exit(EXIT_FAILURE);
   }    
  for(;;)
  {
   if ((in = fopen("TEMP.DAT", "w")) == NULL)
   {
      fprintf(stderr, "Cannot open input file.\n");
      return 1;
   }
    printf("Donja granica >>");
    scanf("%s",&buf);
    dg = atoi(buf);
    printf("Gornja granica >>");
    scanf("%s",&buf);
    gg = atoi(buf);
    puts("Za kraj rada Ctrl-c");
    fputs(poruka[0],in); 
    fputs(poruka[1],in);
    fputs(poruka[2],in);
    sprintf(buf,"plot[%d:%d] '%s' with lines\n",dg,gg,argv[1]);
    fputs(buf,in);
    fputs(poruka[3],in);
    fclose(in);
    signal(SIGINT,prekid);
    system ("gnuplot TEMP.DAT");
  }
   return 0;
}

