#pragma once

#include "predator_class.h"
#include "female_class.h"

class PredatorFemale : public Predator, public Female
{
public:

	PredatorFemale(std::pair<int, int> coord) : Predator(coord, ObjectType::PREDATOR_FEMALE), Female() 
	{ GetLogs().WriteString("Female predator born by coordinates ["+ std::to_string(GetCoord().first)+ "." + std::to_string(GetCoord().second) + "]"); };

	//Makes decisions based on the enviroment
	virtual void Behavior() override;

	//Recieve a responce to a request and perform an action
	virtual void Action(std::pair<Command, std::pair<int, int>> command) override; 
};
