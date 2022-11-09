#include <stdio.h>
#include <stdlib.h>
#include <math.h>


			/*STOG STATICKIM POLJEM*/

typedef struct {			
	int vrh, polje[MAXSTOG];
}Stog;

void init_stog (Stog *stog) {		/*inicijalizacija*/
	stog->vrh = -1;
}

int dodaj (int element, Stog *stog) {		/*dodavanje elementa*/
	if (stog->vrh >= MAXSTOG -1) return 0;
	stog->vrh++;
	stog->polje [stog->vrh] = element;
	return 1;
}

int skini (int *element, Stog *stog) {		/*skidanje elementa*/
	if (stog->vrh <0) return 0;
	*element = stog->polje[stog->vrh];
	stog->vrh--;
	return 1;
}

			/*STOG LISTOM*/

struct at {
	int element;
	struct at *sljed;
};
typedef struct at atom;

typedef struct {
	atom *vrh;
}Stog;

void init_stog (Stog *stog) {		/*inicijalizacija*/
	stog->vrh = NULL;
}

int dodaj (int element, Stog *stog) {		/*dodavanje elementa na stog*/
	atom *novi;
	if ((novi = (atom *)malloc(sizeof(atom)))!=NULL) {
		novi->element = element;
		novi->sljed = stog->vrh;
		stog->vrh = novi;
		return 1;
	}
	else return 0;
}

int skini (int *element, Stog *stog) {		/*skidanje elementa sa stoga*/
	atom *pom;
	if (stog->vrh == NULL) return 0;
	*element = stog->vrh->element;
	pom = stog->vrh->sljed;
	free(stog->vrh);
	stog->vrh = pom;
	return 1;
}

			/*RED STATICKIM POLJEM*/

typedef struct {
	int polje[MAXRED];
	int ulaz, izlaz;
} Red;


int dodaj (int element, Red *red) {			/*dodavanje elementa u red*/
	if ((red->ulaz+1)%MAXRED == red->izlaz) return 0;
	red->ulaz++;
	red->ulaz %= MAXRED;
	red->polje[red->ulaz] = element;
	return 1;
}	


int skini (int *element, Red *red) {		/*skidanje elementa s reda*/
	if (red->ulaz == red->izlaz) return 0;
	red->izlaz++;
	red->izlaz %= MAXRED;
	*element = red->polje[red->izlaz];
	return 1;
}

			/*RED LISTOM*/

struct re {
	int element;
	struct re* sljed;
};
typedef struct re Red;

void init_red (Red *red) {		/*inicijalizacija*/
	red->ulaz = NULL;
	red->izlaz = NULL;
}

int dodaj (int element, Red *red) {		/*dodavanje elementa u red*/
	atom *novi;
	if (novi=malloc(sizeof(atom))) {
		novi->element = element;
		novi->sljed = NULL;
		if (red->izlaz == NULL) red->izlaz = novi;
			else (red->ulaz)->sljed = novi;
		red->ulaz = novi;
		return 1;	
	}
	return 0;
}

int skini (int *element, Red *red) {		/*skidanje elementa s reda*/
	atom *stari;
	if (red->izlaz) {
		*element = red->izlaz->element;
		stari = red->izlaz;
		red->izlaz = red->izlaz->sljed;
		free(stari);
		if (red->izlaz == NULL) red->ulaz = NULL;
	return 1;
	}
	return 0;
}


			/*TEHNIKE ADRESIRANJA*/

/*ulancavanje*/
struct zap {
	char ime [VELIME +1];
	struct zapis* sljed;
};
typedef struct zap zapis;


void upis (zapis *hash[], zapis *element) {		/*upis u hash*/
	int i = adresa(element->ime);
	element->sljed = hash[i];
	hash[i] = element;
}

/*otvoreno adresiranje*/
struct zapis {
	int sifra;
	char ime [VELIME+1];
};

void upis (zapis *hash, zapis element) {	
	int indeks;
	int adresa = Adresa(element->sifra);
	
	for (int i=0; i<M; i++) {
	
		/*LINEARNO ISPITIVANJE*/
		indeks = (adresa + i)%M;
		/*KVADRATNO ISPITIVANJE*/
		indeks = fmod((adresa +c1*i +c2*i*i), M);
				
		if (hash[indeks]->sifra == 0) {
			hash[indeks] = element;
			break;
		}
	}
}
/*DVOSTRUKO RASPRSENO ADRESIRANJE*/
void upis (zapis *hash, zapis element) {
	int indeks;
	int h1 = adresa1(element->sifra);
	int h2 = adresa2 (element->sifra);
	
	for (int i=0; i<M; i++) {
		indeks = (h1+i*h2)%M;
		if (hash[indeks]->sifra == 0) {
			hash[indeks] = element;
			break;
		}
	}
}

/*metoda dijeljenja*/
int adresa1(int sifra) {
	return sifra%M;
}

/*metoda mnozenja*/
unsigned long int adresa(int sifra) {
	unsigned long int A = 2654435769;
	unsigned int pomak = 29;
	return (A*sifra)>>pomak;
}


			/*STABLO*/

struct cv {
	int podatak;
	struct cvor *lijevo_dijete;
	struct cvor *desno_dijete;
	struct cvor *roditelj;
};
typedef struct cv cvor;

cvor *dodaj (cvor *cvor, int element) {		/*dodavanje elementa*/
	if (cvor == NULL) {
		return (NoviCvor(element));
	}
	else {
		if (element <= cvor->podatak)
			cvor->lijevo = dodaj(cvor->lijevo_dijete, element);
		else 
			cvor->desno_dijete = dodaj(cvor->desno_dijete);
	return (cvor);			
	}
}

cvor *NoviCvor (int element) {		/*stvaranje novog cvora*/
	cvor* novi = (cvor *)malloc(sizeof(cvor));
	novi->podatak = element;
	novi->lijevo_dijete= NULL;
	novi->desno_dijete = NULL;
	return (novi);
}


int trazi (cvor *cvor, int trazeno) {		/*pretrazivanje stabla*/
	if (cvor == NULL) return 0;
	else {
		if (trazeno == cvor->podatak) return 1;
		else {
		if (trazeno < cvor->podatak) return (trazi(cvor->lijevo_dijete, trazeno)))
		else return (trazi(cvor->desno_dijete, trazeno));
		}
	}
}


			/*GOMILA*/	


void podesi (int A[], int i, int n) {		/*podesavanje gomile*/
  int j; 
  int stavka;
  j = 2*i;
  stavka = A[i];
  while (j <= n ) {
    if ((j < n) && (A[j] < A[j+1])) j++;
    if (stavka >= A[j]) break;	
    A[j/2] = A[j];				
    j *=2;
  }
  A[j/2] = stavka; 
}
  
  
  void StvoriGomilu (int A[], int n) {		/*stvaranje gomile*/
  int i;
  for (i = n/2; i >= 1; i--) 
		podesi (A, i, n);
}

void HeapSort (int A[], int n) {		/*heap sort algoritam*/
  int i;
  StvoriGomilu (A, n);
  for (i = n; i >= 2; i--) {
		Zamijeni (&A[1], &A[i]);
    Podesi (A, 1, i-1);
  }
}
