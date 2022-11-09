#include <iostream> 
#include <string>
#include <memory>
#include <cmath>
#include <chrono>

using namespace std;

bool linearSearch(int A[], int n, int x) {
    //cout << "linear search" << endl;
    for (int i=0; i<n; i++)
        if (A[i]==x) {
            //cout << "Nasao! idx = " << i << endl;
            return true;
        }
    return false;
}

bool jumpSearch(int A[], int n, int x) {
    //cout << "jump search" << endl;
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
            //cout << "Nasao! idx = " << i << endl;
            return true;
        }

    return false;

}

bool binarySearch(int A[], int n, int x) {
    //cout << "binary search" << endl;

    int dg = 0;
    int gg = n-1;
    int middle;

    while (dg<=gg) {
        middle = (dg+gg) /2;
        //cout << "idx = " << middle << "val: " << A[middle] << endl;
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

class StopWatch {
 private:
   chrono::time_point<chrono::steady_clock> start;

 public:
   void reset() { start = chrono::steady_clock::now(); }
   StopWatch() { reset(); }
   double elapseduSeconds() {
      chrono::duration<double> d = chrono::steady_clock::now() - start;
      return chrono::duration_cast<chrono::microseconds>(d).count();
   }
};

int main(){

    //polje od 10 000 el
    srand(time(0));
    int n = 10000;
    int sortiranoPolje[n];

    sortiranoPolje[0] = 1;

    for (int i=1; i<n; i++){
        int delta = rand() % 100 + 1;
        sortiranoPolje[i] = sortiranoPolje[i-1] + delta;
    }

    //test
    for (int i=0; i<100; i++)
        cout <<  sortiranoPolje[i] << " ";
    
    cout << endl;

    //trazim broj kojeg nema u nizu
    //int x = sortiranoPolje[n-1] +1;

    //prvi
    //int x = 1;

    //srednji
    int x = sortiranoPolje[n/2-1];

    StopWatch s;

    //petlja od milijun koraka
    for (int i=0; i<1000000; i++)
        linearSearch(sortiranoPolje, n, x);

    cout << "Linear search: " << (s.elapseduSeconds() / 1000000) << "us." << endl;

    s.reset();

    //petlja od milijun koraka
    for (int i=0; i<1000000; i++)
        jumpSearch(sortiranoPolje, n, x);

    cout << "Jump search: " << (s.elapseduSeconds() / 1000000) << "us." << endl;

    s.reset();

    //petlja od milijun koraka
    for (int i=0; i<1000000; i++)
        binarySearch(sortiranoPolje, n, x);

    cout << "Binary search: " << (s.elapseduSeconds() / 1000000) << "us." << endl;



    return 0;
}