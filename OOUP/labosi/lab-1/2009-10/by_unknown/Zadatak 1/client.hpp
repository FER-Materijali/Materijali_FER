#include <iostream>
#include "base.hpp"

class Client
{
public:
	Client(Base& b): solver_(b){};
	void operate(){
		std::cout << solver_.solve() <<"\n";
	}
private:
	Base& solver_;
};
