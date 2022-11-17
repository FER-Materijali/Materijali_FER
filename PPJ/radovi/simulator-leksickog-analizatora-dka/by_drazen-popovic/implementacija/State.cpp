#include "State.h"
#include <utility>
using namespace std;
State::State(void)
{
}

State::~State(void)
{
}
State::State(StateP nullState)
{
	isNullState  = false;
	acc = false;
	alphabet = nullState->alphabet;
	regex = nullState->regex;
	for(int i = 0; i < alphabet.size(); i++)
	{
		transitions[ alphabet.at(i) ] = nullState;
	}
	//ovo znaci da smo procitali kraj!!!
	transitions[0] = nullState;
}
void State::addTrans(StateP toState, char trigger)
{
	//if( transitions[ trigger ]->isNullState = true ) transitions[trigger].clear();
	transitions[ trigger ] = toState;
}

void State::setRegDes(char *str)
{
	regDes = new char[ strlen(str) ];
	strcpy(regDes, str);
}

void State::setReg(RegExpP regex_)
{
	regex = regex_;
}

//dodaje prijelaze koji nisu NULL prijelaze sa prijelazima sourceTrans
void State::setTransitions(std::map<char,StateP> sourceTrans)
{
	for(int i = 0; i < alphabet.size(); i++)
	{
		if( sourceTrans[alphabet[i]]->isNullState == true ) continue;
		transitions[alphabet[i]] = sourceTrans[alphabet[i]];
	}
}
