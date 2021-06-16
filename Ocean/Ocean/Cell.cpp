#include <iostream>

using std::cout;
using std::endl;

#include "Cell.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#define REPRODUCT 5
#define HUNGER 15

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
		obj = new Object(0,'.');
		break;
	case typeObject::STONE:
		obj->killMe();
		obj = new Stone(30, '*');
		break;
	case typeObject::PREY:
		obj->killMe();
		obj = new Prey(30, 'o', REPRODUCT);
		break;
	case typeObject::PREDATOR:
		obj->killMe();
		obj = new Predator(30, 'X', HUNGER);
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
			cellSecondary.obj->killMe();
			cellSecondary.obj = new Predator(cellBasic.obj->getLive() - 1, cellBasic.obj->getSymbol(), cellBasic.obj->getHunger() + HUNGER, false);

			cellBasic.deleteObject();
			cellBasic.setObject(typeObject::EMPTY);
		}
		if (cellSecondary.obj->getSymbol() == '.' && cellBasic.obj->getCanMove() == true)			//if position is free and predator can move
		{
			cellSecondary.obj->killMe();
			cellSecondary.obj = new Predator(cellBasic.obj->getLive() - 1, cellBasic.obj->getSymbol(), cellBasic.obj->getHunger() - 1, false);

			cellBasic.deleteObject();
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
			if (cellBasic.obj->getReproduction() <= 0)											    //check prey breeding
			{
				cellBasic.obj->setCanMove(false);													//forbed to move this turn
				cellBasic.obj->setLive(cellSecondary.obj->getLive() - 1);							//age
				cellBasic.obj->setReproduction(REPRODUCT);

				cellSecondary.setObject(typeObject::PREY);
			}
			else
			{
				cellSecondary.obj->killMe();
				cellSecondary.obj = new Prey(cellBasic.obj->getLive() - 1, cellBasic.obj->getSymbol(), cellBasic.obj->getReproduction() - 1, false);

				cellBasic.deleteObject();
				cellBasic.setObject(typeObject::EMPTY);
			}
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
			obj = new Object('.');
		}

		if (obj->getLive() == 0)
		{
			obj->killMe();
			obj = new Object('.');
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