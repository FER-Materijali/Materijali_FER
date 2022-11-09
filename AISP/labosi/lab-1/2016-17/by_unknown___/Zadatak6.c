#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Nigdje u zadatku nije rečeno kolika treba biti veličina niza. Zbog toga sam ja ovdje ostavio nekakav sample niz, koji je drukčiji od onoga što su oni ostavili.
Također nigdje u zadatku nije specificiran način učitavanja niza, pa je ovdje ostavljen neki statički niz. Na labosima bi bila dobra ideja da se odradi učitavanje niza.	
*/

char *ostaviSlova(char *niz){
    int x=0,vel=0;
    while(*(niz+x)){
        if(isalpha(*(niz+x)))
            vel++;
            x++;
    }
   x=0;
   vel=0;
   char *noviniz;
   noviniz=malloc(vel * sizeof(char));
   while(*(niz+x)){
        if(isalpha(*(niz+x))){
            noviniz[vel]=*(niz+x);
            vel++;

        }
        x++;
   }
   *(noviniz + vel +1)='\0';
    return noviniz;
}
int main(void){
    char niz[]="Eh_kada_bi_12..3o";
    char *rezultat;
    rezultat=ostaviSlova(niz);
    printf("%s",rezultat);
    free(rezultat);
    return 0;
}
