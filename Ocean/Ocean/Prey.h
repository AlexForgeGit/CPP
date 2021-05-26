#pragma once
#include "Object.h"

class Prey : public Object
{
public:
	Prey();
	~Prey() ;
	void setLive(int);
	void printMe();
private:
	int live;
}; 