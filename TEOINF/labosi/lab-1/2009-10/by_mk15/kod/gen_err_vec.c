#include <stdio.h>
#include <stdlib.h>
#include "konstante.h"


// Generira vektor pogreške, na temelju vjerojatnosti
// pogreške u prijenosu jednog bita.
char* generiraj() {
  char *bitovi = (char*)malloc(HAM_OUTPUT_BITOVA*sizeof(char));
  int i;

  for(i = 0; i < HAM_OUTPUT_BITOVA; i++) {
    bitovi[i] = ((float)rand()/RAND_MAX) < ERROR_PROB;
  }

  return bitovi;
}


// Ispisuje niz bitova u err_vec.txt.
void zapisi(char* bitovi) {
  FILE *out = fopen("err_vec.txt", "w");
  int i;

  for(i = 0; i < HAM_OUTPUT_BITOVA; i++) {
    fprintf(out, "%d", bitovi[i]);
  }

  fclose(out);
  free(bitovi);
}


int main(int argc, char **argv) {
  srand(time(NULL));
  zapisi(generiraj());
  return 0;
}
