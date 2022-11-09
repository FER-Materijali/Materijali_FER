#include <iostream>
#include <ctime>
using namespace std;

// Stog listom
class Stog {
private:
	struct atom {
		int element;
		struct atom *sljed; 
	};
	atom *_vrh;
	void Brisi (atom *lokalniVrh);
public:
	Stog();
	void Dodaj (int stavka); 
	void Skini (int& stavka);	
  void Ispisi ();
	~Stog ();	
};
Stog::Stog () {
	_vrh = NULL;
}
void Stog::Dodaj (int stavka) { 
	atom *novi; // pokazivac na novi atom
	novi = new atom;
	if (novi == NULL)throw "Nema memorije!";
	novi->element = stavka; 
	novi->sljed = _vrh;
	_vrh = novi;	// spremi pokazivac na novi cvor
	cout << " na adresu " << _vrh;
}
void Stog::Skini (int& stavka) {
	atom *pom;				// pomocni pokazivac
	if (!_vrh) throw "Stog je prazan!";
	stavka = _vrh->element; 
	cout << "S adrese " << _vrh;
	pom = _vrh->sljed;	    // sacuvaj novi vrh
	free (_vrh);			// oslobodi vrh
	_vrh = pom;				// vrati novi vrh
}
Stog::~Stog () {
  Brisi (_vrh);
}
void Stog::Brisi (atom *lokalniVrh) {
	if (lokalniVrh != NULL) {
		Brisi (lokalniVrh->sljed);
		cout << "Brisem s " << lokalniVrh << '\n';	
		free (lokalniVrh);
	}
}
void Stog::Ispisi () {
  atom *a;
  if (_vrh == NULL) cout << "(prazan)";
  cout << '\n';
  for (a = _vrh; a != NULL; a = a->sljed)
    cout << a->element << " ";
}