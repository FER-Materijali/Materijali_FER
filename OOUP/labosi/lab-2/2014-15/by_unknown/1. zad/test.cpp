//==== test.cpp
#include "client.hpp"
#include "derived.hpp"
#include "derived2.hpp"
#include "derived3.hpp"
int main(){
	Derived3 d;
	Client c(d);
	c.operate();
}
