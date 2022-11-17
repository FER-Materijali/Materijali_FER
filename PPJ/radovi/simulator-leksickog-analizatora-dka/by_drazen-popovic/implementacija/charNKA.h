#ifndef CharN_h
#define CharN_h

#include "NKA.h"
#include "State.h"

class charNKA :
	public NKA
{
public:
	charNKA(void);
	charNKA(StateP nullState);
	void make(char trigger);
	~charNKA(void);
private:
	StateP nullState_;
};
#endif