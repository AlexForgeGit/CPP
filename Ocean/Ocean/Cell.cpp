#include <iostream>

using std::cout;
using std::endl;

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
		obj = new Prey(30, 'o', 5);
		break;
	case typeObject::PREDATOR:
		obj = new Predator(30, 'X', 15);
		break;
	default:
		break;
	};
}

char Cell::getObject() const
{
	return obj->getSymbol();
}

void Cell::deleteObject()
{
	obj->killMe();
}

void Cell::moveObject(Cell& cellBasic, Cell& cellSecondary)
{
	switch (cellBasic.getObject())																	
	{
	case 'X':																						//Object predator
		if (cellSecondary.obj->getSymbol() == 'o' && cellBasic.obj->getCanMove() == true)		    //if prey is encountered and predator can move
		{		
			cellSecondary.deleteObject();
			cellSecondary = cellBasic;																//eat prey
			cellSecondary.obj->setCanMove(false);													//forbed to move this turn
			cellSecondary.obj->setHunger(cellSecondary.obj->getHunger() + 10);						//maximum satiety
			cellSecondary.obj->setLive(cellSecondary.obj->getLive() - 1);							//age
			cellBasic.setObject(typeObject::EMPTY);
		}
		if (cellSecondary.obj->getSymbol() == '.' && cellBasic.obj->getCanMove() == true)			//if position is free and predator can move
		{
			cellSecondary.deleteObject();
			cellSecondary = cellBasic;																//take this position
			cellSecondary.obj->setCanMove(false);													//forbed to move this turn
			cellSecondary.obj->setHunger(cellSecondary.obj ->getHunger() - 1);						//increase hunger
			cellSecondary.obj->setLive(cellSecondary.obj->getLive() - 1);							//age

			cellBasic.setObject(typeObject::EMPTY);
		}
		if (cellSecondary.obj->getSymbol() == '*' && cellBasic.obj->getCanMove() == true)
		{
			cellSecondary.obj->setHunger(cellSecondary.obj->getHunger() - 1);						//increase hunger
			cellSecondary.obj->setLive(cellSecondary.obj->getLive() - 1);							//age
		}
		break;
	case 'o':
		if (cellSecondary.obj->getSymbol() == '.' && cellBasic.obj->getCanMove() == true)			//if position is free and prey can move
		{
			cellSecondary.deleteObject();
			cellSecondary = cellBasic;																//take this position
			cellSecondary.obj->setCanMove(false);													//forbed to move this turn
			cellSecondary.obj->setReproduction(cellSecondary.obj->getReproduction() - 1);			//increase reproduction
			cellSecondary.obj->setLive(cellSecondary.obj->getLive() - 1);							//age

			cellBasic.setObject(typeObject::EMPTY);
		}
		if (cellSecondary.obj->getSymbol() == '*' && cellBasic.obj->getCanMove() == true)
		{
			cellSecondary.obj->setReproduction(cellSecondary.obj->getReproduction() - 1);			//increase reproduction
			cellSecondary.obj->setLive(cellSecondary.obj->getLive() - 1);							//age
		}
	default:
		break;
	}
}

void Cell::youCanMoveAgain()
{
	if (obj->getSymbol() != '*' && obj->getSymbol() != '.')		//stone and empty object can`t move
	{
		obj->setCanMove(true);
	}
}

void Cell::objectState()
{
	if (obj->getSymbol() != '.' && obj->getSymbol() != '*')
	{
		if (obj->getSymbol() == 'X' && obj->getHunger() == 0)
		{
			obj->killMe();
			obj = new Object(0, '.');
		}

		if (obj->getLive() == 0)
		{
			obj->killMe();
			obj = new Object(0, '.');
		}
	}
}


void Cell::statistics()
{
	cout << "Total objects on the map : " << Object::getCountObject() << endl;
	cout << "Number of STONE objects : " << Stone::getCountStone() << endl;
	cout << "Number of PREY objects : " << Prey::getCountPrey() << endl;
	cout << "Number of PREDATOR objects : " << Predator::getCountPredator() << endl;
}