#include <fstream>
#include <iostream>
//#include <memory>
#include <string>
using namespace std;

template <class T> class List {
   template <class X> struct ListElement {
      X data;
      shared_ptr<ListElement<X>> next;
   };

   shared_ptr<ListElement<T>> head = nullptr;

 public:
   bool insert(T data) { // umetanje na početak liste
      shared_ptr<ListElement<T>> newElement(new (nothrow) ListElement<T>);
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool append(T data) { // dodavanje na kraj liste
      shared_ptr<ListElement<T>> newElement(new (nothrow) ListElement<T>);
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      shared_ptr<ListElement<T>> *p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
      return true;
   }
   bool insertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
                               // imati implementiran operator >
      shared_ptr<ListElement<T>> newElement(new (nothrow) ListElement<T>);
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      shared_ptr<ListElement<T>> *p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }
   bool remove(T data) {
      shared_ptr<ListElement<T>> *p;
      for (p = &head; *p && data != (*p)->data; p = &((*p)->next))
         ;
      if (*p) {
         shared_ptr<ListElement<T>> tmp;
         tmp = *p;
         *p = (*p)->next;
         tmp.reset();
         return true;
      } else {
         return false;
      }
   }
   void print() {
      for (shared_ptr<ListElement<T>> p = head; p; p = p->next) {
         cout << p->data << " ";
      }
      cout << endl;
   }
   // samo za ilustraciju, nikad tako u stvarnosti
   void printRecursive() { printR(head); }
   void printR(shared_ptr<ListElement<T>> p) {
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
#else
   List<string> l;
   l.insertSorted("pero");
   l.insertSorted("ante");
   l.insertSorted("branko");
   l.insertSorted("zoran");
#endif
   l.print();
   l.printRecursive();
   l.remove(6);
   l.print();
   return 0;
}