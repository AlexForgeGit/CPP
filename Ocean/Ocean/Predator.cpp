#include "Predator.h"

int Predator::countPredator = 0;

Predator::Predator(int l, char c, int h, bool cm) : Object(l, c, cm)
{
	setHunger(h);
	++countPredator;
}

Predator::~Predator()
{
	--countPredator;
}

void Predator::setHunger(int h)
{
	hunger = h;
}

int Predator::getHunger() const
{
	return hunger;
}

int Predator::getCountPredator()
{
	return countPredator;
}