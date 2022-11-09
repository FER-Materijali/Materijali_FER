#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(void) {
   vector<int> v = {1, 2, 3, 4, 5};
   vector<int>::iterator i;
   for (i = v.begin(); i < v.end(); i++) {
      cout << *i << " ";
   }
   cout << endl;
   return 0;
}