#include <stdio.h>

#define M_DIM 20

void stvori(int *mat, int brRed, int brStup, int maksStup, int poElementuBajtova) {
    FILE *prvaDat = fopen("matricaPrva.txt", "r");
    
    int i, j, k, suma, temp;
    
    //Za broj redaka
    for (i = 0; i < brRed; i++) {
        //Za broj stupaca
        for (j = 0; j < brStup; j++) {
            //Kazemo da nam je suma na pocetku jednaka 0
            //Mogli smo ovaj zadatak rijesiti sa 2 sume tako da
            //obje zbrajamo i onda na kraju samo oduzmemo
            suma = 0;
            //Prvo moramo zbrajati po retcima, tako da nam k
            //krece od 0 i ide do trenutnog retka. Primjetite
            //da taj trenutni redak nije ukljucen u sam racun
            for (k = 0; k < i; k++) {
                //E sad tricky part, treba se pozicionirat na odgovarajuce mjesto u 
                //nasoj datoteci. Sto znamo? Znamo da ce biti maks brStup brojeva
                //u nasoj datoteci. Isto tako, znamo da svaki od tih brojeva ima 
                //tocno poElementuBajtova znaka (znamenka ili razmak). Buduci da smo 
                //matricu ispisivali sa novim redovima, znamo i da na kraju svake datoteke
                //imamo 2 bajta. E sad, zasto 2 bajta? Windowsi umeci \r\r.
                //Na UNIXu bi imali samo jedan bajt tj sao \n. Iz ovog razloga nama
                //jos u racunu treba + 2. Dakle, moramo preskociti
                //k * (brRed * poElementuBajtova + 2) bajtova. Isto tako, moramo se pomaknuti
                //i po stupcu, no to mozemo lako, to je samo j * poElementuBajtova buduci da smo uvijek
                //u istom stupcu
                fseek(prvaDat, k * (brRed * poElementuBajtova + 2) + j * poElementuBajtova, SEEK_SET);
                //Nakon toga ucitamo broj i pribrojimo ga
                fscanf(prvaDat, "%d", &temp);
                suma += temp;
            }
            //Ista logika kao i za petlju gore, no sada nam varijabla k predstavlja stupac
            //dok nam je redak u kojem se nalazimo konstantan
            for (k = 0; k < j; k++) {
                fseek(prvaDat, i * (brRed * poElementuBajtova + 2) + k * poElementuBajtova, SEEK_SET);
                fscanf(prvaDat, "%d", &temp);
                suma -= temp;
            }
            //Jos samo moramo u nasu matricu spremiti vrijednost
            mat[i * maksStup + j] = suma;
        }
    }
    
    fclose(prvaDat);
}

int main(void) {

    FILE *prvaDat = fopen("matricaPrva.txt", "w");
    int brRed, brStup, tmp;
    int matDruga[M_DIM][M_DIM];
    int i, j;
    
    scanf("%d %d", &brRed, &brStup);
    
    //Ucitavamo nasu matricu i ispisujemo ju datoteku
    //Za unos 
    /*
2 2
1
2
3
4
Bi dobili u datoteci ispis
  1  2
  3  4
    */
    for (i = 0; i < brRed; i++) {
        for (j = 0; j < brStup; j++) {
            scanf("%d", &tmp);
            fprintf(prvaDat, "%3d", tmp);
        }
        fprintf(prvaDat, "\n");
    }
    
    fclose(prvaDat);
    
    //Pozivamo za stvaranje nove matrice
    stvori(matDruga[0], brRed, brStup, M_DIM, 3);
    
    FILE *drugaDat = fopen("matricaDruga.bin", "w");
    //Zapisujemo drugu matricu u datoteku 
    //Kako? Kao direktnu datoteku po indekima (i, j)
    //Samo preselimo ono sto se nalazi u memoriji u datoteku
    fwrite(matDruga[0], sizeof(int), M_DIM * M_DIM, drugaDat);
    
    printf("\nIspis nove:\n");
    
    //Ovo je toliko glupo da ne znam nit zasto
    //ovaj komentar pisem
    for (i = 0; i < brRed; i++) {
        for (j = 0; j < brStup; j++) {
            printf("%4d", matDruga[i][j] );
        }
        printf("\n");
    }
    fclose(drugaDat);

    return 0;
}