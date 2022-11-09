#include <iostream>
#include <cmath>

using namespace std;

double anFormula(double mi1, double mi2, double a0, double a1, int n){
    double D = pow(mi1, 2) + 4 * mi2;

    double lambda1, lambda2;
    double an;
    if (D == 0){
        double x = mi1 / 2;

        lambda1 = a0;
        lambda2 = a1 / x - a0;

        an = lambda1 * pow(x, n) + lambda2 * n * pow(x, n);
    }else if (D > 0){
        double x1 = (mi1 + sqrt(D)) / 2;
        double x2 = (mi1 - sqrt(D)) / 2;

        lambda2 = (a1 - a0 * x1) / (x2 - x1);
        lambda1 = a0 - lambda2;

        an = lambda1 * pow(x1, n) + lambda2 * pow(x2, n);
    }else{
        an = -1;
    }

    return an;

    // O(n) = 1?
}

double anRecursion(double mi1, double mi2, double a0, double a1, int n){
    if (n == 1){
        return a1;
    }else if (n == 0){
        return a0;
    }

    double an = mi1 * anRecursion(mi1, mi2, a0, a1, n-1) + mi2 * anRecursion(mi1, mi2, a0, a1, n-2);

    return an;

    // O(n) = 2^n
}

int main(void){

    double mi1, mi2;
    cout << "Unesite prvi koeficijent λ_1 rekurzivne relacije: ";
    cin >> mi1;
    cout << "Unesite drugi koeficijent λ_2 rekurzivne relacije: ";
    cin >> mi2;

    double a0, a1;
    cout << "Unesite vrijednost nultog clana niza a_0: ";
    cin >> a0;
    cout << "Unesite vrijednost prvog clana niza a_1: ";
    cin >> a1;

    int n;
    cout << "Unesite redni broj n trazenog clana niza: ";
    cin >> n;

    cout << "Vrijednost n-tog clana niza pomocu formule: " << anFormula(mi1, mi2, a0, a1, n) << endl;
    cout << "Vrijednost n-tog clana niza iz rekurzije: " << anRecursion(mi1, mi2, a0, a1, n) << endl;


    return 0;
}