#include <iostream> 
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

    srand(time(0));

    int x = rand() % 20;
    int y = rand() % 20;
    int odg;

    cout << "Koliko je " << x << " + " << y << "?" << endl;
    cout << "Odg: ";

    auto start = system_clock::now();

    cin >> odg;

    auto end = system_clock::now();

    cout << "Odgovor je" << (odg == (x+y)?"tocan!":"netocan!") << endl;

    auto d = end - start; //duration<double>

    cout << "Vrijeme: " << d.count() << endl;


    return 0;
}


