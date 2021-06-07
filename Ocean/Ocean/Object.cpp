#include "Object.h"

int Object::countObject = 0;

Object::Object(int l, char c, bool cm)
{
	setLive(l);
	setSymbol(c);
	setCanMove(cm);

	++countObject;
}

Object::~Object()
{
	--countObject;
}

int Object::getCountObject()
{
	return countObject;
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

void Object::setCanMove(bool cm)
{
	canMove = cm;
}

bool Object::getCanMove() const
{
	return canMove;
}

void Object::killMe()
{
	delete this;
}