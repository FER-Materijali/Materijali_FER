#include <iostream>
using namespace std;
#define MAX 5
int main(void) {
   int p[5] = {1, 2, 3, 4, 5}, i;
   try {
      while (1) {
         cin >> i;
         if (i < 0 || i >= MAX)
            throw out_of_range("Indeks izvan dozvoljenih granica");
         cout << p[i] << endl;
      }
   } catch (exception &e) {
      cerr << e.what() << endl;
   }
   return 0;
}