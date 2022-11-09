/**
Napišite funkciju čiji je prototip:
template <typename T> int binarnoTrazi (T polje[], int n, T x) ;
koja kao argumente prima pokazivač na početak uzlazno sortiranog polja (polje) čiji su članovi tipa T,
broj članova polja (n) te broj x. U funkciji postupkom binarnog pretraživanja treba provjeriti nalazi li se x
u polju. Funkcija vraća indeks elementa x, ako se x nalazi u polju, a -1 inače.
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n te realni broj x.
Stvorite polje A od n članova tipa float(možete koristiti operator new ili funkciju malloc).
Potrebno je napuniti polje A s n vrijednosti tako da je A[i] = i * 1.1 te ispisati članove polja. Za broj x
potrebno je provjeriti nalazi li se u polju A (koristite funkciju binarnoTrazi). Potrebno je ispisati indeks
člana polja, ako je x pronađen u polju A, a poruku „Broj se ne nalazi u polju.“, ako x nije pronađen u polju
A.
Ponovite postupak s članovima tipa int, tako da je A[i] = i + 3;
*/
#include <iostream>

using namespace std;

template <typename T> int binarnoTrazi (T polje[], int n, T x){
    int gg, dg;
    dg = -1;
    gg = n;
    int index = n / 2;

    while (dg < gg - 1){
        if (x == polje[index]){
            return index;
        } else if(x < polje[index]){
            gg = index;
            index -= (gg - dg) / 2;
        } else {
            dg = index;
            index += (gg - dg) / 2;
        }
    }
    return -1;

}

int main() {

    int n;
    cout << "Upisi n: ";
    cin >> n;
    float x;
    cout << "Upisi x: ";
    cin >> x;
    float *A = new float[n];

    for (int i = 0; i < n; i++){
        A[i] = i * 1.1;
    }

    int indexA = binarnoTrazi(A, n, x);

    if(indexA == -1){
        cout << "Broj se ne nalazi u polju." << endl;
    } else
        cout << indexA << endl;


    int y;
    cout << "Upisi y: ";
    cin >> y;

    int *B = new int[n];

    for (int i = 0; i < n; i++){
        B[i] = i + 3;
    }

    int indexB = binarnoTrazi(B, n, y);

    if(indexB == -1){
        cout << "Broj se ne nalazi u polju." << endl;
    } else
        cout << indexB << endl;

    return 0;
}