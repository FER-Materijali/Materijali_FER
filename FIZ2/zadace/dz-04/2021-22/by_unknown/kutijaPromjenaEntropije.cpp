#include <iostream>

using namespace std;

int main()
{
    cout << "Kutija mase \"neka masa\" kg gurnuta je po podlozi s početnom brzinom \"neka brzina\" m/s i konačno se zbog trenja zaustavi." << endl;
    cout << "Uzmite da je prije i poslije temperatura kutije i podloge sobna temperatura (22 C)." << endl;
    cout << "Kolika je promjena entropije svemira zbog ovog 'događaja'?" << endl;
    
    float masa;
    float brzina;
    float temp;
    float promjena;
    float k = 275.15;
    
    cout << "Unesite masu kutije u kg: ";
    cin >> masa;
    
    cout << "unesite brzinu u m/s: ";
    cin >> brzina;
    
    cout << "Unesite temp podloge (moguce da je u svim zadacima 22 C): ";
    cin >> temp;
    
    promjena = (masa * brzina*brzina)/(2 * (k + temp)); 
    
    cout << "Promjena entropije svemira zbog ovog dogadaja: " << promjena << endl;
    
    return 0;
}
