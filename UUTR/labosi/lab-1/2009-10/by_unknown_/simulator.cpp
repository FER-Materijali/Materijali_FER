#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class sta {
public:
	string naziv;
	string prijelaz;
	string novoStanje;
	string prihvatljivo;
	string izlaz;
};


sta stanja[500];
int brSta = 0;
string trenutno = "pocetno";

void procitajAutomat();
void dekodirajStanje(string);
void dodajStanje(string, string, string, string, string);
bool procitajPrijelaze();
bool prijediUStanje(string);
void ispisiStanje(string);

int main() {	
	procitajAutomat();
	procitajPrijelaze();
	system("PAUSE");
  return 0;
}

void procitajAutomat() {
	ifstream file("automat.txt");
	string line;
	while (!file.eof()&&getline(file, line)) {		
		
		dekodirajStanje(line);
  }

	file.close();
}

void dekodirajStanje(string line) {
  static char naziv[ 1024 ];
  static char prijelaz[ 1024 ];
  static char novoStanje[ 1024 ];
  static char prihvatljivo[ 1024 ];
  static char izlaz[ 1024 ];
  
  if( sscanf( line.c_str(), "%[^#]#%[^-]->%[^|]|%[^=]=%[^\n]", 
              naziv, prijelaz, novoStanje, prihvatljivo, izlaz ) != 5 ) {
		cout <<"Neispravno unesena stranica" <<endl;	
		return;
  }
	dodajStanje( naziv, prijelaz, novoStanje, prihvatljivo, izlaz );
}

bool procitajPrijelaze() {
	cout <<"STANJE: " <<trenutno << setw(50) <<"PRIHV: DA"<<endl;
    string resoursi;
	ifstream file("nizovi.txt");
	getline(file, resoursi);	
	char *res, *str;

 	res = new char [resoursi.size()+1];
	strcpy (res, resoursi.c_str());

	str = strtok(res, " ");
	while(str != NULL) {
		if(!prijediUStanje(str))
			return false;	
		str = strtok(NULL, " ");
  }
	return true;
}

bool prijediUStanje(string prijelaz){	
	bool nadeno = false;
	for (int i = 0; i< brSta; i++)
		if(stanja[i].naziv == trenutno && stanja[i].prijelaz == prijelaz) {
			nadeno = true;			
			
			trenutno = stanja[i].novoStanje;
			
			break;
    }
	if (nadeno)
		ispisiStanje(prijelaz);
	else
		cout <<"Ne postoji prijelaz" <<endl;

	return nadeno;
}
	
void ispisiStanje(string prijelaz) {
	for (int i = 0; i< brSta; i++)
		if(stanja[i].naziv == trenutno ) {
			cout <<left <<"ULAZ: "<< setw(20) <<prijelaz <<"STANJE:" <<setw(40) <<trenutno  <<endl;
            cout <<"      IZLAZ: " <<setw(40) <<stanja[i].izlaz;
			cout <<left << "   PRIHV: "  <<stanja[i].prihvatljivo <<endl;
			break;
    }
	
}
void dodajStanje(string naziv, string prijelaz, string novoStanje, string prihvatljivo, string izlaz){
	stanja[brSta].naziv = naziv;
	stanja[brSta].prijelaz =  prijelaz;
	stanja[brSta].novoStanje =  novoStanje;
	stanja[brSta].prihvatljivo =  prihvatljivo;
	stanja[brSta].izlaz = izlaz;
	brSta ++;
}
