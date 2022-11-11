// U prostoriji bez grijanja, s temperaturom zidova 24 C, nepomično sjedi čovjek bez majice.
// Ako je površinska temperatura kože 34 C, kojom brzinom čovjek gubi toplinu (snaga) zračenjem?
// Uzmite da je površina tijela bez odjeće približno 1.5 m2 i da je omjer snage zračenja ljudskog tijela
// u odnosu na snagu zračenja idealnog crnog tijela 70%. 
// Rezultat izrazite u W.

// Znati sa https://hr.wikipedia.org/wiki/Zra%C4%8Denje_crnog_tijela
// Q - toplinska energija koju izraci tijelo povrsine 1 m kvadratni i aps. temp T u Kelvinima. Vidi Stefan-Boltzmannov zakon
// sigma = 5.670400*1e-8 W*m^(-2)*K^(-4) tj. Stefan-Boltzmannova konstanta

// Znati konverziju C u K:
// 0 C = 273.15 K

#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
    int tempZida = 24; // C
    int tempCovjeka = 34; // C
    float povrsinaTijela = 1.5; // u m^2
    float etha = 0.7; // omjer zracenja ljudskog tijela u odnosu na snagu zracenja idealnog crnog tijela koje je 1
    float Tkelvin = pow((tempCovjeka + 273.15), 4) - pow((tempZida + 273.15), 4); // razlika mora biti u Kelvinima
    float sigma = 5.670400*1e-8;

    float P = etha * povrsinaTijela * sigma * Tkelvin; 

    cout << P << " W" << endl;

    return 0;
}