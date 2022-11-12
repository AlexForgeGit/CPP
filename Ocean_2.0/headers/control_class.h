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
	void AddObject(std::pair<int, int>, ObjectType);

	//Create N objects of a specific type
	void AddMoreObjects(ObjectType, int);

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
		objects_list_.reserve(row_count * column_count);
	}

	~Control() = default;

	Control( const Control& ) = delete;
	Control& operator=( const Control& ) = delete;


	std::vector< std::shared_ptr<Objects> > objects_list_;

	Field& field_;
};
