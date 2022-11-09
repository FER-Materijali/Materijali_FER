#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
   template <class X> struct ListElement {
      X data;
      ListElement<X> *next;
   };

   ListElement<T> *head = nullptr;

 public:
   bool insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
#if 1
      // elementarno, s jednostrukim pokazivačem
      if (!head) { // prazna lista
         head = newElement;
      } else {
         ListElement<T> *p;
         for (p = head; p->next; p = p->next)
            ; // iteracija na kraj liste
         p->next = newElement;
      }
#else
      // naprednije, s **
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
#endif
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
      return true;
   }
   bool remove(T data) {
      ListElement<T> **p;
      for (p = &head; *p && data != (*p)->data; p = &((*p)->next))
         ;
      if (*p) {
         ListElement<T> *tmp;
         tmp = *p;
         *p = (*p)->next;
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
   l.append(4);
   l.append(5);
   l.append(6);
   l.insert(1);
   l.insert(2);
   l.insert(3);

#else
   List<string> l;
   l.insertSorted("pero");
   l.insertSorted("ante");
   l.insertSorted("branko");
   l.insertSorted("zoran");
#endif
   l.print();
   // l.printRecursive();
   l.remove(4);
   l.print();
   return 0;
}