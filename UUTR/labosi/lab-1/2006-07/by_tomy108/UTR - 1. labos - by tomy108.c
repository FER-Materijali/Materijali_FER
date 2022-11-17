#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


int main(){
	FILE *inp;
	char niz[256]; 
	char znak;
	int duljina, ulaz, i,prekid=0,stanje;
	int automat [24][7]={                   //ovo je tablica s automatima i pripadajucim stanjima, zadnji znak je prihvatljivost automata
			{23,23,23,1,2,3,0},
			{4,5,6,23,23,23,0},
			{7,8,9,23,23,23,0},
			{10,11,12,23,23,23,0},
			{23,23,23,23,14,16,1},
            {23,23,23,23,23,15,1},
            {23,23,23,23,13,16,1},
            {23,23,23,19,23,22,1},
            {23,23,23,23,23,23,1},
            {23,23,23,17,23,21,1},
            {23,23,23,18,14,23,1},
            {23,23,23,20,23,23,1},
            {23,23,23,18,13,23,1},
            {7,23,23,23,23,23,0},
            {23,23,9,23,23,23,0},
            {10,23,12,23,23,23,0},
            {23,11,23,23,23,23,0},
            {4,23,23,23,23,23,0},
            {23,5,23,23,23,23,0},
            {23,23,6,23,23,23,0},
            {4,23,6,23,23,23,0},
            {10,23,23,23,23,23,0},
            {23,23,12,23,23,23,0},
            {23,23,23,23,23,23,0}};

	if ((inp = fopen ("labos.txt","r")) == NULL){            //ucitava datoteku
			printf ("Greska kod ucitavanja datoteke\n");
		       exit(1);}
	while ((fscanf (inp, "%s", &niz))!=EOF){ //dok moze ucitati niz vrti while petlju
		duljina=(int) strlen (niz);                 //duljina niza
		printf ("\nUcitan je niz: %s\n",niz);
		stanje=0;               //pocetno stanje niza je 0
		for (i=0;i<duljina;i++){                    //for petlja, ucitava znak po znak iz niza
			znak=niz[i];                        //nas automat prihvaca samo brojeve i slova kao ulaze
			printf ("\n\nUcitavam znak: %c",znak);       // buduci da mi radimo s matricom gdje su adrese odredjene samo brojevima
			switch (znak){              //u ovoj case naredbi pridodajemo znakovima broj, adresu u matrici
				case \\'1\\': ulaz=0; break;
				case \\'2\\': ulaz=1; break;
				case \\'3\\': ulaz=2; break;
				case \\'A\\': ulaz=3; break;
				case \\'B\\': ulaz=4; break;
				case \\'C\\': ulaz=5; break;
				default: printf ("\nUcitan nedopusteni znak\n"); prekid=1; break; // ako je ucitan nedopusten znak, prekida case petlju0
			} 
			if (prekid==1){              //ovdje prekida i for petlju jer nismo to mogli odmah dva breaka ucitat
				prekid=0; break;
			}
			printf ("\nNalazim se u stanju: %d",stanje);
			stanje=automat[stanje][ulaz];         //prelazi u novo stanje, ucitava se iz tablice stanje i ulaz, bas kao u knjizi
			printf ("\nPrelazim u stanje: %d",stanje);
			if (stanje==23) {                      //ako je u gresci (stanje 23) prekidaj
				printf("\nAutomat zadani niz ne prihvaca zbog nedopustenog poteza!"); 
				break;}
			printf ("\nDosad ucitani dio niza se ");
			if (automat[stanje][6]==0) printf("ne ");
			printf ("prihvaca.");
		}
		printf ("\n\nAutomat zadani niz ");
		if (automat[stanje][6]==0) printf("NE prihvaca!\n");
		else printf ("prihvaca!");
	}
	printf("\nAutomat je zavrsio s radom!");
	close(inp);
	scanf("%c",&znak);
}