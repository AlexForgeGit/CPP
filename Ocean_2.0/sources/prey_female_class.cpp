#include "prey_female_class.h"


void PreyFemale::Behavior()
{	
	auto obj_type = GetMemory().find( ObjectType::EMPTY);

	//When it`s time to give birth, set command childbirth
	if ( (GetGestation() >= Settings::MAX_DESTATIONAL_AGE) && obj_type != GetMemory().end() )	
	{	
		SetCommand( ChildBirth( obj_type->second ) );
	}
	else 
		Prey::Behavior();
}

void PreyFemale::Action(std::pair<Command, std::pair<int, int>> command)
{
	switch( command.first )
	{
		//If pairing is successful
		case Command::PAIRING_SUCCES:

			//Conception
			SetGestation( GetGestation() + 1 );

			//Aging age + 1, Growing hunger, check eat, check move
			Fishes::Action(command);
			break;

		case Command::CHILD_BIRTH_SUCCES:

			SetGestation(0);

			Fishes::Action(command);
			break;

		default:
			if ( GetGestation() > 0 )
			{
				//Time gestation + 1
				SetGestation( GetGestation() + 1 );

				Fishes::Action(command);
				break;
			}
			else
				Fishes::Action(command);

			break;
	}
}