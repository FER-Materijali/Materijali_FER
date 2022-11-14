#include <stdio.h>
int main (void){
    int broj;
    printf("Upisite jedan pozitivni cijeli broj: ");
    scanf("%d",&broj);
    if(broj > 0)
        printf("Zadnja znamenka broja %5d je %d",broj,broj%10);
    else
        printf("Broj %5d nije pozitivan broj", broj);
    return 0;

}
