#include <iostream>
using namespace std;
template <class T> class Queue {
 private:
   static const int MAX = 100;
   T queue[MAX];
   int write = 0;
   int read = 0;

 public:
   bool enqueue(T item) {
      if ((write + 1) % MAX == read)
         return false;
      queue[write] = item;
      write = (write + 1) % MAX;
      return true;
   }
   bool dequeue(T &item) {
      if (write == read)
         return false;
      item = queue[read];
      read = (read + 1) % MAX;
      return true;
   }
   int count() {
      if (write >= read) {
         return (write - read); // standardno
      } else {
         return (write - read + MAX); // cirkularnost
      }
   }
};
int main(void) {
   Queue<int> q;
   int item;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   cout << q.count() << endl;
   while (q.dequeue(item))
      cout << item << " ";
   cout << endl;
   return 0;
}