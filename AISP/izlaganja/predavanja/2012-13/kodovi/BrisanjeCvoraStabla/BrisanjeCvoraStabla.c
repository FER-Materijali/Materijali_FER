// SortiranoStablo.c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct cv {
  char element[15];
  struct cv *lijevo;
  struct cv *desno;
};
typedef struct cv cvor;

// upisuje u stablo podatke: lijevo manji, desno veci
cvor *upis (cvor *korijen, char element[]) { 
	int smjer; // odluka o podstablu
	if (korijen == NULL) { // prazno (pod)stablo
		korijen = (cvor *) malloc (sizeof (cvor));
		if (korijen) {
			strcpy (korijen->element, element);
			korijen->lijevo = korijen->desno = NULL;
		} else {
			printf ("U memoriji mena mjesta za upisati '%s'\n", element);
		}
	} else if ((smjer = strcmp (element, korijen->element)) < 0) { 
		korijen->lijevo = upis (korijen->lijevo, element);
	} else if (smjer > 0) {
		korijen->desno  = upis (korijen->desno, element);
	} else {
		printf ("Podatak '%s' vec postoji!\n", element);
	}
	return korijen; // pokazivac na zadnji element
}
// ispis stabla
void ispissta (cvor *korijen, int nivo) {
	int i;
	if (korijen != NULL) {
		ispissta (korijen->desno, nivo+1);
		for (i = 0; i < nivo; i++) printf("    ");
		printf ("%s \n", korijen->element);
		ispissta (korijen->lijevo, nivo+1);
	}
}
// brisnje uparivanjem
void BrisiUparivanjem (cvor **radni) {
	cvor *privremeni = *radni;
	if ((*radni) != NULL) {
		if (!(*radni)->desno)
			(*radni) = (*radni)->lijevo; //ako nema desno dijete, lijevo dijete (ako ga ima) postaje radni
		else if (!(*radni)->lijevo)
			(*radni) = (*radni)->desno;	  // nema lijevo dijete, desno dijete je radni
		else {
			privremeni = (*radni)->lijevo; //1. pomak lijevo
			while (privremeni->desno)   //2. do kraja desno
				privremeni = privremeni->desno;
			privremeni->desno = (*radni)->desno; //povezi najdesniji cvor lijevog podstabla s desnim podtsblom
			privremeni = *radni;
			*radni = (*radni)->lijevo;
		}

		free (privremeni);
	}
}

// trazenje i brisanje cvora u binarnom stablu
void nadjiBrisi (cvor **korijen, char element[]) {
	cvor *radni = *korijen;
	cvor *preth = NULL;
	int smjer;
	while (radni != NULL) {
		if ((smjer = strcmp (element, radni->element)) == 0) 
			break;
		preth = radni;
		if (smjer < 0)
			radni = radni->lijevo;
		else
			radni = radni->desno;
	}
	if (radni != NULL && smjer == 0)
		if (radni == *korijen)
			BrisiUparivanjem (korijen);
		else if (preth->lijevo == radni) {
			BrisiUparivanjem (&(preth->lijevo));
		} else {
			BrisiUparivanjem (&(preth->desno));
		}
	else if (korijen != NULL)
		printf ("%s nije u stablu\n", element);
	else ("Stablo je prazno\n");
}
int main() {
	FILE *fi;					// ulazna datoteka
	int j;						// brojac podataka
	cvor *korijen;	// pokazivac na korijen, pomocni pokazivac
	char ime[15];		
	fi = fopen ("UlazZaSortiranoStablo.txt", "r");
	if (fi) {
		// inicijalizacija i citanje podataka
		j = 1;
		korijen = NULL;
		while (fscanf (fi, "%s", &ime) != EOF) {
			printf ("%d. ulazni podatak je %s \n", j++, ime);
			korijen = upis (korijen, ime);
		}
		fclose (fi);
		// obilazak i ispis stabla
        getchar ();
		printf ("Ispis stabla\n");
		ispissta (korijen, 0);
		// trazenje elementa
		while (1) {
			printf ("Unesite element koji trazite, ili KRAJ >");
			scanf ("%s", ime);
			if (stricmp (ime, "KRAJ") == 0) break;
			nadjiBrisi (&korijen, ime);
			printf ("Ispis stabla nakon brisanja elementa %s\n", ime);
			ispissta (korijen, 0);
		}
	} else {
		printf ("Nema ulaznih podataka\n");
		return 1;
	}
	return 0;
}
