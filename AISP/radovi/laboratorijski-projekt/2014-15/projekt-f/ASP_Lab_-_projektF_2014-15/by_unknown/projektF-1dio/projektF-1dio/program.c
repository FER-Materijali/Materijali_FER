#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys\timeb.h>

#include "dodatno.h"

struct timeb vrijeme1, vrijeme2;
long trajanjems;

#define BROJ_ZAPISA 10000
#define C 100
#define BLOKJ ( C * sizeof(struct idx_jmbag) )
#define BLOKO ( C * sizeof(struct idx_oib) )
#define M ( BROJ_ZAPISA / C )

typedef struct student student;
typedef struct idx_jmbag idx_jmbag;
typedef struct idx_oib idx_oib;

void stat_zapisi(FILE *podaci, FILE *uzorci) {
	int  oib=0, jmbag=0;
	int brojacO=0, brojacJ=0, i, isti;
	char oJ[12];
	student student;

	ftime(&vrijeme1);
	while(fscanf(uzorci, "%s", oJ) == 1) {
		if(strlen(oJ) == 11) {
			oib++;
			for(i=0; i<BROJ_ZAPISA; ++i) {
				fread(&student, sizeof(student), 1, podaci);
				isti = strncmp(oJ, student.oib, 11);
				if(isti == 0) {
					brojacO++;
					break;
				}
			}	
		} else if(strlen(oJ) == 10) {
			jmbag++;
			for(i=0; i<BROJ_ZAPISA; ++i) {
				fread(&student, sizeof(student), 1, podaci);
				isti = strncmp(oJ, student.jmbag, 10);
				if(isti == 0) {
					brojacJ++;
					break;
				}
			}
		}
		fseek(podaci, 0L, SEEK_SET);
	}
	ftime(&vrijeme2);

	trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) + vrijeme2.millitm - vrijeme1.millitm;
	printf("** pretraga po zapisima **\npronadjeno oib-a: %d / %d\npronadjeno jmbag-a: %d / %d\nvrijeme izvodenja: %d ms\n\n",
		 brojacO, oib, brojacJ, jmbag, trajanjems);
}

void stat_idx_slijed(FILE *podaci, FILE *uzorci) {
	int oib=0, jmbag=0;
	int brojacO=0, brojacJ=0, i, isti;
	char oJ[12];
	idx_jmbag idx_jmbag;
	idx_oib idx_oib;

	ftime(&vrijeme1);
	while(fscanf(uzorci, "%s", oJ) == 1) {
		if(strlen(oJ) == 11) {
			oib++;
			fseek(podaci, (long) (BROJ_ZAPISA*sizeof(student) + BROJ_ZAPISA*sizeof(idx_jmbag)), SEEK_SET);
			for(i=0; i<BROJ_ZAPISA; ++i) {
				fread(&idx_oib, sizeof(idx_oib), 1, podaci);
				isti = strncmp(oJ, idx_oib.oib, 11);
				if(isti == 0) {
					brojacO++;
					break;
				}
			}
		} else if(strlen(oJ) == 10) {
			jmbag++;
			fseek(podaci, (long) BROJ_ZAPISA*sizeof(student), SEEK_SET);
			for(i=0; i<BROJ_ZAPISA; ++i) {
				fread(&idx_jmbag, sizeof(idx_jmbag), 1, podaci);
				isti = strncmp(oJ, idx_jmbag.jmbag, 10);
				if(isti == 0) {
					brojacJ++;
					break;
				}
			}
		}
	}
	ftime(&vrijeme2);

	trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) + vrijeme2.millitm - vrijeme1.millitm;
	printf("** slijedna pretraga indeksa **\npronadjeno oib-a: %d / %d\npronadjeno jmbag-a: %d / %d\nvrijeme izvodenja: %d ms\n\n",
		 brojacO, oib, brojacJ, jmbag, trajanjems);
}

