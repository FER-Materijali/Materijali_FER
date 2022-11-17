#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void procitajPodatke();
void dekodirajRed(string);
void dodajStranicu(string, string, string, string);
void podesiStanja();
void zapisiStanja();
void dodajPocetno();
void dodajOstala();
string pronadiImeStranice(string);
string pronadiImePrijStranice(string);

class str {
public:
	string id;
	string naziv;
	string nazivCit;
	string prijelazi[100];
	string resoursi[100];
	int brPrijelaza;
	int brResoursa;
};

class sta {
public:
	string naziv;
	string prijelazi[100];
	string novaStanja[100];
	int brPrijelaza;
	string prihvatljivo;
	string izlaz;
};

void zapisiRed(sta);
void dodajPrijelaze(str*, string);
void dodajResourse(str*, string); 
string pronadiImeStranice(string);
void dodajPrijelazStranice(str*);
void dodajPrijelazeMeduStanja(str *, string, int, int);	

string ulaznaDatoteka;
int brStr = 0;
int brSta = 0;
str stranice[500];
sta stanja[1000];

int main(int argc, char *argv[]) {
    remove("automat.txt");	
	ulaznaDatoteka = "ulaz.txt";
	procitajPodatke();
	podesiStanja();
	zapisiStanja();
	system("PAUSE");
}

void procitajPodatke() {
	string line;
	ifstream file(ulaznaDatoteka.c_str());
	while (getline(file, line) && !file.eof()) {
		dekodirajRed(line);
  }
	file.close();
}

void dekodirajRed(string line) {
  static char id[ 1024 ];
  static char naziv[ 1024 ];
  static char prijelazi[ 1024 ];
  static char res[ 1024 ];
  if( sscanf( line.c_str(), "%[^:]:%[^|]|%[^|]|%[^\n]", id, naziv, prijelazi, res ) != 4 ) {
    puts( "Neispravno unesena stranica!\n" );
    return;
  }
	dodajStranicu(id, naziv, prijelazi, res);		
}

void dodajStranicu(string id, string naziv, string prijelazi, string res) {
	stranice[brStr].id = id;
	stranice[brStr].naziv = naziv;
	stranice[brStr].nazivCit = "Ucitavanje " + naziv;
	dodajPrijelaze(&stranice[brStr], prijelazi);
	dodajResourse(&stranice[brStr], res);
	brStr ++;
}

void dodajPrijelaze(str *stranica, string prijelazi) {
	stranica->brPrijelaza = 0;
	
	char *prij, *str;

 	prij = new char [prijelazi.size()+1];
	strcpy (prij, prijelazi.c_str());

	str = strtok(prij, ",");
	while(str != NULL) {
		stranica->prijelazi[stranica->brPrijelaza] = str;
		stranica->brPrijelaza ++;
		str = strtok(NULL, ",");
  }
}

void dodajResourse(str *stranica, string resoursi) {
	stranica->brResoursa = 0;
	char *res, *str;

 	res = new char [resoursi.size()+1];
	strcpy (res, resoursi.c_str());

	str = strtok(res, ",");
	while(str != NULL) {
		stranica->resoursi[stranica->brResoursa] = str;
		stranica->brResoursa++;
		str = strtok(NULL, ",");
  }	
}

void podesiStanja() {
	dodajPocetno();
	dodajOstala();
}

void dodajPocetno() {
	stanja[brSta].naziv = "pocetno";
	for (int i = 0; i<brStr; i++) {
		stanja[brSta].prijelazi[i] = stranice[i].naziv;
		stanja[brSta].novaStanja[i] = stranice[i].nazivCit;	
  }
	stanja[brSta].brPrijelaza = brStr;
	stanja[brSta].prihvatljivo = "DA";
	stanja[brSta].izlaz = "pocetno";
	brSta ++;
}

void dodajOstala() {
	for (int i=0; i<brStr; i++) {
		dodajPrijelazStranice(&stranice[i]);
		
		dodajPrijelazeMeduStanja(&stranice[i], stranice[i].nazivCit, 0, stranice[i].brResoursa);
  }
}

void dodajPrijelazStranice(str *stranica) {
	stanja[brSta].naziv = stranica->naziv;
	for (int i=0; i<stranica->brPrijelaza; i++) {
		stanja[brSta].prijelazi[i] = pronadiImeStranice(stranica->prijelazi[i]);
		stanja[brSta].novaStanja[i] = pronadiImePrijStranice(stranica->prijelazi[i]);
  }
	stanja[brSta].brPrijelaza = stranica->brPrijelaza;
	stanja[brSta].prihvatljivo = "DA";
	stanja[brSta].izlaz = stranica->naziv;
	brSta ++;
}

void dodajPrijelazeMeduStanja(str *stranica, string naziv, int poc, int br) {
	string lnk = "";
	if (poc==br-1) {
		for (int i=0; i<br-1; i++) {			
			stanja[brSta].naziv = naziv + lnk;
			stanja[brSta].prijelazi[0] = stranica->resoursi[i];

			lnk += "/" + stranica->resoursi[i];
			stanja[brSta].novaStanja[0] = naziv + lnk;		
			stanja[brSta].brPrijelaza = 1;
			stanja[brSta].prihvatljivo = "NE";
			if (i==0)
				stanja[brSta].izlaz = naziv;
			else
				stanja[brSta].izlaz = "Ucitavam " + stranica->resoursi[i-1];
		
			brSta ++;
    }
		stanja[brSta].naziv = naziv+lnk;
		stanja[brSta].prijelazi[0] = stranica->resoursi[br-1];
		stanja[brSta].novaStanja[0] = stranica->naziv;
		stanja[brSta].brPrijelaza = 1;
		stanja[brSta].prihvatljivo = "NE";
		if (br == 1)
			stanja[brSta].izlaz = naziv;
		else
			stanja[brSta].izlaz = "Ucitavam " + stranica->resoursi[br-2];
		brSta ++;
  }
	else	
		for (int i=poc; i<br; i++) {
			string pom = stranica->resoursi[poc];
			stranica->resoursi[poc] = stranica->resoursi[i];
			stranica->resoursi[i] = pom;

			dodajPrijelazeMeduStanja(stranica, naziv, poc+1, br);

			pom = stranica->resoursi[poc];
			stranica->resoursi[poc] = stranica->resoursi[i];
			stranica->resoursi[i] = pom;
    }
}
string pronadiImeStranice(string id) {
	for (int i = 0; i<brStr; i++) {
		if (stranice[i].id ==id)
			return stranice[i].naziv;
  }
}
string pronadiImePrijStranice(string id) {
	for (int i = 0; i<brStr; i++) 
		if (stranice[i].id ==id)
			return stranice[i].nazivCit;
}

void zapisiStanja() {
	for (int i=0; i<brSta; i++) {
		zapisiRed(stanja[i]);
  }
}

void zapisiRed(sta stanje) {	
	ofstream file("automat.txt", ios::app);
    string line;
	for (int i = 0; i<stanje.brPrijelaza; i++) {		
		line = stanje.naziv + "#" + stanje.prijelazi[i] + "->" + stanje.novaStanja[i] + "|" +stanje.prihvatljivo + "=" + stanje.izlaz;
		file <<line <<"\n";
  }
	file.close();
		

}
