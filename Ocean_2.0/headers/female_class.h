#pragma once

#include "gender_class.h"

class Female: public Gender
{
public:

	Female() : Gender(GenderType::FEMALE) {} 
	
	virtual ~Female() {}

	void SetGestation(unsigned short gestation) { gestation_ = gestation; }

	unsigned short GetGestation() { return gestation_; }

	//Return the command to create a new object by coordinates
	std::pair< Command, std::pair< int, int> > ChildBirth(std::pair<int, int> coord) { return std::make_pair(Command::CHILD_BIRTH, coord); }

private:

	unsigned short gestation_;
};
