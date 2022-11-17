#ifndef RegExp_h
#define RegExp_h

class RegExp
{
public:
	RegExp(void);
	RegExp( char* des, char* reg, int prior);
	char* designation;
	char* regex;
	int priority; //prije napisani regularni izrazi imaju prednost
	~RegExp(void);
};

typedef RegExp* RegExpP;

#endif