/**
Napišite rekurzivnu funkciju čiji je prototip:
double f (double z, int k);
koja kao argument prima realni broj z i cijeli broj k te u vremenu O(k) računa izraz:
((-1)^k * z^(2k+1)) / (2k + 1)!
U glavnom programu je potrebno definirati realni broj z = 0.5 te funkciju f pozivati za različite vrijednosti
broja k i ispisivati rezultate poziva. 
*/
#include <cmath>

using namespace std;

double f(double z, int k){
    if(k < 0)
        return 0;

    if (k==0){
        return z;
    }

    return (-1*pow(z, 2)*f(z, k-1))/(((2*k)+1)*(2*k));
}

int main() {

    double z = 0.5;

    while(true)
    {
        int k;
        cout << "Upisite zeljenu vrijednost za k ili broj 42069 za prekid rada programa: ";
        cin >> k;

        if(k == 42069)
        {
            break;
        }

        if(k < 0)
        {
            cout << "Molim upisite broj >= 0!";
            continue;
        }

        cout << "f = " << f(z, k) << endl;
    }

    return 0;
}