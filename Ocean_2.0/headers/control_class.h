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
#include "logs_class.h"

class Control
{
public:

	static Control& Instance(std::size_t, std::size_t);

	//Create an object of a specific type
	template<class ClassType> void AddObject(std::pair<int, int> coord);

	//Create N objects of a specific type
	template<class ClassType> void AddMoreObjects(int n);

	//Delete an object at given coordinates
	void DeleteObject(std::pair<int, int>);

	//Launch an action for each object
	void Step();

	void ClearConsole() { std::cout << "\x1B[2J\x1B[H"; }

	//Runs the simulation for N moves
	void Run(int max_step_number);

	void PrintSimulation(int step_number);

private:

	Control(std::size_t row_count, std::size_t column_count) : 	field_(Field::Instance(row_count, column_count))
	{
		objects_pool_.reserve(row_count * column_count);

		logs_.WriteString("Program launched");
	}

	~Control() { logs_.WriteString("Program completed"); }

	Control( const Control& ) = delete;
	Control& operator=( const Control& ) = delete;


	std::vector< std::shared_ptr<Objects> > objects_pool_;

	Field& field_;

	Logs logs_;
};

template<class ClassType> 
void Control::AddObject(std::pair<int, int> coord)
{
	objects_pool_.push_back(std::make_shared<ClassType>(coord));

	field_.SetObjectType(coord, objects_pool_[objects_pool_.size() - 1]->GetObjecType());
	field_.DeleteFreeCell(coord);
}	


template<class ClassType> 
void Control::AddMoreObjects(int n)
{
	for (auto i = 0; i < n; ++i)
	{
		if (field_.ThereIsFreeCell())
		{
			AddObject<ClassType>(field_.GetRandomFreeCell());
		}
		else
			break;
	}
}
