#include <stdio.h>
#include <stdlib.h>
 
int prijelazi (char *ulazni_niz1, int j1,  int p1, int q1, int *stog1,  int i1){
 int stog[100], j, p, q, i,b, x, y,z;
j=j1;
p=p1;
q=q1;
i=i1;

 for(b=0; b<100; b++)
 stog[b] = stog1[b];
 
int k=0, k2 = 0;
int u_znak;
//stog[i] zadnji element na  stogu
//i - indeks zadnjeg elementa na stogu
// pocetno stanje stoga(K) =  0
// j - indeks zadnjeg procitanog znaka
// X - brojevi 1 3 4 5
// Y -  brojevi 0 2 6 7 8 9
// W (ako je na stogu neki Y, onda je ulazni znak W bilo  koji drugi a ne bas taj iz Y)
 
while (1)
{ if(ulazni_niz1[j] == \\'\0\\' )
   u_znak = 10; // dosli smo do kraja niza: ulazni znak je epsilon...u kodu kao                          // broj 10
   else
   u_znak = ulazni_niz1[j] - \\'0\\';
 
printf("Znak koji se ucitava: %d\n",u_znak);
printf("Trenutno stanja:  [p%d, q%d]\n",p,q);
printf("Trenutno stanje stoga:");
for(b=i; b>=0;  b--)
 printf("%d", stog[b]);
printf("\n");
  x=p;
 y=q;
 z=i;
 
if (u_znak == 0 || u_znak == 2 || u_znak == 6 || u_znak ==7 || u_znak ==  8 || u_znak == 9)
//kad dode neki od ovih znakova, mjenja se samo stanje p.  stog i q ostaju uvijek isti
  p = (p + u_znak)%3;
 else if (u_znak == 1 || u_znak == 3 || u_znak == 4 || u_znak == 5 ||u_znak ==  10)
  {
   if(q == 0)
    { if(stog[i] == 0) // oznaka za K na stogu je 0
          {p = (p +  u_znak)%3;              //stog-K, q=0, u_znak= Y
           q =  0;
           i++;
           stog[i] = u_znak;}
        else   if(stog[i] == 1 || stog[i] == 3 || stog[i] == 4 || stog[i]  ==5)
                {
                  if (stog[i] != u_znak)        //  stog - Y, q=0, u_znak  = W(neko iz Y, a da nije znak na vrhu  stoga)
                     {p = (p + u_znak)%3;
                      q =  0;
                      i++;
                      stog[i] =  u_znak;
                     }
                  else if (u_znak == 10) //  u_znak = e... kraj niza a stanje q=0-->vodi u neprihvatljivo  stanje
                      {p = p;
                       q =  3;
                      }
                  else if (stog[i] == u_znak)  //nedeterminizam
                      {  p=(p+u_znak)%3;
                          i++;
                         stog[i] =  u_znak;
                         q = 0;
                         printf("d([p%d, q%d], %d, %d) = {[p%d, q%d],%d}\n",  x, y, u_znak, stog[z], p, q, stog[i]);
         printf("Novo stanje  stoga:");
         for(b=z; b>=0; b--)
          printf("%c",  ispis[stog[b]]);
         if (y == 2 && x==0)
            printf("\nDosad ucitani niz se prihvaca!\n");
         else
           printf("\nDosad ucitani niz se NE prihvaca!\n");
                          k = prijelazi (ulazni_niz1, j+1, p, q, stog,  i);
                          printf("*************************************************\n\n");
                           //1.verzija-->nastavljamo dodavat na stog
                          i--;          //da vratimo na normalno  stanje
                         q=1;
                          i--;             // 2.verzija - skidanje sa stoga
 
                        printf("d([p%d, q%d], %d, %d) = {[p%d,  q%d],%d}\n", x, y, u_znak, stog[z], p, q, stog[i]);
         printf("Novo  stanje stoga:");
         for(b=z; b>=0; b--)
          printf("%c",  ispis[stog[b]]);
         if (y == 2 && x==0)
            printf("\nDosad ucitani niz se prihvaca!\n");
         else
           printf("\nDosad ucitani niz se NE prihvaca!\n");
                          k2 = prijelazi (ulazni_niz1, j+1, p, q, stog,  i);
                           printf("*************************************************\n\n");
                          if (k == 1 || k2 == 1)
                           return  1;
                         else return 0;
 
                      }
                }
     }
  else if(q == 1)
    {     if(stog[i] == 1 || stog[i] == 3 ||  stog[i] == 4 || stog[i] ==5)
               {
                  if  (stog[i] == u_znak)    // stog = Y, u_znak = Y, q=1
                   {  p=(p+u_znak)%3;
                     q=1;
                      i--;
                   }
                  else if (u_znak == 10)        //stog = Y, u_znak= e, q=1
                    {
                       p=(p+u_znak)%3;
                      q=3;
                     }
                  else if (stog[i] != u_znak)  // stog = Y, u_znak = W,  q=1
                                               //stog razlicit od  ulaznog!!!!! ne smi se skidat sa stoga jer se moze  desit
                                              // da ima jednako  u_znakova koliko i ocekivani niz iako nisu bile sve iste, niz ce bit  prihvacen!!
                     {
                        p=(p+u_znak)%3;    // odma poslat u neprihvatljivo  stanje
                       q=3;
                       i--;
                      }
 
               }
          else if (stog[i] == 0)
                {
                 if (u_znak == 10)            //    q=1, stog = K,, u_znak  =e
                   {p=p;
                    q=2; // PRIHVATLJIVO  stanje
                   }
                 else //         ostali  znakovi Y
                   {p=(p+u_znak)%3;
                    q =  3;
                   }
                }
    }
  else if (q == 3)
   { if (u_znak ==  10)
      {p=p;
      i--;}
     else
        {p=(p+u_znak)%3;
        i--;}
   }
   }
 
 printf("d([p%d, q%d], %d, %d) = {[p%d, q%d],%d}\n", x, y, u_znak,  stog[z], p, q, stog[i]);
 printf("Novo stanje stoga:");
 for(b=i; b>=0;  b--)
   printf("%d", stog[b]);
 if (y == 2 && x==0)
   printf("\nDosad ucitani niz se prihvaca!\n");
 else
  printf("\nDosad  ucitani niz se NE prihvaca!\n");
  if(ulazni_niz1[j] == \\'\0\\' )
    break;
 j++;
 
printf("\n");
  } //kraj while
 
  if (q == 2 && p == 0) return 1;
  else return 0;
 
}
  
 int main(){
char ulazni_niz[100];
int stog[100], k;
FILE  *f;
if((f=fopen("datoteka2.txt","r"))==NULL){
       printf("Ne moze se  ucitati datoteka ");
       exit(1);
        }
while(fscanf(f,"%s",ulazni_niz)==1){
      stog[0]=0;
      k =  prijelazi (ulazni_niz, 0, 0, 0, stog, 0);
      if (k == 1)
         printf("\n~~~~~~~~~~~~~~~~~~Niz %s se prihvaca~~~~~~~~~~~~~~~~~  \n",  ulazni_niz);
      else
        printf("\n~~~~~~~~~~~~~~~~~~Niz %s se NE  prihvaca~~~~~~~~~~~~~~~~~  \n",ulazni_niz);
       printf("\n\n___________________________________________________________________\n\n");
       }
system ("pause");
return 0;
}