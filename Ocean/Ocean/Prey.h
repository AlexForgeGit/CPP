#pragma once
#include "Object.h"

class Prey : public Object
{
public:
	Prey(int = 0, char = 0, int = 0, bool = true);
	~Prey();
	virtual void setReproduction(int);
	virtual int getRepruduction() const;

	static int getCountPrey();

private:
	int reproduct;

	static int countPrey;
}; 