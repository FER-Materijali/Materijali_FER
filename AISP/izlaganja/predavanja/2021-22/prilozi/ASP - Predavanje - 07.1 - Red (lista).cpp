#include <iostream>
#include <string>
using namespace std;

template <typename T> class Queue {
    private:
        int cnt = 0;
        struct Atom
        {
            T data;
            Atom *next;
        };
        Atom *read = nullptr;
        Atom *write = nullptr;
        
    public:
        bool enqueue(T data) {
            Atom* newAtom = new (nothrow) Atom;
            if (newAtom==nullptr) 
                return false;

            newAtom->data = data;  
            newAtom->next = nullptr;

            //ako je to prvi el
            if (write == nullptr) {
                read = newAtom;
            }
            else {
                write->next = newAtom;
            }
            write = newAtom;
            cnt++;
            return true;
        }

        bool dequeue(T &data) {
            if (read == nullptr)
                return false;
            
            data = read->data;
            Atom *tbd = read;
            read = read->next;
            if (read == nullptr)
                write = nullptr;
            
            delete tbd;
            cnt--;
            return true;
        }

        int count() {
            return cnt;
        }

};

int main(){
    Queue<int> q;
    int data;

    cout << "count: " << q.count() << endl;

    q.enqueue(3);
    q.enqueue(6);

    cout << "count: " << q.count() << endl;

    q.enqueue(2);
    q.enqueue(9);

    cout << "count: " << q.count() << endl;   

    while (q.dequeue(data))
        cout << data << " - ";
    cout << endl;

    cout << "count: " << q.count() << endl;   
}