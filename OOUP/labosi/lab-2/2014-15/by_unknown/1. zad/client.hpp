//==== client.hpp
#include "base.hpp"
class Client{
	public:
		Client(Base& b): solver_(b){}
		void operate();
	private:
		Base& solver_;
};
