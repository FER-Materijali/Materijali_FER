#include"funkcije.h"
#include<stdlib.h>
#include<time.h>
char generirajZnak(int vrsta) {
	char znak;
	static int seedset=0;
	if (!seedset) {
		srand((unsigned)time(NULL));
		seedset=1;
	}
	switch (vrsta) {
		case 1:
		  znak=rand()%(26*2);
		  return znak<26 ? znak+'A' : znak-26+'a'; 
		case 2:
		  znak=rand()%('9'-'0'+1)+'0';
		  return znak;
		case 3:
		  znak=rand()%3;
		  if (znak==0) {
		  	return '!';
		  }
		  if (znak==1) {
		  	return '?';
		  }
		  if (znak==2) {
		  	return '/';
		  }
	}
}
void generirajLozinku(int ns, int nb, int ni, char izl[]) {
	int kljuc, i=0;
	char znak;
	srand((unsigned)time(NULL));
	while (ns>0 || nb>0 || ni>0) {
		  do {
		     kljuc=rand()%3+1;
	      } while ((kljuc==1 && ns==0) || (kljuc==2 && nb==0) || (kljuc==3 && ni==0));
	      switch (kljuc) {
		      case 1: --ns;
		      break;
		      case 2: --nb;
		      break;
		      case 3: --ni;
		      break;
	      }
	      znak=generirajZnak(kljuc);
	      izl[i++]=znak;
	}
	izl[i]='\0';
}