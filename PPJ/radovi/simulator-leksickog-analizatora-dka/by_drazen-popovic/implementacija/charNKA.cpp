#include "charNKA.h"

charNKA::charNKA(void)
{
}
charNKA::charNKA( StateP nullState)
{
	nullState_ = nullState;
}
charNKA::~charNKA(void)
{
}

void charNKA::make(char trigger)
{
	startState.push_back( new State(nullState_));
	endState.push_back( new State(nullState_));

	startState[0]->addTrans(endState[0], trigger);
	endState[0]->acc = true;
}
