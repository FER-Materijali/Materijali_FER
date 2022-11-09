#include <iostream>
using namespace std;
void swap(int &a, int &b) {
   int tmp = a;
   a = b;
   b = tmp;
}
int main(void) {
   int a = 1, b = 2;
   swap(a, b);
   cout << a << " " << b;
   return 0;
}