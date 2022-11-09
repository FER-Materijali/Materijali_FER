#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void print(int &i) { cout << i << " "; }
void multiply2(int &i) { i *= 2; }

int main(void) {
   vector<int> v = {1, 2, 3, 4, 5};
   for_each(v.begin(), v.end(), multiply2);
   for_each(v.begin(), v.end(), print);
   return 0;
}