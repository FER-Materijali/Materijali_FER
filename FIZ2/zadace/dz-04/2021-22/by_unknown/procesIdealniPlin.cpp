#include <iostream>

using namespace std;

int main()
{
    cout << "Proces s idealnim plinom se odvija kroz dva koraka. Prvo se pri konstantnom volumenu hladi i tlak pada sa \"prvi tlak\" atmosfera na \"drugi tlak\"" << endl; 
    cout << "Zatim se pri konstantnom tlaku grije na početnu temperaturu, i pri tome mu volumen naraste s \"prvi volumen\" m3 na \"drugi volumen\" m3." << endl; 
    cout << "Izračunajte količinu topline koju je sustav izmijenio s okolinom." << endl;
    
    float P1;
    float P2;
    float V1;
    float V2;
    float result;
    
    cout << "Prvi tlak nije bitan pa ga preskacemo." << endl;
    cout << "Unesite drugi tlak: ";
    cin >> P2;

    cout << "Unesite prvi volumen: ";
    cin >> V1;
    
    cout << "Unesite drugi volumen: ";
    cin >> V2;
    
    // Formula: P2*deltaV (tlak mora iti u paskalima, dakle pomnožiti sa 101325)
    
    result = P2 * ((V2-V1)*101325);

    cout << "Razmijenjena kolicina topline: " << result << endl;

    return 0;
}
