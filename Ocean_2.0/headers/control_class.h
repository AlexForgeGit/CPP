/*
	Класс управления объектами на "игровом поле".
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "field_class.h"
#include "objects_class.h"


class Control
{
public:

	static Control& Instance(std::size_t, std::size_t);

	//Create an object of a specific type
	template<class ClassType> void AddObject(std::pair<int, int> coord, ObjectType object_type)
	{
		objects_pool_.push_back(std::make_shared<ClassType>(coord));

		field_.SetObjectType(coord, object_type);
		field_.DeleteFreeCell(coord);
	}	

	//Create N objects of a specific type
	template<class ClassType> void AddMoreObjects(ObjectType object_type, int n)
	{
		for (auto i = 0; i < n; ++i)
		{
			if (field_.ThereIsFreeCell())
			{
				AddObject<ClassType>(field_.GetRandomFreeCell(), object_type);
			}
			else
				break;
		}
	}

	//Delete an object at given coordinates
	void DeleteObject(std::pair<int, int>);

	//Launch an action for each object
	void Step();

	void ClearConsole() { std::cout << "\x1B[2J\x1B[H"; }

	//Runs the simulation for N moves
	void Run(int);

private:

	Control(std::size_t row_count, std::size_t column_count) : 	field_(Field::Instance(row_count, column_count))
	{
		objects_pool_.reserve(row_count * column_count);
	}

	~Control() = default;

	Control( const Control& ) = delete;
	Control& operator=( const Control& ) = delete;


	std::vector< std::shared_ptr<Objects> > objects_pool_;

	Field& field_;
};
