#ifndef Cat_h
#define Cat_h
#include "NKA.h"


class CatNKA :
	public NKA
{
public:
	CatNKA(void);
	~CatNKA(void);
	CatNKA(StateP nullState);
	void make(NKA* m1, NKA* m2);
private:
	StateP nullState_;
};


#endif