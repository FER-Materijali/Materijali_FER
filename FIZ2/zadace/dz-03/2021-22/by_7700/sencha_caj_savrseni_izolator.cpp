// Sencha caj ver. 1 (salica savrseni toplinski izolator)

// U brzini želite pripremiti pristojnu šalicu sencha čaja.
// Potrebna Vam je voda na 70 C, koju ćete pripremiti miješanjem uzavrele vode iz  čajnika na 100 C i hladne vode iz vodovoda na 18 C. 
// Ako konačno želite 100 ml čaja, koliko mililitara hladne vode treba biti u mješavini? 
// Pretpostavite da je šalica savršeni toplinski izolator.

// Ostavljam float radi preciznosti

#include<iostream>
using namespace std;

int main(void)
{
    float zeljenaTemp = 70; // C, zeljena temperatura caja
	float tempHladne = 18; // C, hladna voda iz vodovoda
    float tempCajnik = 100; // C, vruca voda iz cajnika
	float volumenCaja = 100; // ml, zeljena kolicina caja
    float volumenHladne; // nepoznato, koliko je potrebno hladne vode na 18 C
    
	float razlikaToplaHladna = zeljenaTemp - tempHladne;
	float razlikaToplaVruca = tempCajnik - zeljenaTemp; // tj. moglo se |zeljenaTemp - tempCajnik|
	
	volumenHladne = (razlikaToplaVruca * volumenCaja)/(razlikaToplaHladna + razlikaToplaVruca);
	
	cout << "Treba dodati " << volumenHladne << " ml hladne vode.";
    
    return 0;
}