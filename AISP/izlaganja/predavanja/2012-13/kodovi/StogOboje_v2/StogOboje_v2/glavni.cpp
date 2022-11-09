#include <iostream>
#include <ctime>
#include "stog.h"
using namespace std;


int main () {
	int novi, stari;
	
	Stog *stog = new Stog();

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
