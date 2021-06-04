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
	void moveObject(Cell &, Cell &);
	void deleteObject();
private:
	Object* obj;
};