#include <iostream> 
#include <string>
#include <memory>

using namespace std;

class MojaKlasa {
    public:
        int i; double j; string s;
        MojaKlasa() {i=0; j=0; s = "n/a";}
        MojaKlasa(int i, double j, string s) : i(i), j(j), s(s) {}
        ~MojaKlasa() { cout << "destruktor MojaKlasa" << endl; }
};

// fja koja prima referencu
//mogu joj predati ili ref ili objekt, ne i pokazivač
void fja(int &iref) { cout << "iref: " << iref << endl; }

// 1. template fje
template <typename T>
T veci(T a, T b) {
    return a > b ? a : b;
}

// 2. template klase
template <class T> // template <class T, class S>
class MojContainer {
    private:
        T obj;
    public:
        MojContainer(T o) : obj(o) {}
        T getObj() {return obj; }
        void setObj(T o) { this->obj = o;}
};


int main() {

    string ime = "Marko"; // (skoro) isto kao i string ime("Marko");
    cout << ime << endl;
    ime = "Ana";
    cout << ime << endl;
    ime += " <3 Milovana";
    cout << ime << endl;

    // na heapu se mogu stvarati i primitivni tipovi
    int *iNaHeapu = new int(5);
    cout << *iNaHeapu << endl;

    int i = 3;
    int &ref = i;

    //fja() prima referencu na int, mogu joj poslati ili int ili ref na int
    fja(i);
    fja(ref);
    //fja(iNaHeapu); // KRIVO - trebam ref, a dajem pointer

    // Kako pretvoriti pointer u ref? Nikako :)
    // Ali...
    fja(*iNaHeapu); // ovo je OK, referenca je "alias" za varijablu (objekt)

    //Iznimke
    try {
        string s("burek");
        cout << s.at(67) << endl;
    } catch (exception &e) {
        cerr << "IZNIMKA: " << e.what() << endl;
    }

    // Pazi: div by 0 ili array idx out of bounds nisu iznimke u C++
    // std::array ili std::vector bacaju iznimke, ali ako koristimo metodu .at()
    /*try {
        int i = 0;
        //int j = 2/i;
        int polje[2]{3,3};
        cout << polje[47] << endl;

    } catch (exception &e) {
        cerr << "IZNIMKA: " << e.what() << endl;
    }*/

    try {
        int i = 0;
        if (i == 0) {
            throw invalid_argument("Dijelim s nulom!");
        }
        int j = 2/i;

    } catch (exception &e) {
        cerr << "IZNIMKA: " << e.what() << endl;
    }

    //c++ generics - templates
    // 1. funkcije
    int a = 3, b = 5;
    cout << "Veci broj je " << veci(a,b) << endl; //fj veci je generička

    string aa = "aaaaaa";
    string bb = "bb";
    cout << "Veci string je "<< veci(aa,bb) << endl; //usporedba stringova znak po znak, po asci tablici

    cout << "Veci string je "<< veci("CC","DDD") << endl; // pazi!

    // Radi li ovo?
    //cout << "Veci string je "<< veci("aa",aa) << endl; // različiti tipovi char[] vs string
    
    // A ovo?
    //cout << "Veci string je "<< veci(string("aa"),aa) << endl; // oba parametra su stringovi

    // 2. class templates
    MojContainer<int> mc1(3);
    MojContainer<string> mc2("tri");

    cout << mc1.getObj() << endl;
    cout << mc2.getObj() << endl;

    //smart pointers
    //unique
    unique_ptr<MojaKlasa> up1(new MojaKlasa());
    unique_ptr<MojaKlasa> up2(new MojaKlasa(2,3,"aaa"));
    cout << up1->i << endl;
    cout << up2->s << endl;

    //dva unique pokazivača NE MOGU pokazivati na isti objekt
    //unique_ptr<MojaKlasa> up3 = up1;

    //shared
    shared_ptr<MojaKlasa> sp1(new MojaKlasa(2,3,"bbb"));
    cout << sp1->s << endl;
    cout << "Broj shared pointera: " << sp1.use_count() << endl;

    //dva shared pokazivača MOGU pokazivati na isti objekt
    shared_ptr<MojaKlasa> sp2 = sp1;
    cout << "Broj shared pointera: " << sp2.use_count() << endl;

    sp1.reset();
    cout << "Broj shared pointera: " << sp1.use_count() << endl;
    cout << "Broj shared pointera: " << sp2.use_count() << endl;

    // smart pointer na int
    unique_ptr<int> upInt(new int(99));
    cout << *upInt << endl;

    return 0;
}