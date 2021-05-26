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
		obj = new Object();
		break;
	case typeObject::STONE:
		obj = new Stone();
		break;
	case typeObject::PREY:
		obj = new Prey();
		break;
	case typeObject::PREDATOR:
		obj = new Predator();
		break;
	default:
		break;
	};
}

void Cell::printObject()
{
	obj->printMe();
}