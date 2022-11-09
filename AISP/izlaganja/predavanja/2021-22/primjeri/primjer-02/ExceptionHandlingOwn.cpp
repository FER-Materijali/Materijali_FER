#include <iostream>
using namespace std;
int main(void) {
   int i;
   while (1) {
      try {
         cin >> i;
         if (i == 0)
            throw i;
         else if (i == 1)
            throw "Text exception";
         else
            throw 2.2;
      } catch (int &ie) {
         cerr << "Integer exception " << ie << endl;
      } catch (const char *te) {
         cerr << te << endl;
      } catch (...) {
         cerr << "Neka druga iznimka" << endl;
      }
   }
   return 0;
}