#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys\timeb.h>

#include "dodatno.h"

struct at {
	char *podaci;
	long pozicija;
	struct at *sljed, *preth;
};
typedef struct at atom;

typedef struct {
	atom *pocetak, *kraj;
} indeks;

struct at_2 {
	char *podaci;
	atom *osnovni;
	struct at_2 *sljed, *preth;
};
typedef struct at_2 atom_2;

typedef struct {
	atom_2 *pocetak, *kraj;
	indeks *osnovna;
} indeks_2;

struct timeb vrijeme1, vrijeme2;
long trajanjems;

void izgradi_indekse(FILE *podaci, indeks *idx_jmbag, indeks *idx_oib) {
	struct idx_jmbag zapisJ;
	struct idx_oib zapisO;
	char *niz = NULL;
	atom *novi;

	/*IZGRADNJA LISTE PO JMBAG-U*/

	idx_jmbag->pocetak = idx_jmbag->kraj = NULL;
	fseek(podaci, 1L*BROJ_ZAPISA*sizeof(struct student), SEEK_SET);
	/*fread(&zapisJ, sizeof(zapisJ), 1, podaci);*/
	while(fread(&zapisJ, sizeof(zapisJ), 1, podaci)==1) {
		if(strlen(zapisJ.jmbag) == 11)
			break;
		novi = (atom *) malloc (sizeof(atom));
		niz = (char *) malloc (sizeof(zapisJ.jmbag));
		strcpy(niz, zapisJ.jmbag);
		novi->podaci = niz;
		novi->pozicija = zapisJ.pozicija;
		if(idx_jmbag->pocetak == NULL) {
			novi->preth = NULL;
			idx_jmbag->pocetak = novi;
			idx_jmbag->kraj = novi;
		} else {
			novi->preth = idx_jmbag->kraj;
			idx_jmbag->kraj->sljed = novi;
			idx_jmbag->kraj = novi;
		}
	}
	idx_jmbag->kraj->sljed = NULL;

	/*IZGRADNJA LISTE PO OIB-U*/

	idx_oib->pocetak = idx_oib->kraj = NULL;
	fseek(podaci, 1L*BROJ_ZAPISA*sizeof(struct student)+BROJ_ZAPISA*sizeof(struct idx_jmbag), SEEK_SET);
	fread(&zapisO, sizeof(zapisO), 1, podaci);
	while(fread(&zapisO, sizeof(zapisO), 1, podaci)==1) {
		novi = (atom *) malloc (sizeof(atom));
		niz = (char *) malloc (sizeof(zapisO.oib));
		strcpy(niz, zapisO.oib);
		novi->podaci = niz;
		novi->pozicija = zapisO.pozicija;
		if(idx_oib->pocetak == NULL) {
			novi->preth = NULL;
			idx_oib->pocetak = novi;
			idx_oib->kraj = novi;
		} else {
			novi->preth = idx_oib->kraj;
			idx_oib->kraj->sljed = novi;
			idx_oib->kraj = novi;
		}
	}
	idx_oib->kraj->sljed = NULL;

	return;
}

void stat_idx_1(indeks idx_jmbag, indeks idx_oib, FILE *uzorci) {
	int jmbag = 0, oib = 0, pronadjenoJmbaga = 0, pronadjenoOiba = 0;
	char oibJmbag[12];
	atom *pom;

	ftime(&vrijeme1);
	while(fscanf(uzorci, "%s", oibJmbag) == 1) {
		if(strlen(oibJmbag) == 10) {
		/*AKO JE PROÈITANI NIZ JMBAG*/
			jmbag++;
			for(pom = idx_jmbag.pocetak; pom != NULL; pom = pom->sljed) {
				if(strcmp(pom->podaci, oibJmbag) == 0) {
					pronadjenoJmbaga++;
					break;
				}
			}
		} else {
		/*AKO JE PROÈITANI NIZ OIB*/
			oib++;
			for(pom = idx_oib.pocetak; pom != NULL; pom = pom->sljed) {
				if(strcmp(pom->podaci, oibJmbag) == 0) {
					pronadjenoOiba++;
					break;
				}
			}
		}
	}
	ftime(&vrijeme2);
	trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) + vrijeme2.millitm - vrijeme1.millitm;
	printf("** pretraga jednorazinskim indeksom **\npronadjeno jmbag-a: %d / %d\npronadjeno oib-a: %d / %d\nvrijeme izvodjenja: %d ms\n\n\n\n",
			pronadjenoJmbaga, jmbag, pronadjenoOiba, oib, trajanjems);
	return;
}

