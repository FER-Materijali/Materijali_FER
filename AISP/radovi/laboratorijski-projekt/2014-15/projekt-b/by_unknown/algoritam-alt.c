#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "algoritam.h"
#include "nadji.h"
#include "osnovni.h"

atom *pocetci[26]={NULL};	/*globalne varijable koristene na vise mjesta u programu*/
indeks indx={0};
unsigned long velbloka=0;
unsigned long brstavki=0;
unsigned long brblokova=0;
unsigned long velblokb=0;

void inicijaliziraj(FILE *ulaz){	/*funkcija koristi razne subfunkcije da bi ispravno nasla broj i velicinu blokova, kreirala sortiranu dvostruko povezanu*/
	pom *polje=NULL;	/*listu i popunila na kraju polje pointera koje sluzi da bi se nasao pocetni blok pretrage*/
	if(brblokova==0) init_blok(ulaz);
	polje=create_sort_polje(ulaz);
	create_list(polje);
	free(polje);	/*oslobadjanje zauzete memorije za pomocno dinamicko polje struktura*/
	fill_array();
}

void init_blok(FILE *ulaz){	/*odreduje broj blokova, velicinu bloka i broj zapisa*/
	element zapis={0};
	rewind(ulaz);	/*vraca file pt. od ulaz na pocetak dat.*/
	while(fread(&zapis, sizeof(zapis), 1, ulaz)==1) brstavki++;		/*brojac zapisa, inkrementira se svakom iteracijom while petlje*/
	rewind(ulaz);	/*vraca file pt. od ulaz na pocetak dat.*/
	velbloka=(unsigned long) sqrt(brstavki);		/*odreduje optimalnu velicinu bloka*/
	brblokova=(unsigned long) (brstavki/velbloka);	/*odreduje ukupan broj blokova*/
	velblokb=velbloka*sizeof(zapis);	/*racunanje velicine bloka u bajtovima*/
}

atom* create_atom(void){
	atom *new=(atom*) calloc(1, sizeof(atom));	/*kreiranje novog praznog atoma, funkcija vraca pointer na novi atom u heapu*/
	return new;
}

pom* create_sort_polje(FILE *ulaz){	/*funkcija vraca pointer na polje u heapu, polje sadrzi sortirane strukture tipa pom*/
	pom *polje=(pom*) calloc(brblokova, sizeof(pom));	/*kreiranje praznog dinamickog polja struktura odgovarajuce velicine*/
	element zapis={0};
	pom temp={0};
	char flag=0;
	unsigned long i=0, j=0;
	for(i=0;i<brblokova;i++){	/*petlja ucitava zapis po zapis iz datoteke ulaz i kopira svaki zapis u odgovarajucu strukturu u polju struktura, uz to*/
		fseek(ulaz, (i*velblokb), SEEK_SET);	/*ubacuje i polozaj bloka tog zapisa u tu istu strukturu*/
		fread(&zapis, sizeof(zapis), 1, ulaz);
		strcpy((polje+i)->word, zapis.word);
		(polje+i)->pocetak_bloka=i*velblokb;
	}
	for(i=0;i<brblokova;i++){	/*bubble sort nad poljem struktura, sortira se po slovu na poziciji poz u stringu word tako da se ubacuju odgovarajuci*/
		for(j=0;j<brblokova-1;j++){	/*pointeri na string word s pomakom poz u funkciju strcmp*/
			if(strcmp(((polje+j)->word)+poz, ((polje+j+1)->word)+poz)>0){
				temp=*(polje+j);	/*ubacivanje strukture na poziciji polje[j] u temp varijablu*/
				*(polje+j)=*(polje+j+1);	/*ubacivanje strukture na poziciji polje[j+1] na poziciju polje[j]*/
				*(polje+j+1)=temp;	/*prebacivanje strukture iz varijable temp na poziciju polje[j+1]*/
				flag=1;	/*zastavica oznacuje da se dogodila zamjena*/
			}
		}
		if(flag==0) break;	/*automatski izlazak iz petlje ako se nije dogodila ni jedna zamjena, polje je sortirano*/
	}
	return polje;	/*vracanje pointera na sortirano dinamicko polje u heapu*/
}

void create_list(pom *polje){	/*funkcija kreira dvostruko povezanu listu iz sortiranog dinamickog polja struktura*/
	unsigned long i=0;
	indx.glava=NULL;
	indx.rep=NULL;
	for(i=0;i<brblokova;i++) add_to_list((polje+i)->word, (polje+i)->pocetak_bloka);
}

void add_to_list(char *word, unsigned long pocetak_bloka){	/*funkcija kreira atome liste, ulazni podaci dolaze iz sortiranog dinamickog polja struktura*/
	atom *new=create_atom();	/*poziva se funkcija koja kreira novi prazni atom*/
	strcpy(new->word, word);	/*kopiranje ulazne rijeci u novi atom*/
	new->pocetak_bloka=pocetak_bloka;	/*kopiranje ulaznog pocetnog bloka u novi atom*/
	if(indx.glava==NULL && indx.rep==NULL){	/*ako je ispunjen uvjet ne postoji lista, postavlja se nulti atom*/
		indx.glava=new;
		indx.rep=new;
	}else{	/*inace se povezuju sljedeci atomi u listi s prethodnima i postavlja se tocan pointer na rep*/
		indx.rep->sljed=new;
		new->preth=indx.rep;
		indx.rep=new;
	}
}

void fill_array(void){	/*funkcija puni polje pointera s pointerima na atom koji sadrze prvu pojavu pojedinog slova abecede na poziciji poz rijeci word*/
	atom *temp=NULL;
	unsigned char i=0, flag=0;
	for(flag='a';flag<='z';flag++){	/*petlja ide slovo po slovo i provjerava po listi gdje se nalazi blok gdje je u pocetnom zapisu na poziciji poz prvi put*/
		temp=indx.glava;	/*uoceno pojedino slovo abecede, nakon toga sprema se pointer na taj atom u polje pointera na odgovarajucu poziciju*/
		while(temp!=NULL){	
			if(temp->word[poz]==flag){
				pocetci[i]=temp;	
				i+=1;
				break;	/*cim se naidje na prvu pojavu pojedinog slova abecede automatski se skace iz while petlje i nastavlja pretraga po drugim slovima*/
			}
		temp=temp->sljed;
		}
	}
}

long nadji_blok(char znak, FILE *ulaz){
	atom *temp=pocetci[((int) znak)-97];	/*znak se konvertira u int da bi se onda nasla tocna pozicija pointera na atom koji sadrzi prvu pojavu tog znaka na poz*/
	if(temp!=NULL) return temp->pocetak_bloka;
	else return -1;
}