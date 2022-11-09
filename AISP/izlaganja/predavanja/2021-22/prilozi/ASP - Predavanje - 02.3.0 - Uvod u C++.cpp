#include <iostream> 
#include <string>

using namespace std;

class Razlomak {
    private:
        int br, naz;
    
    public:
        Razlomak() : br(0), naz(0) {}
        Razlomak(int br, int naz) : br(br), naz(naz) {}
        int getBr() const { return br; }
        int getNaz() const { return naz; }
        string toString () { return to_string(br) + "/" + to_string(naz);}

        //zbrajanje dva razlomka - vraća NOVI razlomak
        // Java: Razlomak add(Razlomak other);
        Razlomak add(Razlomak other) {
            Razlomak retval;
            retval.naz = this->naz * other.naz;
            retval.br = this->br * other.naz + other.naz * this->br;
            return retval;
        }

        //isti kod, ali se fja zove operator+
        Razlomak operator+(Razlomak& other) {
            Razlomak retval;
            retval.naz = this->naz * other.naz;
            retval.br = this->br * other.naz + other.br * this->naz;
            return retval;
        }   

        // primjer za zbrajanje Razlomak + int, kako bi izgledala fja za zbrajanje int + Razlomak?
        Razlomak operator+(const int right) {
        Razlomak ret;
        ret.naz = this->naz;
        ret.br = this->br + right*this->naz;
        return ret;
        }

    friend ostream& operator<<(ostream& os,const Razlomak& r); //što ako maknemo const a ostavimo &

};

ostream& operator<<(ostream& os, const Razlomak& r) { //što ako maknemo const a ostavimo &
    //os << r.getBr() << "/" << r.getNaz();
    os << r.br << "/" << r.naz; //friend
    return os;
}

bool operator==(const Razlomak& left, const Razlomak &right) {
    return (left.getBr() == right.getBr() && left.getNaz() == right.getNaz());
};

// Primjer fje za učitavanje razlomka u formatu br/naz
// Ovo ne radi, treba ili nadopisati settere ili fju proglasiti za friend u klasi Razlomak, probajte!
/*istream &operator>>(istream &is, Razlomak &r) {
    int b, n;
    char c;
    is >> b >> c >> n;
    r.setBr(b); // ili r.br = b;
    r.setNaz(n); // ili r.naz = n;
    return is;
}*/

int main() {

    Razlomak r1(1,2);
    Razlomak r2{1,3};

    cout << r1.getBr() << "/" << r1.getNaz() << endl;
    cout << r2.toString() << endl;
    //ovo bi radilo u Javi ali ne u c++ (trebamo napisati fju operator<<)
    //cout << r2 << endl;

    // ako nemam operato<< niti gettere, mogu npr. ovako - opet Java-like kod
    Razlomak r3 = r1 + r2;
    cout << r3.toString() << endl;

    //sad sam definirao operator << pa radi 
    cout << r2 << endl;

    //napisao sam i operator==
    cout << (r1 == r2) << endl;

    // ovo ne radi ako je param funkcije operator<< referenca (a nije const ref), zašto?
    cout << (r1 + r3) << endl;

    //napisao sam i operator+ sa parametrom int
    cout << (r1 + 1);
    
    //Napišite fju s kojom će i ovo raditi
    //cout << (1 + r1);

    //Napišite fju s kojom će i ovo raditi
    //cin >> r1;
    //cout << "novi r1: " << r1 << endl;

    return 0;
}