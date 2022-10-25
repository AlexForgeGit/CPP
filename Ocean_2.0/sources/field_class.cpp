#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>

#include "field_class.h"

Field::Field(std::size_t row_count, std::size_t column_count) : row_count_(row_count), column_count_(column_count)
{
	simulation_field_.resize(row_count_);

	for (auto i = 0; i < row_count_; ++i)
		for (auto j = 0; j < column_count_; ++j)
		{
			//Setting the coordinates and object type in each cell
			simulation_field_[i].insert(std::make_pair(std::make_pair(i , j), ObjectType::EMPTY));
		}

	//Filling the vector pf free cells
	FindAllFreeCells();
}


Field& Field::Instance(std::size_t row_count, std::size_t column_count)
{
	static Field field(row_count, column_count);
	return field;
}


void Field::PrintField()
{
	for (auto &row : simulation_field_)
	{
		for (auto &column : row)
		{
			//Print characters depending of object type
			switch(column.second)
			{
				case ObjectType::EMPTY:
					std::cout << "_ ";
					break;

				case ObjectType::PREY:
					std::cout << "Q ";
					break;

				case ObjectType::PREDATOR:
					std::cout << "P ";
					break;

				case ObjectType::BARRIER:
					std::cout << "+ ";
					break;

				case ObjectType::SEAWEED:
					std::cout << "* ";
					break;

				default:
					break;
			}
		}
	}
}


void Field::SetObjectType(std::pair<int , int> coord, ObjectType object_type)
{
	//Search for the desired iterator by coordinates
	auto it = simulation_field_[coord.first].find(coord);

	//Assign a new type
	it->second = object_type;
}


ObjectType Field::GetObjectType(std::pair<int , int> coord)
{
	//Search for the desired iterator by coordinates
	auto it = simulation_field_[coord.first].find(coord);

	//Return object type
	return it->second;
}

void Field::FindAllFreeCells()
{
	for (auto &row : simulation_field_)
	{
		for (auto &column : row)
		{
			if (column.second == ObjectType::EMPTY)
				free_cells_.push_back(column.first);
		}
	}
}

std::pair<int, int> Field::GetRandomFreeCell()
{
	//Seed with a real random value
	std::random_device rand;

	//Setting the range from 0 to the number of free cells
	std::uniform_int_distribution<int> uniform_dist(0, free_cells_.size());

	//Return random coordinates
	return free_cells_[uniform_dist(rand)];
}


void Field::DeleteFreeCell(std::pair<int , int> coord)
{
	//Search for an iterator of the required coordinates
	auto it = std::remove(free_cells_.begin(), free_cells_.end(), coord);

	//Delete element
	free_cells_.erase(it, free_cells_.end());
}
