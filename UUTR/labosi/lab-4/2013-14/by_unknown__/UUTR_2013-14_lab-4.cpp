#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void nadji_indeks_promjene(string trenutno_stanje ,vector <string> & trenutna_stanja, vector <string> &  znak_na_traci, vector <string> & pomaci_glave,int& indeks_promjene, int polozaj_glave, int velicina_trake,string& zapis_trake ){
	for (unsigned int i = 0; i <= trenutna_stanja.size() -1; i++)
	{
			if (trenutno_stanje == trenutna_stanja[i] && zapis_trake[polozaj_glave] == znak_na_traci[i].at(0))
			{
				indeks_promjene = i;
				if (( polozaj_glave == 0 && pomaci_glave[indeks_promjene] == "L" ) || (polozaj_glave == (velicina_trake -1) && pomaci_glave[indeks_promjene] == "R") )
				{
					indeks_promjene = -1;
					return;
				}
				return;
			}
	}
	indeks_promjene = -1;
	return;
}

void Ucitaj_prihvatljiva(string temp, vector <string> & PrihvatljivaStanja)
{
	getline(cin, temp);
	while (!temp.empty()){
		if (temp.find(",") != string::npos){
			PrihvatljivaStanja.push_back(temp.substr(0, temp.find(",")));
			temp.erase(0, temp.find(",") + sizeof(char));
		}
		else{
			PrihvatljivaStanja.push_back(temp);
			temp.clear();
			return;
		}
	};
}


int main(){
	ifstream myfile;
	myfile.open("C:\\Users\\Repe\\Desktop\\TuringovTest\\test06.in");
	string temp;
	string oznaka_prazne_celije;
	string zapis_trake;
	string trenutno_stanje;
	int polozaj_glave;
	int indeks_promjene; //-1 za gresku
	int velicina_trake;
	vector <string> prihvatljiva_stanja;
	vector <string> trenutna_stanja, znak_na_traci, novo_stanje, novi_znak_na_traci, pomaci_glave;

	getline(cin, temp); //skup stanja
	getline(cin, temp); //ulazni znakovi
	getline(cin, temp); // znakovi trake
	getline(cin, oznaka_prazne_celije); //oznaka prazne æelije, nepotrebno?
	getline(cin, zapis_trake); //zapis trake
	velicina_trake = zapis_trake.length(); //velicina trake, uvjeti prekida

	Ucitaj_prihvatljiva(temp, prihvatljiva_stanja) ;

	getline(cin, trenutno_stanje); //pocetno stanje je automatski i trenutno!!
	getline(cin, temp);
	polozaj_glave = stoi(temp); //pocetno stanje glave

	while (getline(cin, temp))
	{  //ucitavanje funkcija prijelaza
		trenutna_stanja.push_back(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find(",") + sizeof(char));

		znak_na_traci.push_back(temp.substr(0, temp.find("->")));
		temp.erase(0, temp.find("->") + 2 * sizeof(char));

		novo_stanje.push_back(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find(",") + sizeof(char));

		novi_znak_na_traci.push_back(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find(",") + sizeof(char));

		pomaci_glave.push_back(temp);

		temp.clear();
	}

	//obrada
	nadji_indeks_promjene(trenutno_stanje, trenutna_stanja, znak_na_traci, pomaci_glave, indeks_promjene, polozaj_glave, velicina_trake, zapis_trake);

	while (indeks_promjene != -1)
	{
		trenutno_stanje = novo_stanje[indeks_promjene];
		zapis_trake[polozaj_glave] = novi_znak_na_traci[indeks_promjene].at(0);
		pomaci_glave[indeks_promjene] == "R" ? polozaj_glave++ : polozaj_glave-- ;

		nadji_indeks_promjene(trenutno_stanje, trenutna_stanja, znak_na_traci, pomaci_glave, indeks_promjene, polozaj_glave, velicina_trake, zapis_trake);
	}


	//ispis
	if (find(prihvatljiva_stanja.begin(), prihvatljiva_stanja.end(), trenutno_stanje) != prihvatljiva_stanja.end())
	{
		cout << trenutno_stanje << "|" << polozaj_glave << "|" << zapis_trake << "|" << 1;
	}

	else
	{
		cout << trenutno_stanje << "|" << polozaj_glave << "|" << zapis_trake << "|" << 0;
	}

	return 0;
}