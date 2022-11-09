#include <iostream>
#include <string>

using namespace std;

template <typename T> class Stog {

    //može biti i class
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

        bool pop(T &el){
            if (head == nullptr)
                return false;
            
            el = head->data;
            Atom* deleteMe = head;
            head = head->next;
            delete deleteMe;
            return true;
        }

        void print() {
            cout << "TOP -> ";
            for (Atom* i = head; i!=nullptr; i=i->next)
                cout << i->data << " -> ";
            cout << "NULLPTR" << endl;
        }

};


int main(){

    Stog<string> s;

    s.push("Ivo");
    s.print();
    s.push("Ana");
    s.print();
    s.push("Mirko");
    s.print();
    
    string el;
    s.pop(el);
    cout << "Skinuli sa stoga: " << el << endl;
    s.print();

    return 0;
}