void izgradi_indekse_2(indeks idx_jmbag, indeks idx_oib, indeks_2 *idx_2_jmbag, indeks_2 *idx_2_oib) {
	int i, broj = 0;
	atom *pom;
	atom_2 *novi;

	/*IZGRADNJA VIŠERAZINSKE LISTE PO JMBAG-U*/

	idx_2_jmbag->pocetak = idx_2_jmbag->kraj = NULL;
	pom = idx_jmbag.pocetak;
	while(pom != NULL) {
		novi = (atom_2 *) malloc (sizeof(atom_2));
		novi->podaci  = pom->podaci;
		novi->osnovni = pom;
		if(idx_2_jmbag->pocetak == NULL) {
			novi->preth = NULL;
			idx_2_jmbag->pocetak = novi;
			idx_2_jmbag->kraj = novi;
		} else {
			novi->preth = idx_2_jmbag->kraj;
			idx_2_jmbag->kraj->sljed = novi;
			idx_2_jmbag->kraj = novi;
		}
		for(i=0; i<100; ++i) {
			if(pom == NULL) break;
			if(pom->sljed == NULL) {
				novi = (atom_2 *) malloc (sizeof(atom_2));
				novi->podaci  = pom->podaci;
				novi->osnovni = pom;
				novi->preth = idx_2_jmbag->kraj;
				idx_2_jmbag->kraj->sljed = novi;
				idx_2_jmbag->kraj = novi;
				pom = pom->sljed;
				break;
			}
			pom = pom->sljed;
		}
	}
	idx_2_jmbag->kraj->sljed = NULL;

	/*IZGRADNJA VIŠERAINSKE LISTE PO OIB-U*/

	idx_2_oib->pocetak = idx_2_oib->kraj = NULL;
	pom = idx_oib.pocetak;
	while(pom != NULL) {
		broj++;
		novi = (atom_2 *) malloc (sizeof(atom_2));
		novi->podaci  = pom->podaci;
		novi->osnovni = pom;
		if(idx_2_oib->pocetak == NULL) {
			novi->preth = NULL;
			idx_2_oib->pocetak = novi;
			idx_2_oib->kraj = novi;
		} else {
			novi->preth = idx_2_oib->kraj;
			idx_2_oib->kraj->sljed = novi;
			idx_2_oib->kraj = novi;
		}
		for(i=0; i<100; ++i) {
			if(pom == NULL) break;
			if(pom->sljed == NULL) {
				novi = (atom_2 *) malloc (sizeof(atom_2));
				novi->podaci  = pom->podaci;
				novi->osnovni = pom;
				novi->preth = idx_2_oib->kraj;
				idx_2_oib->kraj->sljed = novi;
				idx_2_oib->kraj = novi;
				pom = pom->sljed;
				break;
			}
			pom = pom->sljed;
		}
	}
	idx_2_oib->kraj->sljed = NULL;

	return;
}

void stat_idx_2(indeks_2 idx_jmbag, indeks_2 idx_oib, FILE *uzorci) {
	int i, jmbag = 0, oib = 0, pronadjenoJmbaga = 0, pronadjenoOiba = 0;
	char oibJmbag[12];
	atom *pom;
	atom_2 *pom2;

	fseek(uzorci, 0L, SEEK_SET);
	ftime(&vrijeme1);
	while(fscanf(uzorci, "%s", oibJmbag) == 1) {
		if(strlen(oibJmbag) == 10) {
		/*AKO JE PROÈITANI NIZ JMBAG*/
			jmbag++;
			for(pom2 = idx_jmbag.pocetak; pom2 != NULL; pom2 = pom2->sljed) {
				if(strcmp(pom2->podaci, oibJmbag) > 0) {
					pom2 = pom2->preth;
					pom = pom2->osnovni;
					for(i=0; i<100; ++i) {
						if(strcmp(pom->podaci, oibJmbag) == 0) {
							pronadjenoJmbaga++;
							break;
						}
						pom = pom->sljed;
						if(pom == NULL)
							break;
					}
					break;
				}
			}
		} else {
		/*AKO JE PROÈITANI NIZ OIB*/
			oib++;
			for(pom2 = idx_oib.pocetak; pom2 != NULL; pom2 = pom2->sljed) {
				if(strcmp(pom2->podaci, oibJmbag) > 0) {
					if(pom2->preth == NULL)
						break;
					pom2 = pom2->preth;
					pom = pom2->osnovni;
					for(i=0; i<100; ++i) {
						if(strcmp(pom->podaci, oibJmbag) == 0) {
							pronadjenoOiba++;
							break;
						}
						pom = pom->sljed;
						if(pom == NULL)
							break;
					}
					break;
				}
			}
		}
	}
	ftime(&vrijeme2);
	trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) + vrijeme2.millitm - vrijeme1.millitm;
	printf("** pretraga dvorazinskim indeksom **\npronadjeno jmbag-a: %d / %d\npronadjeno oib-a: %d / %d\nvrijeme izvodjenja: %d ms\n\n\n\n",
			pronadjenoJmbaga, jmbag, pronadjenoOiba, oib, trajanjems);
	return;
}

int main(void) {
	FILE *podaci, *uzorci;
	indeks jmbag, oib;
	indeks_2 jmbag_2, oib_2;
	if((podaci = fopen("studenti.dat", "rb")) == NULL) {
		printf("Neuspjesno otvaranje datoteke \"studenti.dat\"");
		exit (1);
	}
	if((uzorci = fopen("uzorci.txt", "r")) == NULL) {
		printf("Neuspjesno otvaranje datoteke \"uzorci.txt\"");
		exit (1);
	}
	izgradi_indekse(podaci, &jmbag, &oib);
	stat_idx_1(jmbag, oib, uzorci);
	izgradi_indekse_2(jmbag, oib, &jmbag_2, &oib_2);
	stat_idx_2(jmbag_2, oib_2, uzorci);
	return 0;
}