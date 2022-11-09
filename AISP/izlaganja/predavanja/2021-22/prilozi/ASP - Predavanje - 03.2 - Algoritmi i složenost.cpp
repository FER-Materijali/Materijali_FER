#include <iostream> 
#include <string>
#include <memory>
#include <cmath>

using namespace std;

bool linearSearch(int A[], int n, int x) {
    cout << "linear search" << endl;
    for (int i=0; i<n; i++)
        if (A[i]==x) {
            cout << "Nasao! idx = " << i << endl;
            return true;
        }
    return false;
}

bool jumpSearch(int A[], int n, int x) {
    cout << "jump search" << endl;
    int start = 0;
    int korak = sqrt(n);
    int end = start+korak;

    //trazim blok
    while (end < n && A[end] <= x) { //ako je traženi broj u prvom bloku nikad nećemo ni ući u tijelo petlje!
        start = end;
        end += korak;

        if (end > n)
            end = n;
    }

    //nakon što smo našli blok, tražimo slijedno po bloku
    for(int i= start; i< end && A[i] <=x; i++)
        if (A[i] == x) {
            cout << "Nasao! idx = " << i << endl;
            return true;
        }

    return false;

}

bool binarySearch(int A[], int n, int x) {
    cout << "binary search" << endl;

    int dg = 0;
    int gg = n-1;
    int middle;

    while (dg<=gg) {
        middle = (dg+gg) /2;
        cout << "idx = " << middle << "val: " << A[middle] << endl;
        //ako je middle traženi el
        if (A[middle] == x)
            return true;
            
        //ako nisam našao
        if (dg >= gg)
            return false;
        
        //ili izračunam nove granice
        if (A[middle] < x)
            dg = middle +1;
        
        if (A[middle] > x)
            gg = middle -1;
    }
    return false;
}

int main(){

    int polje[10]{-5,1,3,2,6,0,9,-8,123,22};
    int sortiranoPolje[11]{1,2,4,6,8,12,34,560,4000,5123,5126};
    int n = sizeof(polje)/sizeof(polje[0]);//10;

    cout << n << endl;

/*    //ispis polja
    for (int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;

    //pomnoži svaki element s 3 i ispiši
    for (int i=0; i<n; i++) {
        polje[i] *= 3;
        cout << polje[i] << " ";
    }
    cout << endl; */

    //traženje broja
    cout << "Koji broj trazimo? ";

    int x;
    cin >> x;

    bool nasao;
    //nasao = linearSearch(polje, n, x);
    nasao = jumpSearch(sortiranoPolje,11,x); //pazi, moramo imati sortirano polje i dobru veličinu
    //nasao = binarySearch(sortiranoPolje,11,x); //pazi, moramo imati sortirano polje i dobru veličinu

    cout << "Broj " << x << ((nasao == true) ? " je" : " nije") << " nadjen u polju!" << endl; 

    return 0;
}