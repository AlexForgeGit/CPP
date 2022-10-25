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

	Objects() = delete;

	Objects(unsigned short old_age, std::pair<int, int> coord, ObjectType object_type) : age_(0), old_age_(old_age), coord_(coord), object_type_(object_type)
	{}

	virtual ~Objects() {}


	void SetAge(const unsigned short age) { age_ = age; }

	unsigned short GetAge() { return age_; }


	void SetOldAge(const unsigned short old_age) { old_age_ = old_age; }

	unsigned short GetOldAge() { return old_age_; }


	void SetCoord(const std::pair<int, int> coord) { coord_ = coord; }

	std::pair<int, int> GetCoord() { return coord_; }


	void SetObjectType(ObjectType object_type) { object_type_ = object_type; }

	ObjectType GetObjecType() { return object_type_; }


	//Coin toss adds a luck parameter
	bool FlipCoin();

	bool DieOldAge();


	//Send an action request to the control class
	virtual std::pair<Command, std::pair<int, int>> ActionRequest(Field& field);

	//Recieve a responce to a request and perform an action
	virtual void Action(Command command) = 0;


private:

	unsigned short age_;

	unsigned short old_age_;

	std::pair<int,int> coord_;

	ObjectType object_type_;
};
