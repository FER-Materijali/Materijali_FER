#include <stdio.h>

												/*deklaracije funkcija bacajKocku i ispisi2Dpolje*/
void bacajKocku(int brigraca, int brbacanjapoigracu, int brbacanja, int *rez);
void ispisi2DPolje(int red, int stup, int maxstup, int *rez);
int main(void) {
	int polje[10][8];							/*definicija dvodimenzijskog polja: 10 redaka, 8 stupaca*/
	bacajKocku(3, 5, 8, &polje[0][0]); 			/*poziv funkcije bacajKocku: */
												/*3 igrača baca kocku po 5 puta*/
	printf("\n 3 igraca po 5 bacanja.");
	ispisi2DPolje(3, 5, 8, &polje[0][0]);		/*ispis rezultata – ispisi2Dpolje*/
	bacajKocku(4, 8, 8, &polje[0][0]);			/*poziv funkcije bacajKocku: */
												/*4 igrača baca kocku po 8 puta*/
	printf("\n 4 igraca po 8 bacanja.");
	ispisi2DPolje(4, 8, 8, &polje[0][0]);		/*ispis rezultata- ispisi2Dpolje */
	return 0;
}

void bacajKocku(int brigraca, int brbacanjapoigracu, int brbacanja, int *rez){
	static int generiraj=0;
	int i, j;
	if(generiraj==0){
		srand((unsigned)time(NULL));
		generiraj=1;
	}
	for(i=0; i<brigraca; ++i){
		for(j=0; j<brbacanjapoigracu; ++j)
			*(rez+i*brbacanja+j)=rand()%6+1;
	}
	return;
}

void ispisi2DPolje(int red, int stup, int maxstup, int *rez){
	int i, j;
	for(i=0; i<red; ++i){
		printf("\n");
		for(j=0; j<stup; ++j)
			printf("%3d", *(rez+i*maxstup+j));
	}
	return;
}