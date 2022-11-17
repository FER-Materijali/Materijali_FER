#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


// Računa i ispisuje transinformaciju na temelju
// datoteke s ulaznim i izlaznim nizom simbola.
// Očekuje abecedu simbola 'a', 'b', 'c' itd.
void izracunaj_transinformaciju(char *file12, char *file67) {

  int izvornih[VELICINA_ABECEDE] = { 0 };
  int krajnjih[VELICINA_ABECEDE] = { 0 };
  int uvjetnih[VELICINA_ABECEDE][VELICINA_ABECEDE] = { 0 };
  int ukupno = 0, i = 0, j = 0;

  double izvor_probs[VELICINA_ABECEDE] = { 0.0 };
  double kraj_probs[VELICINA_ABECEDE] = { 0.0 };
  double uvjetne_probs[VELICINA_ABECEDE][VELICINA_ABECEDE] = { 0.0 };
  double transinf = 0.0;
  double temp1 = 0.0, temp2 = 0.0;

  char simbol;
  char prvi[BROJ_SIMBOLA], drugi[BROJ_SIMBOLA];

  FILE *in = fopen(file12, "r");
  FILE *out = fopen(file67, "r");

  // Prebroji simbole u datotekama, kako
  // bismo dobili p(xi) i p(yj|xi).
  i = 0;
  while(fscanf(in, "%c", &simbol) != EOF) {
    prvi[i++] = simbol-97;
    izvornih[simbol-97]++;
  }
  fclose(in);

  j = 0;
  while(fscanf(out, "%c", &simbol) != EOF) {
    drugi[j++] = simbol-97;
    krajnjih[simbol-97]++;
  }
  fclose(out);

  if(i < j) {
    // Prva je datoteka kraća od druge.
    ukupno = i;
  } else {
    ukupno = j;
  }

  for(i = 0; i < ukupno; i++) {
    uvjetnih[prvi[i]][drugi[i]]++;
  }

  // Izračunaj vjerojatnosti p(xi) i p(yi).
  for(i = 0; i < VELICINA_ABECEDE; i++) {
    izvor_probs[i] = (double)izvornih[i] / ukupno;
    kraj_probs[i] = (double)krajnjih[i] / ukupno;
  }

  // Izračunaj vjerojatnosti p(yj|xi) i transinformaciju.
  for(i = 0; i < VELICINA_ABECEDE; i++) {
    ukupno = 0;

    for(j = 0; j < VELICINA_ABECEDE; j++) {
      ukupno += uvjetnih[i][j];
    }

    for(j = 0; j < VELICINA_ABECEDE; j++) {
      uvjetne_probs[i][j] = (double)uvjetnih[i][j] / ukupno;

      temp1 = uvjetne_probs[i][j] * izvor_probs[i];
      temp1 = temp1 ? temp1 : 0.0001;
      temp2 = izvor_probs[i] * kraj_probs[j];
//      temp2 = temp2 ? temp2 : 0.0001;
      transinf += temp1 * log(temp1/temp2) / log(2);
    }
  }

  printf("Transinformacija I(X;Y) = %g.\n", transinf);
}


int main(int argc, char **argv) {
  if(argc > 2) {
    izracunaj_transinformaciju(argv[1], argv[2]);
    return 0;
  } else {
    printf("Argumenti moraju biti lokacije datoteka 12.txt i 67.txt.\n");
    return 1;
  }
}
