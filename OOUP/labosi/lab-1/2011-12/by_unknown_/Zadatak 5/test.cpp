#include "client.hpp"
#include "derived.hpp"
#include "derived2.hpp"
#include "derived3.hpp"

int main()
{
    Derived d;
    Client c(d);
    c.operate();

    return 0;
}