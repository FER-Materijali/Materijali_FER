#include <iostream>
#include <ctime>
using namespace std;

// Stog poljem
class Stog {
public:
	Stog ();
	Stog (int n);
	void Dodaj (int stavka); 
	void Skini (int& stavka);
	void Isprazni ();
  void Ispisi();
	~Stog ();
private:
	int *_stog;
	int _MAXSTOG;
	int _vrh;
};
Stog::Stog () {
//  StogP (5);
	_MAXSTOG = 5;
  _stog = new int [_MAXSTOG];
	_vrh = -1;
}
Stog::Stog (int n) {
	_MAXSTOG = n;
	_stog = new int [_MAXSTOG];
	_vrh = -1;
}
void Stog::Dodaj (int stavka) {
	if (_vrh >= _MAXSTOG - 1) throw "Stog je pun!";
	_vrh++;	
	cout << " na adresu " << _vrh;
	_stog [_vrh] = stavka;
}
void Stog::Skini (int& stavka) {
	if (_vrh < 0) throw "Stog je prazan!"; 
	cout << "S adrese " << _vrh;
	stavka = _stog [_vrh];
	_vrh--;
}
void Stog::Isprazni () {
	_vrh = 0;
}
Stog::~Stog () {
	delete [] _stog;
	_vrh = -1;
}
void Stog::Ispisi() {
  int a; 
  if (_vrh == -1) cout << "(prazan)";
  cout << '\n';
  for (a = 0; a <= _vrh; ++a)
    cout << _stog[a] << " ";
}