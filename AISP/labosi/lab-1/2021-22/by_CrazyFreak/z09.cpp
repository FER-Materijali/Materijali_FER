/**
Napišite rekurzivnu funkciju koja kao parametar prima polje cijelih brojeva i njegovu veličinu. Prototip
funkcije je:
void f (int polje[], int n, int m);
Funkcija treba polje popuniti rastućim vrijednostima koje su potencije broja m, na način da element na
indeksu 0 ima vrijednost m^0, na indeksu 1 vrijednost m^1 itd. Elementi polja idu do m^(n-1).
Potrebno je napisati i glavni program koji od korisnika učitava cijele brojeve n i m te zatim stvara
cjelobrojno polje od n članova(možete koristiti operator new ili funkciju malloc). Glavni program zatim
poziva funkciju f za to cjelobrojno polje, broj članova polja n i parametar m te ispisuje rezultate izvođenja
funkcije.
*/
#include <iostream>
#include <cmath>

using namespace std;

void f (int polje[], int n, int m){
    if(n==0) return;
    polje[n-1] = pow(m, n-1);
    f(polje, n-1, m);
}

int main() {

    cout << "upisite n:";
    int n, m;
    cin >> n;
    cout << "upisite m:";
    cin >> m;

    int* polje = new int[n];
    f(polje, n, m);

    for (int j = 0; j < n; ++j) {
        cout << polje[j] << ", ";
    }

    return 0;
}