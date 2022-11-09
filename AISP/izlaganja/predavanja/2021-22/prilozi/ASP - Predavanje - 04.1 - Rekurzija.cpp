#include <iostream> 
#include <windows.h>

using namespace std;

//ispis brojeva uzlazno #1
void printAsc1(int n1, int n2) {
    Sleep(200);
    if (n1 > n2)
        return;
    cout << n1 << " ";
    printAsc1(n1+1, n2);
}

//ispis brojeva uzlazno #2
void printAsc2(int n1, int n2) {
    //Sleep(200);
    if (n1 > n2)
        return;
    printAsc2(n1, n2-1);
    Sleep(200);
    cout << n2 << " ";
}

//ispis brojeva silazno #1
void printDsc1(int n1, int n2) {
    Sleep(200);
    if (n1 > n2)
        return;
    cout << n2 << " ";
    printDsc1(n1, n2-1);
}

//ispis brojeva silazno #2
void printDsc2(int n1, int n2) {
    Sleep(200);
    if (n1 > n2)
        return;
    printDsc2(n1+1, n2);
    cout << n1 << " ";
}

void ispisNiza1(int niz[], int n) {
    Sleep(300);
    if (n<=0)
        return;
    ispisNiza1(niz, n-1);
    cout << niz[n-1] << " ";
}

void ispisNiza2(int niz[], int n) {
    Sleep(300);
    if (n<=0)
        return;
    cout << niz[n-1] << " ";
    ispisNiza2(niz, n-1);
}

int main() {
    int niz[5]{1,2,3,4,5};

    printAsc1(1,10);
    cout << endl;
    printAsc2(1,10);
    cout << endl;
    printDsc1(1,10);
    cout << endl;
    printDsc2(1,10);
    cout << endl;

    ispisNiza1(niz, 5);
    cout << endl;
    ispisNiza2(niz, 5);

    //PREMA UPUTI U PREDAVANJIMA:
    //TO-DO: Napišite funkciju koja izračunava n faktorijela
    cout << "8! = " << fakt(8) << endl;

    //TO_DO: Napišite funkciju koja računa x na y
    cout << "2^5 = " << pwr(2,5) << endl;
    

    return 0;
}