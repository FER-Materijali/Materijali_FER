#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


// Čita simbole iz datoteke i razlama ih na poruke duljine VELICINA_PORUKE.
// Svaka od tih poruka bit će zasebno kodirana.
char** procitaj(char *filepath) {
  FILE *in = fopen(filepath, "r");
  int p = -1, count = 0;
  char simbol, **poruke = (char**)malloc(BROJ_PORUKA*sizeof(char*));

  while(fscanf(in, "%c", &simbol) != EOF) {
    if(count % VELICINA_PORUKE == 0) {
      poruke[++p] = (char*)malloc(VELICINA_PORUKE*sizeof(char));
    }

    poruke[p][count++ % VELICINA_PORUKE] = simbol - 97;
  }

  fclose(in);

  return poruke;
}


// Niz poruka pretvara u niz brojeva (double) između 0 i 1.
double* kodiraj(char **poruke) {
  double *brojevi = (double*)malloc(BROJ_PORUKA*sizeof(double));
  double pocetak, kraj, temp;
  int i, j;

  for(i = 0; i < BROJ_PORUKA; i++) {
    pocetak = 0.0; kraj = 1.0;

    for(j = 0; j < VELICINA_PORUKE; j++) {
      temp = pocetak + GRANICE[poruke[i][j]] * (kraj - pocetak);
      kraj = pocetak + GRANICE[poruke[i][j]+1] * (kraj - pocetak);
      pocetak = temp;
    }

    brojevi[i] = pocetak + (kraj - pocetak)/2.0;

    free(poruke[i]);
  }

  free(poruke);

  return brojevi;
}


// Broj između 0.0 i 1.0 predstavlja u bazi 2, u obliku niza bitova.
char *u_binarno(double broj) {
  char *buff = (char*)malloc(VELICINA_KODIRANE*sizeof(char));
  double tezina;
  int i;

  for(i = 0; i < VELICINA_KODIRANE; i++) {
    tezina = pow(2.0, -i-1);

    if(broj >= tezina) {
      broj -= tezina;
      buff[i] = 1;

    } else {
      buff[i] = 0;
    }
  }

  return buff;
}


// Niz brojeva predstavlja u bazi 2 i zapisuje u datoteku.
void zapisi(double *brojevi) {
  FILE *out = fopen("23.txt", "w");
  char **binarni = (char**)malloc(BROJ_PORUKA*sizeof(char*));
  int i, j;

  for(i = 0; i < BROJ_PORUKA; i++) {
    binarni[i] = u_binarno(brojevi[i]);

    for(j = 0; j < VELICINA_KODIRANE; j++) {
      fprintf(out, "%d", binarni[i][j]);
    }

    free(binarni[i]);
  }

  fclose(out);
  free(brojevi);
  free(binarni);
}


int main(int argc, char **argv) {
  if(argc > 1) {
    zapisi(kodiraj(procitaj(argv[1])));
    return 0;

  } else {
    printf("Prvi argument mora biti lokacija datoteke 12.txt.\n");
    return 1;
  }
}
