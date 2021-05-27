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
	char getObject() const;

private:
	Object* obj;
};