#include "RegExp.h"
#include <string.h>

RegExp::RegExp(void)
{
}

RegExp::~RegExp(void)
{
}

RegExp::RegExp(char *des, char *reg, int prior)
{
	designation = new char[ strlen(des) ];
	regex = new char[ strlen(reg) ];
	strcpy(designation , des);
	strcpy(regex , reg);
	priority = prior;
}