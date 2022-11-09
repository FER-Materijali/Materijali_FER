#include <iostream> 

using namespace std;

//Fibb(0) = 1
//Fibb(1) = 1
//Fibb(2) = Fibb(1) + Fibb(0) = 1+1 = 2
//Fibb(3) = Fibb(2) + Fibb(1) = Fibb(1) + Fibb(0) + 1 = 1+1+1=3
//Fibb(n) + Fibb(n-1) + Fibb(n-2)

int fibbR(int n) {
    if (n<=1) return 1;
    return fibbR(n-1) + fibbR(n-2);
}

int* fibbPolje(int n) {
    int* f = new int[n+1]; // NE MOGU OVO: "int f[n];" Zašto?
    f[0] = f[1] = 1;
    for (int i=2; i<=n; i++)
        f[i] = f[i-1] + f[i-2];
    return f;
}

int fibbI(int n) {
    int f;
    int prev = 1;
    int prevprev = 1;
    for (int i=2; i<=n; i++) {
        f = prev + prevprev;
        prevprev = prev;
        prev = f;
    }
    return f;
}

int main(){

    int n;
    cout << "n: ";
    cin >> n;

    cout << "Fibb(" << n << ") = " << fibbR(n) << endl;
    cout << "FibbI(" << n << ") = " << fibbI(n) << endl;

    int* fpolje = fibbPolje(n);
    for (int i=0; i<=n; i++)
        cout << *(fpolje + i) << " ";
   
    return 0;
}