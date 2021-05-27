#include <iostream>
using std::cout;

#include "Object.h"

Object::Object(int l, char c)
{
	setLive(l);
	setSymbol(c);
}

Object::~Object()
{
	live = 0;
	symbol = 0;
}

void Object::setLive(int l)
{
	live = l;
}

int Object::getLive() const
{
	return live;
}

void Object::setSymbol(char c)
{
	symbol = c;
}

char Object::getSymbol() const
{
	return symbol;
}
