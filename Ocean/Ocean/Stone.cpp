#include "Stone.h"

int Stone::countStone = 0;

Stone::Stone(int l, char c, bool cm) : Object(l, c, cm) 
{
	++countStone;
};

Stone::~Stone()
{
	--countStone;
}

int Stone::getCountStone()
{
	return countStone;
}
