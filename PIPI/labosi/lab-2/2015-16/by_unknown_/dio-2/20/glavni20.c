#include <stdio.h>
#include "funkcije20.h"
#include <stdlib.h>
#include <time.h>
#define MAX 32
int main(void){
  char lozinka[MAX + 1] = {0};
  int ns, nb, ni;
  srand(time(NULL));
  printf("Unesi broj slova, broj brojeva i broj interpunkcijskih znakova koje lozinka treba sadrzavati: ");
  scanf("%d %d %d", &ns, &nb, &ni);
  printf("\n");
  generirajLozinku(ns, nb, ni, lozinka);
  printf("%s", lozinka);
  return 0;
}