#include <iostream>
using std::cout;

#include "Prey.h"

Prey::Prey()
{
	setLive(30);
}

Prey::~Prey()
{
	live = 0;
}

void Prey::setLive(int l)
{
	live = l;
}

void Prey::printMe()
{
	cout << "P";
}