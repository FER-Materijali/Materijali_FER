#include <iostream>
#include <ctime>
using namespace std;

// Red poljem
#include <stdlib.h>
#include <stdio.h>

typedef int tip;

class RedP {
private:
	tip *_red;
	int _MAXRED;
	int _ulaz;
	int _izlaz;
public:
	RedP () {
		_red = new tip [10];
		_MAXRED = 10;
		_ulaz = _izlaz = 0;
	}
	RedP (int n) {
		_red = new tip [n];
		_MAXRED = n;
		_ulaz = _izlaz = 0;
	}
	void DodajURed (tip element) {
		if (((_ulaz+1) % _MAXRED) == _izlaz) 
      throw "Red je pun!";
		_ulaz++; 
		_ulaz %= _MAXRED;
		_red [_ulaz] = element;
	}
	tip SkiniIzReda () {
		if (_ulaz == _izlaz) 
          throw "Red je prazan!";
		_izlaz ++; 
		_izlaz %= _MAXRED;
		return _red[_izlaz];
	}
	int Prebroji () {
		if (_ulaz >= _izlaz) {		
			return (_ulaz - _izlaz);		// standardno
		} else {
			return (_ulaz - _izlaz + _MAXRED);// cirkularnost
		}
	}
	~RedP () {
		delete []_red;
		_ulaz = _izlaz = 0;
	}
};
// Red listom
class RedL {
	private:
		struct atom {
			tip _element;
			struct atom *_sljed;
		};
		atom *_ulaz;
		atom *_izlaz;
public:
	RedL () {
		_ulaz = _izlaz = NULL;
	}
	void DodajURed (int element) {
		atom *novi = new atom;
		if (!novi) throw "Nema memorije";
		novi->_element = element;
		novi->_sljed = NULL;
		if (_izlaz == NULL) {
			_izlaz = novi;		// ako je red bio prazan
		} else {
			_ulaz->_sljed = novi;	// inace, stavi na kraj
		}
		_ulaz = novi;			// zapamti zadnjeg
	}
	tip SkiniIzReda () {
		atom *stari;
		tip element;
		if (_izlaz != NULL) {						// ako red nije prazan 
			element = _izlaz->_element;		// element koji se skida
			stari = _izlaz;					// zapamti trenutni izlaz
			_izlaz = _izlaz->_sljed;			// novi izlaz
			delete stari;					// oslobodi memoriju skinutog
			if (_izlaz == NULL) _ulaz = NULL; // ispraznjeni red
			return element;
		} else {
			throw "Red je prazan";
		}
	}
	int Prebroji () {
		int n;
		atom *izlaz = _izlaz;
		for (n = 0; izlaz != NULL; n++, izlaz = izlaz->_sljed);
		return n;
	}
	~RedL () {
		Brisi (_izlaz);
}
	void Brisi (atom *lokalniIzlaz) {
		if (lokalniIzlaz != NULL) {
			Brisi (lokalniIzlaz->_sljed);
			cout << "Brisem " << lokalniIzlaz->_element << '\n';	
			free (lokalniIzlaz);
		}
		_ulaz = NULL;
	}
};
int main () {
#if 0
	RedP *red = new RedP;
#else
	RedL *red = new RedL;
#endif
	tip element;	// element, krajevi reda
	FILE *fi;							// ulazna datoteka
	// inicijalizacija
	fi = fopen ("UlazZaRed.txt", "r");
	if (fi) {
		while (fscanf (fi, "%d", &element) != EOF) {
  			// stavljanje u red
			try {
				red->DodajURed (element);
				cout << "U red je dodan element " << element << '\n';
				cout << "Broj elemenata u redu je " << red->Prebroji () << '\n';
			}
			catch (char *poruka) {
				cout << poruka << '\n';
			}
		}
		// uklanjanje iz reda
	/*	while (red->Prebroji () > 0) {
			try {
				cout << "Iz reda skinut element " << red->SkiniIzReda () << '\n';
				cout << "Broj elemenata u redu je " << red->Prebroji () << '\n'; 
			}
			catch (char *poruka) {
				cout << poruka << '\n';
			}
		}
		try {
			red->SkiniIzReda (); // testiranje javljanja pogreske za prazni red
		}
		catch (char *poruka) {
				cout << poruka << '\n';
		}
		fclose (fi);*/
		delete red;
		return 0;
	} else {
		printf ("Nema ulazne datoteke\n");
		return 1;
	}
}
