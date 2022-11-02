#pragma once

#include "predator_class.h"
#include "male_class.h"

class PredatorMale : public Predator, public Male
{
public:

	PredatorMale(std::pair<int, int> coord) : Fishes(coord, ObjectType::PREDATOR_MALE), Male() {};

	virtual ~PredatorMale() {}

	//Makes decisions based on the enviroment
	virtual void Behavior() override;

};
