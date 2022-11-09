#include <stdio.h>  //treba za rad s datotekama
#include <string.h>  //treba za funkciju strcmp
#include <math.h>  //treba za funkciju sqrt
#include "nadji.h"  //treba za deklaraciju funkcije
#include "dodatno.h"  //treba za definiciju struct stanovnik

long nadji(char *ime_prezime, FILE *ulaz, long pocetak_bloka){
	struct stanovnik podatak;
	int i = 0;

	fseek(ulaz, pocetak_bloka, SEEK_SET); /*postavi se na pocetak bloka*/
	do{
		fread(&podatak, sizeof(podatak), 1, ulaz);  //procitaj podatak
		if (strcmp(podatak.ime_prezime, ime_prezime) == 0)  //provjeri je li to trazeni podatak
			return SEEK_CUR - sizeof(podatak); /*ako je to trazeni podatak, vec ga je procitao pa se mora vratiti za 1 zapis unatrag*/
		i++;  //povecaj brojac podataka u bloku
	} while ((strcmp(podatak.ime_prezime, ime_prezime) != 0) && (i<sqrt(NSTAVKI))); /*radi sve dok su zapisi razliciti i i je manji od broja stavaka u 1 bloku*/
	return -1;  //ako ga nije nasao, vrati -1
}