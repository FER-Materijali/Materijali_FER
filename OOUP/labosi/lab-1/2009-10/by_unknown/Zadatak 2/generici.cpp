#include <iostream>

template <class T>
inline T mymax(T x, T y) {
       if (x < y)
          return y;
       else 
            return x;
}

int main() {
    std::cout << mymax(3,7) <<"\n";
    std::cout << mymax(3.1,7.3) << "\n";
    std::cout << mymax("ana", "kristian") << "\n";
}
