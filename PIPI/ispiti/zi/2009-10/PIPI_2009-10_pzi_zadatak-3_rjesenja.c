#include <stdio.h>

#define MAX_RED 100
#define MAX_STUP 150
#define RANDOM(DG, GG) (rand() % ((GG) - (DG) + 1) + (DG))

void genMatrica(int *matrica, int brojRedova, int brojStupaca, int maxStupaca, int *rasponi)
{

    int i, j;
    
    for (i = 0; i < brojRedova; i++) {
        for (j = 0; j < brojStupaca; j++) {
            *(matrica + i * maxStupaca + j) = RANDOM(*(rasponi + i * 2), *(rasponi + i * 2 + 1));
        }
    }

}

int main(int argc, char *argv[])
{

    int matrica[MAX_RED][MAX_STUP], rasponi[MAX_RED][2], 
        brojRedova, brojStupaca, i, j;

    do {
        scanf("%d %d", &brojRedova, &brojStupaca);
    } while (brojRedova < 1 || brojRedova > MAX_RED || brojStupaca < 1 || brojStupaca > MAX_STUP);


    for (i = 0; i < brojRedova; i++) {
        scanf("%d %d", &rasponi[i][0], &rasponi[i][1]);
    }

    genMatrica(&matrica[0][0], brojRedova, brojStupaca, MAX_STUP, &rasponi[0][0]);

    for (i = 0; i < brojRedova; i++) {
        for (j = 0; j < brojStupaca; j++) {
            printf("%5d ", matrica[i][j]);
        }
        printf("\n");
    }

    return 0;

}
