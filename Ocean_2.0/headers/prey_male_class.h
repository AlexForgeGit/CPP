#pragma once

#include "prey_class.h"
#include "male_class.h"

class PreyMale : public Prey, public Male
{
public:

	PreyMale(std::pair<int, int> coord) : Fishes(coord, ObjectType::PREY_MALE), Male() {};

	virtual ~PreyMale() {}

	//Makes decisions based on the enviroment
	virtual void Behavior() override;

};
