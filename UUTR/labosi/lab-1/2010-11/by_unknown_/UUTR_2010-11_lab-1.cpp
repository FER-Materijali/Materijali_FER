#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class automat {
private:
    string pocetno_stanje;
    vector<string> stanja;
    vector<string> ulazni_znakovi;
    vector<string> prihvatljiva_stanja;
    vector<string> trenutna_stanja;
    vector<string> ***prijelazi;
    vector<string> *ulaz;
    int prijelaz(string ulaz);
    void epsilon_prijelaz();
    int prihvatljivost();
public:
    void init(char dat[]);
    int ucitaj_ulaz(char dat[]);
    void start(int broj);
    ~automat();
};

void split_string(string str, vector<string> &v, char delimiter) {
    unsigned int start = 0;
    int end;
    end = str.find(delimiter, start);
    while(end != -1) {
        v.push_back(str.substr(start, end-start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    if(start != str.length()) {
        v.push_back(str.substr(start));
    }
    return ;
}

int broj_linija(char dat[]) {
    int rez = 0;
    string tmp;
    ifstream file(dat);
    if(file.is_open()) {
        while(!file.eof()) {
            getline(file, tmp);
            if(!tmp.empty()) { // pokriva slučaj da je zadnja linija prazna
                rez++;
            }
        }
        file.close();
        return rez;
    }
    else {
        cerr << "\nNe mogu otvoriti datoteku "
             << dat << " :(" << endl;
        exit(1);
    }
}

void automat::init(char dat[]) {
    cout << "Inicijaliziram automat... " << endl;
    int n = broj_linija(dat);
    string **definicija, tmp;
    definicija = static_cast<string**>(new string*[n]);
    ifstream file(dat);

    if(file.is_open()) {
        for( int i = 0; i < n; ++i ) {
            getline(file,tmp);
            if(tmp[tmp.size()-1] == '\r') {
                    tmp = tmp.substr(0, tmp.size()-1);
                }
            definicija[i] = new string[tmp.length()];
            *definicija[i] = tmp;
        }
        file.close();
    }
    else {
        cerr << "\nNe mogu otvoriti datoteku "
             << dat << " :(" << endl;
        exit(1);
    }
    split_string(*definicija[0], stanja, ',');
    split_string(*definicija[1], ulazni_znakovi, ',');
    ulazni_znakovi.push_back("$");
    split_string(*definicija[2], prihvatljiva_stanja, ',');
    pocetno_stanje = *definicija[3];

    // unos prijelaza
    int start = 0, end;
    string tmp_stanje, tmp_ulaz;
    string tmp_sljed;
    prijelazi = static_cast<vector<string>***>(new vector<string>**[stanja.size()]);

    for( unsigned int i = 0; i < stanja.size(); ++i ) {
        prijelazi[i] = static_cast<vector<string>**>(new vector<string>*[ulazni_znakovi.size()]);
    }
    for( unsigned int i = 0; i < stanja.size(); ++i ) {
        for( unsigned int j = 0; j < ulazni_znakovi.size(); ++j ) {
            prijelazi[i][j] = static_cast<vector<string>*>(new vector<string>);
        }
    }

    unsigned int redak, stupac;
    for( int i = 4; i < n; ++i ) {
        start = 0;
        redak = 0;
        stupac = 0;

        end = (*definicija[i]).find(",", start);
        tmp_stanje = (*definicija[i]).substr(start, end-start);

        start = end + 1;
        end = (*definicija[i]).find("-", start);
        tmp_ulaz = (*definicija[i]).substr(start, end-start);
        start = end + 2;

        for( redak = 0; redak < stanja.size() && stanja[redak] != tmp_stanje; ++redak );
        if((redak == stanja.size())) {
            cerr << "Pogreška prilikom definiranja automata!" << endl;
            cerr << "Stanje \"" << tmp_stanje << "\" nije na popisu stanja!" << endl;
        }
        for( stupac = 0; stupac < ulazni_znakovi.size() && ulazni_znakovi[stupac] != tmp_ulaz; ++stupac );
        if((stupac == ulazni_znakovi.size())) {
            cerr << "Pogreška prilikom definiranja automata!" << endl;
            cerr << "Ulazni znak \"" << tmp_ulaz << "\" nije na popisu ulaznih znakova!" << endl;
        }         
        tmp_sljed = (*definicija[i]).substr(start);
        split_string(tmp_sljed, *prijelazi[redak][stupac], ',');

    }
    cout << "Učitano " << stanja.size() << " stanja, "
         << ulazni_znakovi.size()-1 << " ulaznih znakova i "
         << n-4 << " prijelaza." << endl;
    cout << "Čistim za sobom... ";
    for( int i = 0; i < n; ++i ) {
        delete [] definicija[i];
    }
    delete [] definicija;
    cout << "Gotovo!" << endl;
    return ;
} 

int automat::ucitaj_ulaz(char dat[]) {
    cout << "Učitavam ulazne nizove... ";  
    int n = broj_linija(dat);
    ulaz = static_cast<vector<string>*>(new vector<string>[n]); 
    string tmp, temp;
    ifstream file(dat);

    if(file.is_open()) {
        for( int i = 0; i < n; ++i ) {
            getline(file,tmp);
            if(tmp[tmp.size()-1] == '\r') {
                    tmp = tmp.substr(0, tmp.size()-1);
                }
            for( unsigned int j = 0; j < tmp.length(); ++j ) {
                temp.erase();
                temp += tmp[j];
                ulaz[i].push_back(temp);
            }
        }
        file.close();
    }
    else {
        cerr << "\nNe mogu otvoriti datoteku "
             << dat << " :(" << endl;
        exit(1);
    }

    cout << "Učitano " << n << " nizova!" << endl;
    return n;
}

int automat::prijelaz(string ulaz) {
    unsigned int n = trenutna_stanja.size(); // koliko je trenutnih stanja?
    unsigned int redak, stupac, provjera;
    int zarez;
    if(ulaz == "$") {
        return 0;
    }
    for( stupac = 0; stupac < ulazni_znakovi.size() && ulazni_znakovi[stupac] != ulaz; ++stupac ); // koji ulaz obrađujemo?
    if(stupac == ulazni_znakovi.size()) { // ulazni znak nije u skupu ulaznih znakova?
        return 1;
    }
    for( unsigned int i = n; i > 0; --i ) { // za svako stanje na listi trenutnih:
        zarez = 0;
        for( redak = 0; stanja[redak] != trenutna_stanja[i-1]; ++redak ); // u kojem smo stanju? 
// OPREZ -> ovo (uvjet for petlje) radi pod pretpostavkom da je redak UVIJEK manji od stanja.size()
        if((*prijelazi[redak][stupac]).empty()) { // ne postoje prijelazi za stanje? -> dead end
            continue;
        }
// ako smo došli do tu, znači da ima prijelaza za trenutno_stanje[i-1] i ulaz :)
// sad ih samo treba dodati na listu stanja, ako već nisu gore :D
        for( unsigned int j = 0; j < (*prijelazi[redak][stupac]).size(); ++j ) {
            for( provjera = n; provjera < trenutna_stanja.size() && (*prijelazi[redak][stupac])[j] != trenutna_stanja[provjera]; ++provjera );
            if(provjera == trenutna_stanja.size()) { // je li stanje već u novom dijelu liste trenutnih stanja?
                trenutna_stanja.push_back((*prijelazi[redak][stupac])[j]);
                if(!zarez) {
                cout << stanja[redak] << "," << ulaz << "->"
                     << (*prijelazi[redak][stupac])[j];
                }
                else {
                    cout << "," << (*prijelazi[redak][stupac])[j];
                }
                ++zarez;
            }
        }
        if(zarez) {
            cout << endl;
        }
    }
    trenutna_stanja.erase(trenutna_stanja.begin(), trenutna_stanja.begin()+n);

    return 0;
}

void automat::epsilon_prijelaz() {
    unsigned int provjera, redak;
    int zarez;
    for( unsigned int j = 0; j < trenutna_stanja.size(); ++j ) {
        zarez = 0;
        for( redak = 0; redak < stanja.size() && stanja[redak] != trenutna_stanja[j]; ++redak ); // u kojem smo stanju?
        if(redak == stanja.size()) {
            cerr << "Trenutno stanje " << trenutna_stanja[j]
                 << " nije u skupu ulaznih stanja O.o" << endl; 
        }
        if((*prijelazi[redak][ulazni_znakovi.size()-1]).empty()) { // ne postoje epsilon prijelazi za stanje?
            continue;
        }
        for( unsigned int i = 0; i < (*prijelazi[redak][ulazni_znakovi.size()-1]).size(); ++i ) {
            for( provjera = 0; provjera < trenutna_stanja.size() && (*prijelazi[redak][ulazni_znakovi.size()-1])[i] != trenutna_stanja[provjera]; ++provjera );
            if(provjera == trenutna_stanja.size()) { // je li stanje već u listi trenutnih stanja?
                trenutna_stanja.push_back((*prijelazi[redak][ulazni_znakovi.size()-1])[i]);
                if(!zarez) {
                cout << stanja[redak] << ",$->"
                     << (*prijelazi[redak][ulazni_znakovi.size()-1])[i];
                }
                else {
                    cout << "," << (*prijelazi[redak][ulazni_znakovi.size()-1])[i];
                }
                ++zarez;
            }
        }
        if(zarez) {
            cout << endl;
        }
    }
    return ;
}

void automat::start(int broj) {
    trenutna_stanja.clear();
    trenutna_stanja.push_back(pocetno_stanje);
    cout << "---------------------------------------------------" << endl;
    cout << "Ulaz: ";
    for( unsigned int i = 0; i < ulaz[broj].size(); ++i ) {
        cout << ulaz[broj][i];
    }
    cout << endl;
    cout << "Početno stanje: " << pocetno_stanje << endl;
    epsilon_prijelaz();
    for( unsigned int i = 0; i < ulaz[broj].size(); ++i ) {
        if(prijelaz(ulaz[broj][i])) {
            trenutna_stanja.clear();
            cout << "Nevaljan ulazni znak! :O" << endl;
            break;
        }
        epsilon_prijelaz();
    }
    sort(trenutna_stanja.begin(), trenutna_stanja.end()); // malo estetike ;)
    cout << "Konačno stanje: ";
    for( unsigned int i = 0; i < trenutna_stanja.size(); ++i ) {
        cout << trenutna_stanja[i] << " ";
    }
    cout << endl;
    cout << "Ulazni niz " ;
    for( unsigned int i = 0; i < ulaz[broj].size(); ++i ) {
        cout << ulaz[broj][i];
    }
    if(prihvatljivost()) {
        cout << " je prihvatljiv! :D" << endl;
    }
    else {
        cout << " nije prihvatljiv! :(" << endl;
    }
    return ;
}

int automat::prihvatljivost() {
    for( unsigned int i = 0; i < trenutna_stanja.size(); ++i ) {
        for( unsigned int j = 0; j < prihvatljiva_stanja.size(); ++j ) {
            if(trenutna_stanja[i] == prihvatljiva_stanja[j]) {
                return 1;
            }
        }
    }
        return 0;
}

automat::~automat() {
    delete [] ulaz;
    for( unsigned int i = 0; i < stanja.size(); ++i ) {
        for( unsigned int j = 0; j < ulazni_znakovi.size(); ++j ) {
            delete prijelazi[i][j];
        }
    }
    for( unsigned int i = 0; i < stanja.size(); ++i ) {
        delete [] prijelazi[i];
    }
    delete [] prijelazi;
    // Hasta La Vista, Baby!    
}

int main(int argc, char *argv[]) {
    automat aut;
    int n;
    if(argc != 3) {
        cerr << "Sintaksa: \"" << argv[0] << " [datoteka s definicijom automata] [datoteka ulaza]\"" << endl;
        exit(2);
    }
    aut.init(argv[1]);
    n = aut.ucitaj_ulaz(argv[2]);
    for( int i = 0; i < n; ++i ) {
        aut.start(i);
    }
    return 0;
}
