#include <conio.h>
#include "Map.h"

int main()
{
	Map ocean(20, 50);
	ocean.createBorders();
	ocean.addStone(10);
	ocean.printMap();

	_getch();
	return 0;
}