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
            /*if (write == MAX)
                return false;
            queue[write++] = item;
            return true;*/
            if ((write+1) % MAX == read)
                return false;
            queue[write] = item;
            write = (write + 1) % MAX;
            return true;
        }

        bool dequeue(T &item) {
            /*if (read == write)
            return false;
            item = queue[read++];
            return true;*/
            if (read == write)
                return false;
            item = queue[read];
            read = (read+1) % MAX; 
            return true;
        }

        void print() {
            cout << "READ -> ";
            /*for (int i = read; i<write; i++)
                cout << queue[i] << " ";*/
            int i = read;
            while(true) {
                cout << queue[i] << " ";
                i = (i+1)% MAX;
                if (i == write)
                    break;
            }
            cout << "<- WRITE" << endl;
        }

        int count() {
            if (write> read)
                return write-read;
            else 
                return write - read + MAX;
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
    q.dequeue(item);
    q.dequeue(item);
    q.print();
    q.enqueue(9);
    q.print();
} 