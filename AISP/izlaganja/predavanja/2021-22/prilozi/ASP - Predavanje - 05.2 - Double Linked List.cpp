#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
   template <class X> struct ListElement {
      X data;
      ListElement<X> *next;
      ListElement<X> *prev;
   };

   ListElement<T> *head = nullptr;
   ListElement<T> *tail = nullptr;

 public:
   bool insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      newElement->prev = nullptr;
      if (head == nullptr) {
         tail = newElement;
      } else {
         head->prev = newElement;
      }
      head = newElement;
      return true;
   }
   bool append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      newElement->prev = tail;
      if (tail == nullptr) {
         head = newElement;
      } else {
         tail->next = newElement;
      }
      tail = newElement;
      return true;
   }
   bool insertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
                               // imati implementiran operator >
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      newElement->prev = nullptr;
      if (head == nullptr) {
         head = tail = newElement;
         return true;
      }
      ListElement<T> *p;
      for (p = head; p && data > p->data; p = p->next)
         ;
      if (p == nullptr) { // umetanje na kraj
         tail->next = newElement;
         newElement->prev = tail;
         tail = newElement;
      } else if (p == head) { // umetanje na početak
         head->prev = newElement;
         newElement->next = head;
         head = newElement;
      } else {
         newElement->next = p;
         newElement->prev = p->prev;
         newElement->prev->next = newElement;
         p->prev = newElement;
      }
      return true;
   }
   bool remove(T data) {
      ListElement<T> *p;
      for (p = head; p && data != p->data; p = p->next)
         ;
      if (p) {
         if (p == head && p == tail) { // posljednji element
            head = nullptr;
            tail = nullptr;
         } else if (p == head) { // brisanje s početka
            head = p->next;
            p->next->prev = nullptr;
         } else if (p == tail) { // brisanje s kraja
            tail = p->prev;
            p->prev->next = nullptr;
         } else { // element koji ima sljedećeg i prethodnog
            p->next->prev = p->prev;
            p->prev->next = p->next;
         }
         delete p;
         return true;
      } else {
         return false;
      }
   }
   void print() {
      for (ListElement<T> *p = head; p; p = p->next) {
         cout << p->data << " ";
      }
      cout << endl;
   }
   void printReverse() {
      for (ListElement<T> *p = tail; p; p = p->prev) {
         cout << p->data << " ";
      }
      cout << endl;
   }
};

int main(void) {
   List<int> l;
   l.insert(1);
   l.insert(2);
   l.insert(3);
   l.append(4);
   l.append(5);
   l.append(6);
   l.print();
   l.printReverse();
   l.remove(4);
   l.print();
   l.printReverse();
   l.remove(6);
   l.print();
   l.printReverse();
   l.remove(3);
   l.print();
   l.printReverse();

   List<string> m;
   m.insertSorted("Ivo");
   m.insertSorted("Ante");
   m.insertSorted("Pero");
   m.insertSorted("Mate");
   m.print();
   m.printReverse();
   return 0;
}