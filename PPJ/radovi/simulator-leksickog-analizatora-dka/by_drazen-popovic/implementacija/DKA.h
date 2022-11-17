#ifndef Dka_h
#define Dka_h
#include "NKA.h"
#include "State.h"
#include <vector>
using namespace std;
class DKA
{
public:
	DKA(void);
	bool acc;
	bool empty;
	vector<StateP> startState;
	vector<StateP> currentState;
	void determinate(vector<NKA*> nkas);
	void reset();
	void next(char trigger);
	~DKA(void);
private:

};

#endif