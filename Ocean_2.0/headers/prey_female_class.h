#pragma once

#include "prey_class.h"
#include "female_class.h"

class PreyFemale : public Prey, public Female
{
public:

	PreyFemale(std::pair<int, int> coord) : Fishes(coord, ObjectType::PREY_FEMALE), Female() {};

	virtual ~PreyFemale() {}

	//Makes decisions based on the enviroment
	virtual void Behavior() override;

	//Recieve a responce to a request and perform an action
	virtual void Action(Command command) override; 
};
