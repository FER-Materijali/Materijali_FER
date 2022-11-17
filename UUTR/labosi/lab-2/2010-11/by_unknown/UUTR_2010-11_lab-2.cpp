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
    string vrh_stoga;
    vector<string> stanja;
    vector<string> ulazni_znakovi;
    vector<string> stogovni_znakovi;
    vector<string> prihvatljiva_stanja;
    vector<string> trenutna_stanja;
    vector<string> ***prijelazi;
    vector< vector<string> > ****prijelazi_stog;
    vector<string> *ulaz;
    vector< vector<string> > stog;
    int prijelaz(string ulaz);
    void epsilon_prijelaz();
    int prihvatljivost();
public:
    void init(vector<string> definicija);
    int start(vector<string> ulaz);
    ~automat();
};

void split_string(string str, vector<string> &v, char delimiter) {
    unsigned int start = 0;
    int end;
    end = str.find(delimiter, start);
    while(end != -1) {
        if(end-start)
            v.push_back(str.substr(start, end-start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    if(start != str.length())
        v.push_back(str.substr(start));
    return ;
}

inline void string2vs(string ulaz, vector<string> &ul) {
    string tmp;
    for( unsigned int i = 0; i < ulaz.size(); ++i ) {
        tmp.clear();
        tmp += ulaz[i];
        ul.push_back(tmp);
    }
    return ;
}

inline bool jednakost_stogova(vector<string> stog1, vector<string> stog2) {
    if(stog1.size() != stog2.size())
        return 0;
    for( unsigned int i = 0; i < stog1.size(); ++i ) {
        if(stog1[i] != stog2[i])
            return 0;
    }

    return 1;
}

void automat::init(vector<string> definicija) {
    split_string(definicija[0], stanja, ',');
    split_string(definicija[1], ulazni_znakovi, ',');
    ulazni_znakovi.push_back("$");
    split_string(definicija[2], stogovni_znakovi, ',');
    pocetno_stanje = definicija[3];
    vrh_stoga = definicija[4];
    split_string(definicija[5], prihvatljiva_stanja, ',');
    // unos prijelaza
    int start = 0, end;
    vector<string> sljed, sljed2, vstog;
    string tmp_stanje, tmp_ulaz, tmp_stog, tmp_sljed;
    prijelazi = new vector<string>**[stanja.size()];
    prijelazi_stog = new vector< vector<string> >***[stanja.size()];

    for( unsigned int i = 0; i < stanja.size(); ++i ) {
        prijelazi[i] = new vector<string>*[ulazni_znakovi.size()];
        prijelazi_stog[i] = new vector< vector<string> >**[ulazni_znakovi.size()];
        for( unsigned int j = 0; j < ulazni_znakovi.size(); ++j ) {
            prijelazi[i][j] = new vector<string>[stogovni_znakovi.size()];
            prijelazi_stog[i][j] = new vector< vector<string> >*[stogovni_znakovi.size()];
            for( unsigned int k = 0; k < stogovni_znakovi.size(); ++k ) {
                prijelazi_stog[i][j][k] = new vector< vector<string> >[stanja.size()];
            }
        }
    }

    unsigned int redak, stupac, razina, planet;
    for( unsigned int i = 6; i < definicija.size(); ++i ) {
        start = 0;
        redak = 0;
        stupac = 0;

        end = (definicija[i]).find(",", start);
        tmp_stanje = (definicija[i]).substr(start, end-start);
        start = end + 1;
        end = (definicija[i]).find(",", start);
        tmp_ulaz = (definicija[i]).substr(start, end-start);
        start = end + 1;
        end = (definicija[i]).find("-", start);
        tmp_stog = (definicija[i]).substr(start, end-start);
        start = end + 2;

        for( redak = 0; redak < stanja.size() && stanja[redak] != tmp_stanje; ++redak );
        if((redak == stanja.size())) {
            cerr << "Pogreška prilikom definiranja automata!" << endl;
            cerr << "Stanje \"" << tmp_stanje << "\" nije u skupu stanja!" << endl;
            exit(2);
        }
        for( stupac = 0; stupac < ulazni_znakovi.size() && ulazni_znakovi[stupac] != tmp_ulaz; ++stupac );
        if((stupac == ulazni_znakovi.size())) {
            cerr << "Pogreška prilikom definiranja automata!" << endl;
            cerr << "Znak \"" << tmp_ulaz << "\" nije u skupu ulaznih znakova!" << endl;
            exit(2);
        }
        for( razina = 0; razina < stogovni_znakovi.size() && stogovni_znakovi[razina] != tmp_stog; ++razina );
        if((razina == stogovni_znakovi.size())) {
            cerr << "Pogreška prilikom definiranja automata!" << endl;
            cerr << "Znak \"" << tmp_stog << "\" nije u skupu znakova stoga!" << endl;
            exit(2);
        }
        tmp_sljed = (definicija[i]).substr(start);
        sljed.clear();
        split_string(tmp_sljed, sljed, '#');
        for( unsigned int j = 0; j < sljed.size(); ++j ) {
            vstog.clear();
            end = (sljed[j].find(",", 0));
            prijelazi[redak][stupac][razina].push_back(sljed[j].substr(0, end));
            for( planet = 0; planet < stanja.size() && stanja[planet] != prijelazi[redak][stupac][razina].back(); ++planet );
            if((planet == stanja.size())) {
                cerr << "Pogreška prilikom definiranja automata!" << endl;
                cerr << "Stanje \"" << prijelazi[redak][stupac][razina].back() << "\" nije u skupu stanja!" << endl;
                exit(3);
            }
            for( int l = sljed[j].size()-1; l > end; --l ) {
                vstog.push_back(sljed[j].substr(l, 1));
            }
            if(prijelazi_stog[redak][stupac][razina][planet].size())
                prijelazi[redak][stupac][razina].pop_back();
            prijelazi_stog[redak][stupac][razina][planet].push_back(vstog);
        }
    }

    return ;
}

int automat::prijelaz(string ulaz) {
    unsigned int n = trenutna_stanja.size(); // koliko je trenutnih stanja?
    unsigned int redak, stupac, razina, planet, provjera;
    vector<string> tmp_stog;
    if(ulaz == "$")
        return 0;
    for( stupac = 0; stupac < ulazni_znakovi.size() && ulazni_znakovi[stupac] != ulaz; ++stupac ); // koji ulaz obrađujemo?
    if(stupac == ulazni_znakovi.size()) // ulazni znak nije u skupu ulaznih znakova?
        return 1;
    for( unsigned int i = n; i > 0; --i ) { // za svako stanje na listi trenutnih:
        for( redak = 0; stanja[redak] != trenutna_stanja[i-1]; ++redak ); // u kojem smo stanju?
// OPREZ -> ovo (uvjet for petlje) radi pod pretpostavkom da je redak UVIJEK manji od stanja.size()
        if(stog[i-1].empty())
            continue;
        for( razina = 0; stogovni_znakovi[razina] != stog[i-1].back(); ++razina ); // što je na vrhu stoga?
        if(prijelazi[redak][stupac][razina].empty()) // ne postoje prijelazi za stanje? -> dead end
            continue;
// ako smo došli do tu, znači da ima prijelaza za trenutno_stanje i ulaz :)
// sad ih samo treba dodati na listu stanja, ako već nisu gore :D
        for( unsigned int j = 0; j < prijelazi[redak][stupac][razina].size(); ++j ) { // za svaki mogući prijelaz:
            for( planet = 0; planet < stanja.size() && stanja[planet] != prijelazi[redak][stupac][razina][j]; ++planet ); // koje je sljedeće stanje?
            for( unsigned int l = 0; l < prijelazi_stog[redak][stupac][razina][planet].size(); ++l ) { // za svaku moguću promjenu stoga:
                tmp_stog = stog[i-1]; // pripremi stog
                if(prijelazi_stog[redak][stupac][razina][planet][l].size() > 1) {
                    tmp_stog[tmp_stog.size()-1] = prijelazi_stog[redak][stupac][razina][planet][l][0];
                    for( unsigned int k = 1; k < prijelazi_stog[redak][stupac][razina][planet][l].size(); ++k ) {
                        tmp_stog.push_back(prijelazi_stog[redak][stupac][razina][planet][l][k]);
                    }
                }
                else if(prijelazi_stog[redak][stupac][razina][planet][l].size() == 1) {
                    if(prijelazi_stog[redak][stupac][razina][planet][l][0] == "$")
                        tmp_stog.pop_back();
                    else
                        tmp_stog[tmp_stog.size()-1] = prijelazi_stog[redak][stupac][razina][planet][l][0];
                }
                else
                    cerr << "Nema stogovnih znakova; redak " << redak << ", stupac " << stupac
                         << ", razina " << razina << ", planet " << planet << endl;
                for( provjera = n; provjera < trenutna_stanja.size() && prijelazi[redak][stupac][razina][j] != trenutna_stanja[provjera]; ++provjera );
                if(provjera == trenutna_stanja.size() || !jednakost_stogova(tmp_stog, stog[provjera])) {
// je li stanje već u novom dijelu liste trenutnih stanja?
                    trenutna_stanja.push_back(prijelazi[redak][stupac][razina][j]);
                    stog.push_back(tmp_stog);
                }
            }
        }
    }
    trenutna_stanja.erase(trenutna_stanja.begin(), trenutna_stanja.begin()+n);
    stog.erase(stog.begin(), stog.begin()+n);
    return 0;
}

void automat::epsilon_prijelaz() {
    unsigned int provjera, redak, razina, planet;
    vector<string> tmp_stog;
    for( unsigned int j = 0; j < trenutna_stanja.size(); ++j ) {
        for( redak = 0; redak < stanja.size() && stanja[redak] != trenutna_stanja[j]; ++redak ); // u kojem smo stanju?
        if(redak == stanja.size())
            cerr << "Trenutno stanje " << trenutna_stanja[j]
                 << " nije u skupu ulaznih stanja O.o" << endl;
        if(stog[j].empty())
            continue;
        for( razina = 0; stogovni_znakovi[razina] != stog[j].back(); ++razina ); // vrh stoga?
        if(prijelazi[redak][ulazni_znakovi.size()-1][razina].empty()) // ne postoje epsilon prijelazi za stanje?
            continue;
        for( unsigned int i = 0; i < prijelazi[redak][ulazni_znakovi.size()-1][razina].size(); ++i ) { // za svako moguće stanje:
            for( planet = 0; planet < stanja.size() && stanja[planet] != prijelazi[redak][ulazni_znakovi.size()-1][razina][i]; ++planet ); // koje je sljedeće stanje?
            for( unsigned int l = 0; l < prijelazi_stog[redak][ulazni_znakovi.size()-1][razina][planet].size(); ++l ) {
                tmp_stog = stog[j];
                if(prijelazi_stog[redak][ulazni_znakovi.size()-1][razina][planet][l][0] == "$")
                    tmp_stog.pop_back();
                else
                    tmp_stog[tmp_stog.size()-1] = prijelazi_stog[redak][ulazni_znakovi.size()-1][razina][planet][l][0];
                for( provjera = 0; provjera < trenutna_stanja.size() && prijelazi[redak][ulazni_znakovi.size()-1][razina][i] != trenutna_stanja[provjera]; ++provjera );
                if(provjera == trenutna_stanja.size() || !jednakost_stogova(tmp_stog, stog[provjera])) { // je li stanje već u listi trenutnih stanja?
                    trenutna_stanja.push_back(prijelazi[redak][ulazni_znakovi.size()-1][razina][i]);
                    stog.push_back(tmp_stog);
                }
            }
        }
    }
    return ;
}

int automat::start(vector<string> ulaz) {
    vector<string> tmp;
    stog.clear();
    tmp.push_back(vrh_stoga);
    stog.push_back(tmp);
    trenutna_stanja.clear();
    trenutna_stanja.push_back(pocetno_stanje);
    epsilon_prijelaz();
    for( unsigned int i = 0; i < ulaz.size(); ++i ) {
        if(prijelaz(ulaz[i]))
            return 0;
        epsilon_prijelaz();
    }
    if(prihvatljivost())
        return 1;
    else
        return 0;
}

int automat::prihvatljivost() {
    for( unsigned int i = 0; i < trenutna_stanja.size(); ++i ) {
        for( unsigned int j = 0; j < prihvatljiva_stanja.size(); ++j ) {
            if(trenutna_stanja[i] == prihvatljiva_stanja[j])
                return 1;
        }
    }
    return 0;
}

automat::~automat() {
    for( unsigned int i = 0; i < stanja.size(); ++i ) {
        for( unsigned int j = 0; j < ulazni_znakovi.size(); ++j ) {
            for( unsigned int k = 0; k < stogovni_znakovi.size(); ++k ) {
                delete [] prijelazi_stog[i][j][k];
            }
            delete [] prijelazi[i][j];
            delete [] prijelazi_stog[i][j];
        }
        delete [] prijelazi[i];
        delete [] prijelazi_stog[i];
    }
    delete [] prijelazi;
    delete [] prijelazi_stog;
    // Hasta La Vista, Baby!
}

int utrlab2(char* definicijaPA, char* ulazniNiz) {
    automat aut;
    vector<string> def, ul;
    string ulaz = ulazniNiz;
    split_string(definicijaPA, def, '%');
    aut.init(def);
    string2vs(ulaz, ul);

    return aut.start(ul);
}

/*
    ______                         
   / ____/___ ___  ____ ___________
  / __/ / __ `__ \/ __ `/ ___/ ___/
 / /___/ / / / / / /_/ / /__(__  ) 
/_____/_/ /_/ /_/\__,_/\___/____/  

      The One True Program. 
*/
