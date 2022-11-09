#include <stdio.h>
#define MAXSTOG 100
int dodaj(int stavka, int stog[], int n, int *vrh) {
	// ako je stog pun
	if (*vrh >= n-1) return 0;
	// ako ima mjesta na stogu
	(*vrh)++;					
	stog [*vrh] = stavka;
	return 1;
} 
int skini (int *stavka, int stog[], int *vrh) {
	// ako je stog prazan
	if (*vrh < 0) return 0;
	// ako ima zapisa na stogu
	*stavka = stog [*vrh];
	(*vrh)--;
	return 1; 
}
int izbaciNajveci(int stog[],int pomStog[], int n, int *vrh) {
	int pomVrh = -1, elemMax, stavka;
	// prebaci element s vrha stoga na pomocni stog,
	// a ujedno ga oznaci kao inicijalno najveci element na stogu
	skini(&elemMax, stog, vrh);
	dodaj(elemMax, pomStog, n, &pomVrh);
	// nadji najveci element na stogu, 
	// a pritom prebacuj sve stavke na pomocni stog
	while (skini(&stavka, stog, vrh)) {
		dodaj(stavka, pomStog, n, &pomVrh);
		if (stavka > elemMax) elemMax = stavka;
	}
	// skidaj s pomocnog stoga sve elemente 
	// i sve, osim najveceg, premjestaj nazad na pocetni stog
	// (Ako ima vise najvecih, sve ce ih izbaciti!)
	while (skini(&stavka, pomStog, &pomVrh)) {
		if (stavka < elemMax) dodaj(stavka, stog, n, vrh);   
	}
	return elemMax;
}

int main() {
  return 0;
}