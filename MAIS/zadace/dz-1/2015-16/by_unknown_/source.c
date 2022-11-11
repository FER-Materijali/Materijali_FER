#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
     unsigned char czp[3];
} pixel;

typedef struct {
     int sirina;
     int visina;
     pixel *podaci;
} slika;


int main (int argc, char *argv[]) {
    int blok = atoi(argv[2]);
    char* datoteka = argv[1];
    char* datotekaizlaz = argv[3];

    FILE *ulaz;

    slika *ulazslika;

    int sirina = 0;
    int visina = 0;
    int maxvrijednost = 0;

    int i = 0;
    int j = 0;
    int k = 0;
    int komentar = 0;

    int vrijednost = 0;
    //char datoteka[] = "lenna.ppm";

    unsigned char slovo;
    ulaz = fopen(datoteka, "rb");

    float Ktablica1[8][8] = { {16, 11, 10, 16, 24, 40, 51, 61},
                       {12, 12, 14, 19, 26, 58, 60, 55},
                       {14, 13, 16, 24, 40, 57, 69, 56},
                       {14, 17, 22, 29, 51, 87, 80, 62},
                       {18, 22, 37, 56, 68, 109, 103, 77},
                       {24, 35, 55, 64, 81, 104, 113, 92},
                       {49, 64, 78, 87, 103, 121, 120, 101},
                       {72, 92, 95, 98, 112, 100, 103, 99}};

    float Ktablica2[8][8] = { {17, 18, 24, 47, 99, 99, 99, 99},
                       {18, 21, 26, 66, 99, 99, 99, 99},
                       {24, 26, 56, 99, 99, 99, 99, 99},
                       {47, 66, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99}};


    if (ulaz == NULL) {
        printf("Datoteka nije uspjeno otvorena\n");
    }
    else {
        printf("Datoteka otvorena\n");
    }
    slovo = getc(ulaz);
    komentar = 0;
    while (slovo == '#') {
        while (getc(ulaz) != '\n');
        slovo = getc(ulaz);
        komentar++;
    }
    if (komentar != 0) {
        ungetc(slovo, ulaz);
    }
    if (slovo !='P' && (slovo = getc(ulaz)) != '6')
        printf("Datoteka nije P6\n");
    else {
        printf("Datoteka je P6\n");
    }

    slovo = getc(ulaz);
    slovo = getc(ulaz);
    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz);
    }
    komentar = 0;
    while (slovo == '#') {

        while (getc(ulaz) != '\n');
        slovo = getc(ulaz);
        komentar++;
    }
    if (komentar != 0) {

        ungetc(slovo, ulaz);
    }

    fscanf(ulaz, "%d %d", &visina, &sirina);
    printf("%d %d\n", visina, sirina);
    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz);
    }
    while (slovo == '#') {
        while (getc(ulaz) != '\n');
        slovo = getc(ulaz);
    }

    fscanf(ulaz, "%d", &maxvrijednost);
    printf("%d \n", maxvrijednost);

    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz);
    }
    while (slovo == '#') {
        while (getc(ulaz) != '\n');
        slovo = getc(ulaz);
    }


    int crv[8][8]={0};
    int zel[8][8]={0};
    int pla[8][8]={0};
    float Y[8][8]={0};
    float Cb[8][8]={0};
    float Cr[8][8]={0};

    slovo = getc(ulaz);
    vrijednost = (int)slovo;
    printf("prije petlje %d\n", vrijednost);


    ulazslika = (slika *)malloc(sizeof(slika)); // alociraj memoriju

    ulazslika->visina=(visina);
    ulazslika->sirina=(sirina);
    printf("visina i sirina %d %d\n", ulazslika->visina, ulazslika->sirina);

    ulazslika->podaci = (pixel *)malloc(visina*sirina*sizeof(pixel));
    fread(ulazslika->podaci, 3*visina, sirina, ulaz);

    int vertikala = 0;
    int pomak = 0;
    pomak = (blok/64);
    vertikala = 512*8*pomak;
    int red = 0;
    i = 0;
    j = 0;
    k = 0;

    while(i<8){
        for(j=(blok%64)*8+red+vertikala;j<(blok%64)*8+red+vertikala+8;j++){
            //printf("unutra sam\n");
            crv[i][k]=ulazslika->podaci[j].czp[0];
            zel[i][k]=ulazslika->podaci[j].czp[1];
            pla[i][k]=ulazslika->podaci[j].czp[2];
            Y[i][k] = 0.299*crv[i][k] + 0.587*zel[i][k] + 0.114*pla[i][k] -128;
            Cb[i][k] = -0.1687*crv[i][k] - 0.3313*zel[i][k] + 0.5*pla[i][k];
            Cr[i][k] =  0.5*crv[i][k] - 0.4187*zel[i][k] - 0.0813*pla[i][k];
            //printf("%d ", crv[i][k]);
            k++;
        }
        i++;
        red = red+512;
        k=0;
    }

    printf("Crvena\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d  ", crv[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("Zelena\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d  ", zel[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("Plava\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d  ", pla[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("Y\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%3.2f  ", Y[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("Cb\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%3.2f  ", Cb[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("Cr\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%3.2f  ", Cr[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("DCT matrice \n");

    float DCTY[8][8]={0};
    float DCTCB[8][8]={0};
    float DCTCR[8][8]={0};
    int l;
    double dct1,dct2,dct3, cu, suma1,suma2,suma3,cv;
    float sivazona1,sivazona2,sivazona3;
    for(i=0;i<8;++i) {
        for(j=0;j<8;++j){
            if (i==0){
                cu = 1.0/sqrt(2.0);
            }
            else {
                cu = 1.0;
            }
            if (j == 0) {
                cv=1.0/sqrt(2.0);
            }
            else {
                cv=1.0;
            }
            suma1 = 0;
            suma2 = 0;
            suma3 = 0;
            for(k=0;k<8;k++){
                for(l=0;l<8;l++){
                    sivazona1=Y[k][l];
                    sivazona2=Cb[k][l];
                    sivazona3=Cr[k][l];
                    dct1 = sivazona1 * cos((2 * k + 1) * i * M_PI / 16.0) * cos((2 * l + 1) * j * M_PI / 16.0);
                    dct2 = sivazona2 * cos((2 * k + 1) * i * M_PI / 16.0) * cos((2 * l + 1) * j * M_PI / 16.0);
                    dct3 = sivazona3 * cos((2 * k + 1) * i * M_PI / 16.0) * cos((2 * l + 1) * j * M_PI / 16.0);
                    suma1 += dct1;
                    suma2 += dct2;
                    suma3 += dct3;
                }
            }
            DCTY[i][j]=0.25*cu*cv*suma1;
            DCTCB[i][j]=0.25*cu*cv*suma2;
            DCTCR[i][j]=0.25*cu*cv*suma3;
        }
    }
    printf("DCTY\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%3.2f  ", DCTY[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("DCTCB\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%3.2f  ", DCTCB[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("DCTCR\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%3.2f  ", DCTCR[i][j]);
            }
            printf("\n");
    }
    printf("\n");


    int KY[8][8]={0};
    int KCb[8][8]={0};
    int KCr[8][8]={0};
    float KYP[8][8]={0};

    for (i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            KY[i][j] = (round)(DCTY[i][j]/Ktablica1[i][j]);
            KCb[i][j] = (round)(DCTCB[i][j]/Ktablica2[i][j]);
            KCr[i][j] = (round)(DCTCR[i][j]/Ktablica2[i][j]);
        }
    }

    FILE *izlaz;

    izlaz = fopen(datotekaizlaz, "w+");

    printf("KY\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d  ", KY[i][j]);
                fprintf(izlaz, "%d ", KY[i][j]);
            }
            fprintf(izlaz, "\n");
            printf("\n");
    }
    printf("\n");
    fprintf(izlaz, "%s ", "\n");

    printf("KCb\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d  ", KCb[i][j]);
                fprintf(izlaz, "%d ", KCb[i][j]);
            }
            fprintf(izlaz, "\n");

            printf("\n");
    }
    printf("\n");
    fprintf(izlaz, "%s ", "\n");

    printf("KCr\n");
    for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d  ", KCr[i][j]);
                fprintf(izlaz, "%d ", KCr[i][j]);
            }
            fprintf(izlaz, "\n");
            printf("\n");
    }
    printf("\n");
    fprintf(izlaz, "%s ", "\n");

    fclose(ulaz);
    fclose(izlaz);
    return 0;
}


