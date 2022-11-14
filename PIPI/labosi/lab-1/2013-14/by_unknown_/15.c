#include <stdio.h>

int main (void){


int vrijeme;
int sati, minute, sekunde;
printf ("Unesite vrijeme izrazeno u sekundama: ");
scanf ("%d", &vrijeme);

sati = vrijeme/3600;
minute = (vrijeme - sati*3600)/60;
sekunde = vrijeme - sati*3600 - minute*60;

printf ("sekunde: %d = sati-minute-sekunde: %d-%d-%d", vrijeme, sati, minute, sekunde);
return 0;
}