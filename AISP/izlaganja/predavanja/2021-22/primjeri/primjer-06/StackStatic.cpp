#include <iostream>
using namespace std;
template <class T> class Stack {
 private:
   static const int MAX = 100;
   T stack[MAX];
   int top = -1;

 public:
   bool push(T item) {
      if (top >= MAX)
         return false;
      stack[++top] = item;
      return true;
   }
   bool pop(T &item) {
      if (top < 0)
         return false;
      item = stack[top--];
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