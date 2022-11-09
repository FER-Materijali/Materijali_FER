#include <iostream>

using namespace std;

class C {
    public:
        int x,y;
        int *p;
        C() : x(0), y(0) {cout << "+ "; p = (int*) malloc(80*sizeof(int));}
        C(int x, int y) : x(x), y(y) { cout << "x "; p = (int*) malloc(80*sizeof(int));}
        ~C() {cout << "~ "; free(p);}
        /*C(C &c) {
            x = c.x;
            this->y = c.y;
            p = (int*) malloc(80*sizeof(int));
            memcpy(p, c.p, sizeof(c.p));
        }*/


};

void fja1(int i) {
    i++;
}

void fja2(C c) {
    c.x++;  c.p[77]++;
}

int main() {
    C *p1, *p2;

    p1 = new C();
    p2 = new C(3,3);
    
    delete p2;

    p2 = new C();
    p2 = new C(5,5); // zauzeo sam novu mem ali nisam oslobodio staru!!!

    cout << endl;
    C *p3 = new C[5];
    cout << endl;
    delete[] p3;

    cout << endl;

    //poziv funkcije... call by value
    int i = 5;
    cout << i << endl;
    fja1(i);
    cout << i << endl; // i je isti, jer smo u fju poslali kopiju

    // ovdje će c.x ostati isti ali će se c.p[77] promijeniti! 
    // To je "neočekivano ponašanje" za call by value, razlog: "shallow copy"
    // ako napišemo copy constructor za C onda će se pri pozivu funkije 
    // napraviti ispravna kopija objekta i c.p[77] neće biti promijenjen
    C c(3, 3);
    c.p[77] = 0;
    cout << c.x << "--" << c.p[77] << endl;
    fja2(c);
    cout << c.x << "--" << c.p[77] << endl; // probati ovo sa i bez copy konstruktora

    return 0;
}