#include <stdio.h>
#include <stdlib.h>
struct element {
	char	JMGB[13+1];
	char	ImePrezime[40+1];
	float	Prihod;
	float	PlatitiPorez;
};
typedef struct element zapis; 
zapis* Ucitaj (char *FileName, int *BrElem) {
	int		i; //lokalne varijable
	long	Br;
	FILE 	*fp;
	zapis	*Polje = NULL;
	zapis	Elem;
	if ((fp = fopen(FileName, "rb")) == NULL) {
		printf("Ne mogu otvoriti datoteku");
		return NULL;
	}
	fread (&Br, sizeof(long), 1, fp );					
	if( Br > 0 ) {
	Polje = (zapis *) malloc (Br * sizeof(zapis));			
	// inicijalizacija varijable Polje – sadrzi adresu 
	// na kojoj je slobodno kontinuirano podruèje od 
	// Br * sizeof(zapis) byte-ova
	}
	else {
		printf ("Neispravan broj elemenata");
		return	NULL;
	}
	i = 0;
	// pridruživanje sadržaja jedne strukture drugoj kopiranjem sadržaja memorije
	// moglo je i: fread (Polje, sizeof(zapis), Br, fp);
	while (fread (&Elem, sizeof(zapis), 1, fp) == 1)  Polje[i++] = Elem;	
	*BrElem = Br; //uz pretpostavku da smo sve uspješno proèitali
	fclose(fp);
	return Polje;
	}
int	MaxPorez( zapis *Polje, int BrElem ) {
	int	i, MaxInd = 0;
	float Max;
	Max = Polje[0].PlatitiPorez;
	for(i = 1; i < BrElem; i++ ) {
		if( Polje[i].PlatitiPorez > Max ) {
			MaxInd = i;
			Max = Polje[i].PlatitiPorez;
		}
	}
	return MaxInd;
}

int main(){
	int	BrElem, MaxInd; //lokalne varijable
	char FileName[40];
	zapis *Polje;
	printf("Unesite ime datoteke : ");
	gets(FileName);
	Polje = Ucitaj(FileName, &BrElem);
	if( Polje != NULL ) {
		MaxInd = MaxPorez(Polje, BrElem);
		printf("Najviše poreza treba platiti %s, u iznosu od %f", Polje[MaxInd].ImePrezime, 
		Polje[MaxInd].PlatitiPorez );
	}
	free (Polje);
}
