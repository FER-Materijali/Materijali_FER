#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definiram strukturu stanje u kojoj spremam prijelaze
typedef struct {
char tr_stanje[3]; 
   char sljed_stanje[3];
   char tr_znak[5];
   char sljed_znak[5];
   char smjer[5];
} stanje;
//ispis prijelaza
void ispis_stanje(stanje tren, FILE *file)
{
 fprintf (file,"S(%s,%c,%c,%c,%c) -> (%s,%c,%c,%c,%c,%c,%c,%c,%c)\n", tren.tr_stanje,tren.tr_znak[0],tren.tr_znak[1],tren.tr_znak[2],tren.tr_znak[3],
 tren.sljed_stanje, tren.sljed_znak[0], tren.smjer[0], tren.sljed_znak[1], tren.smjer[1], tren.sljed_znak[2], tren.smjer[2], tren.sljed_znak[3], tren.smjer[3]);
}
//inicijaliziram stanje stavljam sve na null
void inicijalizacija (stanje *tren) {
   int i;
   for (i=0;i<3;i++) {
       tren->tr_stanje[i]=NULL;
       tren->sljed_stanje[i]=NULL;
   }
   for (i=0;i<5;i++) {
       tren->tr_znak[i]=NULL;
       tren->sljed_znak[i]=NULL;
       tren->smjer[i]=NULL;
   }
}
//èitam prijelaze iz datoteke
stanje ucitavanje_st (char *dat,FILE *file) {
   int i,j=0;  
   stanje tren;
   inicijalizacija(&tren);
   tren.tr_stanje[0]=dat[0];
   tren.tr_stanje[1]=dat[1];
   tren.sljed_stanje[0]=dat[11];   
   tren.sljed_stanje[1]=dat[12];
   for (i=3;i<=9;i=i+2) tren.tr_znak[j++]=dat[i];
   j=0;
   for (i=14;i<=26;i=i+4) tren.sljed_znak[j++]=dat[i];
   j=0;
   for (i=16;i<=28;i=i+4) tren.smjer[j++]=dat[i];   
   return tren;
   ispis_stanje(tren,file);
}
// funkcija za nalaženje novog stanja s obzirom na trenutno stanje i znakove na trakama
stanje pronadi_iduce_stanje (char stanje1[3],char znak1,char znak2,char znak3,char znak4, FILE *file) {
   int i,z=0,z1=1;
   FILE *dat1;
   char dat[100];
   stanje tren;
   inicijalizacija(&tren);
   if ((dat1=fopen("prijelazi.txt","r"))==NULL) {
      printf("Ne mogu otvoriti datoteku\n");
      scanf("%%");
      exit(-1);
   }
   fscanf (dat1,"%s",&tren.tr_stanje);
   while (z!=1) {
      if (fscanf(dat1,"%s",&dat)!=EOF) {
         tren=ucitavanje_st(dat,file);
         if ((stanje1[0]==tren.tr_stanje[0]) && (stanje1[1]==tren.tr_stanje[1])&&(tren.tr_znak[0]==znak1)&&(tren.tr_znak[1]==znak2)&&(tren.tr_znak[2]==znak3)&&(tren.tr_znak[3]==znak4)) {
            z=1;
            ispis_stanje(tren,file);
         }
      }
      else break;
   }

   fclose(dat1);
   if (z==1) return (tren);
   else {
        tren.sljed_stanje[2]='?';
        return tren;
   }
}
//ispisivanje traka
void ispis_trake (char *traka1,char *traka2,char *traka3,char *traka4,int n, int *glava, FILE *file) {
   int i;
   fprintf(file,"\n");
   for (i=0;i<n;i++) {
       if (glava[0]==i) fprintf(file,">");
       fprintf(file,"%c",traka1[i]);
   }
   fprintf(file,"\n");
   for (i=0;i<n;i++) {
       if (glava[1]==i) fprintf(file,">");
       fprintf(file,"%c",traka2[i]);
   }
   fprintf(file,"\n");
   for (i=0;i<n;i++) {
       if (glava[2]==i) fprintf(file,">");
       fprintf(file,"%c",traka3[i]);
   }
   fprintf(file,"\n");
   for (i=0;i<n;i++) {
       if (glava[3]==i) fprintf(file,">");
       fprintf(file,"%c",traka4[i]);
   }
   fprintf(file,"\n\n");
}

