#pragma once

#include "predator_class.h"
#include "male_class.h"

class PredatorMale : public Predator, public Male
{
public:

	PredatorMale(std::pair<int, int> coord) : Predator(coord, ObjectType::PREDATOR_MALE), Male() 
	{ GetLogs().WriteString("Male predator born by coordinates ["+ std::to_string(GetCoord().first)+ "." + std::to_string(GetCoord().second) + "]"); };
};
