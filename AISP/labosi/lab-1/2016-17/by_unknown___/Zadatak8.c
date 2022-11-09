#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*U zadatku nigdje nije navedena maksimalna veličina ulaznog stringa, niti to da se može kontrolirati upisom koliki će biti string. Iz tog razloga, ostavio sam nekakvu dummy veličinu
od 100 znakova.*/
char *izbaciPraznine(char *base){
    int velicina,isPraznina=0,i=0,j=0;
    velicina=strlen(base);

    char *rezultat;
    rezultat = malloc(velicina * sizeof(char));
    while(*(base+i)){
        if(*(base + i) != ' ' && isPraznina==0){
            strcpy(rezultat+j,base+i);
            ++i;
            ++j;
        }
        else if(*(base + i)==' ' && isPraznina==0){
            strcpy(rezultat+j,base+i);
            ++i;
            ++j;
            isPraznina=1;
        }
        else if(*(base + i)==' ' && isPraznina==1)
            ++i;
        else if(*(base + i)!=' ' && isPraznina==1){
            strcpy(rezultat+j,base+i);
            isPraznina=0;
            ++j;
            ++i;
        }

    }
    *(rezultat + j +1)='\0';
    rezultat=realloc(rezultat,strlen(rezultat)+1);
    return rezultat;


}
int main(void){
    char ulaz[100], *noviniz;
    printf("Unesite string: ");;
    gets(ulaz);
    noviniz=izbaciPraznine(ulaz);
    printf("%s",noviniz);
    free(noviniz);
    return 0;
}
