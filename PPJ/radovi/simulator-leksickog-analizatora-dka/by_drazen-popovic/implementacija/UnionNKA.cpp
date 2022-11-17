#include "UnionNKA.h"

UnionNKA::UnionNKA(void)
{
}

UnionNKA::~UnionNKA(void)
{
}

UnionNKA::UnionNKA(StateP nullState)
{
	nullState_ = nullState;
}

void UnionNKA::make(NKA* m1, NKA* m2)
{
	//U nase DKA pocetno stanje stavljamo pocetna stanja od m1 i m2
	//simuliramo DKA

	for(int i = 0; i < m1->startState.size(); i++)
	startState.push_back( m1->startState[i]);
	
	for(int i = 0; i < m2->startState.size(); i++)
	startState.push_back( m2->startState[i]);

	//Isto tako zavrsna stanja stavljamo u ovo zavrsno stanje

	for(int i = 0; i < m1->endState.size(); i++)
	endState.push_back( m1->endState[i]);
	
	for(int i = 0; i < m2->endState.size(); i++)
	endState.push_back( m2->endState[i]);
}