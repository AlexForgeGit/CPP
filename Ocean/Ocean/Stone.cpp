#include <iostream>
using std::cout;

#include "Stone.h"

Stone::Stone(int l, char s) : Object(l, s) {};

Stone::~Stone()
{
	Object::~Object();
}
