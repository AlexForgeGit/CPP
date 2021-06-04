#include <iostream>
using std::cout;
using std::endl;

#include "Map.h"

#include <ctime>
#include <cstdlib>
#include <Windows.h>

int i = 0, j = 0;
int x = 0, y = 0;

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

		if (cells[x][y].getObject() == '.')
		{
			cells[x][y].setObject(typeObj);
			i++;
		}
	}
}


void Map::step()
{
	srand(time(NULL));
	for (i = 0; i < row; i++)
		for (j = 0; j < column; j++)
		{
			switch (rand() % 4)
			{
			case 0:
				cells[i][j].moveObject(cells[i][j], cells[i + 1][j]);
				break;
			case 1:
				cells[i][j].moveObject(cells[i][j], cells[i - 1][j]);
				break;
			case 2:
				cells[i][j].moveObject(cells[i][j], cells[i][j + 1]);
				break;
			case 3:
				cells[i][j].moveObject(cells[i][j], cells[i][j - 1]);
				break;
			default:
				break;
			}
		}
}

void Map::run()
{
	for (int i = 0; i < 100; i++)
	{
		clear();
		step();
		printMap();	
		Sleep(1000);
	}
}