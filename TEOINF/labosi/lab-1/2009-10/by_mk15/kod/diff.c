#include <stdio.h>

// Prebroji razlike između dvije datoteke i ispiši ih.
void usporedi(char *path1, char *path2) {
  FILE *one = fopen(path1, "r");
  FILE *two = fopen(path2, "r");
  char b1, b2;
  int diffs = 0, ukupno = 0;

  while(1) {

    if(fscanf(one, "%c", &b1) == EOF) {
      if(fscanf(two, "%c", &b2) != EOF) {
        printf("%s je kraći od %s.\n", path1, path2);
      }
      break;
    }

    if(fscanf(two, "%c", &b2) == EOF) {
      if(fscanf(one, "%c", &b1) != EOF) {
        printf("%s je kraći od %s.\n", path2, path1);
      }
      break;
    }

    if(b1 != b2) diffs++;
    ukupno++;
  }

  fclose(one);
  fclose(two);

  printf("%s i %s se razlikuju u %g%% sadržaja, za %d bita.\n",
         path1, path2, (double)diffs/ukupno*100, diffs);
}


int main(int argc, char **argv) {
  if(argc > 2) {
    usporedi(argv[1], argv[2]);
    return 0;

  } else {
    printf("Argumenti moraju biti lokacije dvaju datoteka.\n");
    return 1;
  }
}
