#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


// Pretvara niz jedinica i nula u broj baze 10, između 0.0 i 1.0.
double u_double(char *binarno) {
  double broj = 0;
  int i;

  for(i = 0; i < VELICINA_KODIRANE; i++) {
    broj += pow(2.0, -i-1) * binarno[i];
  }

  return broj;
}


// Čita niz bitova iz datoteke, razlama ih u poruke i pretvara
// u brojeve baze 10, između 0.0 i 1.0.
double* procitaj(char *filepath) {
  FILE *in = fopen(filepath, "r");
  char **poruke = (char**)malloc(BROJ_PORUKA*sizeof(char*));
  double *brojevi = (double*)malloc(BROJ_PORUKA*sizeof(double));
  int i, j;

  for(i = 0; i < BROJ_PORUKA; i++) {
    poruke[i] = (char*)malloc(VELICINA_KODIRANE*sizeof(char));

    for(j = 0; j < VELICINA_KODIRANE; j++) {
      fscanf(in, "%c", &poruke[i][j]);
      poruke[i][j] -= 48;
    }

    brojevi[i] = u_double(poruke[i]);
    free(poruke[i]);
  }

  fclose(in);
  free(poruke);

  return brojevi;
}


// Dekodira brojeve između 0.0 i 1.0 natrag u izvorne poruke.
int** dekodiraj(double* brojevi) {
  int **poruke = (int**)malloc(BROJ_PORUKA*sizeof(int*));
  double pocetak, kraj, novip, novik;
  int i, j, simbol;

  for(i = 0; i < BROJ_PORUKA; i++) {
    poruke[i] = (int*)malloc(VELICINA_PORUKE*sizeof(int));
    pocetak = 0.0; kraj = 1.0;

    for(j = 0; j < VELICINA_PORUKE; j++) {
      for(simbol = VELICINA_ABECEDE-1; simbol >= 0; simbol--) {
        novip = pocetak + GRANICE[simbol] * (kraj - pocetak);
        novik = pocetak + GRANICE[simbol+1] * (kraj - pocetak);

        if(brojevi[i] >= novip && brojevi[i] < novik) {
          pocetak = novip; kraj = novik;
          break;
        }
      }

      poruke[i][j] = simbol;
    }
  }

  free(brojevi);
  return poruke;
}


// Zapisuje nizove simbola u datoteku.
void zapisi(int **poruke) {
  FILE *out = fopen("67.txt", "w");
  int i, j;

  for(i = 0; i < BROJ_PORUKA; i++) {
    for(j = 0; j < VELICINA_PORUKE; j++) {
      fprintf(out, "%c", poruke[i][j] + 97);
    }

    free(poruke[i]);
  }

  fclose(out);
  free(poruke);
}


int main(int argc, char **argv) {
  if(argc > 1) {
    zapisi(dekodiraj(procitaj(argv[1])));
    return 0;

  } else {
    printf("Prvi argument mora biti lokacija datoteke 56.txt.\n");
    return 1;
  }
}
