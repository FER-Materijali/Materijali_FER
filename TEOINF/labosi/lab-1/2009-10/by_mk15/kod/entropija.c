#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


// Računa entropiju na temelju datoteke s nizom simbola.
// Očekuje abecedu simbola 'a', 'b', 'c', 'd' itd.
void izracunaj_entropiju(char *filepath) {
  int simbola[VELICINA_ABECEDE] = { 0 }, ukupno = 0, i;
  double probs[VELICINA_ABECEDE] = { 0.0 }, entropija = 0;
  char simbol;
  FILE *in = fopen(filepath, "r");

  // Prebroji simbole u datoteci.
  while(fscanf(in, "%c", &simbol) != EOF) {
    simbola[simbol-97]++;
    ukupno++;
  }
  fclose(in);

  printf("Analiza %s: ", filepath);

  // Izračunaj vjerojatnosti pojavljivanja pojedinih simbola i entropiju.
  for(i = 0; i < VELICINA_ABECEDE; i++) {
    probs[i] = (double)simbola[i] / ukupno;
    printf("p(%c)=%g, ", i+97, probs[i]);
    entropija -= probs[i] * log(probs[i]) / log(2);
  }

  printf("H=%g b/simb.\n", entropija);
}


int main(int argc, char **argv) {
  if(argc > 1) {
    izracunaj_entropiju(argv[1]);
    return 0;
  } else {
    printf("Argument mora biti lokacija datoteke s nizom simbola.\n");
    return 1;
  }
}
