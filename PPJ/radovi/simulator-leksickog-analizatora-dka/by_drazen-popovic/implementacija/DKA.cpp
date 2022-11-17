#include "DKA.h"
#include <iostream>
using namespace std;

DKA::DKA(void)
{
	acc = false;
	empty = false;
}

DKA::~DKA(void)
{
}


void DKA::next(char trigger)
{
	vector<StateP> buffer;
	StateP nextState;
	int size;

	for(int j = 0; j < currentState.size(); j++)
		{
			
			nextState = currentState[j]->transitions[trigger];
			if(nextState->isNullState == false) buffer.push_back(nextState);
			
			
		}	
		currentState.clear();
		for(int j = 0; j < buffer.size(); j++) 
		{
			currentState.push_back( buffer[j] );
		}

		//Provjeravam prihvacenost DKA stanja
		acc = false;
		for(int j = 0; j < currentState.size(); j++)
		{
			if( currentState[j]->acc == true) {acc = true; break;}
		}
		buffer.clear();

		//Ako nema sljedeceg stanja, prijelaza -> error!
		if(currentState.size() == 0) empty = true;
}
void DKA::reset()
{
	//Samo u current state stavimo startstate!
	currentState.clear();
	acc = false;
	for(int i = 0; i < startState.size(); i++)
	{
		currentState.push_back( startState[i] );
		if(startState[i]->acc == true) acc = true;
	}
	
	if( startState.size() == 0 )empty = true;
	else empty = false;

}

void DKA::determinate(vector<NKA*> nkas)
{
	//U DKA startState stavljamo sva pocetna stanja od NKAova!
	for(int i = 0; i < nkas.size(); i++)
	{
		for(int j = 0; j < nkas[i]->startState.size(); j++)
		{
			startState.push_back( nkas[i]->startState[j]);
		}
	}
}