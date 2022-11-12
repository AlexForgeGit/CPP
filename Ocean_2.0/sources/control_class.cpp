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


void Control::AddObject(std::pair<int, int> coord, ObjectType object_type)
{
	switch(object_type)
	{
		case ObjectType::PREY_MALE: 
			objects_list_.push_back(std::make_shared<PreyMale>(coord));
			field_.SetObjectType(coord, ObjectType::PREY_MALE);
			field_.DeleteFreeCell(coord);
			break;

		case ObjectType::PREY_FEMALE:
			objects_list_.push_back(std::make_shared<PreyFemale>(coord));
			field_.SetObjectType(coord, ObjectType::PREY_FEMALE);
			field_.DeleteFreeCell(coord);
			break;

		case ObjectType::PREDATOR_MALE:
			objects_list_.push_back(std::make_shared<PredatorMale>(coord));
			field_.SetObjectType(coord, ObjectType::PREDATOR_MALE);
			field_.DeleteFreeCell(coord);
			break;

		case ObjectType::PREDATOR_FEMALE:
			objects_list_.push_back(std::make_shared<PredatorFemale>(coord));
			field_.SetObjectType(coord, ObjectType::PREDATOR_FEMALE);
			field_.DeleteFreeCell(coord);
			break;

		case ObjectType::STONE:
			objects_list_.push_back(std::make_shared<Stone>(coord));
			field_.SetObjectType(coord, ObjectType::STONE);
			field_.DeleteFreeCell(coord);
			break;

		case ObjectType::SEAWEED:
			objects_list_.push_back(std::make_shared<Seaweed>(coord));
			field_.SetObjectType(coord, ObjectType::SEAWEED);
			field_.DeleteFreeCell(coord);
			break;

		default:
			break;
	}
}

void Control::AddMoreObjects(ObjectType object_type, int n)
{
	for (auto i = 0; i < n; ++i)
	{
		if (field_.ThereIsFreeCell())
			{
				AddObject(field_.GetRandomFreeCell(), object_type);
			}
		else
			break;
	}
}

void Control::DeleteObject(std::pair<int, int> coord)
{
	//Find and delete an object at given coordinates
	objects_list_.erase( std::find_if( objects_list_.begin(), objects_list_.end(), [&coord] (const std::shared_ptr<Objects> objects) { return objects->GetCoord() == coord;} ));

	//Set a free cell in the field
	field_.SetObjectType(coord, ObjectType::EMPTY);

	//Add coordinates to vector of free cells
	field_.AddFreeCell(coord);
}


void Control::Step()
{
	std::pair<Command, std::pair<int, int>> temp_command;

	for (auto& obj : objects_list_)
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
					DeleteObject(temp_command.second);
					obj->Action(std::make_pair(Command::EAT_SUCCES , obj->GetCoord()));
					break; 

				case Command::MOVE_ME:
					field_.SetObjectType(obj->GetCoord(), ObjectType::EMPTY);
					field_.SetObjectType(temp_command.second, obj->GetObjecType());
					obj->Action(std::make_pair(Command::MOVE_SUCCES , temp_command.second));				
					break; 

				case Command::PAIRING:
					std::find_if( objects_list_.begin(), objects_list_.end(), [&temp_command] (const std::shared_ptr<Objects> objects) 
						{ return objects->GetCoord() == temp_command.second; })->get()->Action(std::make_pair(Command::PAIRING_SUCCES , obj->GetCoord()));					
					break;

				case Command::CHILD_BIRTH:
					//AddObject(temp_command.second, obj->GetObjecType());
					//CHILD_BIRTH_SUCCES
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
		field_.PrintField();
		
		Step();

		std::cout<<"Step number - " << i << std::endl;

		//Thread delay by 1 second
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		ClearConsole();

	}
}
