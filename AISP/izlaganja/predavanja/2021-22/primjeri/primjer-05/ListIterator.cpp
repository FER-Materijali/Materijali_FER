#include <algorithm>
#include <iostream>
#include <string>
#define integer

using namespace std;

template <class T> struct ListElement {
   T data;
   ListElement<T> *next;
};

template <class T> class ListIterator {
 private:
   ListElement<T> *ptr = nullptr;

 public:
   ListIterator<T>() : ptr(nullptr) {}
   ListIterator<T>(ListElement<T> *ptr) : ptr(ptr) {}
   ListIterator<T>* operator++() { // prefix ++
      if (ptr)
         ptr = ptr->next;
      return this;
   }
   ListIterator<T> operator++(int i) { // postfix ++
      ListIterator<T> tmp = *this;
      ++(*this);
      return tmp;
   }
   bool operator!=(const ListIterator<T> &other) { return ptr != other.ptr; }
   T &operator*() { return ptr->data; }
};

template <class T> class List {
 private:
   ListElement<T> *head = nullptr;

 public:
   bool Insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool Append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
      return true;
   }
   bool InsertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
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

   typedef ListIterator<T> iterator;
   iterator begin() { return iterator(head); }
   iterator end() { return iterator(); }
};

template <class T> void doubleIt(T &item) { item *= 2; }

template <class T> class Multiply {
   T factor;

 public:
   Multiply(T factor) : factor(factor){};
   void operator()(T &item) { item *= factor; }
};

int main(void) {
#ifdef integer
   List<int> l;
   l.Insert(1);
   l.Insert(2);
   l.Insert(3);
   l.Append(4);
   l.Append(5);
   l.Append(6);
   List<int>::iterator i;
#else
   List<string> l;
   l.InsertSorted("pero");
   l.InsertSorted("ante");
   l.InsertSorted("branko");
   l.InsertSorted("zoran");
   List<string>::iterator i;
#endif
   for (i = l.begin();i != l.end(); ++i) {
      cout << *i << " ";
   }
   cout << endl;

   cout << endl;

#ifdef integer
   for_each(l.begin(), l.end(), doubleIt<int>);
   for (i = l.begin(); i != l.end(); i++) {
      cout << *i << " ";
   }
   cout << endl;
   for_each(l.begin(), l.end(), Multiply<int>(3));
   for (i = l.begin(); i != l.end(); i++) {
      cout << *i << " ";
   }
   cout << endl;
#endif

   return 0;
}