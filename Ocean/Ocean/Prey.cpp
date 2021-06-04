#include <iostream>
using std::cout;

#include "Prey.h"

Prey::Prey(int l, char s) : Object(l, s) {};

Prey::~Prey()
{
	Object::~Object();
}