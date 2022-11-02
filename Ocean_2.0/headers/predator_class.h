#pragma once

#include "fishes_class.h"

class Predator: public virtual Fishes
{
public:
	
	Predator(std::pair<int, int> coord, ObjectType object_type) : Fishes(coord, object_type) {};

	virtual ~Predator() {}

	//Makes decisions based on the enviroment
	virtual void Behavior() override;
};
