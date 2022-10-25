#pragma once

#include <map>

#include "objects_class.h"
#include "settings.h"

class Fishes : public Objects
{
public:

	Fishes(std::pair<int, int> coord, ObjectType object_type) : Objects(Settings::OLD_AGE_FISH, coord, object_type), hunger_(0)
	{}

	unsigned short GetHunger() { return hunger_; }
	void SetHunger( const unsigned short hunger ) { hunger_ = hunger; }

	bool DieHunger();

	void LookNorth(Field& field);
	void LookEast(Field& field);
	void LookSouth(Field& field);
	void LookVest(Field& field);

	//Add to memory objects around me
	void LookAround(Field& field);

	const std::multimap<ObjectType, std::pair<int, int>>& GetMemory() { return memory_; }

	void ClearMemory() { memory_.clear(); }


	std::pair<Command, std::pair<int, int>> Move(std::pair<int, int> coord);

	std::pair<Command, std::pair<int, int>> Eat(std::pair<int, int> coord);

	std::pair<Command, std::pair<int, int>> Pairing(std::pair<int, int> coord);


	//Makes decisions based on the enviroment
	virtual std::pair<Command, std::pair<int, int>> Behavior() = 0;

	//Send an action request to the control class
	virtual std::pair<Command, std::pair<int, int>> ActionRequest(Field& field);


private:

	unsigned short hunger_;

	std::multimap<ObjectType, std::pair<int, int>> memory_;
};
