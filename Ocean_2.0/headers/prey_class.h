#pragma once

#include "fishes_class.h"

class Prey: public Fishes
{
public:
	
	Prey(std::pair<int, int> coord, ObjectType object_type) : Fishes(coord, object_type) {};

	virtual ~Prey() {}

	//Makes decisions based on the enviroment
	virtual void Behavior() override;
};
