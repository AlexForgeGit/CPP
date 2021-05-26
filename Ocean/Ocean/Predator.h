#pragma once
#include "Object.h"

class Predator : public Object
{
public:
	Predator();
	~Predator();
	void setLive(int);
	void printMe();
private:
	int live;
}; 
