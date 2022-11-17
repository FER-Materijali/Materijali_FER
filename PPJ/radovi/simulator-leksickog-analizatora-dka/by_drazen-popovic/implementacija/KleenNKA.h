#ifndef Kleen_h
#define Kleen_h
#include "nka.h"

class KleenNKA :
	public NKA
{
public:
	KleenNKA(void);
	~KleenNKA(void);
	KleenNKA(StateP nullState);
	void make(NKA* m1);
private:
	StateP nullState_;
};

#endif