#include <iostream>

using namespace std;

int main()
{
    float Tc; // hladna temp
    float Th; // topla topla temp
    float k = 275.15;

    cout << "Toplinski stroj radi u ciklusu između dvije temperature \"niza temp\" i \"visa temp\"." << endl;
    cout << "Kolika je najveća moguća efikasnost za takav toplinski stroj?" << endl;
    
    cout << "Unesite nizu temperaturu, npr. 28: " << endl;
    cin >> Tc;
    
    cout << "Unesite visu temperaturu, npr 590: " << endl;
    cin >> Th;
    
    float Carnot = 1-((Tc+k)/(Th+k));
    
    cout << "Najveca moguca efikasnost za takav toplinski stroj je " << Carnot << endl;

    return 0;
}