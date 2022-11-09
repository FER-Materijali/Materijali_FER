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
// obilazak inorder lijevo-desno
void ispisinld (cvor *korijen) {
	if (korijen != NULL) {
		ispisinld (korijen->lijevo);
		printf ("%s \n", korijen->element);
		ispisinld (korijen->desno);
	}        
}
// obilazak inorder desno-lijevo
void ispisindl (cvor *korijen) {
	if (korijen != NULL) {
		ispisindl (korijen->desno);
		printf ("%s \n", korijen->element);
		ispisindl (korijen->lijevo);
	}        
}  
// obilazak preorder
void ispispre (cvor *korijen) {
	if (korijen != NULL) {
		printf ("%s \n", korijen->element);
		ispispre (korijen->lijevo);
		ispispre (korijen->desno);
	}        
} 
// obilazak postorder
void ispispost (cvor *korijen) {
	if (korijen != NULL) {
		ispispost (korijen->lijevo);
		ispispost (korijen->desno);
		printf ("%s \n", korijen->element);
	}        
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
// trazenje cvora u binarnom stablu
cvor *trazi (cvor *korijen, char element[]) {
	int smjer;
	if (korijen) {
		if ((smjer = strcmp (element, korijen->element)) < 0) {
			return trazi (korijen->lijevo, element);
		} else if (smjer > 0) {
			return trazi (korijen->desno, element);
		}
	}
	return korijen; // ili je pronadjen ili NULL;
}
int main() {
	FILE *fi;					// ulazna datoteka
	int j;						// brojac podataka
	cvor *korijen, *p;	// pokazivac na korijen, pomocni pokazivac
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
		printf ("Ispis inorder lijevo-desno\n");
		ispisinld (korijen);
		getchar ();
		printf ("Ispis inorder desno-lijevo\n");
		ispisindl (korijen);
		getchar ();
		printf ("Ispis preorder\n");
		ispispre (korijen);
		getchar ();
		printf ("Ispis postorder\n");
		ispispost (korijen);
		getchar ();
		printf ("Ispis stabla\n");
		ispissta (korijen, 0);
		// trazenje elementa
		while (1) {
			printf ("Unesite element koji trazite, ili KRAJ >");
			scanf ("%s", ime);
			if (stricmp (ime, "KRAJ") == 0) break;
			p = trazi (korijen, ime);
			if (p) {
				printf ("Pronadjen je element: %s\n", p->element);
			} else {
				printf ("Nije pronadjen element: %s\n", ime);
			}
		}
	} else {
		printf ("Nema ulaznih podataka\n");
		return 1;
	}
	return 0;
}
