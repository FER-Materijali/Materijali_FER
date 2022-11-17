#include <stdio.h>
#include <stdlib.h>
#include "konstante.h"


// Čita niz bitova iz datoteke.
char* procitaj(char *filepath) {
  FILE *in = fopen(filepath, "r");
  char simbol, *bitovi = (char*)malloc(HAM_OUTPUT_BITOVA*sizeof(char));
  int i, count = 0;

  for(i = 0; i < HAM_OUTPUT_BITOVA; i++) {
    bitovi[i] = 0;
  }

  while(fscanf(in, "%c", &simbol) != EOF) {
    if(count > HAM_OUTPUT_BITOVA-1) break;
    bitovi[count++] = simbol - 48;
  }

  fclose(in);

  return bitovi;
}


// Invertira bitove niza input na mjestima definiranim unutar err_vec.
char* flippaj(char* input, char* err_vec) {
  int i, count = 0;

  for(i = 0; i < HAM_OUTPUT_BITOVA; i++) {
    if(err_vec[i]) {
      input[i] = !input[i];
      count++;
    }
  }

  printf("Kanal invertirao %d bita na temelju p=%g.\n", count, ERROR_PROB);

  free(err_vec);
  return input;
}


// Ispisuje niz bitova u 45.txt.
void zapisi(char* bitovi) {
  FILE *out = fopen("45.txt", "w");
  int i;

  for(i = 0; i < HAM_OUTPUT_BITOVA; i++) {
    fprintf(out, "%d", bitovi[i]);
  }

  fclose(out);
  free(bitovi);
}


int main(int argc, char **argv) {
  char *err_vec, *input;

  if(argc > 2) {
    input = procitaj(argv[1]);
    err_vec = procitaj(argv[2]);
    zapisi(flippaj(input, err_vec));
    return 0;

  } else {
    printf("Argumenti moraju biti lokacije datoteka 34.txt i err_vec.txt.\n");
    return 1;
  }
}
