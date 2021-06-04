#include <conio.h>
#include "Map.h"
#include <Windows.h>

int main()
{
	Map ocean(20, 50);
	ocean.createBorders();
	ocean.addObject(50, typeObject::STONE);
	ocean.addObject(20, typeObject::PREY);
	ocean.addObject(10, typeObject::PREDATOR);
	ocean.printMap();
	ocean.run();

	_getch();
	return 0;
}