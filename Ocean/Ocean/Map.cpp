#include <iostream>
using std::cout;
using std::endl;

#include "Map.h"

#include <ctime>
#include <cstdlib>
#include <Windows.h>

int i, j;

Map::Map(int n, int m) 
{
	setSizeMap(n, m);
	cells = new Cell * [row];
	for (i = 0; i < row; i++)
		cells[i] = new Cell[column];
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
			cout << cells[i][j].getObject();
		cout << endl;
	}
}

void Map::clear()
{
	system("cls");
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

void Map::addObject(int number, typeObject typeObj)
{
	srand(time(NULL));
	for (i = 0; i < number;)
	{
		int x = 1 + rand() % (row - 2);
		int y = 1 + rand() % (column - 2);

		if (cells[x][y].getObject() == '.')								//If the place is free, take it with a new object
		{
			cells[x][y].setObject(typeObj);
			i++;
		}
	}
}


void Map::step()
{
	srand(time(NULL));
	for (i = 1; i < row-1; i++)											//Range without borders on "i"
		for (j = 1; j < column-1; j++)									//Range without borders on "j"
		{
			switch (rand() % 4)											//Selection of a random direction of movement
			{
			case 0:
				cells[i][j].moveObject(cells[i][j], cells[i + 1][j]);	//Move ↑
				break;
			case 1:
				cells[i][j].moveObject(cells[i][j], cells[i - 1][j]);	//Move ↓
				break;
			case 2:
				cells[i][j].moveObject(cells[i][j], cells[i][j + 1]);	//Move →
				break;
			case 3:
				cells[i][j].moveObject(cells[i][j], cells[i][j - 1]);	//Move ←
				break;
			default:
				break;
			}
		}
}

void Map::updateMovement()
{
	for (i = 1; i < row - 1; i++)											//Range without borders on "i"
		for (j = 1; j < column - 1; j++)									//Range without borders on "j"
		{
			cells[i][j].youCanMoveAgain();									//give the opportunity to move again
		}
}

void Map::statusCheck()
{
	for (i = 1; i < row - 1; i++)											//Range without borders on "i"
		for (j = 1; j < column - 1; j++)									//Range without borders on "j"
		{
			cells[i][j].objectState();
		}
}

void Map::run()
{
	for (auto round = 0; round < 100; round++)
	{
		printMap();
		step();
		cout << "ROUND : " << round << endl;
		(*cells)->statistics();
		updateMovement();
		statusCheck();
		Sleep(1000);
		clear();
	}
}