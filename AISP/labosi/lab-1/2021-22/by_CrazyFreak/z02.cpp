/**
Napišite funkciju čiji je prototip:
int zbrojiKvadrate (int polje[], int n) ;
koja kao argumente prima polje polje i broj članova (n) te rekurzivno zbraja članove polja koji su kvadrati
nekog drugog prirodnog broja.
Primjer: za polje [0, 1, 2, 3, 4] funkcija treba vratiti 5 (zbrojeni su 1 i 4, koji su kvadrati brojeva 1 i 2).
Napišite glavni program koji će učitati broj elemenata jednodimenzionalnog polja n i stvoriti cjelobrojno
polje A od n članova (možete koristiti operator new ili funkciju malloc).
Potrebno je napuniti polje A s n slučajno odabranih prirodnih brojeva iz intervala [1, 100] te ispisati polje
i zbroj članova polja koji su kvadrati nekog drugog prirodnog broja (pozvati funkciju zbrojiKvadrate). 
*/
#include <iostream>
#include <ctime>

using namespace std;

int zbrojiKvadrate (int polje[], int n){
    static int i = 0;
    static int sum = 0;
  
    for (int j = 0; j < n; j++)
    {
        if (i*i == polje[j])
        {
            sum += i*i;
        }
        
    }
    i++;

    if (i == n){
        return sum;
    }else
        zbrojiKvadrate(polje, n);
}

int main(void){
    int n;
    cout << "Upisi n: ";
    cin >> n;

    /*
    float A[n]; // stvaranje novog polja
    float &Aptr = A[0];
    */
    int *A = new int[n]; // alociranje novog polja

    srand(time(0));
    for(int i = 0; i < n; i++){
        A[i] = (double) rand() / RAND_MAX * (100 - 1 + 1) + 1;
        cout << A[i] << " | ";
    }
    cout << endl;
    
    cout << zbrojiKvadrate(A, n);

    return 0;
}