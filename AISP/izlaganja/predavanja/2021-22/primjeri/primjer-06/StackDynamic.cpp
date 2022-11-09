#include <iostream>
using namespace std;
template <class T> class Stack {
 private:
   static const size_t increment = 100;
   size_t size = 100;
   T *stack;
   int top = -1;

 public:
   Stack() { stack = (T *)malloc(size * sizeof(T)); }
   Stack(size_t size) : size(size) { stack = (T *)malloc(size * sizeof(T)); }
   bool push(T item) {
      if (top >= size) {
         T *tmp = (T *)realloc(stack, size + increment);
         if (!tmp)
            return false;
         stack = tmp;
         size += increment;
      }
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