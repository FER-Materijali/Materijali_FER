#include <iostream>
using namespace std;

struct Point {
   int x;
   int y;
};

int main(void) {
   Point p = {1, 2};
   Point r = {3};
   cout << p.x << " " << p.y << std::endl;
   cout << r.x << " " << r.y << std::endl;
   return 0;
}