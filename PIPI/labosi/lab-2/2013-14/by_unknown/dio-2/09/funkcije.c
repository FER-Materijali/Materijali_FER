#include"funkcije.h"
#include<stdio.h>
#include<string.h>

void genPodniz(char *nizUlaz, char *podNiz, int pocPozicija, int duljPodniz){
																			int i=0;
																			for(i=pocPozicija;i<(pocPozicija+duljPodniz);++i) podNiz[i-pocPozicija]=nizUlaz[i];
}

int nizoviJednaki (char *niz1, char *niz2){
										int i=0;
										if(strlen(niz1)!=strlen(niz2)) return 0;
										for(i=0;i<strlen(niz1);++i){
																	if(niz1[i]!=niz2[i]) return 0;
										}
										return 1;
}