//==== client.cpp
#include "client.hpp"
#include <iostream>
void Client::operate(){
	std::cout <<solver_.solve() <<"\n";
}
