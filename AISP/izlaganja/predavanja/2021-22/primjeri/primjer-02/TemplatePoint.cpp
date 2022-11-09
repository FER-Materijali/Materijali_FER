#include <iostream>
using namespace std;

template <typename T> class Point {
 public:
   T x;
   T y;
   Point(T x, T y) {
      this->x = x;
      this->y = y;
   }
};

int main(void) {
   Point<int> pi(1, 2);
   Point<double> pd(3.4, 4.5);
   cout << pi.x << " " << pi.y << endl;
   cout << pd.x << " " << pd.y << endl;
   return 0;
}