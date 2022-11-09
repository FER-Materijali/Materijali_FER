#include <iostream> 

using namespace std;

//0! = 1
//1! = 1
//n! = n * (n-1)!
//npr. 3! = 3 * 2! = 3 * 2 * 1! = 3 * 2 * 1 = 6
int fakt(int n) {
    if (n<=1)
        return 1;
    return n * fakt(n-1);
}

int faktI(int n) {
    int f=1;
    for (int i=1; i<=n; i++)
        f*=i;
    return f;
}

int main(){

    int n;
    cout << "n: ";
    cin >> n;

    cout << n << "! = " << fakt(n) << endl;
    cout << n << "! = " << faktI(n) << endl;

    return 0;
}