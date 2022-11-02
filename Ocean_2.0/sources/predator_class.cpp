#include <algorithm>

#include "predator_class.h"


void Predator::Behavior()
{	
	auto obj_type = std::find_if(GetMemory().begin(), GetMemory().end(), [] ( std::pair<ObjectType, std::pair< int, int >> object) 
		{ return object.first == ObjectType::PREY_MALE || object.first == ObjectType::PREY_FEMALE });

	//If the prey saw seaweed, set command to it
	if ( obj_type != GetMemory().end() )	
	{	
		SetCommand( std::make_pair( Command::EAT_IT, obj_type->second ) );
	}
	else 
		Fishes::Behavior();
}
