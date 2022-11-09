/**
Napišite funkciju čiji je prototip:
void ispis (float polje[], int n) ;
koja kao argumente prima polje polje(tj. pokazivač na početak polja), čiji su elementi tipa float i broj
članova polja (n) te rekurzivno ispisuje negativne članove polja od prvoga prema zadnjemu.
Primjer: za polje [0, -1.2, 2.5, 3.1, -4.17, 5.19, -6.91] treba biti ispisano: -1.2, -4.17, -6.91.
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i alocirati polje A od
n članova tipa float (možete koristiti operator new ili funkciju malloc). Nakon toga učitajte n elemenata
polja A. Negativne članove polja ispišite od prvoga prema zadnjemu korištenjem funkcije ispis.
*/
#include <iostream>

using namespace std;

void ispis (float polje[], int n){
    // normalno ispisivanje polja
    /*
    for (int i = 0; i < n; i++)
    {
        if (polje[i] < 0){
            cout << polje[i] << " ";
        }
    }
    cout << endl;

    return;
    */

    // rekurzivno ispisivanje polja
    static int i = 0;

    if (i > n) return;

    if (polje[i] < 0){
        cout << polje[i] << " ";
    }

    i++;

    ispis(polje, n);
}

int main(void){
    int n;
    cout << "Upisi n: ";
    cin >> n;

    float *A = new float[n]; // alociranje novog polja

    for (int i = 0; i < n; i++){
        cout << "Upisi " << i << ". clan polja: ";
        cin >> A[i];
    }

    ispis(A, n);

    return 0;
}