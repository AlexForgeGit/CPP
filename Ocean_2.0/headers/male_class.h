#pragma once

#include "gender_class.h"

class Male: public Gender
{
public:

	Male() : Gender(GenderType::MALE) {}

	virtual ~Male(){}
};