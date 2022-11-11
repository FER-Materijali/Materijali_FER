// Čovjek sjedi u sjeni pri temperaturi okoline 37 C, koja jednaka kao i njegova tjelesna temperatura.
// Pri tim uvjetima, glavni način na koji njegovo tijelo gubi toplinu koju generira njegov metabolizam 
// je kroz isparavanje znoja. Ako čovjekov metabolizam generira 150 W, koliko znoja je potrebno za isparavanje? 
// Pri 37 C toplina isparavanja vode je 580 kcal/kg. Rezultat izrazite u gramima po satu.

#include<iostream>
using namespace std;

int main(void)
{
    int tempOkoline = 37; // C
    int tempCovjeka = 37; // C
    int Pw = 100; // koliko covjek generira u J/s. Treba prebaciti u J/h
    int Qkcal = 580; // kcal, toplina isparavanje vode pri 37 C. Treba prebaciti u J/kg
    // 1 cal = 4.1868 J

    int P = Pw * 3600; // J/h
    float Q = Qkcal * 4.1868 * 1000; // J/kg

    float m = P/Q; // rjesenje u kg/h

    cout << "Pazite pita li se u kg/h ili g/h: " << endl;
    cout << m << " kg/h" << endl;
    cout << m * 1000 << " g/h" << endl;

    return 0;
}