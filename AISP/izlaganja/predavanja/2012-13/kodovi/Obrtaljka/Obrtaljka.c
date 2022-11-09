#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DULJINA_NIZA 120

void u_malo_slovo (char *niz) {
     char *kraj = niz;
     // ako je veliko slovo, pretvori ga u malo!
     while (*kraj) { 
		 if (((*kraj) >= 'A') && ((*kraj) <= 'Z'))
				(*kraj) += 'a' - 'A';
		 kraj++;
	 }
}

int provjeri(char *niz) {
     char *kraj = niz + strlen (niz) - 1;
     // s pocetka ukloniti sve sto nije slovo
     while (*niz < 'a' || *niz > 'z') niz++;
     while (*kraj < 'a' || *kraj > 'z') kraj--;

     // osnovni slucaj: ako je niz dužine 0 ili 1 - kraj, palindrom je
     if ( kraj - niz < 1) return 1;
     
     // ako se znakovi na pocetku i kraju ne podudaraju, izlazi van, nije palindrom
     if ( *niz != *kraj) return 0;
     
     // novi niz je niz sa svake strane kraci za po jedan znak
     niz++;
     *kraj = 0;
     return provjeri(niz);
}

int main (void) {
    char izvor[DULJINA_NIZA];
	while (1) {
		printf("Upisite rijec ili recenicu:\n");
		gets(izvor);
		printf("\nGledam je li palindrom: \"%s\"\n", izvor);
		u_malo_slovo (izvor);
		provjeri (izvor) > 0 ? printf("Palindrom je!\n") : printf("Nije palindrom!\n");
	}
}
