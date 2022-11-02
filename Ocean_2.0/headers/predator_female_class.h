#pragma once

#include "predator_class.h"
#include "female_class.h"

class PredatorFemale : public Predator, public Female
{
public:

	PredatorFemale(std::pair<int, int> coord) : Fishes(coord, ObjectType::PREDATOR_FEMALE), Female() {};

	virtual ~PredatorFemale() {}

	//Makes decisions based on the enviroment
	virtual void Behavior() override;

	//Recieve a responce to a request and perform an action
	virtual void Action(Command command) override; 
};
