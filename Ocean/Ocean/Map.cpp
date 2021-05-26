#include <iostream>
using std::cout;
using std::endl;

#include "Map.h"

#include <ctime>
#include <cstdlib>

int i = 0, j = 0;

Map::Map(int n, int m) 
{
	setSizeMap(n, m);
	cells = new Cell * [n];
	for (i = 0; i < n; i++)
		cells[i] = new Cell[m];
}

Map::~Map()
{
	for (i = 0; i < row; i++)
		delete[] cells[i];
	delete[] cells;
}

void Map::setSizeMap(int n, int m) 
{
	row = n;
	column = m;
}

void Map::printMap() const
{
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
			cells[i][j].printObject();
		cout << endl;
	}
}

void Map::createBorders()
{
	for (i = 0; i < row; i++)
		cells[i][0].setObject(typeObject::STONE);
	for (i = 0; i < row; i++)
		cells[i][column-1].setObject(typeObject::STONE);
	for (i = 1; i < column-1; i++)
		cells[0][i].setObject(typeObject::STONE);
	for (i = 1; i < column-1; i++)
		cells[row-1][i].setObject(typeObject::STONE);

}

void Map::addStone(int number)
{
	srand(time(NULL));
	for (i = 0; i < number; i++)
	{
		cells[1 + rand() % (row-2)][1 + rand() % (column-2)].setObject(typeObject::STONE);
	}
}