//glavna funkcija
int main () {
    char *traka1,*traka2,*traka3,*traka4,ulaz[100],trenstanje[3];
    int i,j=0,k=0,n,glava[4];
    stanje st;
    FILE *datoteka,*file;
    inicijalizacija(&st);
    printf ("Unesite niz na traku : ");
    gets(ulaz);
    n=((strlen(ulaz)/10)+1)*10;
    if ((traka1=(char*)malloc((n+1)*sizeof(char)))==NULL) {
       printf ("Ne mogu stvoriti polje!");
       exit (-1);
    }
    if ((traka2=(char*)malloc((n+1)*sizeof(char)))==NULL) {
       printf ("Ne mogu stvoriti polje!");
       exit (-1);
    }
    if ((traka3=(char*)malloc((n+1)*sizeof(char)))==NULL) {
        printf ("Ne mogu stvoriti polje!");
        exit (-1);
    }
    if ((traka4=(char*)malloc((n+1)*sizeof(char)))==NULL) {
       printf ("Ne mogu stvoriti polje!");
       exit (-1);
    }
    for (i=0;i<=n;i++) {
        traka1[i]='B';
        traka2[i]='B';
        traka3[i]='B';
        traka4[i]='B';
    }
    // do sada priprema TS
    //prepisivanje ulaza
    for (i=0;i<strlen(ulaz);i++) {
        traka1[i]=ulaz[j++];
    }
    for (i=0;i<4;i++) glava[i]=0;
    if ((datoteka=fopen("prijelazi.txt","r"))==NULL) {  
       printf("Ne mogu otvoriti prijelazi.txt\n");
       exit(-1);
    }
    if ((file=fopen("izlaz.txt","w"))==NULL) {  
       printf("Ne mogu stvoriti izlaz.txt\n");
       exit(-1);
    }
    for (i=0;i<3;i++) trenstanje[i]=NULL;
    fscanf (datoteka,"%s",&trenstanje);
    fclose (datoteka);
    //poèetak simulacije
    while (1) {
          ispis_trake(traka1,traka2,traka3,traka4,n,glava,file);
          fprintf (file, "Trenutno stanje: %s Trenutni znakovi na trakama: %c %c %c %c \n",trenstanje,traka1[glava[0]],traka2[glava[1]],traka3[glava[2]],traka4[glava[3]]);
          st=(pronadi_iduce_stanje(trenstanje,traka1[glava[0]],traka2[glava[1]],traka3[glava[2]],traka4[glava[3]], file));
          if (st.sljed_stanje[2]=='?') {
             printf ("\nSimulacija je zavrsila u %d koraka!\n",k);
             if (trenstanje[0]=='2' && trenstanje[1]=='7') {
                printf("\nTS je zavrsio u prihvatljivom stanju i rezultat je\n\n");
                fprintf(file,"\nTS je zavrsio u prihvatljivom stanju i rezultat je\n\n");
                for (i=1;(i<n)&&(traka2[i]!='B');i++) {
                    printf("%c",traka2[i]);
                    fprintf(file,"%c",traka2[i]);
                }
                printf(" = %d",i-1);fprintf(file," = %d",i-1);
             } else {
                    printf("\nTS nije zavrsio u prihvatljivom stanju!!!");
             }
             break;
          } 
          k++;
          for (j=0;j<3;j++) trenstanje[j]=st.sljed_stanje[j];
          traka1[glava[0]]=st.sljed_znak[0];
          traka2[glava[1]]=st.sljed_znak[1];
          traka3[glava[2]]=st.sljed_znak[2];
          traka4[glava[3]]=st.sljed_znak[3];
          for (j=0;j<4;j++) {
              if (st.smjer[j]=='1') glava[j]=glava[j]+1;
              if (st.smjer[j]=='2') glava[j]=glava[j]-1;
          }
          //alociranje dodatnog prostora ako je malo
          if (glava[0]==(n-1)||glava[1]==(n-1)||glava[2]==(n-1)||glava[3]==(n-1)) {
             j=n;
             n+=10;  
             if ((traka1=(char*)realloc(traka1,(n+1)*sizeof(char)))==NULL) {
                printf ("Ne mogu stvoriti polje!");
                exit (-1);
             }
             if ((traka2=(char*)realloc(traka2,(n+1)*sizeof(char)))==NULL) {
                printf ("Ne mogu stvoriti polje!");
                exit (-1);
             }
             if ((traka3=(char*)realloc(traka3,(n+1)*sizeof(char)))==NULL) {
                printf ("Ne mogu stvoriti polje!");
                exit (-1);
             }
             if ((traka4=(char*)realloc(traka4,(n+1)*sizeof(char)))==NULL) {
                printf ("Ne mogu stvoriti polje!");
                exit (-1);
             }
             for (i=j;i<=n;i++) {
             traka1[i]='B';
             traka2[i]='B';
             traka3[i]='B';
             traka4[i]='B';
             }
          }
    }
    scanf("%c",&ulaz[0]);
    free(traka1);free(traka2);free(traka3);free(traka4);
    return 0;
}
