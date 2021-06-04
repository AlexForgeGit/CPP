#pragma once

#include "Cell.h"

class Map
{
public:
	Map(int = 0, int = 0);
	~Map();
	void setSizeMap(int, int);
	void createBorders();
	void printMap() const;
	void clear();
	void addObject(int, typeObject);
	void step();
	void run();

private:
	Cell** cells;
	int row, column;
};