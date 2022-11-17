#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


// Čita ulaznu datoteku (23.txt) i uzima ulazne bitove.
// Razlama ih na poruke duljine HAM_INF_BITOVI i vraća.
char** procitaj(char *filepath) {
  FILE *in = fopen(filepath, "r");
  int p = -1, count = 0;
  char simbol, **poruke = (char**)malloc(HAM_BROJ_PORUKA*sizeof(char*));

  while(fscanf(in, "%c", &simbol) != EOF) {
    if(count % HAM_INF_BITOVI == 0) {
      poruke[++p] = (char*)malloc(HAM_INF_BITOVI*sizeof(char));
    }

    poruke[p][count++ % HAM_INF_BITOVI] = simbol - 48;
  }

  if(HAM_IGNORIRANI) {
    printf("[!!!] Zanemareno zadnjih %d ulaznih bitova.\n", HAM_IGNORIRANI);
  }

  fclose(in);
  return poruke;
}


// Stvori novu matricu širine w i visine h.
// Svi su elementi postavljeni na nulu.
char** matrica(int w, int h) {
  char **nova = (char**)malloc(h*sizeof(char*));
  int i;

  while(h > 0) {
    nova[--h] = (char*)malloc(w*sizeof(char));
    for(i = 0; i < w; i++) nova[h][i] = 0;
  }

  return nova;
}


// Stvara i vraća matricu HT, bez redaka potencija broja 2.
char** stvori_ht() {
  char **h = matrica(HAM_ZAS_BITOVI, HAM_INF_BITOVI);
  int i, j, k = 0, jedinice;

  for(i = 0; i < HAM_DULJINA; i++) {
    jedinice = 0;

    for(j = 0; j < HAM_ZAS_BITOVI; j++) {
      h[k][j] = ((i+1)&(int)pow(2, j)) != 0;
      if(h[k][j] == 1) jedinice++;
    }

    if(jedinice > 1) k++;
  }

  return h;
}


// Stvara i vraća generirajuću matricu G.
char** stvori_generirajucu() {
  char **g = matrica(HAM_DULJINA, HAM_INF_BITOVI);
  char **h = stvori_ht();
  int i, j;

  for(i = 0; i < HAM_INF_BITOVI; i++) {
    // Popuni jediničnu matricu, lijevi dio matrice G.
    for(j = 0; j < HAM_DULJINA; j++) {
      g[i][j] = i == j;
    }

    // Popunjuje desni, transponirani H dio generirajuće matrice.
    for(j = 0; j < HAM_ZAS_BITOVI; j++) {
      g[i][HAM_INF_BITOVI + j] = h[i][j];
    }
  }

  for(i = 0; i < HAM_INF_BITOVI; i++) free(h[i]);
  free(h);

  return g;
}


// Kodira niz poruka (blokova) Hammingovim kodom.
char** kodiraj(char **poruke) {
  char **g = stvori_generirajucu();
  char **kodirane = matrica(HAM_DULJINA, HAM_BROJ_PORUKA);
  int i, j, k, zbroj;

  for(i = 0; i < HAM_BROJ_PORUKA; i++) {
    for(j = 0; j < HAM_DULJINA; j++) {
      zbroj = 0;

      for(k = 0; k < HAM_INF_BITOVI; k ++) {
        zbroj += poruke[i][k] * g[k][j];
      }

      kodirane[i][j] = zbroj % 2;
    }

    free(poruke[i]);
  }

  free(poruke);
  for(i = 0; i < HAM_INF_BITOVI; i++) free(g[i]);
  free(g);

  return kodirane;
}


// Ispisuje rezultat, niz kodiranih poruka, u datoteku.
void zapisi(char** poruke) {
  FILE *out = fopen("34.txt", "w");
  int i, j;

  for(i = 0; i < HAM_BROJ_PORUKA; i++) {
    for(j = 0; j < HAM_DULJINA; j++) {
      fprintf(out, "%c", poruke[i][j] + 48);
    }

    free(poruke[i]);
  }

  fclose(out);
  free(poruke);
}


int main(int argc, char **argv) {
  if(argc > 1) {
    zapisi(kodiraj(procitaj(argv[1])));
    return 0;

  } else {
    printf("Prvi argument mora biti lokacija datoteke 23.txt.\n");
    return 1;
  }
}
