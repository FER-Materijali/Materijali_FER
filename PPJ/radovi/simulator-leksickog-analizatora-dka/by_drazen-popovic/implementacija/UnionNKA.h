#ifndef Union_h
#define Union_h
#include "NKA.h"
#include <vector>
using namespace std;

class UnionNKA :
	public NKA
{
public:
	UnionNKA(void);
	UnionNKA( StateP nullState );
	void make(NKA* m1, NKA* m2);
	~UnionNKA(void);
private:
	StateP nullState_;
};

#endif