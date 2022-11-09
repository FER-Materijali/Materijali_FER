#include <iostream>
using namespace std;

template <class T> class Stack {

   template <class X> struct StackElement {
      X item;
      StackElement<X> *next;
   };

   StackElement<T> *top = nullptr;

 public:
   bool push(T item) {
      StackElement<T> *newElement = new (nothrow) StackElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->item = item;
      newElement->next = top;
      top = newElement;
      return true;
   }
   bool pop(T &item) {
      if (top == nullptr)
         return false;
      item = top->item;
      StackElement<T> *tmp = top;
      top = top->next;
      delete tmp;
      return true;
   }
};
int main(void) {
   Stack<int> s, t;
   int item;
   s.push(1);
   s.push(2);
   s.push(3);
   t.push(10);
   t.push(20);
   t.push(30);
   while (s.pop(item))
      cout << item << " ";
   cout << endl;
   while (t.pop(item))
      cout << item << " ";
   cout << endl;
   return 0;
}