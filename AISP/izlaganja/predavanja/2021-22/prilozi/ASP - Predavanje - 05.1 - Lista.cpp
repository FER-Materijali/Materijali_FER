#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

template <typename T> class List{
private:
    struct Atom {
        T data;
        Atom* next;
    }; //pazi, treba ";", Probajte maknuti ; pa čitajte erore :)
    Atom* head;
    Atom* tail;

public:
    List() {head = tail = nullptr; }

    bool insert(T data) {
        Atom* newAtom = new (nothrow) Atom;
        if (newAtom==nullptr) return false;

        newAtom->data = data;

        //Novi atom treba pokazivati na ono na što je do sad pokazivao head
        newAtom->next = head;
        //Nakon toga head treba pokazivati na taj novi element
        head = newAtom;

        if (!tail)
            tail = newAtom;

        return true;
    }

    //append ako nemamo tail - složenost O(n)
    /*bool append_slow(T data) {
        Atom* newAtom = new (nothrow) Atom;
        if (newAtom == nullptr) return false;

        newAtom->data = data;
        newAtom->next = nullptr;

        //što ako je lista prazna? onda je head == nullptr
        if (head == nullptr) { // if (!head)
            head = newAtom;
        }
        else {
            Atom *curr = head;
            while (curr->next) {curr = curr->next;} // O(n)
            //sad je curr->next nullptr i na kraju sam liste
            curr->next = newAtom;
        }
        return true;
    }*/

    // append s tail-om, složenost je O(1), imamo extra varijablu u svakoj listi
    bool append(T data) {
        Atom* newAtom = new (nothrow) Atom;
        if (newAtom==nullptr) return false;

        newAtom->data = data;  
        newAtom->next = nullptr;

        if (!head) { //ako je ovo prvi el. (onda nema ni heada ni taila)
            head = tail = newAtom;
        }
        else {
            tail->next = newAtom;
            tail = newAtom;
        }
        return true;

    }

    bool insert_sorted_simple(T data){
        Atom* newAtom = new (nothrow) Atom;
        if (newAtom==nullptr) return false;

        newAtom->data = data;  
        newAtom->next = nullptr;

        //npr. imamo listu 0-2-4-7-9
        
        //što ako dodajem na početak? To je ustvari fja insert
        //na poč dodajem kad je lista prazna ili je el manji od prvog, npr. -1
        if (!head || newAtom->data < head->data) {
            newAtom->next = head;
            head = newAtom;
        }

        //inače dodajem negdje u sredinu
        else {
            //prvo nađemo mjesto
            Atom* curr = head;
            Atom* prev;
            while (curr != nullptr && curr->data < data) {
                prev = curr;
                curr = curr->next;
            }
            //sad ubacim element
            newAtom->next = curr;
            prev->next = newAtom;
        }

        // a tail?
        if (!tail || newAtom->next == nullptr)
            tail = newAtom;

        return true;
    }

    bool insert_sorted(T data) {
        Atom* newAtom = new (nothrow) Atom;
        if (newAtom==nullptr) return false;

        newAtom->data = data;  
        newAtom->next = nullptr;

        Atom **p;

        for(p = &head; // p pokazuje na head
            *p && (*p)->data < data; // dok god postoji "head" ili je head->data < data
            p = &((*p)->next) // pomičem pokazivač na "head" na sljedeći "head"
        ); // u tijelu ne radim ništa

        // sad moram ispred p dodati novi el

        newAtom->next = *p;
        *p = newAtom;

        //tail?
        if (!tail || newAtom->next == nullptr)
            tail = newAtom;

        return true; 
    }

    bool remove_simple(T data) {
        if (head == nullptr)
            return false;

        if (head->data == data) {
            Atom *toDelete = head;
            //ako je jedini el. u listi
            if (head == tail)
                tail = nullptr;
            head = head->next;
            delete toDelete;
        }

        else {
            //prvo nađemo mjesto s kojeg brišemo
            Atom* curr = head;
            Atom* prev;
            while (curr != nullptr && curr->data != data) {
                prev = curr;
                curr = curr->next;
            }

            //sad curr pokazuje na traženi el ili je curr==nullptr
            if (curr == nullptr)
                return false;
            
            prev->next = curr->next;

            //što ako mičem zadnji element?
            if (tail == curr)
                tail = prev;

            delete curr;
        }

        return true;
    }

    void print() {
        cout << "HEAD -> ";
        for (auto curr = head; curr != nullptr; curr = curr->next)
            cout << curr->data << " -> ";
        cout << "NULLPTR" << endl;
    }

};


int main() {
/*
    List<int> *l = new List<int>();

    l->print();
    l->insert(3);
    l->print();
    l->insert(2);
    l->print();
    //l->append_slow(7);
    l->append(7);
    l->print();

    List<string> *ls = new List<string>();

    ls->print();
    ls->insert("Ana");
    ls->print();
    ls->append("<3");
    ls->print();
    ls->append("Milovana");
    ls->print();
*/

    List<int> lsorted;
    lsorted.insert_sorted_simple(2);
    lsorted.print();
    lsorted.insert_sorted_simple(4);
    lsorted.print();
    lsorted.insert_sorted_simple(7);
    lsorted.print();
    lsorted.insert_sorted_simple(3);
    lsorted.print();
    lsorted.insert_sorted_simple(0);
    lsorted.print();

    lsorted.insert(5); // PAZI!!!
    lsorted.print();
    lsorted.insert_sorted_simple(4);
    lsorted.print();
    lsorted.insert_sorted_simple(6);
    lsorted.print();

    int i = 5;
    int* p = &i;
    int **r = &p;


    cout << "i=" << i << endl;
    cout << "p=" << p << endl;
    cout << "*p=" << *p << endl;
    cout << "r=" << r << endl;
    cout << "&p=" << &p << endl;  
    cout << "*r=" << *r << endl; 
    cout << "**r=" << **r << endl; 

    List<int> lsorted2;
    lsorted2.insert_sorted(2);
    lsorted2.print();
    lsorted2.insert_sorted(4);
    lsorted2.print();
    lsorted2.insert_sorted(7);
    lsorted2.print();
    lsorted2.insert_sorted(3);
    lsorted2.print();
    lsorted2.insert_sorted(0);
    lsorted2.print();

    return 0;
}