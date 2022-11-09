#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "algoritam.h"
#include "nadji.h"
#include "osnovni.h"

long nadji(char *uzorak, long pocetak_bloka, void *izvor){	/*funkcija prima ulaznu rijec sa skrivenim znakovima, blok od kojeg pocinje pretraga i void pointer*/
	FILE *fi=(FILE*) izvor;	/*castanje void pt. u FILE pt.*/
	element zapis={0};
	unsigned char j=0, k=0, nalpha=0, nmatch=0, lenuzorak=0, lenzapis=0, flag=0;
	unsigned long i=0;
	if(pocetak_bloka<0) pocetak_bloka=nadji_blok(uzorak[poz], NULL);	/*odredjuje pocetni blok pretrage pomocu pozicije prvog otkrivenog slova u uzorku*/
	if(pocetak_bloka<0) goto kraj;	/*ako primi invalid vrijednost za pocetak bloka automatski skace na kraj funkcije*/
	lenuzorak=strlen(uzorak);	/*pomocu f. strlen otkriva se duljina stringa trazene rijeci*/
	for(j=0;j<lenuzorak;j++){	/*petlja sece po ulaznom stringu i broji broj slova u stringu koji sprema onda u nalpha var*/
		if(isalpha(uzorak[j])) nalpha++;
	}
	fseek(fi, pocetak_bloka, SEEK_SET);	/*pomicanje file pt. na pocetak bloka od kojeg pocinjemo pretragu*/
	for(i=pocetak_bloka;i<(brstavki*sizeof(element));i++){	/*petlja pocinje od pocetka bloka i ide do kraja datoteke, trazi koje rijeci se podudaraju s ulaznom rijeci*/
		fread(&zapis, sizeof(zapis), 1, fi);	/*cita zapis iz dat.*/
		lenzapis=strlen(zapis.word);	/*otkriva se duljina pojedinog zapisa*/
		flag=0;	/*resetiranje flaga*/
		nmatch=0;	/*resetiranje brojaca*/
		if(lenuzorak==lenzapis){	/*ako se duljina zapisa podudara s duljinom ulazne rijeci ulazimo u petlju koja provjerava podudarnost zapisa s ul. rijeci*/
			for(j=0;j<lenzapis;j++){	/*petlje idu po uzorku i zapisu i provjeravaju pojavljuju li se otkrivena slova na mjestima gdje je vrijednost uzorka _*/
				for(k=0;k<lenzapis;k++){
					if(uzorak[j]==zapis.word[k] && uzorak[k]=='_') flag=1;	/*ako da flag se postavlja u 1*/
				}
				if(flag==1) break;	/*ako su se otkrivena slova pojavila na mjestima gdje je _ u uzorku onda tu rijec sigurno ne trebamo pa flag ostaje 1 i automatski izlazimo iz petlje*/
				flag=0;
			}
			if(flag==0){	/*ako je flag veci od 0 znaci da zapis nije prosao gornji uvjet*/
				for(j=0;j<lenzapis;j++){	/*petlja sece po zapisu do duljine ulazne rijeci*/
					if(uzorak[j]=='_') continue;	/*ako je znak ulazne rijeci skriven idemo na sljedecu iteraciju petlje*/
					else if(uzorak[j]==zapis.word[j]) nmatch++;	/*ali ako je znak ulazne rijeci poznat i jednak znaku zapisa na istoj poziciji onda povecamo brojac*/
					else break;	/*izlazak iz petlje ako nema podudaranja*/
				}
			}else continue;	/*ako uvjet flaga nije ispunjen odmah idemo na sljedecu iteraciju petlje*/
		}else continue;	/*ako uvjet duljine nije ispunjen odmah idemo na sljedecu iteraciju petlje*/
		if(nalpha==nmatch) return (ftell(fi) - sizeof(zapis));	/*ako se broj znakova u zapisu podudara s brojem znakova u ulaznoj rijeci vracamo poziciju zapisa*/
	}
	kraj:
	return -1;	/*vraca -1 ako ne pronade zapis koji se podudara s ulaznom rijeci, ili ako primi invalid vrijednost za pocetak bloka*/
}