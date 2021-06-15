#include <conio.h>
#include "Map.h"
#include <Windows.h>

int main()
{
	Map ocean(15, 30);
	ocean.createBorders();
	ocean.addObject(0, typeObject::STONE);
	ocean.addObject(10, typeObject::PREY);
	ocean.addObject(10, typeObject::PREDATOR);
	ocean.run();

	_getch();
	return 0;
}