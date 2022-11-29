#pragma once

#include "objects_class.h"
#include "settings.h"

class Seaweed : public Objects
{
public:

	Seaweed() = delete;

	Seaweed(std::pair<int, int> coord) : Objects(Settings::OLD_AGE_SEAWEED, coord, ObjectType::SEAWEED)
	{ GetLogs().WriteString("Seaweed created by coordinates ["+ std::to_string(GetCoord().first)+ "." + std::to_string(GetCoord().second) + "]"); } 
};
