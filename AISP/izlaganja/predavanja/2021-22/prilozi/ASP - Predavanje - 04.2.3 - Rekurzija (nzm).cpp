#include <iostream> 

using namespace std;

//Najveća zajednička mjera aka Najveći zajednički djelitelj
//en. Greatest common divisor
//Euklidov algoritam:
//nzm(a,0) = a
//nzm(a,b) = nzm(b,a%b)
//npr. nzm(4,6) = nzm(6,4) = nzm(4,2) = nzm(2,0) = 2
int nzm(int a, int b) {
    cout << "nzm(" << a << "," << b << ") = ";
    if (b==0) {
        cout << a << endl;
        return a;
    }
    return nzm(b, a%b);
}

int main() {

    int a, b;

    cout << "Upisite a i b: ";
    cin >> a >> b; //ovo prihvaća "broj-whitespace-broj", npr. "4 6" ili "4ENTER6"

    nzm(a,b);

    return 0;
}