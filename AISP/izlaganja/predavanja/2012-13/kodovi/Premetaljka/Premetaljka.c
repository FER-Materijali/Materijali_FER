#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotiraj(size_t duljina, char *niz) {
  char sacuvaj;
  sacuvaj = *niz;
  while(--duljina) {
    *niz=*(niz+1);
    ++niz;
    }
  *niz = sacuvaj;
}

void permutiraj(size_t duljina, char *niz, unsigned dubina) {
  if (duljina == 0) printf("\n# %s\t",niz-dubina);
  else {
    size_t brojac; 
    for (brojac = duljina ; brojac > 0; --brojac) {
    printf("%s ", niz);
      permutiraj(duljina-1,niz+1,dubina+1);
    printf("%s ", niz);
      rotiraj(duljina,niz);
    printf("%s ", niz);
    }
  }
}

int main() {
  char izvorno[30];
  printf("Upisite rijec:\n");
  gets(izvorno);
  printf("\nPermutiram rijec \"%s\"\n",izvorno);
  permutiraj(strlen(izvorno),izvorno,0);
  return EXIT_SUCCESS;
}
