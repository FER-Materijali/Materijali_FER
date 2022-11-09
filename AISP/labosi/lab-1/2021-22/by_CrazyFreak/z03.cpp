/**
Napišite funkciju čiji je prototip:
double pi (int n) ;
koja kao argument prima broj članova reda (n) te rekurzivno računa broj π prema izrazu:
𝜋/4 = 1 − 1/3 + 1/5 − 1/7...
Primjer: za n = 1, funkcija treba vratiti 4; za n = 2, funkcija treba vratiti 2.666667; za n = 10, funkcija treba
vratiti 3.041840, itd.
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i stvoriti polje A od n
članova tipa double (možete koristiti operator new ili funkciju malloc). Zatim polje treba popuniti tako da
član polja A[i] sadrži aproksimaciju broja π izračunatu korištenjem funkcije pi za i+1 članova reda. Npr.
za n = 3, polje treba sadržavati vrijednosti [4.000000, 2.666667, 3.466667]. Ispisati članove polja A. 
*/
#include <iostream>

using namespace std;

double pi(int n){
    /*
    static int i = 0;
    static double piValue = 0;
    i++;
  
    if (i % 2 == 0){
        piValue -= 1.0 / (2 * i - 1);
    }else{
        piValue += 1.0 / (2 * i - 1);
    }

    if (i == n){
        return piValue * 4;
    }else
        pi(n);
    */

    if (n == 1)
        return 4;
    
    return 4 *  ((n % 2 == 0) ? -1 : 1) * (1. / (2 * n - 1)) + pi(n - 1);
}

int main(void){
    int n;
    cout << "Upisi n: ";
    cin >> n;

    double *A = new double [n]; // alociranje novog polja
    for (int i = 0; i < n; i++){
        A[i] = pi(i + 1);

        cout << A[i] << " | ";
    }

    return 0;
}