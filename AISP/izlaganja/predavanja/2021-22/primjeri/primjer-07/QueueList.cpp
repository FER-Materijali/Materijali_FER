#include <iostream>
using namespace std;

template <class T> class Queue {
 private:
   template <class X> struct QueueElement {
      T data;
      QueueElement<X> *next;
   };
   QueueElement<T> *read = nullptr;
   QueueElement<T> *write = nullptr;

 public:
   bool enqueue(T data) {
      QueueElement<T> *newElement = new (nothrow) QueueElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->next = nullptr;
      newElement->data = data;
      if (write == nullptr) {
         read = newElement;
      } else {
         write->next = newElement;
      }
      write = newElement;
      return true;
   }
   bool dequeue(T &data) {
      if (read == nullptr)
         return false;
      data = read->data;
      QueueElement<T> *tmp = read;
      read = read->next;
      if (read == nullptr)
         write = nullptr;
      delete tmp;
      return true;
   }
   int count() {
      // neučinkovita realizacija, samo za ilustraciju iteriranja po listi
      // bolje bi bilo s private varijablom koja se uvećava u enqueue a smanjuje
      // u dequeue
      int n;
      QueueElement<T> *tmp = read;
      for (n = 0; tmp; tmp = tmp->next)
         n++;
      return n;
   }
};
int main(void) {
   Queue<int> q;
   int data;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   cout << q.count() << endl;
   while (q.dequeue(data))
      cout << data << " ";
   cout << endl;
   return 0;
}