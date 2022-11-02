#pragma once

#include <map>

#include "objects_class.h"
#include "settings.h"

class Fishes : public Objects
{
public:

	Fishes(std::pair<int, int> coord, ObjectType object_type) : Objects(Settings::OLD_AGE_FISH, coord, object_type), hunger_(0)
	{}

	virtual ~Fishes() {}

	unsigned short GetHunger() { return hunger_; }
	void SetHunger( const unsigned short hunger ) { hunger_ = hunger; }

	bool DieHunger();

	void LookNorth(Field& field);
	void LookEast(Field& field);
	void LookSouth(Field& field);
	void LookVest(Field& field);

	//Add to memory objects around me
	void LookAround(Field& field);

	std::multimap<ObjectType, std::pair<int, int>>& GetMemory() { return memory_; }

	void ClearMemory() { memory_.clear(); }

	
	void Move(std::pair<int, int> coord);

	void Eat(std::pair<int, int> coord);

	void Pairing(std::pair<int, int> coord);


	//Makes decisions based on the enviroment
	virtual void Behavior();

	//Send an action request to the control class
	virtual void ActionRequest(Field& field) override;

	//Recieve a responce to a request and perform an action
	virtual void Action(Command command) override; 


private:

	unsigned short hunger_;

	std::multimap<ObjectType, std::pair<int, int>> memory_;
};
