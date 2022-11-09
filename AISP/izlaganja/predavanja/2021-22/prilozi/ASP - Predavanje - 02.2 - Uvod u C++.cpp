#include <iostream> 

using namespace std;

class Point {
    public:
        double x, y;
        Point() { x=0; y=0;} //ili, s init listom: Point() : x(0), y(0) {}
        Point(double xin, double yin) {x = xin; y = yin;} // s init listom: Point(double x, double y) : x(x), y(y) {}
        //~Point(){ cout << "destruktor!" << endl; }
        void print() { cout << "(" << x << "," << y << ")" << endl;}
};

int main(void) {

    Point p; //u Javi je sintaksa: Point p = new Point(); ali u Javi je p referenca, a u C++ je stvarni objekt na stogu
    p.print();
    p.x = 0;
    p.y = 3;
    p.print();

    Point q;

    // U Javi bi ovo bilo pridruživanje referenci, u C++ se događa kopiranje memorije
    q = p;  //isto kao da smo napisali: memcpy(&q, &p, sizeof(p));

    q.print();
    q.x = 9;    // pošto smo kopirali memoriju, p i q nisu nikako povezani
    p.print();
    q.print();

    Point *pp = &p; //ili npr. Point &pr = p; - stvorili bi referencu na p
    (*pp).print();  //isto kao i pp->print();
    pp->x = 1;      //pp pokazuje na p, ako mijenjamo pp->x mijenjamo ustvari p.x
    pp->print();
    p.print();

    Point s(3,6);  //stvaranje točke s pozivom konstruktora s 2 argumenta
    s.print();

    //Ovo ispod ne radi - pukne cout jer je compiler liniju Point s1(); shvatio kao definiciju fje, a ne poziv def. konstruktora
    //Point s1();
    Point s1; //ovako bez zagrada radi, i pozove se def. konstruktor
    cout << s1.x << endl;

    int i{20};
    cout << i << endl;

    Point p1{2,6};
    p1.print();

    //ovo ne radi, compiler ne zna kako zbrojiti dvije točke. Moramo mu napisati funkciju koju će pozvati kad naiđe na Point + Point
    //to ćemo raditi sljedeći sat
    //p + s;

    return 0;
}