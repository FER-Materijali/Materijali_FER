#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
   template <class X> struct ListElement {
      X data;
      ListElement<X> *next;
   };

   ListElement<T> *head = nullptr;
   ListElement<T> *tail = nullptr; // razlika u odnosu na List.cpp
 public:
   bool insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      if (!tail)
         tail = head; // razlika u odnosu na List.cpp
      return true;
   }
   bool append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      if (!tail) {                // razlika u odnosu na List.cpp
         head = newElement;       // razlika u odnosu na List.cpp
      } else {                    // razlika u odnosu na List.cpp
         tail->next = newElement; // razlika u odnosu na List.cpp
      }                           // razlika u odnosu na List.cpp
      tail = newElement;          // razlika u odnosu na List.cpp
      return true;
   }
   bool insertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
                               // imati implementiran operator >
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      ListElement<T> **p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      // jedini element u listi
      if (!tail)
         tail = head; // razlika u odnosu na List.cpp
      // element je dodan na kraj
      if (!newElement->next)
         tail = newElement; // razlika u odnosu na List.cpp
      return true;
   }
   bool remove(T data) {
      ListElement<T> **p;
      // treba nam i pointer na element liste kojemu se mijenja sljedeći, radi
      // eventualne prilagodbe tail-a
      ListElement<T> *r; // razlika u odnosu na List.cpp
      for (p = &head, r = head;
           *p && data != (*p)->data;  // razlika u odnosu na List.cpp
           r = *p, p = &((*p)->next)) // razlika u odnosu na List.cpp
         ;
      if (*p) { // nađen element kojeg treba brisati
         ListElement<T> *tmp;
         tmp = *p;
         *p = (*p)->next;
         // obrisan je jedini
         if (head == nullptr) // razlika u odnosu na List.cpp
            tail = nullptr;   // razlika u odnosu na List.cpp
         // obrisan je zadnji
         else if (*p == nullptr) // razlika u odnosu na List.cpp
            tail = r;            // razlika u odnosu na List.cpp
         delete tmp;
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
   // samo za ilustraciju, nikad tako u stvarnosti
   void printRecursive() { printR(head); }

 private:
   void printR(ListElement<T> *p) {
      if (p == nullptr) {
         cout << endl;
      } else {
         cout << p->data << " ";
         printR(p->next);
      }
   }
};

int main(void) {
#if 1
   List<int> l;
   l.insert(1);
   l.insert(2);
   l.insert(3);
   l.append(4);
   l.append(5);
   l.append(6);
   l.remove(6);
   l.append(7);
#else
   List<string> l;
   l.insertSorted("pero");
   l.insertSorted("ante");
   l.insertSorted("branko");
   l.insertSorted("zoran");
#endif
   l.print();
   // l.printRecursive();
   l.print();
   l.remove(3);
   l.remove(7);
   l.remove(5);
   l.remove(1);
   l.remove(4);
   l.print();
   l.remove(2);
   l.print();
   l.append(11);
   l.print();
   return 0;
}