void stat_idx_blok(FILE *podaci, FILE *uzorci) {
	int oib=0, jmbag=0, pronadjenoOiba = 0, pronadjenoJmbaga = 0;
	int i, isti, podatakNadjen=0;
	char oJ[12];
	idx_jmbag idx_jmbag, pretinacJmbaga[C];
	idx_oib idx_oib, pretinacOiba[C];

	ftime(&vrijeme1);
	while(fscanf(uzorci, "%s", oJ) == 1) {
		podatakNadjen = 0;
		if(strlen(oJ) == 11) {
			oib++;
			fseek(podaci, (long) (BROJ_ZAPISA*sizeof(student) + BROJ_ZAPISA*sizeof(idx_jmbag)), SEEK_SET);
			for(i=0; i<M; ++i) {
				fread(&idx_oib, sizeof(idx_oib), 1, podaci);
				isti = strncmp(oJ, idx_oib.oib, 11);
				if(isti < 0)
					break;
				else if(isti == 0) {
					podatakNadjen = 1;
					break;
				} else {
					fseek(podaci, BLOKO - sizeof(idx_oib), SEEK_CUR);
				}
			}
			if(podatakNadjen == 0) {
				fseek(podaci, -1L * (BLOKO + sizeof(idx_oib)), SEEK_CUR);
				fread(pretinacOiba, sizeof(pretinacOiba), 1, podaci);
				for(i = 1; i < C; ++i) {
					isti = strncmp(oJ, pretinacOiba[i].oib, 11);
					if(isti == 0) {
						podatakNadjen = 1;
						break;
					}
				}
			}
			if(podatakNadjen == 1)
				pronadjenoOiba++;
		} else if(strlen(oJ) == 10) {
			jmbag++;
			fseek(podaci, (long) (BROJ_ZAPISA*sizeof(student)), SEEK_SET);
			for(i = 0; i < M; ++i) {
				fread(&idx_jmbag, sizeof(idx_jmbag), 1, podaci);
				isti = strncmp(oJ, idx_jmbag.jmbag, 11);
				if(isti < 0)
					break;
				else if(isti == 0) {
					podatakNadjen = 1;
					break;
				} else {
					fseek(podaci, BLOKJ - sizeof(idx_jmbag), SEEK_CUR);
				}
			}
			if(podatakNadjen == 0) {
				fseek(podaci, -1L * (BLOKJ + sizeof(idx_jmbag)), SEEK_CUR);
				fread(pretinacJmbaga, sizeof(pretinacJmbaga), 1, podaci);
				for(i = 1; i < C; ++i) {
					isti = strncmp(oJ, pretinacJmbaga[i].jmbag, 11);
					if(isti == 0) {
						podatakNadjen = 1;
						break;
					}
				}
			}
			if(podatakNadjen == 1)
				pronadjenoJmbaga++;
		}
	}
	ftime(&vrijeme2);
	trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) + vrijeme2.millitm - vrijeme1.millitm;
	printf("** pretraga indeksa po blokovima **\npronadjeno oib-a: %d / %d\npronadjeno jmbag-a: %d / %d\nvrijeme izvodenja: %d ms\n\n",
		 pronadjenoOiba, oib, pronadjenoJmbaga, jmbag, trajanjems);
}

int main(void) {
	FILE *podaci, *uzorci;
	if((podaci = fopen("studenti.dat", "rb")) == NULL) {
		printf("Neuspjesno otvaranje datoteke \"studenti.dat\"");
		return 1;
	}
	if((uzorci = fopen("uzorci.txt", "r")) == NULL) {
		printf("Neuspjesno otvaranje datoteke \"uzorci.txt\"");
		return 1;
	}
	stat_zapisi(podaci, uzorci);
	fseek(podaci, 0L, SEEK_SET);
	fseek(uzorci, 0L, SEEK_SET);
	stat_idx_slijed(podaci, uzorci);
	fseek(podaci, 0L, SEEK_SET);
	fseek(uzorci, 0L, SEEK_SET);
	stat_idx_blok(podaci, uzorci);
	fclose(podaci);
	fclose(uzorci);
	return 0;
}