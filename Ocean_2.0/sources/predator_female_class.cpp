#include <algorithm>

#include "predator_female_class.h"


void PredatorFemale::Behavior()
{	
	//Gestational age check
	if (GetGestation())
	{
		//Kill a female if the birth is delayed
		if (GetGestation() >= (Settings::MAX_DESTATIONAL_AGE * 2))
				KillMe();

		//When it`s time to give birth
		else if (GetGestation() >= Settings::MAX_DESTATIONAL_AGE)
		{
			//Find free place
			auto obj = std::find_if(GetMemory().begin(), GetMemory().end(), [] (const std::pair<ObjectType, std::pair<int, int>> &object) 
				{ return object.first == ObjectType::EMPTY; });

			if (obj != GetMemory().end())	
				SetCommand( ChildBirth( obj->second ) );
			else 
				Predator::Behavior();
		}
	}
	//Female is not pregnant, may look for a partner
	else 
	{	
		//Search for a partner
		auto obj = std::find_if(GetMemory().begin(), GetMemory().end(), [] (const std::pair<ObjectType, std::pair<int, int>> &object) 
			{ return object.first == ObjectType::PREDATOR_MALE; });

		//If the female sees the male, set command pairing
		if (obj != GetMemory().end())	
			Pairing(obj->second);
		else 
			Predator::Behavior();
	}
}

void PredatorFemale::Action(std::pair<Command, std::pair<int, int>> command)
{
	switch( command.first )
	{
		//If pairing is successful
		case Command::PAIRING_SUCCES:
			//Conception
			SetGestation(1);
			Fishes::Action(command);
			break;

		case Command::CHILD_BIRTH_SUCCES:
			SetGestation(0);
			Fishes::Action(command);
			break;

		default:
			if (GetGestation())
			{
				//Time gestation + 1
				SetGestation( GetGestation() + 1 );

				Fishes::Action(command);
				break;
			}
			else
			{
				Fishes::Action(command);
				break;
			}
	}
}