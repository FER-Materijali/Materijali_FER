#include <iostream>
using namespace std;

int main(void) {
   int a = 1;
   int &b = a;
   b = 7;
   cout << a << " " << b;
   return 0;
}