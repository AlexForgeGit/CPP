/*
Абстрактный базовый класс, описывающий общие функции всех объектов океана.
*/

#pragma once

#include <vector>

#include "enumerations.h"
#include "field_class.h"

class Objects
{
public:

	Objects(unsigned short old_age, std::pair<int, int> coord, ObjectType object_type) : age_(0), old_age_(old_age), coord_(coord), object_type_(object_type)
	{
		Wait();
	}

	virtual ~Objects() {}


	void SetAge(const unsigned short age) { age_ = age; }

	unsigned short GetAge() { return age_; }


	void SetOldAge(const unsigned short old_age) { old_age_ = old_age; }

	unsigned short GetOldAge() { return old_age_; }


	void SetCoord(const std::pair<int, int> coord) { coord_ = coord; }

	std::pair<int, int> GetCoord() { return coord_; }


	void SetObjectType(ObjectType object_type) { object_type_ = object_type; }

	ObjectType GetObjecType() { return object_type_; }


	void SetCommand(std::pair<Command, std::pair<int, int>> command) { command_ = command; }

	std::pair<Command, std::pair<int, int>> GetCommand() { return command_ ;}


	void Wait();

	//Coin toss adds a luck parameter
	bool FlipCoin();

	bool DieOldAge();

	void KillMe();


	//Send an action request to the control class
	virtual void ActionRequest(Field& field);

	//Recieve a responce to a request and perform an action
	virtual void Action(std::pair<Command, std::pair<int, int>> command); 


private:

	unsigned short age_;

	unsigned short old_age_;

	std::pair<int,int> coord_;

	ObjectType object_type_;

	std::pair<Command, std::pair<int, int>> command_;
};
