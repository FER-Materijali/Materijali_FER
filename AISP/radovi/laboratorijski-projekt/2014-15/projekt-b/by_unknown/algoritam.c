#include <stdio.h>
#include <math.h>

#include "algoritam.h"
#include "nadji.h"
#include "osnovni.h"

unsigned long velbloka=0;	/*globalne varijable koristene na vise mjesta u programu*/
unsigned long brstavki=0;
unsigned long brblokova=0;
unsigned long velblokb=0;

void inicijaliziraj(FILE *ulaz){	/*odreduje broj blokova, velicinu bloka i broj zapisa*/
	element zapis={0};
	rewind(ulaz);	/*vraca file pt. od ulaz na pocetak dat.*/
	while(fread(&zapis, sizeof(zapis), 1, ulaz)==1) brstavki++;		/*brojac zapisa, inkrementira se svakom iteracijom while petlje*/
	rewind(ulaz);	/*vraca file pt. od ulaz na pocetak dat.*/
	velbloka=(unsigned long) sqrt(brstavki);		/*odreduje optimalnu velicinu bloka*/
	brblokova=(unsigned long) (brstavki/velbloka);	/*odreduje ukupan broj blokova*/
	velblokb=velbloka*sizeof(zapis);	/*racunanje velicine bloka u bajtovima*/
}

long nadji_blok(char znak, FILE *ulaz){		/*wrapper funkcija od nadji_blok_r, proslijeduje tocne parametere i vraca adresu*/
	return nadji_blok_r(znak, ulaz, 0, brblokova);	/*pocetnog zapisa bloka u kojem se nalazi prvi zapis koji sadrzi pocetni znak jednak trazenom*/
}

long nadji_blok_r(char znak, FILE *ulaz, long lijevo, long desno){	/*funkcija rekurzivnog bin. searcha, prima ulazni znak, pt. na ulaznu dat. i granice*/
	element zapis={0};												/*a vraca adresu bloka gdje se prvi put u prvom znaku zapisa pojavljuje trazeni znak*/
	unsigned long sredina=lijevo+((desno-lijevo)/2);	/*racunanje sredisnjeg bloka*/
	if((lijevo==sredina) || (desno==sredina)) goto kraj;	/*uvjet bin. searcha, ako je ispunjen automatski skace na kraj funkcije*/
	fseek(ulaz, (sredina*velblokb), SEEK_SET);	/*pozicioniranje file pt. na pocetak sredisnjeg bloka*/
	fread(&zapis, sizeof(zapis), 1, ulaz);	/*citanje prvog zapisa sredisnjeg bloka*/
	if(znak==zapis.word[0]){	/*ako je prvi znak prvog zapisa jednak trazenom onda idemo u daljnju provjeru je li to stvarno blok kojeg trazimo*/
		fseek(ulaz, ((sredina*velblokb)-sizeof(zapis)), SEEK_SET);	/*pozicioniranje file pt. na kraj prethodnog bloka*/
		fread(&zapis, sizeof(zapis), 1, ulaz);	/*citanje zadnjeg zapisa u prethodnom bloku*/
		if(zapis.word[0]!=znak) goto kraj;	/*ako u prvom znaku zadnjeg zapisa nema trazenog znaka skacemo na kraj i vraca se pozicija sredisnjeg bloka*/
		else return nadji_blok_r(znak, ulaz, lijevo, sredina);	/*a ako ga ima onda idemo dalje s rekurzijom, desna granica se postavlja na sredinu*/
	}
	else if(znak<zapis.word[0]) return nadji_blok_r(znak, ulaz, lijevo, sredina);	/*ako je vrijednost znaka manja od vrijednosti pocetnog znaka pocetnog zapisa postavljamo novu desnu granicu*/
	else if(znak>zapis.word[0]) return nadji_blok_r(znak, ulaz, sredina, desno);	/*ako je vrijednost znaka veca od vrijednosti pocetnog znaka pocetnog zapisa postavljamo novu lijevu granicu*/
	kraj: 
	return (sredina*velblokb);
}