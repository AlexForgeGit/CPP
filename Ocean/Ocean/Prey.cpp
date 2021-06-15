#include "Prey.h"

int Prey::countPrey = 0;

Prey::Prey(int l, char c, int r, bool cm) : Object(l, c, cm) 
{
	setReproduction(r);
	++countPrey;
};

Prey::~Prey()
{
	--countPrey;
}

void Prey::setReproduction(int r)
{
	reproduct = r;
}

int Prey::getReproduction() const
{
	return reproduct;
}

int Prey::getCountPrey()
{
	return countPrey;
}