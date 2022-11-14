#include <stdio.h>

int main(int argc, char *argv[])
{

    FILE *racun, *proizvodi;

    char naziv[50 + 1], znak;

    int sifra, tmpSifra;

    float kolicina, cijena, maxCijena = 0;

    racun = fopen("racun.txt", "r");
    proizvodi = fopen("proizvodi.txt", "r");

    while (fscanf(racun, "%d %f %f", &tmpSifra, &kolicina, &cijena) == 3) {
        if (maxCijena < cijena) {
            maxCijena = cijena;
            sifra = tmpSifra;
        }
    }

    while (fscanf(proizvodi, "%d %50[^\n]%c", &tmpSifra, naziv, &znak) == 2) {
        if (tmpSifra == sifra) {
            puts(naziv);
            break;
        }
    }


    return 0;

}
