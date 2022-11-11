#include <iostream>

using namespace std;

int main()
{
    cout << "Idealan Carnotov stroj ima efikasnost \"neki postotak\"%." << endl; 
    cout << "Ako bi ga mogli pogoniti u suprotnom smjeru, kao hladnjak (rashladni stroj), koliki bi mu bio koeficijent hladjenja?" << endl;
    cout << "(Napomena: Nemojte rezultat izražavati u postotcima.)" << endl;
    
    cout << "Objasnjenja zadatka su u kodu!" << endl;
    
    float eta; // tj. efikasnost
    cout << "Unesite postotak efikasnosti: ";
    cin >> eta;
    
    float etaConverted = eta/100; // prebaciti iz postotaka
    
    float result;
    
    // Carnot => eta = 1 - (T2/T1)
    
    // T2 = 1-etaConverted*T1;
    
    // efikasnostHladenja = T2/(T1-T2) tj. (1-etaConverted*T1)/(T1-1-etaConverted*T1). Kada se sredi, dobije se:
    // (1 - etaConverted)/etaConverted
    
    result = (1 - etaConverted)/etaConverted;
    
    cout << "Koeficijent hladenja: " << result << endl;
    
    return 0;
}