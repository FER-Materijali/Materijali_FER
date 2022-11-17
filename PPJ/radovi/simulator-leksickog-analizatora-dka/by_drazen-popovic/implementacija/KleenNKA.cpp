#include "KleenNKA.h"

KleenNKA::KleenNKA(void)
{
}

KleenNKA::~KleenNKA(void)
{
}

KleenNKA::KleenNKA(StateP nullState)
{
	nullState_ = nullState;
}
void KleenNKA::make(NKA *m1)
{
	//S = E = Em1 eStates
	for(int i = 0; i < m1->endState.size(); i++)
	{
		startState.push_back( m1->endState[i]);
		endState.push_back( m1->endState[i]);
	}	

	//moramo acc-at start stanja
	for(int i = 0; i < m1->startState.size(); i++) m1->startState[i]->acc = true;
	
	StateP eState,sState;
	for(int i = 0; i < m1->endState.size();i++)
	{
		eState = m1->endState[i];
		for(int ii = 0; ii < m1->startState.size(); ii++)
		{
			sState = m1->startState[ii];
			eState->setTransitions(sState->transitions);
		}
	}
}