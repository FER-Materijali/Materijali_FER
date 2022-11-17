#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "konstante.h"


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


// Čita niz bitova iz datoteke i razlama ih na blokove duljine HAM_DULJINA.
char** procitaj(char *filepath) {
  FILE *in = fopen(filepath, "r");
  char simbol, **poruke = matrica(HAM_DULJINA, HAM_BROJ_PORUKA);
  int p = -1, count = 0;

  while(fscanf(in, "%c", &simbol) != EOF) {
    if(count % HAM_DULJINA == 0) p++;
    poruke[p][count++ % HAM_DULJINA] = simbol - 48;
  }

  fclose(in);
  return poruke;
}


// Stvara i vraća transponiranu matricu provjere pariteta HT.
char** stvori_ht() {
  char **h = matrica(HAM_ZAS_BITOVI, HAM_DULJINA);
  int i, j, k = 0, l = 0, jedinice;

  for(i = 0; i < HAM_DULJINA; i++) {
    jedinice = 0;

    // Stvara redak matrice.
    for(j = 0; j < HAM_ZAS_BITOVI; j++) {
      h[k][j] = ((i+1)&(int)pow(2, j)) != 0;
      if(h[k][j] == 1) jedinice++;
    }

    if(jedinice > 1) {
      k++;

    // Ukoliko se radi o retku potencije broja 2,
    // guramo ga na kraj (donji dio) matrice.
    } else {
      for(j = 0; j < HAM_ZAS_BITOVI; j++) {
        h[HAM_INF_BITOVI+l][j] = h[k][j];
      }

      // Iduća će potencija broja dva ići na redak niže.
      l++;
    }
  }

  return h;
}


// Na temelju sindroma i matrice HT, određuje i vraća lokaciju gdje
// je nastupila greška. Ukoliko otkrije grešku koju ne može ispraviti,
// vraća negativan broj.
int odredi_mjesto_greske(char *sindrom, char **ht) {
  int i, j, pronadeno;

  for(i = 0; i < HAM_DULJINA; i++) {
    pronadeno = 1; // Je li ovo redak koji odgovara sindromu?

    for(j = 0; j < HAM_ZAS_BITOVI; j++) {
      if(sindrom[j] != ht[i][j]) {
        pronadeno = 0; // Nije, jer se ovaj bit retka razlikuje.
        break;
      }
    }

    if(pronadeno) return i; // i-ti redak je jednak sindromu.
  }

  // Ako sindrom ne odgovara nijednom retku HT-a,
  // radi se o grešci koju ne možemo ispraviti.
  return -112;
}


// Ispravlja grešku u primljenoj poruci, ukoliko ona postoji i
// ukoliko ju je moguće ispraviti.
char* ispravi(char *poruka, char *sindrom, char **ht) {
  char *dekodirana = (char*)malloc(HAM_INF_BITOVI*sizeof(char));
  int i, j, k = 0, greska = 0, mjesto_greske;

  // Je li sindrom različit od [000...]? Ako da, postoji greška.
  for(i = 0; i < HAM_ZAS_BITOVI; i++) {
    if(sindrom[i]) greska = 1;
  }

  // Invertiraj bit na kojem je došlo do greške.
  if(greska) {
    mjesto_greske = odredi_mjesto_greske(sindrom, ht);

    if(mjesto_greske >= 0) {
      poruka[mjesto_greske] = !poruka[mjesto_greske];

    // Grešku nije moguće ispraviti.
    } else {
      ; // TODO, voditi statistiku?
    }
  }

  // Kopiramo samo informacijske bitove.
  for(i = 0; i < HAM_INF_BITOVI; i++) {
    dekodirana[i] = poruka[i];
  }

  return dekodirana;
}


// Dekodira svaku u nizu poruka. Vraća dekodirane poruke (blokove).
char** dekodiraj(char **poruke) {
  char **dekodirane = (char**)malloc(HAM_BROJ_PORUKA*sizeof(char*));
  char *sindrom = (char*)malloc(HAM_ZAS_BITOVI*sizeof(char));
  char **ht = stvori_ht();
  int i, j, k, zbroj;

  for(i = 0; i < HAM_BROJ_PORUKA; i++) {
    for(j = 0; j < HAM_ZAS_BITOVI; j++) {
      zbroj = 0;

      for(k = 0; k < HAM_DULJINA; k++) {
        zbroj += poruke[i][k] * ht[k][j];
      }

      sindrom[j] = zbroj % 2;
    }

    dekodirane[i] = ispravi(poruke[i], sindrom, ht);
    free(poruke[i]);
  }

  free(poruke);
  free(sindrom);
  for(i = 0; i < HAM_DULJINA; i++) free(ht[i]);
  free(ht);

  return dekodirane;
}


// Ispisuje dekodirane poruke u datoteku (56.txt).
void zapisi(char** poruke) {
  FILE *out = fopen("56.txt", "w");
  int i, j;

  for(i = 0; i < HAM_BROJ_PORUKA; i++) {
    for(j = 0; j < HAM_INF_BITOVI; j++) {
      fprintf(out, "%c", poruke[i][j] + 48);
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
    printf("Prvi argument mora biti lokacija datoteke 45.txt.\n");
    return 1;
  }
}
