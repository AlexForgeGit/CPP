#include <iostream>
using std::cout;

#include "Predator.h"

Predator::Predator(int l, char s, int h) : Object(l, s)
{
	setHunger(h);
}

Predator::~Predator()
{
	Object::~Object();
	hunger = 0;
}

void Predator::setHunger(int h)
{
	hunger = h;
}

int Predator::getHunger() const
{
	return hunger;
}