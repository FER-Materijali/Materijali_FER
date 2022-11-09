#include <iostream>
#include <string>
#define MAX 100 //0-99

using namespace std;

template <typename T> class Stog {
    T stog[MAX];
    int vrh = -1; // index vrha stoga, stog je prazan kad je -1

    public:
        bool push(T el) {
            if (vrh >= (MAX-1)) // pun stog -> vrh==99, tj. max-1
                return false;

            stog[++vrh] = el;
            return true;
        }

        T pop() {
            if (vrh < 0) //ako je vrh == -1 stog je prazan
                throw runtime_error("Stog je prazan");

            return stog[vrh--]; //vrati stog[vrh] pa smanji vrh
        }

        T peek() {
            if (vrh < 0)
                throw runtime_error("Stog je prazan");

            return stog[vrh];         
        }

        bool popRef(T &el) {
            if (vrh < 0)
                return false;

            el = stog[vrh--];
            return true;
        }

        // nije standardna fja stoga ali nama pomaže da vidimo stanje stoga
        void print() {
            cout << "VRH - ";
            for (int i=vrh; i> -1; i--)
                cout << stog[i] << " - ";
            cout << "DNO" << endl;
        }

};

int main(){
    Stog<int> s;

    s.print();
    s.push(2);
    s.push(5);

    s.push(3);
    s.print();

    s.pop();
    s.print();

    cout << "Na vrhu je: " << s.peek() << endl;
    s.print();

    cout << "S vrha smo skinuli: " << s.pop() << endl;
    s.print();

    return 0;
}