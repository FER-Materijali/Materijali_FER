#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
     unsigned char crno;
} pixel;

typedef struct {
     int sirina;
     int visina;
     pixel *podatak;
} slika;

int main (int argc, char *argv[]) {
    int blok = atoi(argv[1]);
    //int blok = 0;
    char datoteka1[] = "lenna.pgm";
    char datoteka2[] = "lenna1.pgm";

    FILE *ulaz1;
	FILE *ulaz2;

    slika *ulazslika1;
	slika *ulazslika2;

    int sirina = 0;
    int visina = 0;
    int maxvrijednost = 0;

    int i = 0;
    int j = 0;
    int k = 0;
	int m = 0;
    int komentar = 0;

    int vrijednost = 0;


    unsigned char slovo;
    ulaz1 = fopen(datoteka1, "rb"); // lenna.pgm

	if (ulaz1 == NULL) { // sve provjere datoteke
        printf("Datoteka nije uspjeno otvorena\n");
    }
    else {
        //printf("Datoteka otvorena\n");
    }
    slovo = getc(ulaz1);
    komentar = 0;
    while (slovo == '#') { // komentar
        while (getc(ulaz1) != '\n');
        slovo = getc(ulaz1);
        komentar++;
    }
    if (komentar != 0) {
        ungetc(slovo, ulaz1);
    }
    if (slovo !='P' && (slovo = getc(ulaz1)) != '5'){ // provjera p5
        printf("Datoteka nije P5\n");
	}
    else {
        //printf("Datoteka je P5\n");
    }

    slovo = getc(ulaz1);
    slovo = getc(ulaz1);
    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz1);
    }
    komentar = 0;
    while (slovo == '#') { // komentar

        while (getc(ulaz1) != '\n');
        slovo = getc(ulaz1);
        komentar++;
    }
    if (komentar != 0) {

        ungetc(slovo, ulaz1);
    }

    fscanf(ulaz1, "%d %d", &visina, &sirina); // ucitavamo visinu i sirinu
    //printf("%d %d\n", visina, sirina);
    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz1);
    }
    while (slovo == '#') {
        while (getc(ulaz1) != '\n');
        slovo = getc(ulaz1);
    }

    fscanf(ulaz1, "%d", &maxvrijednost);
    //printf("%d \n", maxvrijednost);

    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz1);
    }
    while (slovo == '#') {
        while (getc(ulaz1) != '\n');
        slovo = getc(ulaz1);
    }
	slovo = getc(ulaz1);
    vrijednost = (int)slovo;
    //printf("prije petlje %d\n", vrijednost); // dosli do line feed, pocinju podaci

	ulazslika1 = (slika *)malloc(sizeof(slika)); // alociraj memoriju

    ulazslika1->visina=(visina);
    ulazslika1->sirina=(sirina);
	//printf("visina i sirina %d %d\n", ulazslika1->visina, ulazslika1->sirina);

	ulazslika1->podatak = (pixel *)malloc(visina*sirina*sizeof(pixel)); // kolko pixela
	fread(ulazslika1->podatak, visina, sirina, ulaz1); // ucitaj pixele, svi blokovi ucitani

	//printf("Velicina iznosi %d\n", sizeof(ulazslika2->podatak));
	//printf("Prvi pixel %d\n",ulazslika2->podatak[1]);
	//system("pause");





	ulaz2 = fopen(datoteka2, "rb"); // lenna1.pgm

	if (ulaz2 == NULL) { // sve provjere datoteke
        printf("Datoteka nije uspjeno otvorena\n");
    }
    else {
        //printf("Datoteka otvorena\n");
    }
    slovo = getc(ulaz2);
    komentar = 0;
    while (slovo == '#') { // komentar
        while (getc(ulaz2) != '\n');
        slovo = getc(ulaz2);
        komentar++;
    }
    if (komentar != 0) {
        ungetc(slovo, ulaz2);
    }
    if (slovo !='P' && (slovo = getc(ulaz2)) != '5'){ // provjera p5
        printf("Datoteka nije P5\n");
	}
    else {
        //printf("Datoteka je P5\n");
    }

    slovo = getc(ulaz2);
    slovo = getc(ulaz2);
    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz2);
    }
    komentar = 0;
    while (slovo == '#') { // komentar

        while (getc(ulaz2) != '\n');
        slovo = getc(ulaz2);
        komentar++;
    }
    if (komentar != 0) {

        ungetc(slovo, ulaz2);
    }

    fscanf(ulaz2, "%d %d", &visina, &sirina); // ucitavamo visinu i sirinu
    //printf("%d %d\n", visina, sirina);
    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz2);
    }
    while (slovo == '#') {
        while (getc(ulaz2) != '\n');
        slovo = getc(ulaz2);
    }

    fscanf(ulaz2, "%d", &maxvrijednost);
    //printf("%d \n", maxvrijednost);

    while (slovo == '\n' && slovo == '\t' && slovo == ' ' && slovo == '\r'){
        slovo = getc(ulaz2);
    }
    while (slovo == '#') {
        while (getc(ulaz2) != '\n');
        slovo = getc(ulaz2);
    }
	slovo = getc(ulaz2);
    vrijednost = (int)slovo;
    //printf("prije petlje %d\n", vrijednost); // dosli do line feed, pocinju podaci

	ulazslika2 = (slika *)malloc(sizeof(slika)); // alociraj memoriju

    ulazslika2->visina=(visina);
    ulazslika2->sirina=(sirina);
	//printf("visina i sirina %d %d\n", ulazslika2->visina, ulazslika2->sirina);

	ulazslika2->podatak = (pixel *)malloc(visina*sirina*sizeof(pixel)); // kolko pixela
	fread(ulazslika2->podatak, visina, sirina, ulaz2); // ucitaj pixele, slijedi citanje bloka

	//printf("Velicina iznosi %d\n", sizeof(ulazslika2->podatak));
	//printf("Prvi pixel %d\n",ulazslika2->podatak[1]);
	//system("pause");

	int red_1 = 0; // racun dali postoje pixeli gore,dolje,lijevo,desno
	int stupac_1 = 0;
	int red_2 = 0;
	int stupac_2 = 0;

	red_1 = (int)floor(blok / (sirina / 16));
	stupac_1 = blok - red_1 * (sirina / 16);

	red_2 = stupac_1 * 16;
	stupac_2 = red_1 * 16;
	//printf("red: %d stupac: %d\n",red_2, stupac_2 ); // vrijednost pixela koje smo izracunali



	int trazeni_blok_2[16][16]={0};
	int red = 0;
	i=0;
	j=0;
    k=0;
    int n=0;

    int vertikala=0;
    int pomak = 0;
    pomak=blok/32;  //npr ako je blok [0-255, pomak=0], [256-511, pomak=1]
    //printf("Pomak u slici je:  %d\n", pomak);
    vertikala=512*16*pomak;    //preskoci pomak redova, 512 pixela u redu, 16 u stupcu, pomak koji blok
	while(i<16){
        for(j=(blok%32)*16+red+vertikala;j<(blok%32)*16+red+vertikala+16;j++){
            //printf("unutra sam\n");
			trazeni_blok_2[i][k] = ulazslika2->podatak[j].crno;
            //printf("Printam vrijednost %d\n", trazeni_blok[i][k]);
            k++;

        }
        i++;
        red = red+512;
        k=0;
    } // trazeni blok je spremljen


	int startx, starty, krajx, krajy;
	i=0;
	j=0;
    k=0;
	int l;
	float mad;
	float max_mad = 10000;
	int vektorx;
	int vektory;

	if (red_2 - 16 < 0){ // provjera gornji dio ruba
		startx = 0;
	}
	else {
		startx = red_2 - 16;
	}

	if ((red_2 + 32) > sirina){ // provjera desnog ruba
		krajx = sirina - 16;
	}
	else {
		krajx = (red_2 + 16);
	}

	if (stupac_2 - 16 < 0){ // provjera lijevog ruba
		starty = 0;
	}
	else {
		starty = stupac_2 - 16;
	}

	if ((stupac_2 + 32) > visina){ // provjera donjeg ruba
		krajy = visina - 16;
	}
	else {
		krajy = (stupac_2 + 16);
	}

	//printf("printam startx %d, endx %d, starty %d, endy %d\n", startx, krajx, starty, krajy);
	//system("pause");
	for(i=starty;i<=krajy;i++){
		for(j=startx;j<=krajx;j++){
			for(k=0;k<16;k++){
				for(l=0;l<16;l++){
					mad += abs(trazeni_blok_2[k][l] - (ulazslika1->podatak[(i+k) * sirina + (j+l)].crno));
					//printf("data2 %d, data %d, mad %f",trazeni_blok_2[k][l],ulazslika1->podatak[(i+k) * sirina + (j+l)].crno,mad);
					//system("pause");

				}
			}

			mad = (float) mad / (256);
			if (mad < max_mad) {
				max_mad = mad;
				vektorx = -(red_2 - j);
				vektory = -(stupac_2 - i);
			}
			mad = 0;
		}
	}

	printf("(%d,%d), MAD: %f", vektorx, vektory, max_mad);


}
