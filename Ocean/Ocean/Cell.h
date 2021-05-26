#pragma once

#include "Object.h"

enum class typeObject
{
	EMPTY,
	STONE,
	PREY,
	PREDATOR
};

class Cell
{
public:
	Cell();
	~Cell();
	void setObject(typeObject);
	void printObject();
private:
	Object* obj;
};