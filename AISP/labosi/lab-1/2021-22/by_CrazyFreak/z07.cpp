/**
Napišite funkciju koja prima pokazivač na polje cijelih brojeva i koja vraća pokazivač na novo polje koje
se sastoji od nasumično poredanih kvadriranih elemenata ulaznog polja.
Primjerice, ako se ulazno polje sastoji od elemenata 1, 2, 3, 4 i 5, izlazno polje može biti 25, 16, 1, 9, 4.
Potrebno je napisati i glavni program koji od korisnika učitava cijeli broj n te zatim rezervira memorijski
prostor za cjelobrojno polje (polje) od n članova (možete koristiti operator new ili funkciju malloc).
Članove polja polje treba učitati s tipkovnice. Glavni program zatim poziva funkciju i ispisuje rezultat
izvođenja funkcije (izlazno polje).
*/
#include <iostream>
#include <ctime>

using namespace std;

int* shuffleSquares(int polje[], int n){
    int *randArray = new int[n];
    bool *positions = new bool[n] {};

    for (int i = 0; i < n; ++i) {
        int index;
        do {
            index = rand() % n;
        } while (positions[index]);

        randArray[i] = polje[index] * polje[index];
        positions[index] = true;
    }

    delete[] positions;
    return randArray;

}

int main() {

    srand(time(0));
    cout << "Upisi n: ";
    int n;
    cin >> n;

    int* polje = new int[n];
    cout << "Upisi clanove: ";
    for (int i = 0; i < n; ++i) {
        cin >> polje[i];
    }

    int* randArray = new int[n];
    randArray = shuffleSquares(polje, n);

    cout << "Ispis pomijesanog kvadriranog polja: ";
    for (int i = 0; i < n; ++i) {
        cout << randArray[i] << ", ";
    }

    return 0;
}