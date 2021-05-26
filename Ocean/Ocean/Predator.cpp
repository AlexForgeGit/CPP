#include <iostream>
using std::cout;

#include "Predator.h"

Predator::Predator()
{
	setLive(30);
}

Predator::~Predator()
{
	live = 0;
}

void Predator::setLive(int l)
{
	live = l;
}

void Predator::printMe()
{
	cout << "†";
}

