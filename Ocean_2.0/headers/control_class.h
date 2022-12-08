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
#include "factories.h"
#include "logs_class.h"

class Control
{
public:

	static Control& Instance(std::size_t, std::size_t);

	//Create N objects of a specific type
	void AddObjects(ObjectsFactory& obj_factory, int n = 1);

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
