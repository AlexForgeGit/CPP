#pragma once
#include "Object.h"

class Predator : public Object
{
public:
	Predator(int = 0, char = 0, int = 0);
	~Predator();
	void setHunger(int);
	int getHunger() const;

private:
	int hunger;
}; 
