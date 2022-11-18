#pragma once

#include "prey_class.h"
#include "male_class.h"

class PreyMale : public Prey, public Male
{
public:

	PreyMale(std::pair<int, int> coord) : Prey(coord, ObjectType::PREY_MALE), Male() {};

	virtual ~PreyMale() {}
};
