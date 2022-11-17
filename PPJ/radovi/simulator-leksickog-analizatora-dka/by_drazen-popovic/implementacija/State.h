#ifndef State_h
#define State_h
#include <vector>
#include <map>
#include "D:\Projekt_Zavrsni\bladyjoker\SSP\RegExp.h"
using namespace std;

//forward declaration
class State;
typedef State* StateP;
class State 
{
public:
	State(void);
	State(StateP nullState);
	bool acc; //acceptance?
	char* regDes; //stanje od kojeg reg izraza?
	void setRegDes(char* str);
	void setReg(RegExpP regex_);
	RegExpP regex;
	vector<char> alphabet; //treba nam!
	void addTrans(StateP toState, char trigger);
	void setTransitions( map< char, StateP>);
	map< char, StateP > transitions; //map< key, value > ...key jest trigger a value jes stanje u koje ide!
	bool isNullState;
	~State(void);
};


#endif