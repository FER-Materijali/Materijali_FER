#include <iostream> 
#include <string>
#include <memory>

using namespace std;

int main(){

    int polje[10]{-5,1,3,2,6,0,9,-8,123,22};
    int n = sizeof(polje)/sizeof(polje[0]);//10;

    cout << n << endl;

    //ispis polja
    for (int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;

    //pomnoži svaki element s 3 i ispiši
    for (int i=0; i<n; i++) {
        polje[i] *= 3;
        cout << polje[i] << " ";
    }
    cout << endl; 

    //traženje broja
    cout << "Koji broj trazimo? ";

    int x;
    cin >> x;

    for (int i=0; i<n; i++)
        if (polje[i]==x) {
            cout << "Broj " << x << " je na idx=" << i << endl;
            return 0;
        }
    
    cout << "Broj " << x << " nije nadjen u polju!" << endl; 

    return 0;
}