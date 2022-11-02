#include "prey_class.h"

void Prey::Behavior()
{	
	auto obj_type = GetMemory().find( ObjectType::SEAWEED );

	//If the prey saw seaweed, set command to it
	if ( obj_type != GetMemory().end() )	
	{	
		SetCommand( std::make_pair( Command::EAT_IT, obj_type->second ) );
	}
	else 
		Fishes::Behavior();
}
