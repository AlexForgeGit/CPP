#include <iostream>

using std::cout;

#include "Cell.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

Cell::Cell()
{
	setObject(typeObject::EMPTY);
}

Cell::~Cell()
{
	delete obj;
}

void Cell::setObject(typeObject typeObj)
{
	switch (typeObj)
	{
	case typeObject::EMPTY:
		obj = new Object(0, '.');
		break;
	case typeObject::STONE:
		obj = new Stone(30, '*');
		break;
	case typeObject::PREY:
		obj = new Prey(10, 'o');
		break;
	case typeObject::PREDATOR:
		obj = new Predator(10, 'X', 5);
		break;
	default:
		break;
	};
}

char Cell::getObject() const
{
	return obj->getSymbol();
}