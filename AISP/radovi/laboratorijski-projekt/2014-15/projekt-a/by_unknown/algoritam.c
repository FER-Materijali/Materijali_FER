#include <stdio.h>  //treba za rad s datotekama
#include <string.h>  //treba za funkciju strcmp
#include <math.h>  //treba za funkciju sqrt
#include "algoritam.h"  //treba za deklaracije funkcija
#include "dodatno.h"  //treba za deklaraciju struct stanovnik

long vel_bloka, vel_datoteke;  //globalne varijable - napune se u funkciji inicijaliziraj

long nadji_blok_r(char *ime_prezime, FILE *ulaz, long lijevo, long desno){ //funkcija dobiva redni broj lijevog i desnog bloka (npr. 22. blok, 23. blok...), a ne adresu bloka
	struct stanovnik podatak;
	long sredina, adresa_srednjeg_bloka;

	sredina = (long)(((desno - lijevo) / 2) + lijevo); //Drugi nacin (losiji zbog preljeva velikih brojeva): (lijevo + desno) / 2;
	adresa_srednjeg_bloka = (long)(sredina*vel_bloka);

	fseek(ulaz, adresa_srednjeg_bloka, SEEK_SET);  //postavljanje na poziciju srednjeg bloka u datoteci
	fread(&podatak, sizeof(podatak), 1, ulaz);  //citanje podatka na sredini

	while (desno - lijevo > 1){ //podatak se mora nalaziti unutar 1 bloka pa se taj blok kasnije slijedno pretrazuje
		if (strcmp(ime_prezime, podatak.ime_prezime) < 0){  //ako se trazeni podatak nalazi u lijevoj polovici
			desno = sredina;
			return nadji_blok_r(ime_prezime, ulaz, lijevo, desno);
		}
		if (strcmp(ime_prezime, podatak.ime_prezime) == 0){  //ako binarnom pretragom naleti bas na trazeni podatak
			return adresa_srednjeg_bloka;
		}
		if (strcmp(ime_prezime, podatak.ime_prezime) > 0){  //ako se trazeni podatak nalazi u desnoj polovici
			lijevo = sredina;
			return nadji_blok_r(ime_prezime, ulaz, lijevo, desno);
		}
	}
	return (long)(lijevo*vel_bloka); //kad nadje moguci blok, vrati adresu s kojom zapocinje blok
}

long nadji_blok(char *ime_prezime, FILE *ulaz){
	long zadnji_blok;
	zadnji_blok = (long)(vel_datoteke / vel_bloka); //broj blokova
	return nadji_blok_r(ime_prezime, ulaz, 0, zadnji_blok);  //prvi poziv funkcije nadji_blok_r
}

void inicijaliziraj(FILE *ulaz){
	vel_bloka = sqrt(NSTAVKI)*sizeof(struct stanovnik);
	vel_datoteke = NSTAVKI*sizeof(struct stanovnik);
}

char *izl_naziv(){
	return ("binarna_pretraga.rez");
}