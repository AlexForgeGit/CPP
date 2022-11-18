#include <thread>
#include <chrono>
#include <algorithm>

#include "control_class.h"
#include "stone_class.h"
#include "seaweed_class.h"
#include "prey_male_class.h"
#include "prey_female_class.h"
#include "predator_male_class.h"
#include "predator_female_class.h"

Control& Control::Instance(std::size_t row_count, std::size_t column_count)
{
	static Control control(row_count, column_count);
	return control;
}

void Control::DeleteObject(std::pair<int, int> coord)
{
	//Find and delete an object at given coordinates
	objects_pool_.erase( std::find_if( objects_pool_.begin(), objects_pool_.end(), [&coord] (const std::shared_ptr<Objects> objects) { return objects->GetCoord() == coord;} ));

	//Set a free cell in the field
	field_.SetObjectType(coord, ObjectType::EMPTY);

	//Add coordinates to vector of free cells
	field_.AddFreeCell(coord);
}


void Control::Step()
{
	std::pair<Command, std::pair<int, int>> temp_command;

	for (auto& obj : objects_pool_)
	{
		if (obj != nullptr)
		{
			obj->ActionRequest(field_);

			temp_command = obj->GetCommand();

			switch( temp_command.first )
			{
				case Command::KILL_ME:
					DeleteObject(obj->GetCoord());
					break; 

				case Command::EAT_IT:
					obj->Action(std::make_pair(Command::EAT_SUCCES , obj->GetCoord()));
					DeleteObject(temp_command.second);
					break; 

				case Command::MOVE_ME:
					field_.SetObjectType(obj->GetCoord(), ObjectType::EMPTY);
					obj->Action(std::make_pair(Command::MOVE_SUCCES , temp_command.second));
					field_.SetObjectType(obj->GetCoord(), obj->GetObjecType());
					break; 

				case Command::PAIRING:
					obj->Action(std::make_pair(Command::PAIRING_SUCCES , obj->GetCoord()));		
					break;

				case Command::CHILD_BIRTH:
					//координаты свободной ячейки temp_command.second 
					//objects_pool_.push_front(std::make_shared<!!!!>(!!!!));
					//AddObject(temp_command.second, obj->GetObjecType());
					//CHILD_BIRTH_SUCCES
					obj->Action(std::make_pair(Command::INACTION , obj->GetCoord()));
					break; 


				default:
					obj->Action(std::make_pair(Command::INACTION , temp_command.second));
					break;
			}
		}
	}
}


void Control::Run(int n)
{
	for (auto i = 0; i < n; ++i)
	{
		
		Step();

		field_.PrintField();

		std::cout<<"Step number          - " << i << std::endl;
		std::cout<<"Objects count        - " << objects_pool_.size() << std::endl;
		std::cout<<"Number of free cells - " << field_.GetNumberFreeCells() << std::endl;	

		//Thread delay by 1 second
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		ClearConsole();

		std::random_shuffle(objects_pool_.begin(), objects_pool_.end());

	}
}
