#pragma once
#include "Object.h"

class Predator : public Object
{
public:
	Predator(int = 0, char = 0, int = 0, bool = true);
	~Predator();
	virtual void setHunger(int);
	virtual int getHunger() const;

	static int getCountPredator();

private:
	int hunger;

	static int countPredator;
}; 
