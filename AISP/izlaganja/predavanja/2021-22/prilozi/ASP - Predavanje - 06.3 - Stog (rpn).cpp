#include <iostream>
#include <string>

using namespace std;

template <typename T> class Stog {

    struct Atom {
        T data;
        Atom* next;
    };

    Atom* head = nullptr; //početak liste tj. stoga

    public:
        bool push(T data) {
            Atom *newAtom = new (nothrow) Atom;
            if (newAtom==nullptr) 
                return false;
            
            newAtom->data = data;
            newAtom->next = head;
            head = newAtom;

            return true;
        }

        T pop(){
            if (head == nullptr)
                throw runtime_error("Stog je prazan");
            
            T el = head->data;
            Atom* deleteMe = head;
            head = head->next;
            delete deleteMe;
            return el;
        }

        void print() {
            cout << "TOP -> ";
            for (Atom* i = head; i!=nullptr; i=i->next)
                cout << i->data << " -> ";
            cout << "NULLPTR" << endl;
        }

};

bool isOperator(string &s){
    if (s=="+" || s=="-" || s=="*" || s=="/")
        return true;
    return false;
}

int compute(int a, string op, int b){
    if (op=="+")
        return a+b;
    else if (op=="-")
        return a-b;
    else if (op=="*")
        return a*b;
    else if (op=="/")
        return a/b;
    //što sad?
    throw runtime_error("Operacija nije podržana");
}

int main(){

    Stog<string> s;
    string izraz[7]{"5","9","+","2","/","3","*"};

    for (int i=0; i<7; i++) {
        //ako je element izraza operator
        if (isOperator(izraz[i])) {
            //1. skinemo 2 operanda
            int b = stoi(s.pop());
            int a = stoi(s.pop());

            //i izračunamo vrijednost
            int rez = compute(a,izraz[i],b);

            //pa je vratimo na stog vrijednosti            
            s.push(to_string(rez));

        }
        //inače je broj
        else {
            s.push(izraz[i]);
        }

        //testni ispis da vidimo stanje stoga u svakom koraku
        s.print();
    }

    //na kraju na stogu je samo jedan ele i to je konačni rezultat
    cout << "Rezultat je: " << s.pop();

    return 0;
}