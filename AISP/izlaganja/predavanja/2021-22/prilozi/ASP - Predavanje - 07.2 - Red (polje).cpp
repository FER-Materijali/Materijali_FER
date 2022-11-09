#include <iostream>
#include <string>
//#define MAX 8
using namespace std;

template <typename T> class Queue {
    private:
        static const int MAX = 8;
        T queue[MAX];
        int read = 0;
        int write = 0;

    public:
        bool enqueue(T item) {
            if (write == MAX)
                return false;
            queue[write++] = item;
            return true;
        }

        bool dequeue(T &item) {
            if (read == write)
            return false;
            item = queue[read++];
            return true;
        }

        void print() {
            cout << "READ -> ";
            for (int i = read; i<write; i++)
                cout << queue[i] << " ";
            cout << "<- WRITE" << endl;
        }

        int count() {
            return write-read;
        }

};

int main(void) {

    Queue<int> q;
    int item;

    q.print();
    q.enqueue(5);
    q.print();
    q.enqueue(4);
    q.print();
    q.enqueue(1);
    q.print();
    q.dequeue(item);
    cout << "procitao sam " << item << endl;
    q.print();
    q.enqueue(1);
    q.print();
    q.enqueue(1);
    q.print();
    q.enqueue(1);
    q.print();
    q.enqueue(1);
    q.print();
    q.enqueue(1);
    q.print();
    q.enqueue(1);
    q.print();
} 