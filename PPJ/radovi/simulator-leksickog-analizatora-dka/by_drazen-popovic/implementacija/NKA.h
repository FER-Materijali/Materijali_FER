#ifndef Nka_h
#define Nka_h
#include <vector>
#include "State.h"
using namespace std;

class NKA
{
public:
	NKA(void);
	std::vector<StateP> startState;
	std::vector<StateP> endState;
	~NKA(void);
};


#endif Nka_h