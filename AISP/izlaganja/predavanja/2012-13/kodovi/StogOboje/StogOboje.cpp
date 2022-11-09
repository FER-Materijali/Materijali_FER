#include <iostream>
#include <ctime>
using namespace std;

// Stog poljem
class StogP {
public:
	StogP ();
	StogP (int n);
	void Dodaj (int stavka); 
	void Skini (int& stavka);
	void Isprazni ();
	int Prazan();
  void Ispisi();
	~StogP ();
private:
	int *_stog;
	int _MAXSTOG;
	int _vrh;
};
StogP::StogP () {
//  StogP (5);
	_MAXSTOG = 5;
  _stog = new int [_MAXSTOG];
	_vrh = -1;
}
StogP::StogP (int n) {
	_MAXSTOG = n;
	_stog = new int [_MAXSTOG];
	_vrh = -1;
}
void StogP::Dodaj (int stavka) {
	if (_vrh >= _MAXSTOG - 1) throw "Stog je pun!";
	_vrh++;	
	cout << " na adresu " << _vrh;
	_stog [_vrh] = stavka;
}
void StogP::Skini (int& stavka) {
	if (_vrh < 0) throw "Stog je prazan!"; 
	cout << "S adrese " << _vrh;
	stavka = _stog [_vrh];
	_vrh--;
}
void StogP::Isprazni () {
	_vrh = -1;
}
int StogP::Prazan() {
	return _vrh == -1;
}
StogP::~StogP () {
	delete [] _stog;
}
void StogP::Ispisi() {
  int a; 
  if (_vrh == -1) cout << "(prazan)";
  cout << '\n';
  for (a = 0; a <= _vrh; ++a)
    cout << _stog[a] << " ";
}
// Stog listom
class StogL {
private:
	struct atom {
		int element;
		struct atom *sljed; 
	};
	atom *_vrh;
	void Brisi (atom *lokalniVrh);
public:
	StogL();
	void Dodaj (int stavka); 
	void Skini (int& stavka);	
  void Ispisi ();
	~StogL ();
};
StogL::StogL () {
	_vrh = NULL;
}
void StogL::Dodaj (int stavka) { 
	atom *novi; // pokazivac na novi atom
	novi = new atom;
	if (novi == NULL)throw "Nema memorije!";
	novi->element = stavka; 
	novi->sljed = _vrh;
	_vrh = novi;	// spremi pokazivac na novi cvor
	cout << " na adresu " << _vrh;
}
void StogL::Skini (int& stavka) {
	atom *pom;				// pomocni pokazivac
	if (!_vrh) throw "Stog je prazan!";
	stavka = _vrh->element; 
	cout << "S adrese " << _vrh;
	pom = _vrh->sljed;	    // sacuvaj novi vrh
	free (_vrh);			// oslobodi vrh
	_vrh = pom;				// vrati novi vrh
}
StogL::~StogL () {
  Brisi (_vrh);
}
void StogL::Brisi (atom *lokalniVrh) {
	if (lokalniVrh != NULL) {
		Brisi (lokalniVrh->sljed);
		cout << "Brisem s " << lokalniVrh << '\n';	
		free (lokalniVrh);
	}
}
void StogL::Ispisi () {
  atom *a;
  if (_vrh == NULL) cout << "(prazan)";
  cout << '\n';
  for (a = _vrh; a != NULL; a = a->sljed)
    cout << a->element << " ";
}
int main () {
	int novi, stari;
#if 1 						// Stog listom
	StogL *stog = new StogL ();
#else						// Stog poljem
	StogP *stog = new StogP();
#endif

	cout << "Slucajno se generiraju nenegativni cijeli brojevi.\n";
	cout << "Neparni brojevi upisuju se na stog\n";
	cout << "Parni broj simulira skidanje sa stoga\n";
	cout << "Za obavljanje jednog koraka pritisnuti ENTER, za kraj K\n\n";
	srand ((unsigned) time (NULL));
	while (1) {			
    stog->Ispisi();
		putchar ('\n');	
		if (toupper (getchar ()) == 'K') break;
		novi = rand ();
		if (novi%2) {		// Neparni se upisuju na stog
			cout << "Dodaj " << novi;
			try {
				stog->Dodaj (novi);
			}
			catch (char *poruka)
			{
				cout << "Pogreska: " << poruka << '\n';
			}
		} else {			// Parni broj simulira skidanje sa stoga
			try {
				stog->Skini (stari);	
				cout << " skinut " << stari << '\n';
			}
			catch (char *poruka)
			{
				cout << "Pogreska: " << poruka << '\n';
			}
		}

	}
	delete stog;
	return 0;
}
