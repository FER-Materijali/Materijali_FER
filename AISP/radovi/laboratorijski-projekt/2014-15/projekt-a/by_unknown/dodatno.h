/* 
	dodatno.h - osnovna zaglavna datoteka definira tipove, konstante i funkcije
	koji se koriste tijekom cijelog programa iz raznih modula 
*/

/*
	struktura zapisa u datoteci stanovnici.dat
*/
struct stanovnik {
	char ime_prezime[51];
	char oib[12];
};

#define NSTAVKI 10000
#define DATOTEKA_PODACI "stanovnici.dat"
#define DATOTEKA_TEST "test.dat"

