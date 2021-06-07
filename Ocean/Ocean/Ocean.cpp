#include <conio.h>
#include "Map.h"
#include <Windows.h>

int main()
{
	Map ocean(19, 50);
	ocean.createBorders();
	ocean.addObject(15, typeObject::STONE);
	ocean.addObject(50, typeObject::PREY);
	ocean.addObject(10, typeObject::PREDATOR);
	ocean.run();

	_getch();
	return 0;
}