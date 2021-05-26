#include <iostream>
using std::cout;

#include "Stone.h"

Stone::Stone()
{
	setLive(30);
}

Stone::~Stone()
{
	live = 0;
}

void Stone::setLive(int l)
{
	live = l;
}

void Stone::printMe()
{
	cout << "*";
}