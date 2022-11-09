#include <iostream>
#include <string>

using namespace std;

template <class T> struct Atom {
    T data;
    Atom<T>* next;
};

template <class T> class ListIterator {
    private:
        Atom<T>* ptr = nullptr;
    
    public:
        ListIterator<T>() {ptr = nullptr;}
        ListIterator<T>(Atom<T>* p) {ptr = p;}

        ListIterator<T>& operator++() { //prefix ++a
            if (ptr != nullptr) ptr = ptr->next;
            return *this;
        }

        ListIterator<T> operator++(int){ //postfix ++, tj. a++
            ListIterator<T> tmp = *this;
            if (ptr != nullptr) ptr = ptr->next;
            return tmp;
        }

        bool operator!=(const ListIterator<T> &other) {
            return ptr != other.ptr;
        }

        T &operator*(){
            return ptr->data;
        }
};

template <class T> class List {
private:
    Atom<T> *head;
    Atom<T> *tail;

public:
    List() {head = tail = nullptr;}

    bool insert(T data) {
        Atom<T>* newAtom = new (nothrow) Atom<T>;
        if (newAtom == nullptr) return false;

        newAtom->data = data;
        newAtom->next = nullptr;

        newAtom->next = head;
        head = newAtom;

        if (!tail)
            tail = newAtom;

        return true;
    }

    typedef ListIterator<T> iterator;
    iterator begin() {return iterator(head);}
    iterator end() {return iterator(nullptr);}

    void print() {
        cout << "HEAD -> ";
        for (auto curr = head; curr != nullptr; curr = curr->next)
            cout << curr->data << " -> ";
        cout << "NULLPTR" << endl;
    }

};

int main() {

    List<int> lista;

    lista.insert(3);
    lista.insert(2);
    lista.insert(1);
    lista.print();

    List<int>::iterator i;

    for (i = lista.begin(); i != lista.end(); i++) {
        cout << *i;
    }

    return 0;
}