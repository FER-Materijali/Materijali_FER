/**
Napišite funkciju čiji je prototip:
double exp (double x, int n, int *fakt, double *xpot);
koja kao argument prima realni broj x i broj članova reda (n) te rekurzivno računa e
x prema izrazu:
𝑒^𝑥 = 1 + 𝑥 + 𝑥^2 / 2! + ...
Funkcija prima i dva dodatna argumenta: fakt (adresa na kojoj je pohranjen n! za trenutni n) i xpot
(adresa na kojoj je pohranjena n-ta potencija broja x za trenutni n). Korištenjem ovih pomoćnih
argumenata trebate napisati funkciju exp koja se izvodi u vremenu O(n).
Primjer: za x = 1 i n = 0, funkcija treba vratiti 1; za x = 1 i n = 1, funkcija treba vratiti 2; za x = 1 i n = 3
funkcija treba vratiti 2.666667; x = 1 i n = 10, funkcija treba vratiti 2.718282, itd.
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i broj x tipa double.
Stvorite polje A od n članova tipa double (možete koristiti operator new ili funkciju malloc). Zatim polje
treba popuniti tako da član polja A[i] sadrži vrijednost izraza e
x izračunatog korištenjem funkcije exp za
i članova reda. Npr. za n = 5 i x = 1, polje A treba sadržavati vrijednosti [1.000000, 2.000000, 2.500000,
2.666667, 2.708333]. Ispisati članove polja A. 
*/
#include <iostream>
#include <cmath>

using namespace std;

double exp(double x, int n, int *fakt, double *xpot){

    if (n < 0)
        return 0;
    
    return *xpot / *fakt + exp(x, n - 1, fakt + 1, xpot + 1);
}

int fakt(int n){
    return (n==0) || (n==1) ? 1 : n * fakt(n-1);
}

int main(void){
    int n;
    cout << "Upisi n: ";
    cin >> n;
    double x;
    cout << "Upisi x: ";
    cin >> x;

    int *faktorijel = new int[n];
    double *potX = new double[n];

    for (int i = 0; i < n; i++) {
        faktorijel[i] = fakt(i);
        // cout << faktorijel[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        potX[i] = pow(x, i);
        // cout << potX[i] << endl;
    }

    double *A = new double [n]; // alociranje novog polja
    for (int i = 0; i < n; i++){
        A[i] = exp(x, i, faktorijel, potX);

        cout << A[i] << " | ";
    }

    return 0;
}