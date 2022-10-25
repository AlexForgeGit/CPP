#pragma once

#include "objects_class.h"
#include "settings.h"

class Stone : public Objects
{
public:

	Stone() = delete;

	Stone(std::pair<int, int> coord) : Objects(Settings::OLD_AGE_STONE, coord, ObjectType::STONE)
	{}

};
