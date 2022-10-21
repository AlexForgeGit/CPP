#pragma once

#include <vector>
#include <map>

#include "enumerations.h"

class Field 
{
public:
	//Create an instance of a singleton class
	static Field& Instance(std::size_t, std::size_t);

	void PrintField();

	//Change cell type to field by coordinates
	void SetObjectType(std::pair<int , int>, ObjectType);

	//Return cell type to field by coordinates	
	ObjectType GetObjectType(std::pair<int , int>);

	//Searches and writes to vector free_cells all free cells
	void FindAllFreeCells();

	//Return the coordinates of a random free cell
	std::pair<int, int> GetRandomFreeCell();

	//Remove coordinates from vector free cells
	void DeleteFreeCell(std::pair<int , int>);

private:

	Field(std::size_t row_count, std::size_t column_count);

	Field() = delete;

	Field(const Field&) = delete;

	Field& operator=(const Field&) = delete;

	~Field() = default;

	std::size_t row_count_;
	std::size_t column_count_;

	std::vector<std::map<std::pair<int, int> , ObjectType>> simulation_field_;

	//Vector for storing the coordinates of empty cells on the simulation field
	std::vector<std::pair<int, int>> free_cells_; 								
};