#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


// Vraća niz nasumično generiranih simbola.
int* generiraj() {
  int *simboli = (int*)malloc(BROJ_SIMBOLA*sizeof(int));
  int *brojaci = (int*)malloc(VELICINA_ABECEDE*sizeof(int));
  int i, j, odstupanje_preveliko = 1;

  double random;

  // Generiraj niz simbola sve dok generirani simboli ne budu
  // unutar valjanih granica. (Najveće dopušteno odstupanje od
  // vjerojatnosti zadanih u zadatku je do +/-5%.)
  while(odstupanje_preveliko) {
    // Postavi brojače generiranih simbola na nulu.
    for(i = 0; i < VELICINA_ABECEDE; i++) {
      brojaci[i] = 0;
    }

    // Generiraj i izbroji simbole.
    for(i = 0; i < BROJ_SIMBOLA; i++) {
      random = (double)rand()/RAND_MAX;
      for(j = 0; j < VELICINA_ABECEDE; j++) {
        if(random <= GRANICE[j+1]) {
          simboli[i] = j;
          brojaci[j]++;
          break;
        }
      }
    }

    // Ukoliko je odstupanje preveliko, ponovi proces.
    for(i = 0; i < VELICINA_ABECEDE; i++) {
      if(abs((double)brojaci[i] - (GRANICE[i+1]-GRANICE[i])*BROJ_SIMBOLA) >
         (GRANICE[i+1]-GRANICE[i])*BROJ_SIMBOLA*0.05) {
        odstupanje_preveliko = 1;
        break; // Odstupanje preveliko, sve ispočetka.

      } else {
        odstupanje_preveliko = 0;
      }
    }
  }

  return simboli;
}


// Zapisuje niz simbola u datoteku.
void zapisi(int *simboli) {
  FILE *out = fopen("12.txt", "w");
  int i;

  for(i = 0; i < BROJ_SIMBOLA; i++) {
    fprintf(out, "%c", 97 + simboli[i]);
  }

  fclose(out);
  free(simboli);
}


int main() {
  srand(time(NULL));
  zapisi(generiraj());
  return 0;
}
